

#include <msp430g2553.h>
#include "Basic_config.h"
#include "SPI.h"

volatile int i,j,count=0;
volatile char data = 0;
int b[10]={0x40,0xF9,0x24,0x30,0x19,0x12,0x02,0xF8,0x80,0x10};

void main(void)
{
	WDTCTL = WDTPW + WDTHOLD;
	Config_SPI_A();
	P1DIR |= BIT0;
	P2DIR |= BIT0;
	P1OUT |= 0x40;
	IE2 |= UCA0RXIE;                          // Enable USCI0 RX interrupt


	__delay_cycles(7500);
	P1OUT &= ~0x01;
	Send_byte_A(0xAB, 2);
	Send_byte_A(0x00, 2);
	Send_byte_A(0x00, 2);
	Send_byte_A(0x00, 2);
	Send_byte_A(0x00, 2);
	P1OUT |= 0x01;
	__delay_cycles(70);

	__delay_cycles(7500);
	P1OUT &= ~0x01;
	Send_byte_A(0x06, 2);
	//Send_byte_A(0x00, 2);
	P1OUT |= 0x01;
	__delay_cycles(70);

	P1OUT |= 0x01;
	__delay_cycles(70);

	__delay_cycles(7500);
	P1OUT &= ~0x01; //bit 6 select
	Send_byte_A(0x02, 10);
	Send_byte_A(0x0F, 10);
	Send_byte_A(0x0F, 10);
	Send_byte_A(0x09, 10);
	Send_byte_A(0x00, 10);
	Send_byte_A(0x00, 10);
	Send_byte_A(0x00, 10);

	for(i = 0; i < 10; i ++)
	{
			Send_byte_A(b[i], 10);
	}

	P1OUT |= 0x01;
	__delay_cycles(70);

	__delay_cycles(7500);
	P1OUT &= ~0x01;
	Send_byte_A(0x04, 2);

	P1OUT |= 0x01;
	__delay_cycles(70);

	 __bis_SR_register(GIE);       // CPU off, enable interrupts
	while(1)
	{


		__delay_cycles(7500);
		P1OUT &= ~0x01;
		Send_byte_A(0x03, 5);
		Send_byte_A(0x0F, 5);
		Send_byte_A(0x0F, 5);
		Send_byte_A(0x09, 5);
		for(count=0;count<=22;count++)
		{
			Send_byte_A(0x00, 10);
			if(count>=3)
			{
			 // Send_byte_B(b[count - 13],1000);
				delay_ms(1000);
			  P2OUT &= ~0x01;
			  __delay_cycles(7000);
			  P2OUT |= 0x01;
			}
		}


		P1OUT |= 0x01;
		__delay_cycles(7);

	}
}

#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCIA0RX_ISR(void)
{

  while (!(IFG2 & UCA0RXIFG));              // USCI_A0 TX buffer ready?
  data = UCA0RXBUF;


}

