#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9  // Reset pin for the RC522 module
#define SS_PIN 10  // Slave Select pin for the RC522 module

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

// 固定的加密密钥（16 字节）
const byte encryptionKey[16] = {0xFC, 0x66, 0x91, 0xED, 0xAA, 0x8D, 0x4A, 0x36, 0x99, 0x77, 0x1A, 0xCC, 0x00, 0x00, 0x00, 0x00};

// 用于存储生成的加密密码
byte encryptedPassword[16];

// 卡片目标数据块（第2扇区的第1块，即块号8）
const byte targetBlock = 8;

// 初始化串口接收到的数据
String command = "";

void setup() {
  Serial.begin(9600);  // 初始化串口通信
  SPI.begin();         // 初始化 SPI 总线
  mfrc522.PCD_Init();  // 初始化 RC522 模块
  Serial.println("RFID 读写系统已启动...");
}

void loop() {
  // 检查是否有串口数据
  if (Serial.available()) {
    command = Serial.readStringUntil('\n');  // 读取一行指令
    command.trim();                          // 去掉多余的空格和换行符
    processCommand(command);                 // 处理指令
  }
}
void clearUID() {
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    mfrc522.uid.uidByte[i] = 0;  // 将所有 UID 字节清零
  }
  mfrc522.uid.size = 0;  // 清除 UID 长度
  mfrc522.uid.sak = 0;   // 清除选择确认字节 (SAK)
  //Serial.println("卡片 UID 已清除！");
}
// 处理指令
void processCommand(String cmd) {
  if (cmd.startsWith("r+")) {  // 处理入住指令
    String roomNumber = cmd.substring(2);  // 获取房间号
    if (roomNumber.length() == 4 && isDigits(roomNumber)) {  // 确保房间号长度为 4 且全为数字
      //Serial.println("正在进行入住操作...");
      writeEncryptedPasswordToCard(roomNumber, true);
    } else {
      //Serial.println("房间号格式错误，请输入 4 位数字的房间号！");
    }
  } else if (cmd == "t") {  // 处理退房指令
    //Serial.println("正在进行退房操作...");
    readAndClearKeyFromCard();  // 读取并清除密钥
  } else {
    //Serial.println("未知指令，请发送有效的指令（例如：r+房间号 或 t）");
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
void writeEncryptedPasswordToCard(String roomNumber, bool isCheckIn) {
  if (mfrc522.PICC_IsNewCardPresent()) {
    if (mfrc522.PICC_Select(&mfrc522.uid) == MFRC522::STATUS_OK) {
      //Serial.println("检测到卡片！");
    }
  }

  // 验证密钥
  MFRC522::MIFARE_Key key;
  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;
  MFRC522::StatusCode status = mfrc522.PCD_Authenticate(
      MFRC522::PICC_CMD_MF_AUTH_KEY_A, targetBlock, &key, &(mfrc522.uid));
  if (status != MFRC522::STATUS_OK) {
    //Serial.print("认证失败: ");
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  // 检查目标块是否为空
  byte buffer[18];
  byte size = sizeof(buffer);
  status = mfrc522.MIFARE_Read(targetBlock, buffer, &size);
  if (status != MFRC522::STATUS_OK) {
    //Serial.print("读取失败: ");
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
    Serial.println("卡片未清除，请先退房!");
    return;
  }

  // 生成加密密码
  byte roomBytes[4];
  for (byte i = 0; i < 4; i++) {
    roomBytes[i] = roomNumber[i];
  }

  for (byte i = 0; i < 16; i++) {
    if (i < 12) {
      encryptedPassword[i] = encryptionKey[i];
    } else {
      encryptedPassword[i] = isCheckIn ? (roomBytes[i - 12] ^ encryptionKey[i]) : 0x00;
    }
  }

 /* Serial.print("password:");
  for (byte i = 0; i < 16; i++) {
    Serial.print(encryptedPassword[i], HEX);
    Serial.print(" ");
  }
  Serial.println();
*/
  // 写入加密密码到卡片
  status = mfrc522.MIFARE_Write(targetBlock, encryptedPassword, 16);
  if (status != MFRC522::STATUS_OK) {
    Serial.print("写入失败:");
    Serial.println(mfrc522.GetStatusCodeName(status));
  } else {
    Serial.println("OK!");
  }

  // 停止卡片通信
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();

  // 清除 UID
  //clearUID();
}

// 读取并清除卡片中的密钥
void readAndClearKeyFromCard() {
  if (mfrc522.PICC_IsNewCardPresent()) {
    if (mfrc522.PICC_Select(&mfrc522.uid) == MFRC522::STATUS_OK) {
      //Serial.println("检测到卡片!");
    }
  }

  // 验证密钥
  MFRC522::MIFARE_Key key;
  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;
  MFRC522::StatusCode status = mfrc522.PCD_Authenticate(
      MFRC522::PICC_CMD_MF_AUTH_KEY_A, targetBlock, &key, &(mfrc522.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.print("ERRORmy!");
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  // 读取卡片中的密钥
  byte buffer[18];
  byte size = sizeof(buffer);
  status = mfrc522.MIFARE_Read(targetBlock, buffer, &size);
  if (status != MFRC522::STATUS_OK) {
    Serial.print("ERROR!");
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  // 解析房间号
  String roomNumber = "";
  for (byte i = 12; i < 16; i++) {
    roomNumber += char(buffer[i] ^ encryptionKey[i]);
  }
  Serial.print("roomid:");
  Serial.println(roomNumber);

  // 通过串口发送房间号
  sendRoomNumber(roomNumber);

  // 清除密钥
  for (byte i = 0; i < 16; i++) {
    buffer[i] = 0x00;  // 将目标块清零
  }
  status = mfrc522.MIFARE_Write(targetBlock, buffer, 16);
  if (status != MFRC522::STATUS_OK) {
    //Serial.print("ERROR!");
    Serial.println(mfrc522.GetStatusCodeName(status));
  } else {
    Serial.println("OK!");
  }

  // 停止卡片通信
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();

  // 清除 UID
  //clearUID();
}

// 通过串口发送房间号
void sendRoomNumber(String roomNumber) {
  Serial.print("roomid:");
  Serial.println(roomNumber);
}