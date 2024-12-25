#include <SoftwareSerial.h>
#include <MFRC522.h>
#include <Servo.h>

#define RST_PIN 9
#define SS_PIN 10
#define SERVO_PIN 6

MFRC522 mfrc522(SS_PIN, RST_PIN);
Servo servo;

const char* ssid = "PXY";
const char* password = "12345678";

const int udpPort = 5678;

SoftwareSerial espSerial(2, 3);

// 房间权限存储
bool roomControlEnabled = false; // 默认禁用普通房间号控制
bool rootControlEnabled = true;  // 默认启用 root 房间号控制
String localRoomNumber = "";     // 本地房间号（由 UDP 数据设置）

// 卡片目标数据块（第2扇区的第1块，即块号8）
const byte targetBlock = 8;

void setup() {
  Serial.begin(9600);
  espSerial.begin(9600);

  SPI.begin();
  mfrc522.PCD_Init();

  servo.attach(SERVO_PIN);
  servo.write(0);

  delay(2000);

  // 检测 ESP8266 是否正常工作
  sendCommand("AT", "OK", 2000);

  // 连接到 Wi-Fi
  connectToWiFi(ssid, password);

  // 配置为 UDP Server
  configureAsUDPServer();
}

void loop() {
  // 检查是否有来自广播的数据
  if (espSerial.available()) {
    // 读取 ESP8266 返回的所有原始数据
    String rawData = espSerial.readString();
    Serial.println("接收到的原始数据: " + rawData);

    // 检测到数据时处理
    if (rawData.indexOf("+IPD") != -1) {
      processUDPData(rawData);
    } else {
      Serial.println("未检测到 +IPD 数据，可能是其他响应...");
    }
  }

  // 检查是否有卡片靠近
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    String cardRoomNumber = readCardRoomNumber();
    Serial.println("检测到卡片，房间号: " + cardRoomNumber);

    // 检查权限
    if ((cardRoomNumber == "root" && rootControlEnabled) ||
        (cardRoomNumber == localRoomNumber && roomControlEnabled)) {
      Serial.println("权限验证通过，控制舵机旋转");
      controlServo();
    } else {
      Serial.println("权限验证失败，无法控制舵机");
    }

    // 停止卡片通信，释放资源
    mfrc522.PICC_HaltA();
  }
}

// 手动连接 Wi-Fi（首次启动时调用）
void connectToWiFi(const char* ssid, const char* password) {
  Serial.println("尝试连接到 Wi-Fi...");
  String command = "AT+CWJAP=\"" + String(ssid) + "\",\"" + String(password) + "\"";
  sendCommand(command, "OK", 10000);
  Serial.println("已发送连接 Wi-Fi 指令");
}

// 配置为 UDP Server
void configureAsUDPServer() {
  sendCommand("AT+CWMODE=3", "OK", 2000); // 设置为 STA 模式
  sendCommand("AT+CIPMUX=1", "OK", 2000); // 启用多连接
  sendCommand("AT+CIPCLOSE=0", "OK", 2000); // 尝试关闭连接 0（UDP 服务）
  sendCommand("AT+CIPSTART=0,\"UDP\",\"0.0.0.0\"," + String(udpPort) + "," + String(udpPort) + ",0", "OK", 2000); // 启动 UDP Server
  Serial.println("UDP 服务已启动，端口: " + String(udpPort));
}

// 处理 UDP 数据
void processUDPData(String data) {
  Serial.println("处理 UDP 数据: " + data);

  // 提取 "+IPD" 后的数据内容
  int ipdIndex = data.indexOf("+IPD,");
  if (ipdIndex != -1) {
    int colonIndex = data.indexOf(":", ipdIndex);  // 找到 ":" 的位置
    if (colonIndex != -1) {
      String udpPayload = data.substring(colonIndex + 1); // 提取 ":" 后的数据
      udpPayload.trim(); // 去除多余字符
      Serial.println("接收到的 UDP 数据内容: " + udpPayload);

      // 解析 UDP 数据
      if (udpPayload.startsWith("on:")) {
        localRoomNumber = udpPayload.substring(3); // 获取房间号
        roomControlEnabled = true; // 启用该房间号控制
        Serial.println("启用房间号 " + localRoomNumber + " 的控制权限");
      } else if (udpPayload.startsWith("off:")) {
        localRoomNumber = udpPayload.substring(4); // 获取房间号
        roomControlEnabled = false; // 禁用该房间号控制
        Serial.println("禁用房间号 " + localRoomNumber + " 的控制权限");
      } else {
        Serial.println("未知的 UDP 命令: " + udpPayload);
      }
    } else {
      Serial.println("未找到 ':' 分隔符，无法解析数据内容");
    }
  } else {
    Serial.println("未找到 +IPD，可能是无效数据");
  }
}

// 控制舵机
void controlServo() {
  servo.write(90); // 打开舵机
  delay(2000);     // 保持打开状态 2 秒
  servo.write(0);  // 关闭舵机
  Serial.println("舵机控制完成");
}

// 读取卡片房间号（从加密数据块解析房间号）
String readCardRoomNumber() {
  MFRC522::StatusCode status;
  byte buffer[18];  // 用于存储从块中读取的数据
  byte blockSize = sizeof(buffer);

  // 固定的加密密钥（16 字节）
  const byte encryptionKey[16] = {0xFC, 0x66, 0x91, 0xED, 0xAA, 0x8D, 0x4A, 0x36, 0x99, 0x77, 0x1A, 0xCC, 0x00, 0x00, 0x00, 0x00};

  // 验证目标块（使用默认密钥）
  MFRC522::MIFARE_Key key;
  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF; // 默认密钥：全FF

  // 验证目标块（块号 targetBlock）
  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, targetBlock, &key, &(mfrc522.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.print("认证失败: ");
    Serial.println(mfrc522.GetStatusCodeName(status));

    // 停止通信，释放资源
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    return "";
  }

  // 从目标块读取数据
  status = mfrc522.MIFARE_Read(targetBlock, buffer, &blockSize);
  if (status != MFRC522::STATUS_OK) {
    Serial.print("读取目标块失败: ");
    Serial.println(mfrc522.GetStatusCodeName(status));

    // 停止通信，释放资源
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    return "";
  }

  // 解密并解析房间号
  String roomNumber = "";
  for (byte i = 12; i < 16; i++) { // 房间号存储在加密数据的最后 4 字节
    roomNumber += char(buffer[i] ^ encryptionKey[i]); // 解密房间号
  }

  Serial.print("读取到的房间号: ");
  Serial.println(roomNumber);

  // 停止卡片通信，释放资源
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();

  return roomNumber;
}

// 发送 AT 指令
void sendCommand(String command, String expectedResponse, unsigned long timeout) {
  espSerial.println(command);  // 发送 AT 指令到 ESP8266
  unsigned long startTime = millis();
  String response = "";

  while (millis() - startTime < timeout) { // 等待响应
    if (espSerial.available()) {
      response += espSerial.readString();
    }
  }

  Serial.println("ESP8266 响应: " + response);

  // 检查响应中是否包含预期字符串
  if (response.indexOf(expectedResponse) != -1) {
    Serial.println("命令成功: " + command);
  } else {
    Serial.println("命令超时或失败: " + command);
  }
}