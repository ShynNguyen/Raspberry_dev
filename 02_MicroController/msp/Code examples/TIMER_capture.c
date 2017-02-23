/*
 * main.c
 *
 *  Created on: May 12, 2013
 *      Author: BloodElf
 */
#include <msp430.h>

int cap_value;
void main(void)
{
	WDTCTL = WDTPW + WDTHOLD;				//Tat watchdogtimer
	TA1CTL = TASSEL_2 + MC_2;				//Chon clocktimer = 1Mhz, Cont.up mode
	TA1CCTL1 |= CM_1+CCIS_0+CAP+CCIE;		// Config CCR1 la capture : kich canh len
											//Channel A, capture mode, enable ngat
	TA1R =0;

	P2SEL |= BIT1;							//Config pin thanh chan capture theo ccr1
	P2SEL2 &=~BIT1;							//Xem datasheet de biet pin nao co kha nang
	P2DIR &=~BIT1;							//capture

	_BIS_SR(LPM0_bits + GIE);				//Low-power mode + enable ngat toan cuc
}
#pragma vector=TIMER1_A1_VECTOR
__interrupt void TA1IV_Interrupt (void)
{
	{
	case TA1IV_TACCR1:
	{
		cap_value = TA1CCR1;				//Lay gia tri capture vo bien cap_value
		TA1R =0;							//Reset bo dem timer
		//CCR1+=31250;
		break;
	}
	case TA1IV_TA1CCR2:
	{
	}
	case TA1IV_TAIFG :
	{
	}
	}

}

