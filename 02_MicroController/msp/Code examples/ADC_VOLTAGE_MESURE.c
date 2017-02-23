/******************************************************************************
 *
 * WWW.PAYITFORWARD.EDU.VN
 *
 ******************************************************************************/

/******************************************************************************
 *
 * C7 TRAINING
 *
 ******************************************************************************/

/******************************************************************************
 *
 *  Module         : VOLTAGE MESURE
 *  Description    : This file describes API functions that support for
 *    				 ADC module on MSP430G2553
 *
 *  Tool           : CCS 5.1
 *  Chip           : MSP430G2553
 *  History        : 04-11-2012
 *  Version        : 1.1
 *
 *  Author         : NHH
 *  Notes          : To apply these functions, you must include the header file lcd.h and
 *                   source file lcd.c to your project.
 *
 *
******************************************************************************/

/*****************************************************************************
 * Pin Description
******************************************************************************
*
*		                     MSP430G2x53
*                         -----------------
*                     /|\|              XIN|-
*                      | |                 |
*                      --|RST          XOUT|-
*                        |                 |
* Analog signal input >--|P1.1/A1          |--> ||
*                        |                 |-->	|| Out to LCD
*                        |				   |--> || Described in LCD.c
*                        |				   |--> ||
*                        |				   |
*
******************************************************************************/

/*****************************************************************************
 * IMPORT
******************************************************************************/
#include <msp430g2553.h>
#include "LCD.h"

/*****************************************************************************
 * DECLARATIONS
******************************************************************************/

#define Vref 3.3	//Define Vcc voltage when select Vref = VCC

unsigned long adc_result, volt;

/*****************************************************************************
* 						SUBROUTINES
******************************************************************************/

//*****************************************************************************
// Initialization for ADC10 module
//*****************************************************************************
void ADC10_Init(void)
{
	ADC10CTL0 = SREF_0 + ADC10SHT_1 + ADC10ON + ADC10IE;
	/*
	 * Vref = VCC
	 * ADC sample and hold time = 8 ADC clocks
	 * Turn on ADC10
	 * Enable ADC10 Interrupt
	 */
	ADC10CTL1 = INCH_1 + ADC10DIV_1 + ADC10SSEL_3;
	/*
	 * Select Input chanel 1
	 * ADC10DF = 0: The 10-bit conversion results are right justified
	 * ADC10 Clock divider: 2
	 * ADC10 clock source select: SMCLK
	 */
	ADC10AE0 |= BIT1;	//Enable analog input on A1 chanel
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
		ADC10CTL0 |= ENC + ADC10SC;	//Enable ADC10, Start sample - conversion
		_bis_SR_register(LPM0_bits + GIE);	//Enter LPM0, wait for sample-conversion finish
		lcd_clear();
		lcd_puts("Result: ");
		volt = (adc_result * Vref * 100) / 1024;	//Calculate result (= 100 * Voltage)
		//Display result
		lcd_putc((volt / 100) + 48);				//ASCII code (of a number) = number + 48
		lcd_puts(".");
		lcd_putc((volt / 10) % 10 + 48);
		lcd_putc((volt % 10) + 48);
		lcd_puts("V");
		_delay_cycles(500000);
	}
}

/*****************************************************************************
* 						INTERRUPT PROGRAM
******************************************************************************/
#pragma vector = ADC10_VECTOR
__interrupt void ADC10_Interrupt(void)
{
	adc_result = ADC10MEM;					//Save Result
	_bic_SR_register_on_exit(LPM0_bits);	//Exit LPM0
}
/*****************************************************************************
* 						END OF MAIN.C
******************************************************************************/
