#include <reg52.h>
#include <intrins.h>
void delayms(unsigned int xms);

sbit beep = P3^0;

unsigned char code table[] = {
0x03, 0x9f, 0x25, 0x0d, 0x99,
0x49, 0x41, 0x1f, 0x01, 0x09
};

void main()
{
	int i = 0;
	int j = 0;
	unsigned char a = 0xee;
	while (1) {
		P1 = a;	
		
		for (i = 0; i<50; i++) {
			P2 = 0x01;
			P0 = table[j / 1000];
			beep = ~beep;
			delayms(5);
	
			P2 = 0x02;
			P0 = table[(j / 100)%10];
			beep = ~beep;
			delayms(5);
	
			P2 = 0x04;
			P0 = table[(j / 10)%10];
			beep = ~beep;
			delayms(5);
	
			P2 = 0x08;
			P0 = table[j%10];
			beep = ~beep;
			delayms(5);
		}
		a = _crol_(a,1);
		j++;
		if (j == 9999)
			j = 0;			
	}
}

void delayms(unsigned int xms)
{
	unsigned int i, j;
	for (i = xms; i > 0; i--)
		for (j = 110; j > 0; j--);
}