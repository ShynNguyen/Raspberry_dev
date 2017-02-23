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
 *	Module		: standard_form.c
 *	Description	: Blink a Led on P1.0
 *  Tool		: CCS 5.3
 *	Chip		: MSP430G2xxx
 * 	History		: 07/04/2013
 *  Version     : 1.0
 *
 *	Author		: Nguyen Tien Manh, CLB NCKH DDT
 *	Notes		:
 *
 *****************************************************************************/

/******************************************************************************
 * IMPORT
 *****************************************************************************/

#include <msp430.h>

/******************************************************************************
 * EXTERN
 *****************************************************************************/
/*__Khai bao cac ham, bien da ton tai trong file C khac, vi du:
extern void Exit(void); */

/******************************************************************************
 * GLOBAL VARIABLE
 *****************************************************************************/
/*__Khoi tao bien toan cuc */

// This will keep count of how many cycles between LED toggles.
unsigned int i = 0;

/******************************************************************************
 * ROUTINES
 *****************************************************************************/
/*__Cac chuong trinh con viet o day */

/* -- void init_port(void) ---------------------------------------------------
 *
 * Description	: Init P1.0 as output .
 * Parameters	: none
 * Return		: don't care
 */
void init_port(void)
{
	// P1DIR is a register that configures the direction (DIR)
		// of Port1 pins as outputs or inputs.
	// To set a specific pin as output or input, we write a '1'
		// or '0' on the appropriate bit of this register.
	// P1DIR = <PIN7><PIN6><PIN5><PIN4><PIN3><PIN2><PIN1><PIN0>
	// Now, we want to set the direction of Port1, Pin0 (P1.0) as an output.
	// We do that by writing a 1 on the PIN0 bit of the P1DIR register.
	// P1DIR = <PIN7><PIN6><PIN5><PIN4><PIN3><PIN2><PIN1><PIN0>
	// P1DIR = 0000 0001
	// or: P1DIR = 0x01     <-- this is the hexadecimal conversion
	// We use OR operator to set Bit0 as 1, but not change the others.
	// P1DIR |= 0x01; <=> P1DIR = P1DIR | 0x01; ( | means OR)
	// For example: '1010 0100' | '0000 0001' = '1010 0101'
				//  '1010 0101' | '0000 0001' = '1010 0101'
	P1DIR |= 0x01;
}

/******************************************************************************
 * MAIN
 *****************************************************************************/
//__ Chuong trinh chinh

 void main (void)
{
	// Stop watchdog timer.
	// This line of code is needed at the beginning of most MSP430 projects.
	// This line of code turns off the watchdog timer,
		// which can reset the device after a certain period of time.
	WDTCTL = WDTPW + WDTHOLD;
	// Call the subroutine init_port() to Set P1.0 as output.
	init_port();

	while (1) //__ Vong lap vo tap
	{
	// Toggle P1.0 using exclusive-OR operation (^=)
	// P1OUT is another register which holds the voltage status at Port1 pins.
		// '1' specifies that the voltage is at HIGH level (3.3 V)
		// '0' specifies that the voltage is at LOW level (0 V)
	// Since our LED is tied to P1.0, we will toggle the 0 bit of P1OUT
	// We use XOR operator to toggle Bit0, but not change the others.
	// P1OUT ^= 0x01; <=> P1OUT = P1OUT ^ 0x01; ( ^ means XOR)
	// For example: '1010 0100' ^ '0000 0001' = '1010 0101'
				//  '1010 0101' ^ '0000 0001' = '1010 0100'
	P1OUT ^= 0x01;

	// Delay between LED toggles.
	// This for-loop will run until the condition is met.
	// In this case, it will loop until the variable i increments to 20000.
    for(i=0; i< 20000; i++);
	
	// You can also use: _delay_cycles(x); for a quick delay
		// x is the number of machine cycle that the MCU waits
	}
}

/******************************************************************************
 * END OF standard_form.c
 *****************************************************************************/