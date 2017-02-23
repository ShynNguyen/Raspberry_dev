#include <msp430g2553.h>
#include "Basic_config.h"
#include "SPI.h"

int i,j=0;
int b[10]={0x40,0xF9,0x24,0x30,0x19,0x12,0x02,0xF8,0x80,0x10};

void main(void)
{
	WDTCTL = WDTPW + WDTHOLD;
	Config_SPI_A();
	P1DIR |= BIT6;
	

	while(1)
	{
		Send_byte_A(b[i], 1000);

		P1OUT &= ~0x40;
		__delay_cycles(2000);
		P1OUT |= 0x40;

		i++;
		if(i==10)
		{
			i = 0;
		}
	}
}

