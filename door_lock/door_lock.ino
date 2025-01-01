#include <SoftwareSerial.h>
#include <MFRC522.h>
#include <Servo.h>

// PIN 配置
#define RST_PIN 9
#define SS_PIN 10
#define SERVO_PIN 6

MFRC522 mfrc522(SS_PIN, RST_PIN);
Servo servo;

// Wi-Fi 配置
const char* ssid = "PXY";
const char* password = "12345678";

// UDP 配置
const int udpPort = 5678;

// 软件串口，用于 ESP8266
SoftwareSerial espSerial(2, 3);

// 房间控制逻辑
bool roomControlEnabled = false; // 默认禁用普通房间号控制
const String localRoomNumber = "0001"; // 固定本地房间号
String savedPassword = "9527";             // 保存的 16 位动态密码

// 卡片目标数据块（第 2 扇区的第 1 块，即块号 8）
const byte targetBlock = 8;

// 舵机状态变量
bool servoOpened = false;              // 舵机是否已经打开
unsigned long servoStartTime = 0;      // 舵机打开时间戳

// 随机生成 MAC 地址
String generateRandomMacAddress() {
  String mac = "";
  for (int i = 0; i < 6; i++) {
    int byteValue = random(0, 256);    // 生成 0 到 255 的随机值
    if (i > 0) mac += ":";             // 添加分隔符
    if (byteValue < 16) mac += "0";    // 确保每个字节为两位十六进制数
    mac += String(byteValue, HEX);     // 转换为十六进制字符串
  }
  mac.toUpperCase();                   // 转换为大写
  return mac;
}

// 设置 ESP8266 的 MAC 地址
void setEspMacAddress(String macAddress) {
  String command = "AT+CIPSTAMAC=\"" + macAddress + "\"";
  sendCommand(command, "OK", 2000);    // 发送指令并等待响应
  Serial.println("已设置随机 MAC 地址: " + macAddress);
}

// 初始化设置
void setup() {
  Serial.begin(9600);
  espSerial.begin(9600);

  SPI.begin();
  mfrc522.PCD_Init();

  servo.attach(SERVO_PIN);
  servo.write(0); // 初始状态关闭舵机

  delay(2000);

  // 检测 ESP8266 是否正常工作
  sendCommand("AT", "OK", 2000);

  // 生成并设置随机 MAC 地址
  String randomMac = generateRandomMacAddress();
  setEspMacAddress(randomMac);

  // 循环检测 Wi-Fi 连接直到成功
  connectToWiFi(ssid, password);

  // 配置为 UDP Server
  configureAsUDPServer();
}

// 处理 UDP 数据
void processUDPData(String data) {
  Serial.println("处理 UDP 数据: " + data);

  int ipdIndex = data.indexOf("+IPD,");
  if (ipdIndex != -1) {
    int colonIndex = data.indexOf(":", ipdIndex);  // 找到 ":" 的位置
    if (colonIndex != -1) {
      String udpPayload = data.substring(colonIndex + 1); // 提取 ":" 后的数据
      udpPayload.trim(); // 去除多余字符
      Serial.println("接收到的 UDP 数据内容: " + udpPayload);

      if (udpPayload.startsWith("on:")) {  // 处理 "on:" 指令
        String receivedPassword = udpPayload.substring(3); // 获取动态密码
        if (receivedPassword.length() >= 16) {
          savedPassword = receivedPassword; // 保存动态密码
          roomControlEnabled = true;        // 启用房间控制
          Serial.println("保存的动态密码: " + savedPassword);
        } else {
          Serial.println("动态密码长度不足，无法处理");
        }
      } else if (udpPayload.startsWith("off:")) {  // 处理 "off:" 指令
        savedPassword = "9527";              // 清空动态密码
        roomControlEnabled = false;      // 禁用房间控制
        Serial.println("已清除本地保存的开门密码");
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

// 主程序循环
void loop() {
  // 定期检查 Wi-Fi 状态
 /* static unsigned long lastCheck = 0;
  if (millis() - lastCheck > 60000) { // 每 60 秒检查一次
    lastCheck = millis();
    checkWiFiStatus();
  }*/

  // 检查是否有来自 UDP 的数据
  if (espSerial.available()) {
    String rawData = espSerial.readString();
    Serial.println("接收到的原始数据: " + rawData);

    if (rawData.indexOf("+IPD") != -1) {
      processUDPData(rawData);
    }
  }

  // 检查是否有卡片靠近
  if (mfrc522.PICC_IsNewCardPresent()) {
    if (mfrc522.PICC_ReadCardSerial()) {
      String cardPassword = readCardPassword();
      Serial.println("检测到卡片，动态密码: " + cardPassword);

      // 条件：本地保存的密码和读取到的卡片动态密码必须相等
      if (cardPassword == savedPassword) {
        Serial.println("密码匹配成功，允许开门");
        servoOpened = true;                // 设置舵机打开状态
        servoStartTime = millis();         // 记录打开时间
        servo.write(90);                   // 打开舵机
      } else {
        Serial.println("密码不匹配，无法开门");
      }

      mfrc522.PICC_HaltA();                // 停止卡片的读取
      mfrc522.PCD_StopCrypto1();           // 停止加密通信
    }
  }

  // 非阻塞舵机关闭逻辑
  if (servoOpened && millis() - servoStartTime > 2000) {
    servo.write(0);                      // 关闭舵机
    servoOpened = false;                 // 重置舵机状态
    Serial.println("舵机已关闭");
  }
}

// 检查 Wi-Fi 状态
void checkWiFiStatus() {
  espSerial.println("AT+CWJAP?");
  delay(100); // 小延时避免串口拥堵

  if (espSerial.available()) {
    String response = espSerial.readString();
    Serial.println("Wi-Fi 状态检查: " + response);

    if (response.indexOf("WIFI DISCONNECT") != -1 || response.indexOf("No AP") != -1) {
      Serial.println("Wi-Fi 连接丢失，尝试重新连接...");
      connectToWiFi(ssid, password);
    }
  }
}

// 循环检测 Wi-Fi 连接（首次启动时调用）
void connectToWiFi(const char* ssid, const char* password) {
  Serial.println("尝试连接到 Wi-Fi...");
  while (true) {
    String command = "AT+CWJAP=\"" + String(ssid) + "\",\"" + String(password) + "\"";
    sendCommand(command, "OK", 10000);

    espSerial.println("AT+CWJAP?");
    delay(2000);

    if (espSerial.available()) {
      String response = espSerial.readString();
      Serial.println("Wi-Fi 连接状态: " + response);
      if (response.indexOf(String(ssid)) != -1) {
        Serial.println("Wi-Fi 已成功连接到: " + String(ssid));
        break;
      }
    }
    Serial.println("Wi-Fi 连接失败，重新尝试...");
    delay(5000);
  }
}

// 配置为 UDP Server
void configureAsUDPServer() {
  sendCommand("AT+CWMODE=3", "OK", 2000);
  sendCommand("AT+CIPMUX=1", "OK", 2000);
  sendCommand("AT+CIPCLOSE=0", "OK", 2000);
  sendCommand("AT+CIPSTART=0,\"UDP\",\"0.0.0.0\"," + String(udpPort) + "," + String(udpPort) + ",0", "OK", 2000);
  Serial.println("UDP 服务已启动，端口: " + String(udpPort));
}

// 读取卡片动态密码
String readCardPassword() {
  MFRC522::StatusCode status;
  byte buffer[18];
  byte blockSize = sizeof(buffer);

  MFRC522::MIFARE_Key key;
  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;

  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, targetBlock, &key, &(mfrc522.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.print("认证失败: ");
    Serial.println(mfrc522.GetStatusCodeName(status));
    return "";
  }

  status = mfrc522.MIFARE_Read(targetBlock, buffer, &blockSize);
  if (status != MFRC522::STATUS_OK) {
    Serial.print("读取目标块失败: ");
    Serial.println(mfrc522.GetStatusCodeName(status));
    return "";
  }

  String dynamicPassword = "";
  for (byte i = 0; i < 16; i++) {
    dynamicPassword += char(buffer[i]);
  }

  return dynamicPassword;
}

// 发送 AT 指令
void sendCommand(String command, String expectedResponse, unsigned long timeout) {
  espSerial.println(command);
  unsigned long startTime = millis();
  String response = "";

  while (millis() - startTime < timeout) {
    if (espSerial.available()) {
      response += espSerial.readString();
    }
  }

  Serial.println("ESP8266 响应: " + response);

  if (response.indexOf(expectedResponse) != -1) {
    Serial.println("命令成功: " + command);
  } else {
    Serial.println("命令超时或失败: " + command);
  }
}