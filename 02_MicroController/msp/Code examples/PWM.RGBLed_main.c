/******************************************************************************
 *
 * www.payitforward.edu.vn
 *
 *****************************************************************************/

/******************************************************************************
 *
 * PIF C8 COURSE
 *
 *****************************************************************************/

/******************************************************************************
 *
 *	Module		: PWM.RGBLed_main.c
 *	Description	: LCD Example for C8
 *  Tool		: CCS 5.1
 *	Chip		: MSP430G2xxx
 * 	History		: 06-07-2013
 *  Version     : 1.0
 *
 *	Author		: Nguyen Tien Manh, CLB NCKH DDT
 *	Notes		: Ouput PWM to RGB Led (P1.2-P2.1-P2.4)
 *				  Anode of RGB Led connects to 3.3V
 *
 *****************************************************************************/

/******************************************************************************
 * IMPORT
 *****************************************************************************/

#include <msp430.h>
#include "Basic_config.h"
#include "LCD.h"

/******************************************************************************
 * MAIN
 *****************************************************************************/
void main()
{
	// Ma mau RGB cua mau hong la: 238-18-137
	unsigned char red = 238; //(0 <= red <= 255)
	unsigned char green = 18; //(0 <= green <= 255)
	unsigned char blue = 137; //(0 <= blue <= 255)

	Config_stop_WDT(); // stop WDT, see description in Basic_config.c
	Config_Clocks();

	///// Config Timer 0 for red Led
	TA0CTL = TASSEL_2 + MC_1;	// Timer Clock = SMCLK = 1Mhz, Mode Up

	// P1.2 chon chuc nang TA0.1: Red Led
	TA0CCTL1 = OUTMOD_3;		// CCR1 : xuat xung theo mode 3
	P1DIR |= BIT2;
	P1SEL |= BIT2;
	P1SEL2 &=~BIT2;

	TA0CCR0 = 255;				// CCR0 chon chu ky PWM 255
	TA0CCR1 = red;				// dat xung red/255 cho Led do

	///// Config Timer 1 for green and blue Led
	TA1CTL = TASSEL_2 + MC_1;	//Timer Clock = SMCLK = 1Mhz, Mode Up

	// P2.1 chon chuc nang TA1.1: Grren Led
	TA1CCTL1 = OUTMOD_3;		// CCR1 : xuat xung theo mode 3
	P2DIR |= BIT1;
	P2SEL |= BIT1;
	P2SEL2 &=~BIT1;

	// P2.4 chon chuc nang TA1.2: Blue Led
	TA1CCTL2 = OUTMOD_3;		// CCR2 : xuat xung theo mode 3
	P2DIR |= BIT4;
	P2SEL |= BIT4;
	P2SEL2 &=~BIT4;

	TA1CCR0 = 255;				// CCR0 chon chu ky PWM 255
	TA1CCR1 = green;			// dat xung grren/255 cho Led luc
	TA1CCR2 = blue;				// dat xung red/255 cho Led lam

	_BIS_SR(LPM0_bits + GIE);	// Low-power mode 0
								// (che do ngu, chi ngoai vi hoat dong)
}
/******************************************************************************
 * END OF PWM.RGBLed_main.c
 *****************************************************************************/