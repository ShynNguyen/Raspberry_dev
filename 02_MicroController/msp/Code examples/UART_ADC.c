/******************************************************************************
 *
 * www.payitforward.edu.vn
 *
 *****************************************************************************/

/******************************************************************************
 *
 * C7 TRAINING
 *
 *****************************************************************************/

/******************************************************************************
 *
 *	Module		: ADC_UART.main.c
 *	Description	: Send the voltage read from ADC through UART
 *  Tool		: CCS 5.1
 *	Chip		: MSP430G2xxx
 * 	History		: 18/11/2012
 *  Version     : 1
 *
 *	Author		: Nguyen Tien Manh, CLB NCKH DDT
 *	Notes		: To apply these functions, you must include driver
 *	              uart to your project
 *
 *****************************************************************************/


/******************************************************************************
 * IMPORT
 *****************************************************************************/

#include <msp430.h>
#include "Basic_config.h"
#include "UART.h"

/*****************************************************************************
 * DECLARATIONS
******************************************************************************/
#define Vref 3.3	//Define Vcc voltage when select Vref = VCC

/******************************************************************************
 * EXTERN
 *****************************************************************************/

/******************************************************************************
 * GLOBAL VARIABLE
 *****************************************************************************/
unsigned long adc_result, volt;

/******************************************************************************
 * ROUTINES
 *****************************************************************************/
void timer_init (void)
{
	TACTL = TASSEL_1 + MC_2;                  // ACLK (12kHz), continuous mode
	CCR0 = 12000;                             // cycle 12000*1/12000 = 1s
	CCTL0 = CCIE;                             // CCR0 interrupt enabled
}
void ADC10_Init(void)
{
	ADC10CTL0 = SREF_0 + ADC10SHT_1 + ADC10ON + ADC10IE;
	/*
	 * Vref = VCC
	 * ADC sample and hold time = 8 ADC clocks
	 * Turn on ADC10
	 * Enable ADC10 Interrupt
	 */
	ADC10CTL1 = INCH_3 + ADC10DIV_1 + ADC10SSEL_3;
	/*
	 * Select Input chanel 3
	 * ADC10DF = 0: The 10-bit conversion results are right justified
	 * ADC10 Clock divider: 2
	 * ADC10 clock source select: SMCLK
	 */
	ADC10AE0 |= BIT3;	//Enable analog input on A3 chanel
}

/******************************************************************************
 * MAIN
 *****************************************************************************/

void main()
{
	Config_stop_WDT();
	Config_Clocks();
	timer_init();
	ADC10_Init ();
	uart_init ();
	ADC10CTL0 |= ENC + ADC10SC;	//Enable ADC10, Start sample - conversion
	delay_ms (200);
	_BIS_SR(LPM0_bits + GIE);                 // Enter LPM0 with interrupt
	while (1);
}

/*****************************************************************************
* 						INTERRUPT PROGRAM
******************************************************************************/
// Timer A0 interrupt service routine
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void)
{
	uart_puts("\n\rVoltage: ");
	volt = (adc_result * Vref * 100) / 1024;	//Calculate result (= 100 * Voltage)
	//Display result
	uart_put_num (volt, 2, 0);
	uart_puts("V");
	ADC10CTL0 |= ENC + ADC10SC;	//Enable ADC10, Start sample - conversion
	CCR0 += 12000;                            // Add Offset to CCR0
}
// ADC10 interrupt service routine
#pragma vector = ADC10_VECTOR
__interrupt void ADC10_Interrupt(void)
{
	adc_result = ADC10MEM;					//Save Result
}

/******************************************************************************
 * END OF ADC_UART.main.c
 *****************************************************************************/
