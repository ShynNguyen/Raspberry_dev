/****************************************************************
 *
 * www.payitforward.edu.vn
 *
 ****************************************************************/
/****************************************************************
 *
 * PIF C7 COURSE
 *
 ****************************************************************/

/****************************************************************
 *
 *	Module		: TimerA0.c
 *	Description	:
 *  Tool		: CCS 5.1
 *	Chip		: MSP430G2553
 * 	History		: 09/28/2012
 *  Version     : 1.0
 *
 *	Author		: Mai Tan Khoa
 *	Notes		:
 *
 *
 ****************************************************************/


 /****************************************************************
 * IMPORT
 ****************************************************************/

#include <msp430g2553.h>


 /****************************************************************
 * EXTERN
 ****************************************************************/

void ConfigClocks();
void FaultRoutine();
void Timera0_init();
void Port_init();

/*****************************************************************
GLOBAL VARIABLE
******************************************************************/

/*none...*/

/*****************************************************************
* ROUTINES
******************************************************************/

/*
				Clock_init
		Config MCU's Clock at 1Mhz
		Using VLO at LFXT1
 */
void Clock_init()
 {
 if (CALBC1_1MHZ ==0xFF || CALDCO_1MHZ == 0xFF)
   FaultRoutine();		                    // If calibration data is erased
 				                            // run FaultRoutine()
  BCSCTL1 = CALBC1_1MHZ; 					// Set range
  DCOCTL = CALDCO_1MHZ;  					// Set DCO step + modulation
  BCSCTL3 |= LFXT1S_2;                      // LFXT1 = VLO
  IFG1 &= ~OFIFG;                           // Clear OSCFault flag
  BCSCTL2 |= SELM_0 ;      					// MCLK = DCO, SMCLK = DCO
 }
void FaultRoutine()
 {
   P1OUT = BIT0;                            // P1.0 on (red LED)
   while(1); 			                    // TRAP
 }
/*
				Timer Init
		Setup timer A0 to work with VLO(12Khz), Continuous Mode and Enable Interrupt Overflow
 */
void Timera0_init()
{
	TACTL = TASSEL_1 + MC_2+TAIE;

}
/*
				Port_init
		Set I/O propriety
 */
void Port_init()
{
	P1DIR |= BIT0 + BIT6;
	P1OUT = 0x40;

}
/*****************************************************************************
Interrupt Service Routine
*****************************************************************************/
#pragma vector=TIMER0_A1_VECTOR
__interrupt void TAIV_Interrupt (void)
{
	switch(TA0IV)
	{
	case 0x0A:
	{
		P1OUT ^= P1OUT;
	}
	}
}
/******************************************************************************
 * MAIN
 *****************************************************************************/

 void main (void)
{
WDTCTL = WDTPW + WDTHOLD;
Clock_init();
Port_init();
Timera0_init();
_BIS_SR(LPM0_bits + GIE);
}

/****************************************************************
 * END OF standard_form.c
 ****************************************************************/

