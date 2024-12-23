#include "rfid.h"

int PiccRead(int fd,unsigned char sector)
{
	unsigned char WBuf[128], RBuf[128];
	int  ret, i ;
	fd_set rdfd;
	static struct timeval timeout;

	memset(WBuf, 0, 128);
	memset(RBuf,0,128);
	WBuf[0] = 0x07;	//帧长= 7 Byte
	WBuf[1] = 0x02;	//包号= 0 , 命令类型= 0x02
	WBuf[2] = 'G';	//命令= 'g
	WBuf[3] = 0x01;	//信息长度= 1
	WBuf[4] = sector;	//读哪个扇区
	WBuf[5] = CalBCC(WBuf, WBuf[0]-2);		//校验和
	WBuf[6] = 0x03; 	//结束标志

        timeout.tv_sec = 300;
        timeout.tv_usec = 0;
	FD_ZERO(&rdfd);
	FD_SET(fd,&rdfd);

	write(fd, WBuf, WBuf[0]);
	ret = select(fd + 1,&rdfd, NULL,NULL,&timeout);
	switch(ret)
	{
		case -1:
			perror("PiccRead error\n");
			break;
		case  0:
			printf("PiccRead timed out.\n");
			break;
		default:
			ret = read(fd, RBuf, 23);
			if (ret < 0)
			{
				printf("PiccRead  ret = %d, %d\n", ret, errno);
				break;
			}
			if (RBuf[2] == 0x00)	 	//应答帧状态部分为0 则请求成功
			{
			        usleep(10*1000);
			        read(fd,&RBuf[ret],6);
			        memcpy(DataReadBuf,&RBuf[4],16); //读取到该扇区的数据
			        // for(int i=0;i<16;i++)
			        // {
			        //     printf("PiccRead RBuf[%d]=>%x\n",i,DataReadBuf[i]);
			        // }
				return 0;
			}
			break;
	}
	return -1;
}



int PiccWrite(int fd,unsigned char sector)
{
	unsigned char WBuf[128], RBuf[128];
	int  ret, i;
	fd_set rdfd;
	static struct timeval timeout;

	memset(WBuf, 0, 128);
	memset(RBuf,0,128);
	WBuf[0] = 23;	//帧长= 23 Byte
	WBuf[1] = 0x02;	//包号= 0 , 命令类型= 0x02
	WBuf[2] = 'H';	//命令= 'H
	WBuf[3] = 0X11;	//信息长度= 17
	WBuf[4] = sector;   //写哪个扇区
    memcpy(&WBuf[5],DataWriteBuf,16);
	WBuf[21] = CalBCC(WBuf, WBuf[0]-2);		//校验和
	WBuf[22] = 0x03; 	//结束标志

        timeout.tv_sec = 300;
        timeout.tv_usec = 0;
	FD_ZERO(&rdfd);
	FD_SET(fd,&rdfd);
        
	write(fd, WBuf, 23);
	ret = select(fd + 1,&rdfd, NULL,NULL,&timeout);
	switch(ret)
	{
		case -1:
			perror("PiccWrite error\n");
			break;
		case  0:
			printf("PiccWrite timed out.\n");
			break;
		default:
			ret = read(fd, RBuf, 7);
			if (ret < 0)
			{
				printf("PiccWrite  ret = %d, %d\n", ret, errno);
				break;
			}
			if (RBuf[2] == 0x00)	 	//应答帧状态部分为0 则请求成功
			{       printf("------写入完成！请拿开卡！------\n");
			        printf("PiccWrite card success\n");
				return 0;
			}
			break;
	}
	return -1;
}