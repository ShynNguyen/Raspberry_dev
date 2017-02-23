/* --COPYRIGHT--,BSD_EX
 * Copyright (c) 2012, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *******************************************************************************
 * 
 *                       MSP430 CODE EXAMPLE DISCLAIMER
 *
 * MSP430 code examples are self-contained low-level programs that typically
 * demonstrate a single peripheral function or device feature in a highly
 * concise manner. For this the code may rely on the device's power-on default
 * register values and settings such as the clock configuration and care must
 * be taken when combining code from several examples to avoid potential side
 * effects. Also see www.ti.com/grace for a GUI- and www.ti.com/msp430ware
 * for an API functional library-approach to peripheral configuration.
 *
 * --/COPYRIGHT--*/
var jsonInfo = [
	{
		"MCU"    : "MSP430",
		"Device" : "MSP430G2x13",
		"Filter" : "MSP430G2\\d13"
	}
];

var jsonObjC = [
	{"Source Preview" : "msp430g2x13_ca_01.c",                        "Description" : "Comp_A, Output Reference Voltages on P1.1"},
	{"Source Preview" : "msp430g2x13_ca_02.c",                        "Description" : "Comp_A, Detect Threshold, Set P1.0 if P1.1 > 0.25*Vcc"},
	{"Source Preview" : "msp430g2x13_ca_03.c",                        "Description" : "Comp_A, Simple 2.2V Low Battery Detect"},
	{"Source Preview" : "msp430g2xx3_1.c",                            "Description" : "Software Toggle P1.0"},
	{"Source Preview" : "msp430g2xx3_1_vlo.c",                        "Description" : "Software Toggle P1.0, MCLK = VLO/8"},
	{"Source Preview" : "msp430g2xx3_clks.c",                         "Description" : "Basic Clock, Output Buffered SMCLK, ACLK and MCLK/10"},
	{"Source Preview" : "msp430g2xx3_dco_calib.c",                    "Description" : "Basic Clock with preloaded DCO calibration constants "},
	{"Source Preview" : "msp430g2xx3_dco_flashcal.c",                 "Description" : "DCO Calibration Constants Programmer"},
	{"Source Preview" : "msp430g2xx3_flashwrite_01.c",                "Description" : "Flash In-System Programming, Copy SegC to SegD"},
	{"Source Preview" : "msp430g2xx3_LFxtal_nmi.c",                   "Description" : "LFXT1 Oscillator Fault Detection"},
	{"Source Preview" : "msp430g2xx3_lpm3.c",                         "Description" : "Basic Clock, LPM3 Using WDT ISR, 32kHz ACLK"},
	{"Source Preview" : "msp430g2xx3_lpm3_vlo.c",                     "Description" : "Basic Clock, LPM3 Using WDT ISR, VLO ACLK"},
	{"Source Preview" : "msp430g2xx3_nmi.c",                          "Description" : "Basic Clock, Configure RST/NMI as NMI"},
	{"Source Preview" : "msp430g2xx3_P1_01.c",                        "Description" : "Software Poll P1.4, Set P1.0 if P1.4 = 1"},
	{"Source Preview" : "msp430g2xx3_P1_02.c",                        "Description" : "Software Port Interrupt Service on P1.4 from LPM4"},
	{"Source Preview" : "msp430g2xx3_P1_03.c",                        "Description" : "Poll P1 With Software with Internal Pull-up"},
	{"Source Preview" : "msp430g2xx3_P1_04.c",                        "Description" : "P1 Interrupt from LPM4 with Internal Pull-up"},
	{"Source Preview" : "msp430g2xx3_pinosc_01.c",                    "Description" : "Capacitive Touch, Pin Oscillator Method, 1 button"},
	{"Source Preview" : "msp430g2xx3_pinosc_02.c",                    "Description" : "Capacitive Touch, Pin Oscillator Method, 4-buttons"},
	{"Source Preview" : "msp430g2xx3_pinosc_03.c",                    "Description" : "Capacitive Touch, Pin Oscillator Method, 4-buttons, ACLK for CCR"},
	{"Source Preview" : "msp430g2xx3_pinosc_04.c",                    "Description" : "Capacitive Touch, Pin Oscillator Method, 8 buttons, UART"},
	{"Source Preview" : "msp430g2xx3_ta_01.c",                        "Description" : "Timer_A, Toggle P1.0, CCR0 Cont. Mode ISR, DCO SMCLK"},
	{"Source Preview" : "msp430g2xx3_ta_02.c",                        "Description" : "Timer_A, Toggle P1.0, CCR0 Up Mode ISR, DCO SMCLK"},
	{"Source Preview" : "msp430g2xx3_ta_03.c",                        "Description" : "Timer_A, Toggle P1.0, Overflow ISR, DCO SMCLK"},
	{"Source Preview" : "msp430g2xx3_ta_04.c",                        "Description" : "Timer_A, Toggle P1.0, Overflow ISR, 32kHz ACLK"},
	{"Source Preview" : "msp430g2xx3_ta_05.c",                        "Description" : "Timer_A, Toggle P1.0, CCR0 Up Mode ISR, 32kHz ACLK"},
	{"Source Preview" : "msp430g2xx3_ta_06.c",                        "Description" : "Timer_A, Toggle P1.0, CCR1 Cont. Mode ISR, DCO SMCLK"},
	{"Source Preview" : "msp430g2xx3_ta_07.c",                        "Description" : "Timer_A, Toggle P1.0-2, Cont. Mode ISR, DCO SMCLK"},
	{"Source Preview" : "msp430g2xx3_ta_08.c",                        "Description" : "Timer_A, Toggle P1.0-2, Cont. Mode ISR, 32kHz ACLK"},
	{"Source Preview" : "msp430g2xx3_ta_10.c",                        "Description" : "Timer_A, Toggle P1.1/TA0, Up Mode, DCO SMCLK"},
	{"Source Preview" : "msp430g2xx3_ta_11.c",                        "Description" : "Timer_A, Toggle P1.1/TA0, Up Mode, 32kHz ACLK"},
	{"Source Preview" : "msp430g2xx3_ta_13.c",                        "Description" : "Timer_A, Toggle P1.1/TA0, Up/Down Mode, DCO SMCLK"},
	{"Source Preview" : "msp430g2xx3_ta_14.c",                        "Description" : "Timer_A, Toggle P1.1/TA0, Up/Down Mode, 32kHz ACLK"},
	{"Source Preview" : "msp430g2xx3_ta_16.c",                        "Description" : "Timer_A, PWM TA1-2, Up Mode, DCO SMCLK"},
	{"Source Preview" : "msp430g2xx3_ta_17.c",                        "Description" : "Timer_A, PWM TA1, Up Mode, 32kHz ACLK"},
	{"Source Preview" : "msp430g2xx3_ta_19.c",                        "Description" : "Timer_A, PWM TA1, Up/Down Mode, DCO SMCLK"},
	{"Source Preview" : "msp430g2xx3_ta_20.c",                        "Description" : "Timer_A, PWM TA1, Up/Down Mode, 32kHz ACLK"},
	{"Source Preview" : "msp430g2xx3_ta_21.c",                        "Description" : "Timer_A, Normal Timer Mode Input Period and Duty Cycle Measurement"},
	{"Source Preview" : "msp430g2xx3_ta_uart2400.c",                  "Description" : "Timer_A, Ultra-Low Pwr UART 2400 Echo, 32kHz ACLK"},
	{"Source Preview" : "msp430g2xx3_ta_uart9600.c",                  "Description" : "Timer_A, Ultra-Low Pwr Full-duplex UART 9600, 32kHz ACLK"},
	{"Source Preview" : "msp430g2xx3_uscia0_irda_01.c",               "Description" : "USCI_A0 IrDA External Loopback Test, 8MHz SMCLK"},
	{"Source Preview" : "msp430g2xx3_uscia0_irda_02.c",               "Description" : "USCI_A0 IrDA Monitor, 8MHz SMCLK"},
	{"Source Preview" : "msp430g2xx3_uscia0_irda_03.c",               "Description" : "USCI_A0 IrDA Physical Layer Comm, 8MHz SMCLK"},
	{"Source Preview" : "msp430g2xx3_uscia0_spi_09.c",                "Description" : "USCI_A0, SPI 3-Wire Master Incremented Data"},
	{"Source Preview" : "msp430g2xx3_uscia0_spi_10.c",                "Description" : "USCI_A0, SPI 3-Wire Slave Data Echo"},
	{"Source Preview" : "msp430g2xx3_uscia0_uart_01_115k.c",          "Description" : "USCI_A0, 115200 UART Echo ISR, DCO SMCLK"},
	{"Source Preview" : "msp430g2xx3_uscia0_uart_01_115k_lpm.c",      "Description" : "USCI_A0, 115200 UART Echo ISR, DCO SMCLK, LPM4"},
	{"Source Preview" : "msp430g2xx3_uscia0_uart_01_19200.c",         "Description" : "USCI_A0, 19200 UART Echo ISR, DCO SMCLK"},
	{"Source Preview" : "msp430g2xx3_uscia0_uart_01_9600.c",          "Description" : "USCI_A0, 9600 UART Echo ISR, DCO SMCLK"},
	{"Source Preview" : "msp430g2xx3_uscia0_uart_05_9600.c",          "Description" : "USCI_A0, Ultra-Low Pwr UART 9600 Echo ISR, 32kHz ACLK"},
	{"Source Preview" : "msp430g2xx3_uscia0_uart_06_9600.c",          "Description" : "USCI_A0, Ultra-Low Pwr UART 9600 String, 32kHz ACLK"},
	{"Source Preview" : "msp430g2xx3_uscia0_uart_07_9600.c",          "Description" : "USCI_A0, Ultra-Low Pwr UART 9600 RX/TX, 32kHz ACLK"},
	{"Source Preview" : "msp430g2xx3_uscia0_uart_08_9600.c",          "Description" : "USCI_A0, UART 9600 Full-Duplex Transceiver, 32kHz ACLK"},
	{"Source Preview" : "msp430g2xx3_uscib0_i2c_01.c",                "Description" : "USCI_B0 I2C Master to TMP100, Set P1.0 if Temp > 28C"},
	{"Source Preview" : "msp430g2xx3_uscib0_i2c_02.c",                "Description" : "USCI_B0 I2C Master Interface to PCF8574, Read/Write"},
	{"Source Preview" : "msp430g2xx3_uscib0_i2c_03.c",                "Description" : "USCI_B0 I2C Master Interface to DAC8571, Write"},
	{"Source Preview" : "msp430g2xx3_uscib0_i2c_04.c",                "Description" : "USCI_B0 I2C Master RX single bytes from MSP430 Slave"},
	{"Source Preview" : "msp430g2xx3_uscib0_i2c_05.c",                "Description" : "USCI_B0 I2C Slave TX single bytes to MSP430 Master"},
	{"Source Preview" : "msp430g2xx3_uscib0_i2c_06.c",                "Description" : "USCI_B0 I2C Master TX single bytes to MSP430 Slave"},
	{"Source Preview" : "msp430g2xx3_uscib0_i2c_07.c",                "Description" : "USCI_B0 I2C Slave RX single bytes from MSP430 Master"},
	{"Source Preview" : "msp430g2xx3_uscib0_i2c_08.c",                "Description" : "USCI_B0 I2C Master TX multiple bytes to MSP430 Slave"},
	{"Source Preview" : "msp430g2xx3_uscib0_i2c_09.c",                "Description" : "USCI_B0 I2C Slave RX multiple bytes from MSP430 Master"},
	{"Source Preview" : "msp430g2xx3_uscib0_i2c_10.c",                "Description" : "USCI_B0 I2C Master RX multiple bytes from MSP430 Slave"},
	{"Source Preview" : "msp430g2xx3_uscib0_i2c_11.c",                "Description" : "USCI_B0 I2C Slave TX multiple bytes to MSP430 Master"},
	{"Source Preview" : "msp430g2xx3_uscib0_i2c_12.c",                "Description" : "USCI_B0 I2C Master TX/RX multiple bytes from MSP430 Slave with a repeated start in between TX and RX operations."},
	{"Source Preview" : "msp430g2xx3_uscib0_i2c_13.c",                "Description" : "USCI_B0 I2C Slave RX/TX multiple bytes to MSP430 Master"},
	{"Source Preview" : "msp430g2xx3_wdt_01.c",                       "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, DCO SMCLK"},
	{"Source Preview" : "msp430g2xx3_wdt_02.c",                       "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, 32kHz ACLK"},
	{"Source Preview" : "msp430g2xx3_wdt_04.c",                       "Description" : "WDT+ Failsafe Clock, DCO SMCLK"},
	{"Source Preview" : "msp430g2xx3_wdt_05.c",                       "Description" : "Reset on Invalid Address fetch, Toggle P1.0"},
	{"Source Preview" : "msp430g2xx3_wdt_06.c",                       "Description" : "WDT+ Failsafe Clock, 32kHz ACLK"},
	{"Source Preview" : "msp430g2xx3_wdt_07.c",                       "Description" : "WDT+ periodic reset"}
];

