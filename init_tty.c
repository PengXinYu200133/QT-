#include <rfid.h>








/* 设置窗口参数:9600速率 */
void init_tty()
{   
	fd = open(DEV_PATH, O_RDWR | O_NOCTTY | O_NONBLOCK);
	if (fd < 0)
	{
		fprintf(stderr, "Open Gec210_ttySAC1 fail!\n");
		
	} 





	//声明设置串口的结构体
	struct termios termios_new;
	//先清空该结构体
	bzero( &termios_new, sizeof(termios_new));
	//	cfmakeraw()设置终端属性，就是设置termios结构中的各个参数。
	cfmakeraw(&termios_new);
	//设置波特率
	//termios_new.c_cflag=(B9600);
	cfsetispeed(&termios_new, B9600);
	cfsetospeed(&termios_new, B9600);
	//CLOCAL和CREAD分别用于本地连接和接受使能，因此，首先要通过位掩码的方式激活这两个选项。    
	termios_new.c_cflag |= CLOCAL | CREAD;
	//通过掩码设置数据位为8位
	termios_new.c_cflag &= ~CSIZE;
	termios_new.c_cflag |= CS8; 
	//设置无奇偶校验
	termios_new.c_cflag &= ~PARENB;
	//一位停止位
	termios_new.c_cflag &= ~CSTOPB;
	tcflush(fd,TCIFLUSH);
	// 可设置接收字符和等待时间，无特殊要求可以将其设置为0
	termios_new.c_cc[VTIME] = 10;
	termios_new.c_cc[VMIN] = 1;
	// 用于清空输入/输出缓冲区
	tcflush (fd, TCIFLUSH);
	//完成配置后，可以使用以下函数激活串口设置
	if(tcsetattr(fd,TCSANOW,&termios_new) )
		printf("Setting the serial1 failed!\n");

}


/*计算校验和*/
unsigned char CalBCC(unsigned char *buf, int n)
{
	int i;
	unsigned char bcc=0;
	for(i = 0; i < n; i++)
	{
		bcc ^= *(buf+i);
	}
	return (~bcc);
}

//请求
int PiccRequest(int fd)
{
	unsigned char WBuf[128], RBuf[128];
	int  ret, i;
	fd_set rdfd;
	static struct timeval timeout;

	memset(WBuf, 0, 128);
	memset(RBuf,0,128);
	WBuf[0] = 0x07;	//帧长= 7 Byte
	WBuf[1] = 0x02;	//包号= 0 , 命令类型= 0x02
	WBuf[2] = 'A';	//命令= 'A'
	WBuf[3] = 0x01;	//信息长度= 1
	WBuf[4] = 0x52;	//请求模式:  ALL=0x52
	WBuf[5] = CalBCC(WBuf, WBuf[0]-2);		//校验和
	WBuf[6] = 0x03; 	//结束标志

        timeout.tv_sec = 300;
        timeout.tv_usec = 0;
	FD_ZERO(&rdfd);
	FD_SET(fd,&rdfd);

	write(fd, WBuf, 7);
	ret = select(fd + 1,&rdfd, NULL,NULL,&timeout); //  I/O多路复用--阻塞、非阻塞，
	
 	printf("3 PiccRequest......................\n");
	switch(ret)
	{
		case -1:
			perror("PiccRequest select error\n");
			break;
		case  0:
			printf("PiccRequest timed out.\n");
			break;
		default:
			ret = read(fd, RBuf, 8);
			if (ret < 0)
			{
				printf("PiccRequest ret = %d, %d\n", ret, errno);
				break;
			}
			if (RBuf[2] == 0x00)	 	//应答帧状态部分为0 则请求成功  返回卡的类型
			{
			        DataBfr[0] = RBuf[4];
			        DataBfr[1] = RBuf[5];
			        FD_CLR(fd,&rdfd);
			        printf("PiccRequest success\n");
				return 0;
			}
			break;
	}
	FD_CLR(fd,&rdfd);
	return 1;
}


/*防碰撞，获取范围内最大ID*/
int PiccAnticoll(int fd)
{
	unsigned char WBuf[128], RBuf[128];
	int ret, i;
	fd_set rdfd;
	struct timeval timeout;
	unsigned int ID;

#if 0
	memset(WBuf, 0, 128);
	memset(RBuf,0,128);
	WBuf[0] = 0x0C;	//帧长= 8 Byte
	WBuf[1] = 0xC2;	//包号= 0 , 命令类型= 0x02
	WBuf[2] = 'B';	//命令= 'B'
	WBuf[3] = 0x06;	//信息长度= 2
	WBuf[4] = 0x93;	//防碰撞0x93 --一级防碰撞
	WBuf[5] = 0x0A;	//位计数0
	WBuf[6] = 0xE2;
	WBuf[7] = 0xB5;
	WBuf[8] = 0x5D;
	WBuf[9] = 0xBB;
	WBuf[10] = CalBCC(WBuf, WBuf[0]-2);		//校验和
	WBuf[11] = 0x03; 	//结束标志
#endif

#if 1
	memset(WBuf, 0, 128);
	memset(RBuf,0,128);
	WBuf[0] = 0x08;	//帧长= 8 Byte
	WBuf[1] = 0x02;	//包号= 0 , 命令类型= 0x02
	WBuf[2] = 'B';	//命令= 'B'
	WBuf[3] = 0x02;	//信息长度= 2
	WBuf[4] = 0x93;	//防碰撞0x93 --一级防碰撞
	WBuf[5] = 0x00;	//位计数0
	WBuf[6] = CalBCC(WBuf, WBuf[0]-2);		//校验和
	WBuf[7] = 0x03; 	//结束标志
#endif 

	timeout.tv_sec = 300;
	timeout.tv_usec = 0;
	FD_ZERO(&rdfd);
	FD_SET(fd,&rdfd);
	write(fd, WBuf, 8);

	ret = select(fd + 1,&rdfd, NULL,NULL,&timeout);
	switch(ret)
	{
		case -1:
			perror("PiccAnticoll select error\n");
			break;
		case  0:
			perror("PiccAnticoll Timeout:");
			break;
		default:
			ret = read(fd, RBuf, 10);
			if (ret < 0)
			{
				printf("PiccAnticoll ret = %d, %d\n", ret, errno);
				break;
			}
			if (RBuf[2] == 0x00) //应答帧状态部分为0 则获取ID 成功
			{
				ID = (RBuf[7]<<24) | (RBuf[6]<<16) | (RBuf[5]<<8) | RBuf[4];
				
				memcpy(cardid,&RBuf[4],4);
				printf("PiccAnticoll The card ID is %x\n",ID);
				crad_id=ID;
				return 0;
			}
	}
	return -1;
}


//选择
int PiccSelect(int fd)
{
	unsigned char WBuf[128], RBuf[128];
	int  ret, i;
	fd_set rdfd;
	static struct timeval timeout;

	memset(WBuf, 0, 128);
	memset(RBuf,0,128);
	WBuf[0] = 0x0B;	//帧长= 7 Byte
	WBuf[1] = 0x02;	//包号= 0 , 命令类型= 0x02
	WBuf[2] = 'C';	//命令= 'C
	WBuf[3] = 0x05;	//信息长度= 5
	WBuf[4] = 0x93;	//请求模式:  ALL=0x52
        memcpy(&WBuf[5],cardid,4);
	WBuf[9] = CalBCC(WBuf, WBuf[0]-2);		//校验和
	WBuf[10] = 0x03; 	//结束标志

	timeout.tv_sec = 300;
	timeout.tv_usec = 0;
	FD_ZERO(&rdfd);
	FD_SET(fd,&rdfd);
	
	write(fd, WBuf, WBuf[0]);
	ret = select(fd + 1,&rdfd, NULL,NULL,&timeout);
	switch(ret)
	{
		case -1:
			perror("PiccSelect error\n");
			break;
		case  0:
			printf("PiccSelect timed out.\n");
			break;
		default:
			ret = read(fd, RBuf, 7);
			if (ret < 0)
			{
				printf("PiccSelect  ret = %d, %d\n", ret, errno);
				break;
			}
			if (RBuf[2] == 0x00)	 	//应答帧状态部分为0 则请求成功
			{
			        printf("PiccSelect success\n");
				return 0;
			}
			break;
	}
	return -1;
}

//挂起
int PiccHalt(int fd)
{
	unsigned char WBuf[128], RBuf[128];
	int  ret, i;
	fd_set rdfd;
	static struct timeval timeout;

	memset(WBuf, 0, 128);
	memset(RBuf,0,128);
	WBuf[0] = 0x06;	//帧长= 6 Byte
	WBuf[1] = 0x02;	//包号= 0 , 命令类型= 0x02
	WBuf[2] = 'D';	//命令= 'D
	WBuf[3] = 0x00;	//信息长度= 0
	WBuf[4] = CalBCC(WBuf, WBuf[0]-2);		//校验和
	WBuf[5] = 0x03; 	//结束标志

        timeout.tv_sec = 300;
        timeout.tv_usec = 0;
	FD_ZERO(&rdfd);
	FD_SET(fd,&rdfd);
	
	write(fd, WBuf, WBuf[0]);
	ret = select(fd + 1,&rdfd, NULL,NULL,&timeout);
	switch(ret)
	{
		case -1:
			perror("PiccHalt error\n");
			break;
		case  0:
			printf("PiccHalt timed out.\n");
			break;
		default:
			ret = read(fd, RBuf, 7);
			if (ret < 0)
			{
				printf("PiccHalt  ret = %d, %d\n", ret, errno);
				break;
			}
			if (RBuf[2] == 0x00)	 	//应答帧状态部分为0 则请求成功
			{
			        printf("PiccHalt success\n");
				return 0;
			}
			break;
	}
	return -1;
}

//证实
int PiccAuthKey(int fd,int sector,unsigned char KeyAB)
{
	unsigned char WBuf[128], RBuf[128];
	int  ret, i;
	fd_set rdfd;
	static struct timeval timeout;

	memset(WBuf, 0, 128);
	memset(RBuf,0,128);
	WBuf[0] = 0x12;	//帧长= 17 Byte
	WBuf[1] = 0x02;	//包号= 0 , 命令类型 = 0x02
	WBuf[2] = 'F';	//命令= 'F'
	WBuf[3] = 12;	//信息长度= 0x0c
	WBuf[4] = KeyAB;
	memcpy(&WBuf[5],cardid,4);
	memcpy(&WBuf[9],KEYA_BUF,6);
	WBuf[15]=sector;   //读写哪个区
	WBuf[16] = CalBCC(WBuf, WBuf[0]-2);		//校验和
	WBuf[17] = 0x03; 	//结束标志

	timeout.tv_sec = 300;
	timeout.tv_usec = 0;
	FD_ZERO(&rdfd);
	FD_SET(fd,&rdfd);

	write(fd, WBuf, WBuf[0]);
	ret = select(fd + 1,&rdfd, NULL,NULL,&timeout);
	switch(ret)
	{
		case -1:
			perror("PiccAuthKey error\n");
			break;
		case  0:
			printf("PiccAuthKey timed out.\n");
			break;
		default:
			ret = read(fd, RBuf, 7);
			if (ret < 0)
			{
				printf("PiccAuthKey  ret = %d, %d\n", ret, errno);
				break;
			}
			if (RBuf[2] == 0x00)	 	//应答帧状态部分为0 则请求成功
			{
			        printf("PiccAuthKey success\n");
				return 0;
			}
			break;
	}
	return -1;
}

