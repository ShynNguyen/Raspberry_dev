/******************************************************************************
 *
 * www.payitforward.edu.vn
 *
 ******************************************************************************/

/******************************************************************************
 *
 * C7 TRAINING
 *
 ******************************************************************************/

/******************************************************************************
 *
 *  Module         : TEMPERATURE SENSOR
 *  Description    : This file describes API functions that support for
 *    				temperature sensor on MSP430G2553
 *
 *  Tool           : CCS 5.1
 *  Chip           : MSP430G2553
 *  History        : 04-11-2012
 *  Version        : 1.1
 *
 *  Author         :
 *  Notes          : To apply these functions, you must include the header file lcd.h and
 *                   source file lcd.c to your project.
 *
 *
******************************************************************************/

 /****************************************************************************
 * IMPORT
******************************************************************************/
#include <msp430g2553.h>
#include "LCD.h"

 /****************************************************************************
 * DECLARATIONS
******************************************************************************/
unsigned char temp;

/*****************************************************************************
* 						SUBROUTINES
******************************************************************************/

//*****************************************************************************
// Initialization for ADC10 module
//*****************************************************************************
void ADC10_Init(void)
{
	ADC10CTL0 = SREF_1 + ADC10SHT_3 + ADC10ON + ADC10IE + REFON;
	/*
	 * Vr+ = Vref+
	 * ADC sample and hold time = 64 ADC clocks: When using the temperature
	   sensor, the sample period must be greater than 30 µs
	 * Turn on ADC10
	 * Enable ADC10 Interrupt
	 * Turn on reference generator
	 */
	ADC10CTL1 = INCH_10 + ADC10DIV_1 + ADC10SSEL_3 ;
	/*
	 * Select Input chanel: Temperature Sensor
	 * ADC10DF = 0: The 10-bit conversion results are right justified
	 * ADC10 Clock divider: 4
	 * ADC10 clock source select: SMCLK
	 */
}

/*****************************************************************************
* 						MAIN PROGRAM
******************************************************************************/
void main(void)
{
	WDTCTL = WDTPW + WDTHOLD;	//Stop Watchdog Timer
	ADC10_Init();				//Initialize ADC10
	lcd_init (1); // init LCD
	//lcd_backlight(1); // turn on LCD backlight
	P2SEL = 0;					//Turn off external crystal
	P2SEL2 = 0;
	lcd_clear();				//Clear LCD
	while (1)
	{
		ADC10CTL0 |= ENC + ADC10SC;			//Enable ADC10, Start sample - conversion
		_bis_SR_register(LPM0_bits + GIE);	//Enter LPM0, wait for sample-conversion finish
		lcd_clear();
		lcd_gotoxy(2,0);
		lcd_puts("Temperature:");
		lcd_gotoxy(7,1);
		lcd_putc((temp / 10) + 48);
		lcd_putc((temp % 10) + 48);
		_delay_cycles(500000);

	}
}

/*****************************************************************************
* 						INTERRUPT PROGRAM
******************************************************************************/
#pragma vector = ADC10_VECTOR
__interrupt void ADC10_Interrupt(void)
{
	temp=((ADC10MEM - 673) * 423) / 1024;	//Calculate temperature
	/*
	 * VTEMP=0.00355(TEMPC)+0.986
	 * Vref = 1.5V
	 */
	_bic_SR_register_on_exit(LPM0_bits);	//Exit LPM0
}
/*****************************************************************************
* 						END
******************************************************************************/