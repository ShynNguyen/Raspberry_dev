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
var jsonObjASM = [
	{"Source Preview" : "msp430g2x13_ca_01.asm",              "Description" : "Comp_A, Output Reference Voltages on P1.1"},
	{"Source Preview" : "msp430g2x13_ca_02.asm",              "Description" : "Comp_A, Detect Threshold, Set P1.0 if P1.1 > 0.25*Vcc"},
	{"Source Preview" : "msp430g2x13_ca_03.asm",              "Description" : "Comp_A, Simple 2.2V Low Battery Detect"},
	{"Source Preview" : "msp430g2x33_adc10_01.asm",           "Description" : "ADC10, Sample A0, Set P1.0 if A0 > 0.5*AVcc"},
	{"Source Preview" : "msp430g2x33_adc10_02.asm",           "Description" : "ADC10, Sample A1, 1.5V Ref, Set P1.0 if A1 > 0.2V"},
	{"Source Preview" : "msp430g2x33_adc10_03.asm",           "Description" : "ADC10, ADC10, Sample A10 Temp, Set P1.0 if Temp ++ ~2C"},
	{"Source Preview" : "msp430g2x33_adc10_04.asm",           "Description" : "ADC10, ADC10, Sample A1, Signed, Set P1.0 if A1 > 0.5*AVcc"},
	{"Source Preview" : "msp430g2x33_adc10_05.asm",           "Description" : "ADC10, ADC10, Sample A11, Lo_Batt, Set P1.0 if AVcc < 2.3V"},
	{"Source Preview" : "msp430g2x33_adc10_06.asm",           "Description" : "ADC10, ADC10, Output Internal Vref on P1.4 & ADCCLK on P1.3"},
	{"Source Preview" : "msp430g2x33_adc10_07.asm",           "Description" : "ADC10, DTC Sample A1 32x, AVcc, Repeat Single, DCO"},
	{"Source Preview" : "msp430g2x33_adc10_08.asm",           "Description" : "ADC10, ADC10, DTC Sample A1 32x, 1.5V, Repeat Single, DCO"},
	{"Source Preview" : "msp430g2x33_adc10_09.asm",           "Description" : "ADC10, ADC10, DTC Sample A10 32x, 1.5V, Repeat Single, DCO"},
	{"Source Preview" : "msp430g2x33_adc10_10.asm",           "Description" : "ADC10, ADC10, DTC Sample A3-01, AVcc, Single Sequence, DCO"},
	{"Source Preview" : "msp430g2x33_adc10_11.asm",           "Description" : "ADC10, ADC10, Sample A1, 1.5V, TA1 Trig, Set P1.0 if > 0.5V"},
	{"Source Preview" : "msp430g2x33_adc10_12.asm",           "Description" : "ADC10, Sample A7, 1.5V, TA1 Trig, Ultra-Low Pwr"},
	{"Source Preview" : "msp430g2x33_adc10_13.asm",           "Description" : "ADC10, DTC Sample A1 32x, AVcc, TA0 Trig, DCO"},
	{"Source Preview" : "msp430g2x33_adc10_14.asm",           "Description" : "ADC10, DTC Sample A1-0 16x, AVcc, Repeat Seq, DCO"},
	{"Source Preview" : "msp430g2x33_adc10_16.asm",           "Description" : "ADC10, ADC10, DTC Sample A0 -> TA1, AVcc, DCO"},
	{"Source Preview" : "msp430g2x33_adc10_temp.asm",         "Description" : "ADC10, Sample A10 Temp and Convert to oC and oF"},
	{"Source Preview" : "msp430g2xx3_1.asm",                  "Description" : "Software Toggle P1.0"},
	{"Source Preview" : "msp430g2xx3_1_vlo.asm",              "Description" : "Software Toggle P1.0, MCLK = VLO/8"},
	{"Source Preview" : "msp430g2xx3_clks.asm",               "Description" : "Basic Clock, Output Buffered SMCLK, ACLK and MCLK/10"},
	{"Source Preview" : "msp430g2xx3_dco_flashcal.asm",       "Description" : "DCO Calibration Constants Programmer"},
	{"Source Preview" : "msp430g2xx3_flashwrite_01.asm",      "Description" : "Flash In-System Programming, Copy SegC to SegD"},
	{"Source Preview" : "msp430g2xx3_LFxtal_nmi.asm",         "Description" : "LFXT1 Oscillator Fault Detection"},
	{"Source Preview" : "msp430g2xx3_lpm3.asm",               "Description" : "Basic Clock, LPM3 Using WDT ISR, 32kHz ACLK"},
	{"Source Preview" : "msp430g2xx3_lpm3_vlo.asm",           "Description" : "Basic Clock, LPM3 Using WDT ISR, VLO ACLK"},
	{"Source Preview" : "msp430g2xx3_nmi.asm",                "Description" : "Basic Clock, Configure RST/NMI as NMI"},
	{"Source Preview" : "msp430g2xx3_P1_01.asm",              "Description" : "Software Poll P1.4, Set P1.0 if P1.4 = 1"},
	{"Source Preview" : "msp430g2xx3_P1_02.asm",              "Description" : "Software Port Interrupt on P1.4 from LPM4"},
	{"Source Preview" : "msp430g2xx3_P1_03.asm",              "Description" : "Poll P1 With Software with Internal Pull-up"},
	{"Source Preview" : "msp430g2xx3_P1_04.asm",              "Description" : "P1 Interrupt from LPM4 with Internal Pull-up"},
	{"Source Preview" : "msp430g2xx3_ta_01.asm",              "Description" : "Timer_A, Toggle P1.0, CCR0 Cont. Mode ISR, DCO SMCLK"},
	{"Source Preview" : "msp430g2xx3_ta_02.asm",              "Description" : "Timer_A, Toggle P1.0, CCR0 Up Mode ISR, DCO SMCLK"},
	{"Source Preview" : "msp430g2xx3_ta_03.asm",              "Description" : "Timer_A, Toggle P1.0, Overflow ISR, DCO SMCLK"},
	{"Source Preview" : "msp430g2xx3_ta_04.asm",              "Description" : "Timer_A, Toggle P1.0, Overflow ISR, 32kHz ACLK"},
	{"Source Preview" : "msp430g2xx3_ta_05.asm",              "Description" : "Timer_A, Toggle P1.0, CCR0 Up Mode ISR, 32kHz ACLK"},
	{"Source Preview" : "msp430g2xx3_ta_06.asm",              "Description" : "Timer_A, Toggle P1.0, CCR1 Cont. Mode ISR, DCO SMCLK"},
	{"Source Preview" : "msp430g2xx3_ta_07.asm",              "Description" : "Timer_A, Toggle P1.0-3, Cont. Mode ISR, DCO SMCLK"},
	{"Source Preview" : "msp430g2xx3_ta_08.asm",              "Description" : "Timer_A, Toggle P1.0-2, Cont. Mode ISR, 32kHz ACLK"},
	{"Source Preview" : "msp430g2xx3_ta_10.asm",              "Description" : "Timer_A, Toggle P1.1/TA0, Up Mode, DCO SMCLK"},
	{"Source Preview" : "msp430g2xx3_ta_11.asm",              "Description" : "Timer_A, Toggle P1.1/TA0, Up Mode, 32kHz ACLK"},
	{"Source Preview" : "msp430g2xx3_ta_13.asm",              "Description" : "Timer_A, Toggle P1.1/TA0, Up/Down Mode, DCO SMCLK"},
	{"Source Preview" : "msp430g2xx3_ta_14.asm",              "Description" : "Timer_A, Toggle P1.1/TA0, Up/Down Mode, 32kHz ACLK"},
	{"Source Preview" : "msp430g2xx3_ta_16.asm",              "Description" : "Timer_A, PWM TA1, Up Mode, DCO SMCLK"},
	{"Source Preview" : "msp430g2xx3_ta_17.asm",              "Description" : "Timer_A, PWM TA1, Up Mode, 32kHz ACLK"},
	{"Source Preview" : "msp430g2xx3_ta_19.asm",              "Description" : "Timer_A, PWM TA1, Up/Down Mode, DCO SMCLK"},
	{"Source Preview" : "msp430g2xx3_ta_20.asm",              "Description" : "Timer_A, PWM TA1-2, Up/Down Mode, 32kHz ACLK"},
	{"Source Preview" : "msp430g2xx3_ta_uart2400.asm",        "Description" : "Timer_A, Ultra-Low Pwr UART 2400 Echo, 32kHz ACLK"},
	{"Source Preview" : "msp430g2xx3_wdt_01.asm",             "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, DCO SMCLK"},
	{"Source Preview" : "msp430g2xx3_wdt_02.asm",             "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, 32kHz ACLK"},
	{"Source Preview" : "msp430g2xx3_wdt_04.asm",             "Description" : "WDT+ Failsafe Clock, DCO SMCLK"},
	{"Source Preview" : "msp430g2xx3_wdt_05.asm",             "Description" : "Reset on Invalid Address fetch, Toggle P1.0"},
	{"Source Preview" : "msp430g2xx3_wdt_06.asm",             "Description" : "WDT+ Failsafe Clock, 32kHz ACLK"}
];

