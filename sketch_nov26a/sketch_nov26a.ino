#include <SPI.h>
#include <MFRC522.h>
#include <SoftwareSerial.h>

#define RST_PIN 9  // Reset pin for the RC522 module
#define SS_PIN 10  // Slave Select pin for the RC522 module
#define RX_PIN 3   // 软件串口接收引脚
#define TX_PIN 2  // 软件串口发送引脚

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance
SoftwareSerial softSerial(RX_PIN, TX_PIN); // 创建软件串口实例

// 用于存储动态生成的密码
byte encryptedPassword[16];

// 卡片目标数据块（第2扇区的第1块，即块号8）
const byte targetBlock = 8;

// 初始化串口接收到的数据
String command = "";

void setup() {
  Serial.begin(9600);         // 初始化系统串口通信
  softSerial.begin(115200);     // 初始化软件串口通信，用于发送动态密码和 OK 指令
  SPI.begin();                // 初始化 SPI 总线
  mfrc522.PCD_Init();         // 初始化 RC522 模块
  Serial.println("RFID 读写系统已启动...");
}

void loop() {
  // 检查是否有串口数据
  if (softSerial.available()) {
    command = softSerial.readStringUntil('\n');  // 读取一行指令
    command.trim();                          // 去掉多余的空格和换行符
    processCommand(command);                 // 处理指令
  }
}

// 处理指令
void processCommand(String cmd) {
  if (cmd.startsWith("r+")) {  // 处理入住指令
    String roomNumber = cmd.substring(2);  // 获取房间号
    if (roomNumber.length() == 4 && isDigits(roomNumber)) {  // 确保房间号长度为 4 且全为数字
      writeEncryptedPasswordToCard(roomNumber, true);
    } else {
      Serial.println("房间号格式错误，请输入 4 位数字的房间号！");
    }
  } else if (cmd == "t") {  // 处理退房指令
    readAndClearKeyFromCard();  // 读取并清除密钥
  } else {
    Serial.println("未知指令，请发送有效的指令（例如：r+房间号 或 t）");
  }
}

// 辅助函数：检查字符串是否为数字
bool isDigits(String str) {
  for (char c : str) {
    if (!isdigit(c)) return false;
  }
  return true;
}

// 写入加密密码到卡片
// 写入加密密码到卡片
void writeEncryptedPasswordToCard(String roomNumber, bool isCheckIn) {
  if (mfrc522.PICC_IsNewCardPresent()) {
    if (mfrc522.PICC_Select(&mfrc522.uid) == MFRC522::STATUS_OK) {
      Serial.println("检测到卡片！");
    }
  }

  // 验证密钥
  MFRC522::MIFARE_Key key;
  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;
  MFRC522::StatusCode status = mfrc522.PCD_Authenticate(
      MFRC522::PICC_CMD_MF_AUTH_KEY_A, targetBlock, &key, &(mfrc522.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.print("认证失败: ");
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  // 检查目标块是否为空
  byte buffer[18];
  byte size = sizeof(buffer);
  status = mfrc522.MIFARE_Read(targetBlock, buffer, &size);
  if (status != MFRC522::STATUS_OK) {
    Serial.print("读取失败: ");
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  bool isEmpty = true;
  for (byte i = 0; i < 16; i++) {
    if (buffer[i] != 0x00) {
      isEmpty = false;
      break;
    }
  }

  if (!isEmpty && isCheckIn) {
    Serial.println("卡片未清除，开始清除数据块...");
    // 清除目标数据块（将其内容置为全零）
    for (byte i = 0; i < 16; i++) {
      buffer[i] = 0x00;
    }
    status = mfrc522.MIFARE_Write(targetBlock, buffer, 16);
    if (status != MFRC522::STATUS_OK) {
      Serial.print("清除数据块失败:");
      Serial.println(mfrc522.GetStatusCodeName(status));
      return;
    } else {
      Serial.println("数据块已成功清除！");
    }
  }

  // 生成动态密码，前12位随机，后4位为房间号
  String dynamicPassword = generateDynamicPassword() + roomNumber;

  // 将动态密码写入卡片
  dynamicPassword.getBytes(encryptedPassword, 17);  // 转换为字节数组
  status = mfrc522.MIFARE_Write(targetBlock, encryptedPassword, 16);
  if (status != MFRC522::STATUS_OK) {
    Serial.print("写入失败:");
    Serial.println(mfrc522.GetStatusCodeName(status));
  } else {
    Serial.println("入住成功！");
    softSerial.println("OK:" + dynamicPassword+"\r\n");  // 发送动态密码到软件串口
    Serial.println("入住成功！OK:" + dynamicPassword);
  }

  // 停止卡片通信
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
}


// 动态密码生成函数（生成随机12位密码，仅包含数字和英文字母）
String generateDynamicPassword() {
  String password = "";
  for (int i = 0; i < 12; i++) {
    int randomType = random(0, 3); // 随机选择生成字符的类型：0 - 数字, 1 - 大写字母, 2 - 小写字母
    char randomChar;
    if (randomType == 0) {
      randomChar = char(random(48, 58)); // 数字字符 '0'-'9' (ASCII 48-57)
    } else if (randomType == 1) {
      randomChar = char(random(65, 91)); // 大写字母 'A'-'Z' (ASCII 65-90)
    } else {
      randomChar = char(random(97, 123)); // 小写字母 'a'-'z' (ASCII 97-122)
    }
    password += randomChar;
  }
  return password;
}

// 读取并清除卡片中的密钥
// 读取并清除卡片中的密钥
void readAndClearKeyFromCard() {
  if (mfrc522.PICC_IsNewCardPresent()) {
    if (mfrc522.PICC_Select(&mfrc522.uid) == MFRC522::STATUS_OK) {
      Serial.println("检测到卡片!");
    }
  }

  // 验证密钥
  MFRC522::MIFARE_Key key;
  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;
  MFRC522::StatusCode status = mfrc522.PCD_Authenticate(
      MFRC522::PICC_CMD_MF_AUTH_KEY_A, targetBlock, &key, &(mfrc522.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.print("认证失败: ");
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  // 读取卡片中的密钥
  byte buffer[18];
  byte size = sizeof(buffer);
  status = mfrc522.MIFARE_Read(targetBlock, buffer, &size);
  if (status != MFRC522::STATUS_OK) {
    Serial.print("读取失败: ");
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  // 解析存储的动态密码
  String storedPassword = "";
  for (byte i = 0; i < 16; i++) {
    storedPassword += char(buffer[i]);
  }

  Serial.println("读取到的动态密码: " + storedPassword);

  // 提取房间号（动态密码的最后 4 位）
  if (storedPassword.length() >= 16) {
    String roomNumber = storedPassword.substring(12, 16); // 提取密码的最后 4 位
    Serial.println("房间号解析成功: " + roomNumber);

    // 通过软件串口发送房间号
    softSerial.println("roomid:" + roomNumber);
  } else {
    Serial.println("动态密码长度不足，无法解析房间号！");
  }

  // 清除密钥
  for (byte i = 0; i < 16; i++) {
    buffer[i] = 0x00;  // 将目标块清零
  }
  status = mfrc522.MIFARE_Write(targetBlock, buffer, 16);
  if (status != MFRC522::STATUS_OK) {
    Serial.print("清除失败: ");
    Serial.println(mfrc522.GetStatusCodeName(status));
  } else {
    Serial.println("退房成功！");
  }

  // 停止卡片通信
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
}