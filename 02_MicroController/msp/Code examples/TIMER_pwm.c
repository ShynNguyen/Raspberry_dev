/*
 * main.c
 *
 *  Created on: May 5, 2013
 *      Author: BloodElf
 */
#include <msp430g2553.h>



void main(void)
{
	WDTCTL = WDTPW + WDTHOLD;	//Tat watchdog timer


	TA0CTL = TASSEL_2 +MC_1;	//Timer Clock = SMCLK = 1Mhz, Mode Up
	TA0CCTL1 = OUTMOD_3;		// CCR1 : xuat xung theo mode 3

	P1DIR |= BIT2+BIT6;
	P1SEL |= BIT2+BIT6;			//Port 1.2 và 1.6 cung co the xung theo CCR1(TA0.1)
	P1SEL2 &=~(BIT2+BIT6);		// Xem data sheet de biet pin nao co chuc nang nay

	TA0CCR0 = 100;				//Chon CCR0 lam chu ky và CCR1 la nguong de thay
	TA0CCR1 = 10;					//doi gia tri OUT theo mode


	_BIS_SR(LPM0_bits + GIE);	//Low-power mode
}


