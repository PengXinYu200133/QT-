extern "C" {
#ifndef __RFID_H__
#define __RFID_H__

//头文件添加
#include <stdio.h>
#include <fcntl.h> 
#include <unistd.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/select.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>



//宏定义
#define DEV_PATH   "/dev/ttySAC1"
#define KEYA		0x60
#define KEYB		0x61



//定义全局变量
unsigned char cardid[4];
unsigned char KEYA_BUF[6];
unsigned char KEYB_BUF[6];
unsigned char DataWriteBuf[16];
unsigned char DataReadBuf[16];
unsigned char DataBfr[16];
unsigned int crad_id;
int fd;//串口1标识符
short int room_id ;
char *time_buf ;


//函数声明



void init_tty();
unsigned char CalBCC(unsigned char *buf, int n);
int PiccRequest(int fd);
int PiccAnticoll(int fd);
int PiccSelect(int fd);
int PiccHalt(int fd);
int PiccAuthKey(int fd,int sector,unsigned char KeyAB);
int PiccRead(int fd,unsigned char sector);
int PiccWrite(int fd,unsigned char sector);
void time_d();
int buf_int(char *p, int i, int j);
int rfid_ctl(int room_id ,int room_day , int mod );

void rfid_flow();
void rfid_read(int cc);
void rfid_write();



void c_function1();





time_t card_time ;
time_t card_star ;
time_t card_end ;
time_t time_temp;

int car_id ;
int car_day;

#endif
}

