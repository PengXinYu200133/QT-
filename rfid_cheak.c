#include "rfid.h"


//#include "font.h"
//unsigned char KEYA_BUF[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
//unsigned char KEYB_BUF[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

int hour[4];
int minute[4];
int day[4];
unsigned char money = 0;
int add_car1_time = 0;
int add_car2_time = 0;
int wr_flag = 0;
unsigned char sector = 1;

void rfid_flow()
{

	printf("Start..............\n");
	
	
	/*请求天线范围的卡*/
	if (PiccRequest(fd)) //成功  ---》0
	{
		sleep(2);
		printf("1 The request failed!\n");
		// continue;
	}
	usleep(30 * 1000);
	/*进行防碰撞，获取天线范围内最大的ID*/
	if (PiccAnticoll(fd))
	{
		printf("2 RFID PiccAnticoll failed\n");
		// continue;
	}

	usleep(30 * 1000);

	if (PiccSelect(fd))
	{
		printf("3 PiccSelect failed\n");
		// continue;
	}

	usleep(30 * 1000);

	if (PiccAuthKey(fd, sector, KEYA))
	{
		printf("4 PiccAuthKey KEYA failed now try KEYB\n");

		/*请求天线范围的卡*/
		if (PiccRequest(fd))
		{
			printf("5 The request failed!\n");
			// continue;
		}
		/*进行防碰撞，获取天线范围内最大的ID*/
		if (PiccAnticoll(fd))
		{
			printf("6 RFID PiccAnticoll failed\n");
			// continue;
		}
		if (PiccSelect(fd))
		{
			printf("7 PiccSelect failed\n");
			// continue;
		}
		if (PiccAuthKey(fd, sector, KEYB))
			printf("8PiccAuthKey failed\n");
		// continue;
	}
	printf("流程完成！\n");
	usleep(300 * 1000);
	
}

void rfid_read(int cc)
{
	if (PiccRead(fd, sector))
	{
		printf("==PiccRead failed\n");
		// continue;
	}

	/* 获取卡内信息  卡号 + 入住时长 */
	car_id = DataReadBuf[15];
	car_day = DataReadBuf[14];
	DataReadBuf[14] = '\0';
	DataReadBuf[15] = '\0';
	//         把字符串转换成整形
	card_time = atoi(DataReadBuf);
	//          转换时间格式
	time_buf = ctime(&card_time);
	if (DataReadBuf[0] == 0)
	{
		printf("未找到卡！\n");
	}
	else
	{
		printf("read OK! car_id:%d  car_day:%d \n", car_id, car_day);
		// printf(" 卡内时间 : %s\n", time_buf);
		//   for (int i = 0; i < 16; i++)
		//   {
		//      printf("1DataReadBuf[%d]=>%x\n", i, DataReadBuf[i]);
		//   }

		if (cc == 1)
		{
			if (add_car1_time % 2 == 0 && car_id == 250)
			{
				card_star = card_time;
				day[0] = buf_int(time_buf, 8, 9);
				hour[0] = buf_int(time_buf, 11, 12);
				minute[0] = buf_int(time_buf, 14, 15);

				printf("car 1 time star : %s\n", ctime(&card_star));
			}
			if (add_car1_time % 2 == 1 && car_id == 250)
			{
				card_end = card_time;
				day[1] = buf_int(time_buf, 8, 9);
				hour[1] = buf_int(time_buf, 11, 12);
				minute[1] = buf_int(time_buf, 14, 15);
				printf("car 1 time end : %s\n", ctime(&card_end));

				time_d(day[1], day[0], hour[1], hour[0], minute[1], minute[0]);
			}
			if (add_car2_time % 2 == 0 && car_id == 222)
			{
				card_star = card_time;
				day[2] = buf_int(time_buf, 8, 9);
				hour[2] = buf_int(time_buf, 11, 12);
				minute[2] = buf_int(time_buf, 14, 15);

				printf("car 2 time star : %s\n", ctime(&card_star));
			}
			if (add_car2_time % 2 == 1 && car_id == 222)
			{
				card_end = card_time;
				day[3] = buf_int(time_buf, 8, 9);
				hour[3] = buf_int(time_buf, 11, 12);
				minute[3] = buf_int(time_buf, 14, 15);

				printf("car 2 time end : %s\n", ctime(&card_end));
				time_d(day[3], day[2], hour[3], hour[2], minute[3], minute[2]);
			}

			if (car_id == 250)
			{
				add_car1_time++;
			}
			if (car_id == 222)
			{
				add_car2_time++;
			}
		}
	}
}

void rfid_write()
{
	time_t ti;
	time(&ti);
	sprintf(DataWriteBuf, "%d", ti);
	printf("ti:%d DataWriteBuf:%s\n", ti, DataWriteBuf);

	DataWriteBuf[14] = DataWriteBuf[14] - money;
	printf("余额：%d", DataWriteBuf[14]);

	time_buf = ctime(&ti);
	printf("系统时间: %s\n", time_buf);

	if (PiccWrite(fd, sector))
	{
		printf("PiccWrite failed\n");
		// continue;
	}

	memset(DataReadBuf, 0, 16);

	memset(cardid, 0, 4);

	usleep(200 * 1000);
	money = 0;
	// DataWriteBuf[14]=0;
}

/*
本函数用于操作RFID射频识别卡
	参数说明：
		room_id:    需要操作的房间号
		room_day:   修改房间入住天数
		mod:        操作模式， 1 表示需要写入内容 其他值不执行写入操作
*/
int rfid_ctl(int car_id, int car_day, int mod)
{

	int ret, i;

	if (1 == mod)
	{

		//待写入的数据
		DataWriteBuf[0] = '\0';
		DataWriteBuf[1] = '\0';
		DataWriteBuf[2] = '\0';
		DataWriteBuf[3] = '\0';
		DataWriteBuf[4] = '\0';
		DataWriteBuf[5] = '\0';
		DataWriteBuf[6] = '\0';
		DataWriteBuf[7] = '\0';
		DataWriteBuf[8] = '\0';
		DataWriteBuf[9] = '\0';
		DataWriteBuf[10] = '\0';
		DataWriteBuf[11] = '\0';
		DataWriteBuf[12] = '\0';
		DataWriteBuf[13] = '\0';
		DataWriteBuf[14] = car_day;
		DataWriteBuf[15] = car_id;
	}

	time_t ti;
	time(&ti);
	sprintf(DataWriteBuf, "%d", ti);
	printf("ti:%d DataWriteBuf:%s\n", ti, DataWriteBuf);

	time_buf = ctime(&ti);
	printf("time: %s\n", time_buf);

	while (1)
	{

		i = 2;

		while (i--)
		{

			if (PiccRead(fd, sector))
			{
				printf("==PiccRead failed\n");
				continue;
			}

			/* 获取卡内信息  卡号 + 入住时长 */
			car_id = DataReadBuf[15];
			car_day = DataReadBuf[14];
			DataReadBuf[14] = '\0';
			DataReadBuf[15] = '\0';
			//         把字符串转换成整形
			card_time = atoi(DataReadBuf);
			//          转换时间格式
			time_buf = ctime(&card_time);
			printf("car_id:%d \n", car_id);

			if (add_car1_time % 2 == 0 && car_id == 250)
			{
				card_star = card_time;
				day[0] = buf_int(time_buf, 8, 9);
				hour[0] = buf_int(time_buf, 11, 12);
				minute[0] = buf_int(time_buf, 14, 15);
				printf("car 1 time star : %s\n", ctime(&card_star));
			}
			if (add_car1_time % 2 == 1 && car_id == 250)
			{
				card_end = card_time;
				day[1] = buf_int(time_buf, 8, 9);
				hour[1] = buf_int(time_buf, 11, 12);
				minute[1] = buf_int(time_buf, 14, 15);
				printf("car 1 time end : %s\n", ctime(&card_end));
				time_d(day[1], day[0], hour[1], hour[0], minute[1], minute[0]);
			}

			if (add_car2_time % 2 == 0 && car_id == 222)
			{
				card_star = card_time;
				day[2] = buf_int(time_buf, 8, 9);
				hour[2] = buf_int(time_buf, 11, 12);
				minute[2] = buf_int(time_buf, 14, 15);
				printf("car 2 time star : %s\n", ctime(&card_star));
			}
			if (add_car2_time % 2 == 1 && car_id == 222)
			{
				card_end = card_time;
				day[3] = buf_int(time_buf, 8, 9);
				hour[3] = buf_int(time_buf, 11, 12);
				minute[3] = buf_int(time_buf, 14, 15);
				printf("car 2 time end : %s\n", ctime(&card_end));
				time_d(day[3], day[2], hour[3], hour[2], minute[3], minute[2]);
			}

			if (1 == mod)
			{

				if (PiccWrite(fd, sector))
				{
					printf("PiccWrite failed\n");
					// continue;
				}
				if (car_id == 250)
				{
					add_car1_time++;
				}
				if (car_id == 222)
				{
					add_car2_time++;
				}

				memset(DataReadBuf, 0, 16);
				memset(cardid, 0, 4);

				usleep(200 * 1000);
			}

			// for(i=0;i<16;i++)
			// {
			// 	printf("1DataReadBuf[%d]=>%x\n",i,DataReadBuf[i]);
			// }

			memset(DataReadBuf, 0, 16);

			// wr_flag = 1;

			sleep(1);

			if (PiccRead(fd, sector + 1))
			{
				printf("==PiccRead failed\n");
				continue;
			}
			printf("2DataReadBuf= %x\n", DataReadBuf);

			memset(DataReadBuf, 0, 16);
			memset(cardid, 0, 4);
			usleep(200 * 1000);

			if (car_id != 0)
			{
				printf("quit rfid_ctl..\n");
				close(fd);
				return 0;
			}
		}

		memset(DataReadBuf, 0, 16);
		memset(cardid, 0, 4);
		printf("------写入完成！请拿开卡！------\n");
		sleep(1);
	}
	close(fd);
	return 0;
}

//函数功能：针对时间字符串char转int
//参数说明：数组i位，数组j位
//返回值  ：十进制数
int buf_int(char *p, int i, int j)
{
	char a[] = "";
	a[0] = p[i];
	a[1] = p[j];
	int d = atoi(a);
	return d;
}

void time_d(int d2, int d1, int h2, int h1, int m2, int m1)
{

	int i_d = d2 - d1;
	int ih = h2 - h1;
	int im = m2 - m1;
	if (im < 0)
	{
		im = 60 + im;
		ih--;
	}
	printf("时间差是%d天%d小时%d分。\n", i_d, ih, im);
	int cr=i_d * 10 + ih * 5 + im * 1;
	printf("共消费%d元\n",cr );
	money = i_d * 10 + ih * 5 + im * 1;
}
