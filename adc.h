#ifndef __ADC_H
#define __ADC_H
/******************************************************************************
 *                  ADC PERIPHERAL LIBRARY HEADER FILE
 ******************************************************************************
 * FileName:        		adc.h
 * Dependencies:    	    See include below
 * Processor:       		PIC18
 * Compiler:        		MCC18
 * Company:         		Microchip Technology, Inc.
 *
 * Software License Agreement
 * The software supplied herewith by Microchip Technology Incorporated
 * (the “Company”) for its PICmicro® Microcontroller is intended and
 * supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PICmicro Microcontroller products. The
 * software is owned by the Company and/or its supplier, and is
 * protected under applicable copyright laws. All rights are reserved.
 * Any use in violation of the foregoing restrictions may subject the
 * user to criminal sanctions under applicable laws, as well as to
 * civil liability for the breach of the terms and conditions of this
 * license.
 *
 * THIS SOFTWARE IS PROVIDED IN AN “AS IS” CONDITION. NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *****************************************************************************/

#include "pconfig.h"


/***********************************************************************************
Macro       : ADC_INT_ENABLE()
Overview : Macro enables the ADC interrupt
Parameters   : None
Remarks     : Interrupt is configured as low priority interrupt
***********************************************************************************/
#define ADC_INT_ENABLE()     (PIR1bits.ADIF=0,INTCONbits.PEIE=1,PIE1bits.ADIE=1) 

/***********************************************************************************
Macro       : ADC_INT_DISABLE()
Overview : Macro disables the ADC interrupt
Parameters   : None
Remarks     : None
***********************************************************************************/
#define ADC_INT_DISABLE()    (PIE1bits.ADIE=0)

#if	defined (ADC_V15) || defined (ADC_V15_1)
#define ADCON1H_VALUE                0x00
#define ADCON1L_VALUE                0x00
#define ADCON2H_VALUE                0x00
#define ADCON2L_VALUE                0x00
#define ADCON3H_VALUE                0x00
#define ADCON3L_VALUE                0x00
#define ADCON5H_VALUE                0x00
#define ADCON5L_VALUE                0x00
#define ADCHS0H_VALUE                0x00
#define ADCHS0L_VALUE                0x00
#define ADCSS1H_VALUE                0x00
#define ADCSS1L_VALUE                0x00
#define ADCSS0H_VALUE                0x00
#define ADCSS0L_VALUE                0x00
#endif

#if	defined (ADC_V1) || defined (ADC_V2) || defined (ADC_V3) || defined (ADC_V4) ||\
    defined (ADC_V5) || defined (ADC_V6) || defined (ADC_V8) || defined (ADC_V9) || defined (ADC_V9_1) ||\
	defined (ADC_V10) || defined (ADC_V11) || defined (ADC_V11_1) || defined (ADC_V12)\
	|| defined (ADC_V13) || defined (ADC_V13_1) || defined (ADC_V13_2) ||\
	defined (ADC_V13_3) || defined (ADC_V14) || defined (ADC_V14_1) || defined (ADC_V14_2) || defined (ADC_V14_3) 

#ifndef USE_OR_MASKS
//*************** A/D Conversion Clock Selection *****************************
#define ADC_FOSC_2       0b10001111 			//A/D conversion clock source is Fosc/2
#define ADC_FOSC_4       0b11001111 			//A/D conversion clock source is Fosc/4
#define ADC_FOSC_8       0b10011111 			//A/D conversion clock source is Fosc/8
#define ADC_FOSC_16      0b11011111 			//A/D conversion clock source is Fosc/16
#define ADC_FOSC_32      0b10101111 			//A/D conversion clock source is Fosc/32
#define ADC_FOSC_64      0b11101111 			//A/D conversion clock source is Fosc/64
#define ADC_FOSC_RC      0b11111111 			//A/D conversion clock source is Internal RC OSC

//************** A/D Acquisition Time Selection *******************************
#define ADC_0_TAD        0b11110001				//A/D Acquisition Time is 0 TAD
#define ADC_2_TAD        0b11110011				//A/D Acquisition Time is 2 TAD
#define ADC_4_TAD        0b11110101				//A/D Acquisition Time is 4 TAD
#define ADC_6_TAD        0b11110111				//A/D Acquisition Time is 6 TAD
#define ADC_8_TAD        0b11111001				//A/D Acquisition Time is 8 TAD
#define ADC_12_TAD       0b11111011				//A/D Acquisition Time is 12 TAD
#define ADC_16_TAD       0b11111101				//A/D Acquisition Time is 16 TAD
#define ADC_20_TAD       0b11111111				//A/D Acquisition Time is 20 TAD

//*************** ADC Interrupt Enable/Disable *******************************
#define ADC_INT_ON       0b11111111				//A/D Interrupt Enable
#define ADC_INT_OFF      0b01111111				//A/D Interrupt Disable

#else // USE_OR_MASKS
//*************** A/D Conversion Clock Select *****************************
#define ADC_FOSC_2       0b00000000 			//A/D conversion clock source is Fosc/2
#define ADC_FOSC_4       0b01000000 			//A/D conversion clock source is Fosc/4
#define ADC_FOSC_8       0b00010000 			//A/D conversion clock source is Fosc/8
#define ADC_FOSC_16      0b01010000 			//A/D conversion clock source is Fosc/16
#define ADC_FOSC_32      0b00100000 			//A/D conversion clock source is Fosc/32
#define ADC_FOSC_64      0b01100000 			//A/D conversion clock source is Fosc/64
#define ADC_FOSC_RC      0b01110000 			//A/D conversion clock source is Internal RC OSC
#define ADC_FOSC_MASK	 (~ADC_FOSC_RC)			//Mask A/D conversion clock source bits

//************** A/D Acquisition Time Selection *******************************
#define ADC_0_TAD        0b00000000				//A/D Acquisition Time is 0 TAD
#define ADC_2_TAD        0b00000010				//A/D Acquisition Time is 2 TAD
#define ADC_4_TAD        0b00000100				//A/D Acquisition Time is 4 TAD
#define ADC_6_TAD        0b00000110				//A/D Acquisition Time is 6 TAD
#define ADC_8_TAD        0b00001000				//A/D Acquisition Time is 8 TAD
#define ADC_12_TAD       0b00001010				//A/D Acquisition Time is 12 TAD
#define ADC_16_TAD       0b00001100				//A/D Acquisition Time is 16 TAD
#define ADC_20_TAD       0b00001110				//A/D Acquisition Time is 20 TAD
#define ADC_TAD_MASK	(~ADC_20_TAD)			//Mask A/D Acquisition Time bits

//*************** ADC Interrupt Enable/Disable *******************************
#define ADC_INT_ON       0b10000000				//A/D Interrupt Enable
#define ADC_INT_OFF      0b00000000				//A/D Interrupt Disable
#define ADC_INT_MASK     (~ADC_INT_ON)			//Mask A/D Interrupt
#endif	// USE_OR_MASKS

#endif	// End of versions


#if defined (ADC_V2) || defined (ADC_V3) || defined (ADC_V4) || defined (ADC_V5) ||\
    defined (ADC_V6) || defined (ADC_V8) || defined (ADC_V9) || defined (ADC_V9_1) || defined (ADC_V11)|| defined (ADC_V11_1)||\
	defined (ADC_V12)

#ifndef USE_OR_MASKS
//************** Voltage Reference Configuration ****************************** 
#define ADC_REF_VDD_VREFMINUS   	0b11111110 	// ADC voltage source VREF+ = VDD and VREF- = ext.source at VREF-
#define ADC_REF_VREFPLUS_VREFMINUS  0b11111111 	// ADC voltage source VREF+ = ext.source at VREF+ and VREF- = ext.source at VREF-
#define ADC_REF_VREFPLUS_VSS		0b11111101 	// ADC voltage source VREF+ = ext.source at VREF+ and VREF- = VSS
#define	ADC_REF_VDD_VSS  			0b11111100 	// ADC voltage source VREF+ = VDD and VREF- = VSS
#else // USE_OR_MASKS	
//************** Voltage Reference Configuration ****************************** 
#define ADC_REF_VDD_VREFMINUS   	0b00000010 	// ADC voltage source VREF+ = VDD and VREF- = ext.source at VREF-
#define ADC_REF_VREFPLUS_VREFMINUS  0b00000011 	// ADC voltage source VREF+ = ext.source at VREF+ and VREF- = ext.source at VREF-
#define ADC_REF_VREFPLUS_VSS		0b00000001 	// ADC voltage source VREF+ = ext.source at VREF+ and VREF- = VSS
#define	ADC_REF_VDD_VSS  		    0b00000000 	// ADC voltage source VREF+ = VDD and VREF- = VSS
#define ADC_REF_MASK	            (~ADC_REF_VREFPLUS_VREFMINUS)	//Mask ADC Voltage Source
#endif	// USE_OR_MASKS

#endif	// End of versions


#ifndef	USE_OR_MASKS
//*************** A/D Result Format Select ***********************************
#define ADC_RIGHT_JUST   0b11111111 			// Right justify A/D result
#define ADC_LEFT_JUST    0b01111111 			// Left justify A/D result
#else // USE_OR_MASKS
//*************** A/D Result Format Select ***********************************
#define ADC_RIGHT_JUST   0b10000000 			// Right justify A/D result
#define ADC_LEFT_JUST    0b00000000 			// Left justify A/D result
#define ADC_RESULT_MASK	 (~ADC_RIGHT_JUST)		//Mask ADC Result adjust bit
#endif // USE_OR_MASKS


#if defined (ADC_V1)

#ifndef	USE_OR_MASKS
//***************A/D Port Configuration Control *******************************
#define ADC_8ANA_0REF    0b11110000				// VREF+=VDD,VREF-=VSS: all analog channels   (8 analog channels/0 Voltage Reference)
#define ADC_7ANA_1REF    0b11110001				// AN3=VREF+:  all analog channels except AN3 (7 analog channels/1 Voltage Reference)
#define ADC_5ANA_0REF    0b11110010 			// VREF+=VDD,VREF-=VSS: DIG-AN7,6,5 : ANG-AN4,3,2,1,0  (5 analog channels/0 Voltage Reference)
#define ADC_4ANA_1REF    0b11110011 			// AN3=VREF+:  DIG- AN7,6,5 : ANG- AN4,2,1,0  (4 analog channels/1 Voltage Reference)
#define ADC_3ANA_0REF    0b11110100 			// VREF+=VDD,VREF-=VSS: DIG- AN7,6,5,4,2 : ANG- AN3,1,0   (3 analog channels/0 Voltage Reference)
#define ADC_2ANA_1REF    0b11110101 			// AN3=VREF+:  DIG- AN7,6,5,4,2 : ANG- AN1,0   (2 analog channels/1 Voltage Reference)
#define ADC_0ANA_0REF    0b11110111 			// ALL DIGITAL Channels  (0 analog channels/0 Voltage Reference)
#define ADC_6ANA_2REF    0b11111000 			// AN3=VREF+,AN2=VREF-:  ANG- AN7,6,5,4,1,0  (6 analog channels/2 Voltage Reference)
#define ADC_6ANA_0REF    0b11111001 			// VREF+=VDD,VREF-=VSS:  DIG- AN7,6 : ANG- AN5,4,3,2,1,0  (6 analog channels/0 Voltage Reference)
#define ADC_5ANA_1REF    0b11111010 			// AN3=VREF+,VREF-=VSS:  DIG- AN7,6 : ANG- AN5,4,2,1,0  (5 analog channels/1 Voltage Reference)
#define ADC_4ANA_2REF    0b11111011 			// AN3=VREF+ AN2=VREF-:   DIG- AN7,6 : ANG- AN5,4,1,0 (4 analog channels/2 Voltage Reference)
#define ADC_3ANA_2REF    0b11111100 			// AN3=VREF+ AN2=VREF-:  DIG- AN7,6,5 : ANG- AN4,1,0  (3 analog channels/2 Voltage Reference)
#define ADC_2ANA_2REF    0b11111101 			// AN3=VREF+ AN2=VREF-:   DIG- AN7,6,5,4 : ANG- AN1,0  (2 analog channels/2 Voltage Reference)
#define ADC_1ANA_0REF    0b11111110 			// AN0 is the only analog input  (1 analog channels/0 Voltage Reference)
#define ADC_1ANA_2REF    0b11111111 			// AN3=VREF+ AN2=VREF-:   DIG- AN7,6,5,4,1 : ANG- AN0   (1 analog channels/2 Voltage Reference)
#else // USE_OR_MASKS
//***************A/D Port Configuration Control *******************************
#define ADC_8ANA_0REF    0b00000000				// VREF+=VDD,VREF-=VSS: all analog channels   (8 analog channels/0 Voltage Reference)
#define ADC_7ANA_1REF    0b00000001				// AN3=VREF+:  all analog channels except AN3 (7 analog channels/1 Voltage Reference)
#define ADC_5ANA_0REF    0b00000010 			// VREF+=VDD,VREF-=VSS: DIG-AN7,6,5 : ANG-AN4,3,2,1,0  (5 analog channels/0 Voltage Reference)
#define ADC_4ANA_1REF    0b00000011 			// AN3=VREF+:  DIG- AN7,6,5 : ANG- AN4,2,1,0  (4 analog channels/1 Voltage Reference)
#define ADC_3ANA_0REF    0b00000100 			// VREF+=VDD,VREF-=VSS: DIG- AN7,6,5,4,2 : ANG- AN3,1,0   (3 analog channels/0 Voltage Reference)
#define ADC_2ANA_1REF    0b00000101 			// AN3=VREF+:  DIG- AN7,6,5,4,2 : ANG- AN1,0   (2 analog channels/1 Voltage Reference)
#define ADC_0ANA_0REF    0b00000111 			// ALL DIGITAL Channels  (0 analog channels/0 Voltage Reference)
#define ADC_6ANA_2REF    0b00001000 			// AN3=VREF+,AN2=VREF-:  ANG- AN7,6,5,4,1,0  (6 analog channels/2 Voltage Reference)
#define ADC_6ANA_0REF    0b00001001 			// VREF+=VDD,VREF-=VSS:  DIG- AN7,6 : ANG- AN5,4,3,2,1,0  (6 analog channels/0 Voltage Reference)
#define ADC_5ANA_1REF    0b00001010 			// AN3=VREF+,VREF-=VSS:  DIG- AN7,6 : ANG- AN5,4,2,1,0  (5 analog channels/1 Voltage Reference)
#define ADC_4ANA_2REF    0b00001011 			// AN3=VREF+ AN2=VREF-:   DIG- AN7,6 : ANG- AN5,4,1,0 (4 analog channels/2 Voltage Reference)
#define ADC_3ANA_2REF    0b00001100 			// AN3=VREF+ AN2=VREF-:  DIG- AN7,6,5 : ANG- AN4,1,0  (3 analog channels/2 Voltage Reference)
#define ADC_2ANA_2REF    0b00001101 			// AN3=VREF+ AN2=VREF-:   DIG- AN7,6,5,4 : ANG- AN1,0  (2 analog channels/2 Voltage Reference)
#define ADC_1ANA_0REF    0b00001110 			// AN0 is the only analog input  (1 analog channels/0 Voltage Reference)
#define ADC_1ANA_2REF    0b00001111 			// AN3=VREF+ AN2=VREF-:   DIG- AN7,6,5,4,1 : ANG- AN0   (1 analog channels/2 Voltage Reference)
#define ADC_CONFIG_MASK	 (~ADC_1ANA_2REF)		//Mask ADC port configuration bits
#endif // USE_OR_MASKS

#elif defined (ADC_V2) || defined (ADC_V5) || defined (ADC_V6) || defined (ADC_V12) 

#ifndef USE_OR_MASKS
//***************A/D Port Configuration Control *******************************
#define ADC_0ANA   0b11111111 					// All channels are digital
#define ADC_1ANA   0b11111110 					// analog: AN0 and remaining channels are digital
#define ADC_2ANA   0b11111101 					// analog: AN0->1 and remaining channels are digital
#define ADC_3ANA   0b11111100 					// analog: AN0->2 and remaining channels are digital
#define ADC_4ANA   0b11111011 					// analog: AN0->3 and remaining channels are digital
#define ADC_5ANA   0b11111010 					// analog: AN0->4 and remaining channels are digital
#define ADC_6ANA   0b11111001 					// analog: AN0->5 and remaining channels are digital
#define ADC_7ANA   0b11111000 					// analog: AN0->6 and remaining channels are digital
#define ADC_8ANA   0b11110111 					// analog: AN0->7 and remaining channels are digital
#define ADC_9ANA   0b11110110 					// analog: AN0->8 and remaining channels are digital
#define ADC_10ANA  0b11110101 					// analog: AN0->9 and remaining channels are digital
#define ADC_11ANA  0b11110100 					// analog: AN0->10 and remaining channels are digital
#ifndef ADC_V12
#define ADC_12ANA  0b11110011 					// analog: AN0->11 and remaining channels are digital
#define ADC_13ANA  0b11110010 					// analog: AN0->12 and remaining channels are digital
#define ADC_14ANA  0b11110001 					// analog: AN0->13 and remaining channels are digital
#define ADC_15ANA  0b11110000 					// All channels are analog
#endif
#else // USE_OR_MASKS
//***************A/D Port Configuration Control *******************************
#define ADC_0ANA   0b00001111 					// All channels are digital
#define ADC_1ANA   0b00001110 					// analog: AN0  and remaining channels are digital
#define ADC_2ANA   0b00001101 					// analog: AN0->1 and remaining channels are digital
#define ADC_3ANA   0b00001100 					// analog: AN0->2 and remaining channels are digital
#define ADC_4ANA   0b00001011 					// analog: AN0->3 and remaining channels are digital
#define ADC_5ANA   0b00001010 					// analog: AN0->4 and remaining channels are digital
#define ADC_6ANA   0b00001001 					// analog: AN0->5 and remaining channels are digital
#define ADC_7ANA   0b00001000 					// analog: AN0->6 and remaining channels are digital
#define ADC_8ANA   0b00000111 					// analog: AN0->7 and remaining channels are digital
#define ADC_9ANA   0b00000110 					// analog: AN0->8 and remaining channels are digital
#define ADC_10ANA  0b00000101 					// analog: AN0->9 and remaining channels are digital
#define ADC_11ANA  0b00000100 					// analog: AN0->10 and remaining channels are digital
#ifndef ADC_V12
#define ADC_12ANA  0b00000011 					// analog: AN0->11 and remaining channels are digital
#define ADC_13ANA  0b00000010 					// analog: AN0->12 and remaining channels are digital
#define ADC_14ANA  0b00000001 					// analog: AN0->13 and remaining channels are digital
#define ADC_15ANA  0b00000000 					// All channels are analog
#endif
#define ADC_CONFIG_MASK  (~ADC_0ANA)			//Mask ADC port configuration bits
#endif // USE_OR_MASKS

#elif defined (ADC_V3)

//***************A/D Port Configuration Control *******************************
#define ADC_0ANA   0b11111111 					// All channels are digital
#define ADC_1ANA   0b11111110	 				// analog: AN0  and remaining channels are digital
#define ADC_2ANA   0b11111100 					// analog: AN0->1 and remaining channels are digital
#define ADC_3ANA   0b11111000 					// analog: AN0->2 and remaining channels are digital
#define ADC_4ANA   0b11110000 					// analog: AN0->3  and remaining channels are digital
#define ADC_5ANA   0b11100000 					// analog: AN0->4  and remaining channels are digital
#define ADC_6ANA   0b11000000 					// analog: AN0->5  and remaining channels are digital
#define ADC_7ANA   0b10000000 					// analog: AN0->6  and remaining channels are digital

#elif defined (ADC_V4)

#ifndef USE_OR_MASKS
//***************A/D Port Configuration Control *******************************
#define ADC_0ANA   0b11111111 					// All channels are digital
#define ADC_1ANA   0b11111110	 				// analog: AN0  and remaining channels are digital
#define ADC_2ANA   0b11111100 					// analog: AN0->1 and remaining channels are digital
#define ADC_3ANA   0b11111000 					// analog: AN0->2 and remaining channels are digital
#define ADC_4ANA   0b11110000 					// analog: AN0->3  and remaining channels are digital
#else // USE_OR_MASKS
//***************A/D Port Configuration Control *******************************
#define ADC_0ANA   0b00001111 					// All channels are digital
#define ADC_1ANA   0b00001110	 				// analog: AN0  and remaining channels are digital
#define ADC_2ANA   0b00001100 					// analog: AN0->1 and remaining channels are digital
#define ADC_3ANA   0b00001000 					// analog: AN0->2 and remaining channels are digital
#define ADC_4ANA   0b00000000 					// analog: AN0->3  and remaining channels are digital
#define ADC_CONFIG_MASK  (~ADC_0ANA)			//Mask ADC port configuration bits
#endif // USE_OR_MASKS


#elif defined (ADC_V9) || defined (ADC_V9_1) 

//***************A/D Port Configuration Control *******************************
#define ADC_0ANA      0b1111111111111111 		// All channels are digital
#define ADC_1ANA      0b1111111111111110	 	// analog: AN0 and remaining channels are digital
#define ADC_2ANA      0b1111111111111100 		// analog: AN0-AN1 and remaining channels are digital
#define ADC_3ANA      0b1111111111111000 		// analog: AN0-AN2 and remaining channels are digital
#define ADC_4ANA      0b1111111111110000 		// analog: AN0-AN3 and remaining channels are digital
#define ADC_5ANA      0b1111111111100000		// analog: AN0-AN4 and remaining channels are digital
//#define ADC_6ANA      0b1111111111000000	 	// analog: AN0-AN5 and remaining channels are digital
#if defined (ADC_V9)
#define ADC_7ANA      0b1111111110000000 		// analog: AN0-AN6 and remaining channels are digital
#endif
#define ADC_8ANA      0b1111111100000000 		// analog: AN0-AN7 and remaining channels are digital
#if defined (ADC_V9)
#define ADC_9ANA      0b1111111000000000 		// analog: AN0-AN8 and remaining channels are digital
#define ADC_10ANA     0b1111110000000000 		// analog: AN0-AN9 and remaining channels are digital
#endif
#define ADC_11ANA     0b1111100000000000	 	// analog: AN0-AN10 and remaining channels are digital
#define ADC_12ANA     0b1111000000000000 		// analog: AN0-AN11 and remaining channels are digital
#define ADC_13ANA     0b1110000000000000 		// analog: AN0-AN12 and remaining channels are digital
#define ADC_14ANA     0b1100000000000000	 	// analog: AN0-AN13 and remaining channels are digital
#define ADC_15ANA     0b1000000000000000 		// analog: AN0-AN14 and remaining channels are digital
#define ADC_16ANA     0b0000000000000000 		// All channels are analog


#elif defined (ADC_V8) || defined (ADC_V10) 

//***************A/D Port Configuration Control *******************************
#define ADC_0ANA      0b0000000000000000 		// All channels are digital
#define ADC_1ANA      0b0000000000000001	 	// analog: AN0 and remaining channels are digital
#define ADC_2ANA      0b0000000000000011 		// analog: AN0-AN1 and remaining channels are digital
#define ADC_3ANA      0b0000000000000111 		// analog: AN0-AN2 and remaining channels are digital
#define ADC_4ANA      0b0000000000001111 		// analog: AN0-AN3 and remaining channels are digital
#define ADC_5ANA      0b0000000000011111		// analog: AN0-AN4 and remaining channels are digital
#define ADC_6ANA      0b0000000000111111	 	// analog: AN0-AN5 and remaining channels are digital
#define ADC_7ANA      0b0000000001111111 		// analog: AN0-AN6 and remaining channels are digital
#define ADC_8ANA      0b0000000011111111 		// analog: AN0-AN7 and remaining channels are digital
#define ADC_9ANA      0b0000000111111111 		// analog: AN0-AN8 and remaining channels are digital
#define ADC_10ANA     0b0000001111111111 		// analog: AN0-An9 and remaining channels are digital
#define ADC_11ANA     0b0000011111111111	 	// analog: AN0-AN10 and remaining channels are digital
#define ADC_12ANA     0b0000111111111111 		// analog: AN0-AN11 and remaining channels are digital
#define ADC_13ANA     0b0001111111111111 		// All channels are analog

#elif defined (ADC_V11) || defined (ADC_V11_1) 

//***************A/D Port Configuration Control *******************************
#define ADC_0ANA      0b0001111111111111 		// All channels are digital
#define ADC_1ANA      0b0001111111111110	 	// analog: AN0 and remaining channels are digital
#define ADC_2ANA      0b0001111111111100 		// analog: AN0-AN1 and remaining channels are digital
#define ADC_3ANA      0b0001111111111000 		// analog: AN0-AN2 and remaining channels are digital
#define ADC_4ANA      0b0001111111110000 		// analog: AN0-AN3 and remaining channels are digital
#define ADC_5ANA      0b0001111111100000		// analog: AN0-AN4 and remaining channels are digital
#define ADC_6ANA      0b0001111111000000	 	// analog: AN0-AN5 and remaining channels are digital
#define ADC_7ANA      0b0001111110000000 		// analog: AN0-AN6 and remaining channels are digital
#define ADC_8ANA      0b0001111100000000 		// analog: AN0-AN7 and remaining channels are digital
#define ADC_9ANA      0b0001111000000000 		// analog: AN0-AN8 and remaining channels are digital
#define ADC_10ANA     0b0001110000000000 		// analog: AN0-An9 and remaining channels are digital
#define ADC_11ANA     0b0001100000000000	 	// analog: AN0-AN10 and remaining channels are digital
#define ADC_12ANA     0b0001000000000000 		// analog: AN0-AN11 and remaining channels are digital
#define ADC_13ANA     0b0000000000000000 		// All channels are analog

#if defined (ADC_V11) || defined (ADC_V11_1) 
//************** Band Gap selection *******************************************
#define ADC_VBG_ON    0b1000000000000000      	//VBG output of Band Gap module is enabled
#define ADC_VBG_OFF   0b0000000000000000     	//VBG output of Band Gap module is disabled 
#endif

#endif		// End of versions


#if defined (ADC_V7) || defined (ADC_V7_1)

#ifndef USE_OR_MASKS
//************** A/D conversion type *******************************************
#define	ADC_CONV_CONTINUOUS			0b11111111	//Auto-Conversion Continuous Loop Enabled
#define	ADC_CONV_SINGLE_SHOT		0b11110111	//Single shot mode enabled

//************* A/D conversion mode *******************************************
#define	ADC_MODE_MULTI_CH			0b11111111	//Multi-Channel mode enabled
#define	ADC_MODE_SINGLE_CH			0b11111011	//Single-Channel mode enabled

//************** A/D conversion mode sequence select *****************************
#define	ADC_CONV_SEQ_SEQM1			0b11111100	//Sequential Mode 1 (SEQM1); two samples are taken in sequence
#define	ADC_CONV_SEQ_SEQM2			0b11111101	//Sequential Mode 2 (SEQM2); four samples are taken in sequence
#define	ADC_CONV_SEQ_STNM1			0b11111110	//Simultaneous Mode 1 (STNM1); two samples are taken simultaneously
#define	ADC_CONV_SEQ_STNM2			0b11111111	//Simultaneous Mode 2 (STNM2); two samples are taken simultaneously
#define	ADC_CONV_SEQ_SCM1			0b11111100	//Single Channel Mode 1 (SCM1); Group A is taken and converted
#define	ADC_CONV_SEQ_SCM2			0b11111101	//Single Channel Mode 2 (SCM2); Group B is taken and converted
#define	ADC_CONV_SEQ_SCM3			0b11111110	//Single Channel Mode 3 (SCM3); Group C is taken and converted
#define	ADC_CONV_SEQ_SCM4			0b11111111	//Single Channel Mode 4 (SCM4); Group D is taken and converted

//************** A/D Vref selection *********************************************
#define	ADC_REF_VDD_VREFMINUS		0b10111111	// ADC voltage source VREF+ = VDD and VREF- = ext.source at VREF-
#define	ADC_REF_VREFPLUS_VSS		0b01111111	// ADC voltage source VREF+ = ext.source at VREF+ and VREF- = VSS
#define	ADC_REF_VREFPLUS_VREFMINUS	0b11111111	// ADC voltage source VREF+ = ext.source at VREF+ and VREF- = ext.source at VREF-
#define	ADC_REF_VDD_VSS				0b00111111	// ADC voltage source VREF+ = VDD and VREF- = VSS

//************** A/D FIFO buffer control ****************************************
#define	ADC_FIFO_EN					0b11111111	//FIFO Buffer Enable
#define	ADC_FIFO_DIS				0b11011111	//FIFO Buffer Disable

//************** A/D Buffer depth interrupt control  *******************************
#define	INT_EACH_WR_BUF				0b00111111	//Interrupt is generated when each word is written to the buffer
#define	INT_2_4_WR_BUF				0b01111111	//Interrupt is generated when the 2nd and 4th words are written to the buffer
#define	INT_4_WR_BUF				0b10111111	//Interrupt is generated when the 4th word is written to the buffer

//************** A/D trigger source *********************************************
#define	ADC_TRIG_EXT_INT0			0b11100001	//External interrupt RC3/INT0 starts A/D sequence
#define	ADC_TRIG_TMR_5				0b11100010	//Timer5 starts A/D sequence
#define	ADC_TRIG_INP_CAP			0b11100100	//Input Capture 1 (IC1) starts A/D sequence
#define	ADC_TRIG_CCP2_COM			0b11101000	//CCP2 compare match starts A/D sequence
#define	ADC_TRIG_PCPWM				0b11110000	//Power Control PWM module rising edge starts A/D sequence

//************** A/D Acquisition Time Selection *******************************
#define	ADC_0_TAD					0b10000111	//A/D Acquisition Time is 0 TAD
#define	ADC_2_TAD					0b10001111	//A/D Acquisition Time is 2 TAD
#define	ADC_4_TAD					0b10010111	//A/D Acquisition Time is 4 TAD
#define	ADC_6_TAD					0b10011111	//A/D Acquisition Time is 6 TAD
#define	ADC_8_TAD					0b10100111	//A/D Acquisition Time is 8 TAD
#define	ADC_10_TAD					0b10101111	//A/D Acquisition Time is 10 TAD
#define	ADC_12_TAD					0b10110111	//A/D Acquisition Time is 12 TAD
#define	ADC_16_TAD					0b10111111	//A/D Acquisition Time is 16 TAD
#define	ADC_20_TAD					0b11000111	//A/D Acquisition Time is 20 TAD
#define	ADC_24_TAD					0b11001111	//A/D Acquisition Time is 24 TAD
#define	ADC_28_TAD					0b11010111	//A/D Acquisition Time is 28 TAD
#define	ADC_32_TAD					0b11011111	//A/D Acquisition Time is 32 TAD
#define	ADC_36_TAD					0b11100111	//A/D Acquisition Time is 36 TAD
#define	ADC_40_TAD					0b11101111	//A/D Acquisition Time is 40 TAD
#define	ADC_48_TAD					0b11110111	//A/D Acquisition Time is 48 TAD
#define	ADC_64_TAD					0b11111111	//A/D Acquisition Time is 64 TAD

//*************** A/D Interrupt Enable/Disable *******************************
#define ADC_INT_ON       			0b11111111	//A/D Interrupt Enable
#define ADC_INT_OFF      			0b11011111	//A/D Interrupt Disable

//*************** A/D Conversion Clock Selection *****************************
#define ADC_FOSC_2      		 	0b11111000 	//A/D conversion clock source is Fosc/2
#define ADC_FOSC_4      			0b11111100 	//A/D conversion clock source is Fosc/4
#define ADC_FRC_4        			0b11111011 	//A/D conversion clock source is FRC/4
#define ADC_FOSC_8       			0b11111001 	//A/D conversion clock source is Fosc/8
#define ADC_FOSC_16      			0b11111101 	//A/D conversion clock source is Fosc/16
#define ADC_FOSC_32      			0b11111010 	//A/D conversion clock source is Fosc/32
#define ADC_FOSC_64      			0b11111110 	//A/D conversion clock source is Fosc/64
#define ADC_FOSC_RC      			0b11111111 	//A/D conversion clock source is Internal RC OSC

#else // USE_OR_MASKS

//************** A/D conversion type *******************************************
#define	ADC_CONV_CONTINUOUS			0b00001000	//Auto-Conversion Continuous Loop Enabled
#define	ADC_CONV_SINGLE_SHOT		0b00000000	//Single shot mode enabled
#define ADC_CONV_TYPE_MASK			(~ADC_CONV_CONTINUOUS)	//Mask ADC conversion type selection bit

//************* A/D conversion mode *******************************************
#define	ADC_MODE_MULTI_CH			0b00000100	//Multi-Channel mode enabled
#define	ADC_MODE_SINGLE_CH			0b00000000	//Single-Channel mode enabled
#define ADC_MODE_MASK				(~ADC_MODE_MULTI_CH)	//Mask ADC conversion mode selection bit

//************** A/D conversion mode sequence select *****************************
#define	ADC_CONV_SEQ_SEQM1			0b00000000	//Sequential Mode 1 (SEQM1); two samples are taken in sequence
#define	ADC_CONV_SEQ_SEQM2			0b00000001	//Sequential Mode 2 (SEQM2); four samples are taken in sequence
#define	ADC_CONV_SEQ_STNM1			0b00000010	//Simultaneous Mode 1 (STNM1); two samples are taken simultaneously
#define	ADC_CONV_SEQ_STNM2			0b00000011	//Simultaneous Mode 2 (STNM2); two samples are taken simultaneously
#define	ADC_CONV_SEQ_SCM1			0b00000000	//Single Channel Mode 1 (SCM1); Group A is taken and converted
#define	ADC_CONV_SEQ_SCM2			0b00000001	//Single Channel Mode 2 (SCM2); Group B is taken and converted
#define	ADC_CONV_SEQ_SCM3			0b00000010	//Single Channel Mode 3 (SCM3); Group C is taken and converted
#define	ADC_CONV_SEQ_SCM4			0b00000011	//Single Channel Mode 4 (SCM4); Group D is taken and converted
#define ADC_CONV_SEQ_MASK			(~ADC_CONV_SEQ_STNM2)	//Mask ADC conversion mode sequence select bits

//************** A/D Vref selection *********************************************
#define	ADC_REF_VDD_VREFMINUS		0b10000000	// ADC voltage source VREF+ = VDD and VREF- = ext.source at VREF-
#define	ADC_REF_VREFPLUS_VSS		0b01000000	// ADC voltage source VREF+ = ext.source at VREF+ and VREF- = VSS
#define	ADC_REF_VREFPLUS_VREFMINUS	0b11000000	// ADC voltage source VREF+ = ext.source at VREF+ and VREF- = ext.source at VREF-
#define	ADC_REF_VDD_VSS				0b00000000	// ADC voltage source VREF+ = VDD and VREF- = VSS
#define ADC_REF_MASK	            (~ADC_REF_VREFPLUS_VREFMINUS)	//Mask ADC Vref selection bits

//************** A/D FIFO buffer control ****************************************
#define	ADC_FIFO_EN					0b00100000	//FIFO Buffer Enable
#define	ADC_FIFO_DIS				0b00000000	//FIFO Buffer Disable
#define ADC_FIFO_MASK				(~ADC_FIFO_EN)	//Mask ADC FIFO buffer control bit

//************** A/D Buffer depth interrupt control  *******************************
#define	INT_EACH_WR_BUF				0b00000000	//Interrupt is generated when each word is written to the buffer
#define	INT_2_4_WR_BUF				0b01000000	//Interrupt is generated when the 2nd and 4th words are written to the buffer
#define	INT_4_WR_BUF				0b10000000	//Interrupt is generated when the 4th word is written to the buffer
#define	INT_MASK				    (0b00111111)	//Mask ADC Buffer depth interrupt control bits

//************** A/D trigger source *********************************************
#define	ADC_TRIG_EXT_INT0			0b00000001	//External interrupt RC3/INT0 starts A/D sequence
#define	ADC_TRIG_TMR_5				0b00000010	//Timer5 starts A/D sequence
#define	ADC_TRIG_INP_CAP			0b00000100	//Input Capture 1 (IC1) starts A/D sequence
#define	ADC_TRIG_CCP2_COM			0b00001000	//CCP2 compare match starts A/D sequence	
#define	ADC_TRIG_PCPWM				0b00010000	//Power Control PWM module rising edge starts A/D sequence
#define ADC_TRIG_MASK				(0b11100000)	//Mask ADC  trigger source bits 

//************** A/D Acquisition Time Selection *******************************
#define	ADC_0_TAD					0b00000000	//A/D Acquisition Time is 0 TAD
#define	ADC_2_TAD					0b00001000	//A/D Acquisition Time is 2 TAD
#define	ADC_4_TAD					0b00010000	//A/D Acquisition Time is 4 TAD
#define	ADC_6_TAD					0b00011000	//A/D Acquisition Time is 6 TAD
#define	ADC_8_TAD					0b00100000	//A/D Acquisition Time is 8 TAD
#define	ADC_10_TAD					0b00101000	//A/D Acquisition Time is 10 TAD
#define	ADC_12_TAD					0b00110000	//A/D Acquisition Time is 12 TAD
#define	ADC_16_TAD					0b00111000	//A/D Acquisition Time is 16 TAD
#define	ADC_20_TAD					0b01000000	//A/D Acquisition Time is 20 TAD
#define	ADC_24_TAD					0b01001000	//A/D Acquisition Time is 24 TAD
#define	ADC_28_TAD					0b01010000	//A/D Acquisition Time is 28 TAD
#define	ADC_32_TAD					0b01011000	//A/D Acquisition Time is 32 TAD
#define	ADC_36_TAD					0b01100000	//A/D Acquisition Time is 36 TAD
#define	ADC_40_TAD					0b01101000	//A/D Acquisition Time is 40 TAD
#define	ADC_48_TAD					0b01110000	//A/D Acquisition Time is 48 TAD
#define	ADC_64_TAD					0b01111000	//A/D Acquisition Time is 64 TAD
#define ADC_TAD_MASK				(~ADC_64_TAD)	//Mask ADC Acquisition Time Selection bits

//*************** A/D Interrupt Enable/Disable *******************************
#define ADC_INT_ON                  0b00100000	//A/D Interrupt Enable
#define ADC_INT_OFF                 0b00000000	//A/D Interrupt Disable
#define ADC_INT_MASK                ~ADC_INT_ON	//Mask ADC Interrupt Enable/Disable

//*************** A/D Conversion Clock Selection *****************************
#define ADC_FOSC_2      		 	0b00000000 	//A/D conversion clock source is Fosc/2
#define ADC_FOSC_4      			0b00000100 	//A/D conversion clock source is Fosc/4
#define ADC_FRC_4        			0b00000011 	//A/D conversion clock source is FRC/4
#define ADC_FOSC_8       			0b00000001 	//A/D conversion clock source is Fosc/8
#define ADC_FOSC_16      			0b00000101 	//A/D conversion clock source is Fosc/16
#define ADC_FOSC_32      			0b00000010 	//A/D conversion clock source is Fosc/32
#define ADC_FOSC_64      			0b00000110 	//A/D conversion clock source is Fosc/64
#define ADC_FOSC_RC      			0b00000111 	//A/D conversion clock source is Internal RC OSC
#define ADC_FOSC_MASK				(~ADC_FOSC_RC)	//Mask ADC Conversion Clock Selection bits
#endif // USE_OR_MASKS

#endif	// End of versions

#if	defined (ADC_V1) || defined (ADC_V2) || defined (ADC_V3) || defined (ADC_V4) ||\
    defined (ADC_V5) || defined (ADC_V6) || defined (ADC_V8) || defined (ADC_V9) || defined (ADC_V9_1) ||\
	defined (ADC_V10) || defined (ADC_V11) || defined (ADC_V12) || defined (ADC_V11_1) 
#ifndef USE_OR_MASKS
//**************** channel selection ******************************************
#define ADC_CH0          0b10000111  			//Select Channel 0
#define ADC_CH1          0b10001111  			//Select Channel 1
#define ADC_CH2          0b10010111  			//Select Channel 2
#define ADC_CH3          0b10011111  			//Select Channel 3
#define ADC_CH4          0b10100111  			//Select Channel 4
#define ADC_CH5          0b10101111  			//Select Channel 5
#define ADC_CH6          0b10110111  			//Select Channel 6
#define ADC_CH7          0b10111111  			//Select Channel 7
#define ADC_CH8          0b11000111  			//Select Channel 8
#define ADC_CH9          0b11001111  			//Select Channel 9
#define ADC_CH10         0b11010111  			//Select Channel 10
#define ADC_CH11         0b11011111  			//Select Channel 11
#define ADC_CH12         0b11100111  			//Select Channel 12
#if defined (ADC_V11) || defined (ADC_V11_1) 
#define ADC_CH_CTMU      0b11101111  			// All analog inputs are off
#define ADC_CH_VDDCORE   0b11110111  			// VDDCORESelect Channel
#define ADC_CH_VBG       0b11111111  			// Voltage Band gapSelect Channel
#else
#define ADC_CH13         0b11101111  			//Select Channel 13
#define ADC_CH14         0b11110111  			//Select Channel 14
#define ADC_CH15         0b11111111  			//Select Channel 15
#endif

#else // USE_OR_MASKS

//**************** channel selection ******************************************
#define ADC_CH0          0b00000000  			//Select Channel 0
#define ADC_CH1          0b00001000  			//Select Channel 1
#define ADC_CH2          0b00010000  			//Select Channel 2
#define ADC_CH3          0b00011000  			//Select Channel 3
#define ADC_CH4          0b00100000  			//Select Channel 4
#define ADC_CH5          0b00101000  			//Select Channel 5
#define ADC_CH6          0b00110000  			//Select Channel 6
#define ADC_CH7          0b00111000  			//Select Channel 7
#define ADC_CH8          0b01000000  			//Select Channel 8
#define ADC_CH9          0b01001000  			//Select Channel 9
#define ADC_CH10         0b01010000  			//Select Channel 10
#define ADC_CH11         0b01011000  			//Select Channel  11
#define ADC_CH12         0b01100000  			//Select Channel 12
#if defined (ADC_V11) || defined (ADC_V11_1) 
#define ADC_CH_CTMU      0b01101000  			// All analog inputs are off - CTMU
#define ADC_CH_VDDCORE   0b01110000  			// VDDCORESelect Channel
#define ADC_CH_VBG       0b01111000  			// Voltage Band gapSelect Channel
#define ADC_CH_MASK		 (~ADC_CH_VBG)			//Mask ADC channel selection bits
#elif defined (ADC_V10)
#define ADC_CH_MASK		 (~FVR1)			//Mask ADC channel selection bits
#else
#define ADC_CH13         0b01101000  			//Select Channel 13
#define ADC_CH14         0b01110000  			//Select Channel 14
#define ADC_CH15         0b01111000  			//Select Channel 15
#define ADC_CH_MASK		 (~ADC_CH15)			//Mask ADC channel selection bits
#endif

#endif // USE_OR_MASKS
#endif

#if defined (ADC_V10)

#ifndef USE_OR_MASKS
//**************** channel selection ******************************************
#define ADC_CH3          0b10011111  		//Select Channel 3
#define ADC_CH4          0b10100111  		//Select Channel 4
#define ADC_CH5          0b10101111  		//Select Channel 5
#define ADC_CH6          0b10110111  		//Select Channel 6
#define ADC_CH7          0b10111111  		//Select Channel 7
#define ADC_CH8          0b11000111  		//Select Channel 8
#define ADC_CH9          0b11001111  		//Select Channel 9
#define ADC_CH10         0b11010111  		//Select Channel 10
#define ADC_CH11         0b11011111  		//Select Channel 11
#define DAC1			 0b11110111  		// Digital to Analog convertor
#define FVR1			 0b11111111  		// Fixed Voltage Regulator

//************** Positive Voltage Reference Configuration *************************
#define ADC_REF_VDD_VDD			0b11110011 	// ADC voltage source VREF+ = AVDD
#define ADC_REF_VDD_VREFPLUS 	0b11110111 	// ADC voltage source VREF+ = ext. source at VREF+
#define ADC_REF_VDD_FVREF		0b11111011 	// ADC voltage source VREF+ = FVREF+

//************** Negetive Voltage Reference Configuration *************************
#define ADC_REF_VDD_VSS			0b11111100 	// ADC voltage source VREF- = AVSS
#define ADC_REF_VDD_VREFMINUS	0b11111101 	// ADC voltage source VREF- = ext. source at VREF-

//------------------------------------------------
#else //USE_OR_MASKS
//**************** channel selection ******************************************
#define ADC_CH3          0b00011000  		//Select Channel 3
#define ADC_CH4          0b00100000  		//Select Channel 4
#define ADC_CH5          0b00101000  		//Select Channel 5
#define ADC_CH6          0b00110000  		//Select Channel 6
#define ADC_CH7          0b00111000  		//Select Channel 7
#define ADC_CH8          0b01000000  		//Select Channel 8
#define ADC_CH9          0b01001000  		//Select Channel 9
#define ADC_CH10         0b01010000  		//Select Channel 10
#define ADC_CH11         0b01011000  		//Select Channel  11
#define DAC1			 0b01110000  		// Digital to Analog convertor
#define FVR1			 0b01111000  		// Fixed Voltage Regulator


//************** Positive Voltage Reference Configuration *************************
#define ADC_REF_VDD_VDD			0b00000000 	// ADC voltage source VREF+ = AVDD
#define ADC_REF_VDD_VREFPLUS	0b00000100 	// ADC voltage source VREF+ = ext. source at VREF+
#define ADC_REF_VDD_FVREF		0b00001000 	// ADC voltage source VREF+ = FVREF+

//************** Negetive Voltage Reference Configuration *************************
#define ADC_REF_VDD_VSS		    0b00000000 	// ADC voltage source VREF- = AVSS
#define ADC_REF_VDD_VREFMINUS	0b00000001 	// ADC voltage source VREF- = ext. source at VREF-
#endif //USE_OR_MASKS

#endif  // End of version ADC_V10

#if defined (ADC_V12) 

#ifndef USE_OR_MASKS
//**************** Special Trigger Select bit *********************************
#define ADC_TRIG_CTMU           0b11111111 	//Special trigger from the CTMU
#define ADC_TRIG_CCP2           0b01111111 	//Special trigger from CCP2
#else //USE_OR_MASKS
//**************** Special Trigger Select bit *********************************
#define ADC_TRIG_CTMU           0b10000000 	//Special trigger from the CTMU
#define ADC_TRIG_CCP2           0b00000000 	//Special trigger from CCP2
#define ADC_TRIG_MASK           (~ADC_TRIG_CTMU)	//Mask ADC Special Trigger Select bit
#endif //USE_OR_MASKS

#endif  // End of version ADC_V12


#if defined (ADC_V13) || defined (ADC_V13_1) || defined (ADC_V11_1) ||\
	defined (ADC_V13_2) || defined (ADC_V13_3)
#ifndef USE_OR_MASKS
//**************** Special Trigger Select bit *********************************
#define ADC_TRIG_RTCC           0b11111111 	//Special trigger from the RTCC
#define ADC_TRIG_TIMER1         0b10111111 	//Special trigger from TIMER1
#define ADC_TRIG_CTMU           0b01111111 	//Special trigger from the CTMU
#define ADC_TRIG_CCP2           0b00111111 	//Special trigger from CCP2
#else //USE_OR_MASKS
//**************** Special Trigger Select bit *********************************
#define ADC_TRIG_RTCC           0b11000000 	//Special trigger from the RTCC
#define ADC_TRIG_TIMER1         0b10000000 	//Special trigger from TIMER1
#define ADC_TRIG_CTMU           0b01000000 	//Special trigger from the CTMU
#define ADC_TRIG_CCP2           0b00000000 	//Special trigger from CCP2
#define ADC_TRIG_MASK           (~ADC_TRIG_RTCC)	//Mask ADC Special Trigger Select bit
#endif //USE_OR_MASKS
#endif


#if defined (ADC_V13) || defined (ADC_V13_1) || defined (ADC_V13_2)\
	 || defined (ADC_V13_3)

#ifndef USE_OR_MASKS
//**************** channel selection ******************************************
#define ADC_CH0          0b10000011  			//Select Channel 0
#define ADC_CH1          0b10000111  			//Select Channel 1
#define ADC_CH2          0b10001011  			//Select Channel 2
#define ADC_CH3          0b10001111  			//Select Channel 3
#define ADC_CH4          0b10010011  			//Select Channel 4
#if defined (ADC_V13) || defined (ADC_V13_1)  || defined (ADC_V13_3)
#define ADC_CH5          0b10010111  			//Select Channel 5
#define ADC_CH6          0b10011011  			//Select Channel 6
#define ADC_CH7          0b10011111  			//Select Channel 7
#endif
#define ADC_CH8          0b10100011  			//Select Channel 8
#define ADC_CH9          0b10100111  			//Select Channel 9
#define ADC_CH10         0b10101011  			//Select Channel 10
#if defined (ADC_V13) || defined (ADC_V13_1) 
#define ADC_CH11         0b10101111  			//Select Channel  11
#endif
#if defined (ADC_V13) || defined (ADC_V13_1) 
#if defined (ADC_V13)
#define ADC_CH12         0b10110011  			//Select Channel 12
#define ADC_CH13         0b10110111  			//Select Channel 13
#define ADC_CH14         0b10111011  			//Select Channel 14
#define ADC_CH15         0b10111111  			//Select Channel 15
#endif
#define ADC_CH16         0b11000011  			//Select Channel 16
#define ADC_CH17         0b11000111  			//Select Channel  17
#define ADC_CH18         0b11001011  			//Select Channel 18
#define ADC_CH19         0b11001111  			//Select Channel 19
#if defined (ADC_V13)
#define ADC_CH20         0b11010011  			//Select Channel 20
#define ADC_CH21         0b11010111  			//Select Channel 21
#define ADC_CH22         0b11011011  			//Select Channel 22
#define ADC_CH23         0b11011111  			//Select Channel 23
#define ADC_CH28         0b11110011  			//Select Channel 28 for CTMU
#define ADC_CH29         0b11110111  			//Select Channel 29 for Temperature Sensor
#endif
#define ADC_CH30         0b11111011  			//Select Channel 30
#define ADC_CH31         0b11111111  			//Select Channel 31
#endif
#else // USE_OR_MASKS

//**************** channel selection ******************************************
#define ADC_CH0          0b00000000  			//Select Channel 0
#define ADC_CH1          0b00000100  			//Select Channel 1
#define ADC_CH2          0b00001000  			//Select Channel 2
#define ADC_CH3          0b00001100  			//Select Channel 3
#define ADC_CH4          0b00010000  			//Select Channel 4
#if defined (ADC_V13) || defined (ADC_V13_1)  || defined (ADC_V13_3)
#define ADC_CH5          0b00010100  			//Select Channel 5
#define ADC_CH6          0b00011000  			//Select Channel 6
#define ADC_CH7          0b00011100  			//Select Channel 7
#endif
#define ADC_CH8          0b00100000  			//Select Channel 8
#define ADC_CH9          0b00100100  			//Select Channel 9
#define ADC_CH10         0b00101000  			//Select Channel 10
#if defined (ADC_V13) || defined (ADC_V13_1) 
#define ADC_CH11         0b00101100  			//Select Channel  11
#endif
#if defined (ADC_V13) || defined (ADC_V13_1) 
#if defined (ADC_V13)
#define ADC_CH12         0b00110000  			//Select Channel 12
#define ADC_CH13         0b00110100  			//Select Channel 13
#define ADC_CH14         0b00111000  			//Select Channel 14
#define ADC_CH15         0b00111100  			//Select Channel 15
#endif
#define ADC_CH16         0b01000000  			//Select Channel 16
#define ADC_CH17         0b01000100  			//Select Channel  17
#define ADC_CH18         0b01001000  			//Select Channel 18
#define ADC_CH19         0b01001100  			//Select Channel 19
#if defined (ADC_V13)
#define ADC_CH20         0b01010000  			//Select Channel 20
#define ADC_CH21         0b01010100  			//Select Channel 21
#define ADC_CH22         0b01011000  			//Select Channel 22
#define ADC_CH23         0b01011100  			//Select Channel 23
#define ADC_CH28         0b01110000  			//Select Channel 28 for CTMU
#define ADC_CH29         0b01110100  			//Select Channel 29 for Temperature Sensor
#endif
#define ADC_CH30         0b01111000  			//Select Channel 30
#define ADC_CH31         0b01111100  			//Select Channel 31
#endif
#define ADC_CH_MASK		 (~0b01111100)			//Mask ADC channel selection bits

#endif // USE_OR_MASKS


#ifndef USE_OR_MASKS
//**************** Analog Negetive Channel Select *********************************
#define ADC_NEG_CH0          0b11111000  			//Select Analog Negetive Channel 0
#define ADC_NEG_CH1          0b11111001  			//Select Analog Negetive  Channel 1
#define ADC_NEG_CH2          0b11111010  			//Select Analog Negetive  Channel 2
#define ADC_NEG_CH3          0b11111011  			//Select Analog Negetive  Channel 3
#define ADC_NEG_CH4          0b11111100  			//Select Analog Negetive  Channel 4
#define ADC_NEG_CH5          0b11111101  			//Select Analog Negetive  Channel 5
#define ADC_NEG_CH6          0b11111110  			//Select Analog Negetive  Channel 6
#if defined (ADC_V13) || defined (ADC_V13_1)
#define ADC_NEG_CH7          0b11111111  			//Select Analog Negetive  Channel 7
#endif
#else //USE_OR_MASKS
//**************** Analog Negetive Channel Select *********************************
#define ADC_NEG_CH0          0b00000000  			//Select Analog Negetive Channel 0
#define ADC_NEG_CH1          0b00000001  			//Select Analog Negetive  Channel 1
#define ADC_NEG_CH2          0b00000010  			//Select Analog Negetive  Channel 2
#define ADC_NEG_CH3          0b00000011  			//Select Analog Negetive  Channel 3
#define ADC_NEG_CH4          0b00000100  			//Select Analog Negetive  Channel 4
#define ADC_NEG_CH5          0b00000101  			//Select Analog Negetive  Channel 5
#define ADC_NEG_CH6          0b00000110  			//Select Analog Negetive  Channel 6
#if defined (ADC_V13) || defined (ADC_V13_1)
#define ADC_NEG_CH7          0b00000111  			//Select Analog Negetive  Channel 7
#endif
#define ADC_NEG_CH_MASK		 (~0b00000111)			//Mask ADC Negetive channel selection bits
#endif //USE_OR_MASKS

#ifndef USE_OR_MASKS
//************** Positive Voltage Reference Configuration *************************
#define ADC_REF_VDD_VDD			0b11001111 	// ADC voltage positive source VREF+ = AVDD
#define ADC_REF_VDD_VREFPLUS	0b11011111 	// ADC voltage positive source VREF+ = ext. source at VREF+
#define ADC_REF_VDD_INT_VREF_2	0b11101111 	// ADC voltage positive source VREF+ = Inetrnal VREF of 2.048V
#define ADC_REF_VDD_INT_VREF_4	0b11111111 	// ADC voltage positive source VREF+ = Inetrnal VREF of 4.096V
//************** Negetive Voltage Reference Configuration *************************
#define ADC_REF_VDD_VSS		    0b11110111 	// ADC voltage negetive source VREF- = AVSS
#define ADC_REF_VDD_VREFMINUS	0b11111111 	// ADC voltage negetive source VREF- = ext. source at VREF-
#else //USE_OR_MASKS
//************** Positive Voltage Reference Configuration *************************
#define ADC_REF_VDD_VDD			0b00000000 	// ADC voltage positive source VREF+ = AVDD
#define ADC_REF_VDD_VREFPLUS	0b00010000 	// ADC voltage positive source VREF+ = ext. source at VREF+
#define ADC_REF_VDD_INT_VREF_2	0b00100000 	// ADC voltage positive source VREF+ = Inetrnal VREF of 2.048V
#define ADC_REF_VDD_INT_VREF_4	0b00110000 	// ADC voltage positive source VREF+ = Inetrnal VREF of 4.096V
#define ADC_REF_POS_MASK		(~ADC_REF_VDD_INT_VREF_4)			//Mask ADC positive voltage source selection bits
//************** Negetive Voltage Reference Configuration *************************
#define ADC_REF_VDD_VSS		    0b00000000 	// ADC voltage negetive source VREF- = AVSS
#define ADC_REF_VDD_VREFMINUS	0b00001000 	// ADC voltage negetive source VREF- = ext. source at VREF-
#define ADC_REF_NEG_MASK		(~ADC_REF_VDD_VREFMINUS)			//Mask ADC negetive voltage source selection bits
#endif //USE_OR_MASKS

/*ADC Port Configuration register definition*/
#define ENABLE_AN0_DIG()              ANCON0bits.ANSEL0=0 /*Enable AN0 in digital mode */
#define ENABLE_AN0_ANA()              ANCON0bits.ANSEL0=1 /*Enable AN0 in analog mode */
#define ENABLE_AN1_DIG()              ANCON0bits.ANSEL1=0 /*Enable AN1 in digital mode */
#define ENABLE_AN1_ANA()              ANCON0bits.ANSEL1=1 /*Enable AN1 in analog mode */
#define ENABLE_AN2_DIG()              ANCON0bits.ANSEL2=0 /*Enable AN2 in digital mode */
#define ENABLE_AN2_ANA()              ANCON0bits.ANSEL2=1 /*Enable AN2 in analog mode */
#define ENABLE_AN3_DIG()              ANCON0bits.ANSEL3=0 /*Enable AN3 in digital mode */
#define ENABLE_AN3_ANA()              ANCON0bits.ANSEL3=1 /*Enable AN3 in analog mode */
#define ENABLE_AN4_DIG()              ANCON0bits.ANSEL4=0 /*Enable AN4 in digital mode */
#define ENABLE_AN4_ANA()              ANCON0bits.ANSEL4=1 /*Enable AN4 in analog mode */
#if defined (ADC_V13) || defined (ADC_V13_1)  || defined (ADC_V13_3)
#define ENABLE_AN5_DIG()              ANCON0bits.ANSEL5=0 /*Enable AN5 in digital mode */
#define ENABLE_AN5_ANA()              ANCON0bits.ANSEL5=1 /*Enable AN5 in analog mode */
#define ENABLE_AN6_DIG()              ANCON0bits.ANSEL6=0 /*Enable AN6 in digital mode */
#define ENABLE_AN6_ANA()              ANCON0bits.ANSEL6=1 /*Enable AN6 in analog mode */
#define ENABLE_AN7_DIG()              ANCON0bits.ANSEL7=0 /*Enable AN7 in digital mode */
#define ENABLE_AN7_ANA()              ANCON0bits.ANSEL7=1 /*Enable AN7 in analog mode */
#define ENABLE_ALL_ANA_0_7()          ANCON0=0xFF /*Enable AN0-AN7 in analog mode */
#define ENABLE_ALL_DIG_0_7()          ANCON0=0x00 /*Enable AN0-AN7 in Digital mode */
#endif
#define ENABLE_AN8_DIG()              ANCON1bits.ANSEL8=0 /*Enable AN8 in digital mode */
#define ENABLE_AN8_ANA()              ANCON1bits.ANSEL8=1 /*Enable AN8 in analog mode */
#if defined (ADC_V13) || defined (ADC_V13_1)  || defined (ADC_V13_3)
#define ENABLE_AN9_DIG()              ANCON1bits.ANSEL9=0 /*Enable AN9 in digital mode */
#define ENABLE_AN9_ANA()              ANCON1bits.ANSEL9=1 /*Enable AN9 in analog mode */
#define ENABLE_AN10_DIG()             ANCON1bits.ANSEL10=0 /*Enable AN10 in digital mode */
#define ENABLE_AN10_ANA()             ANCON1bits.ANSEL10=1 /*Enable AN10 in analog mode */
#endif
#if defined (ADC_V13) || defined (ADC_V13_1) 
#define ENABLE_AN11_DIG()             ANCON1bits.ANSEL11=0 /*Enable AN11 in digital mode */
#define ENABLE_AN11_ANA()             ANCON1bits.ANSEL11=1 /*Enable AN11 in analog mode */

#if defined (ADC_V13)
#define ENABLE_AN12_DIG()             ANCON1bits.ANSEL12=0 /*Enable AN12 in digital mode */
#define ENABLE_AN12_ANA()             ANCON1bits.ANSEL12=1 /*Enable AN12 in analog mode */
#define ENABLE_AN13_DIG()             ANCON1bits.ANSEL13=0 /*Enable AN13 in digital mode */
#define ENABLE_AN13_ANA()             ANCON1bits.ANSEL13=1 /*Enable AN13 in analog mode */
#define ENABLE_AN14_DIG()             ANCON1bits.ANSEL14=0 /*Enable AN14 in digital mode */
#define ENABLE_AN14_ANA()             ANCON1bits.ANSEL14=1 /*Enable AN14 in analog mode */
#define ENABLE_AN15_DIG()             ANCON1bits.ANSEL15=0 /*Enable AN15 in digital mode */
#define ENABLE_AN15_ANA()             ANCON1bits.ANSEL15=1 /*Enable AN15 in analog mode */
#endif
#define ENABLE_ALL_ANA_8_15()         ANCON1=0xFF /*Enable AN8-AN15 in analog mode */
#define ENABLE_ALL_DIG_8_15()         ANCON1=0x00 /*Enable AN8-AN15 in Digital mode */

#define ENABLE_AN16_DIG()             ANCON2bits.ANSEL16=0 /*Enable AN16 in digital mode */
#define ENABLE_AN16_ANA()             ANCON2bits.ANSEL16=1 /*Enable AN16 in analog mode */
#define ENABLE_AN17_DIG()             ANCON2bits.ANSEL17=0 /*Enable AN17 in digital mode */
#define ENABLE_AN17_ANA()             ANCON2bits.ANSEL17=1 /*Enable AN17 in analog mode */
#define ENABLE_AN18_DIG()             ANCON2bits.ANSEL18=0 /*Enable AN18 in digital mode */
#define ENABLE_AN18_ANA()             ANCON2bits.ANSEL18=1 /*Enable AN18 in analog mode */
#define ENABLE_AN19_DIG()             ANCON2bits.ANSEL19=0 /*Enable AN19 in digital mode */
#define ENABLE_AN19_ANA()             ANCON2bits.ANSEL19=1 /*Enable AN19 in analog mode */
#if defined (ADC_V13)
#define ENABLE_AN20_DIG()             ANCON2bits.ANSEL20=0 /*Enable AN20 in digital mode */
#define ENABLE_AN20_ANA()             ANCON2bits.ANSEL20=1 /*Enable AN20 in analog mode */
#define ENABLE_AN21_DIG()             ANCON2bits.ANSEL21=0 /*Enable AN21 in digital mode */
#define ENABLE_AN21_ANA()             ANCON2bits.ANSEL21=1 /*Enable AN21 in analog mode */
#define ENABLE_AN22_DIG()             ANCON2bits.ANSEL22=0 /*Enable AN22 in digital mode */
#define ENABLE_AN22_ANA()             ANCON2bits.ANSEL22=1 /*Enable AN22 in analog mode */
#define ENABLE_AN23_DIG()             ANCON2bits.ANSEL23=0 /*Enable AN23 in digital mode */
#define ENABLE_AN23_ANA()             ANCON2bits.ANSEL23=1 /*Enable AN23 in analog mode */
#endif
#define ENABLE_ALL_ANA_16_23()        ANCON2=0xFF /*Enable AN16-AN23 in analog mode */
#define ENABLE_ALL_DIG_16_23()        ANCON2=0x00 /*Enable AN16-AN23 in Digital mode */
#endif

#endif  // End of version ADC_V13 & ADC_V13_1

#if defined (ADC_V14) || defined (ADC_V14_1) || defined (ADC_V14_2) || defined (ADC_V14_3)

#ifndef	USE_OR_MASKS
//*************** A/D Result Format Select ***********************************
#define ADC_RIGHT_JUST   0b11111111 			// Right justify A/D result
#define ADC_LEFT_JUST    0b01111111 			// Left justify A/D result
#else // USE_OR_MASKS
//*************** A/D Result Format Select ***********************************
#define ADC_RIGHT_JUST   0b10000000 			// Right justify A/D result
#define ADC_LEFT_JUST    0b00000000 			// Left justify A/D result
#define ADC_RESULT_MASK	 (~ADC_RIGHT_JUST)		//Mask ADC Result adjust bit
#endif // USE_OR_MASKS

#ifndef USE_OR_MASKS
//************** Positive Voltage Reference Configuration *************************
#define ADC_REF_VDD_VDD			0b11110011 	// ADC voltage positive source VREF+ = AVDD
#define ADC_REF_VDD_VREFPLUS	0b11110111 	// ADC voltage positive source VREF+ = ext. source at VREF+
#define ADC_REF_FVR_BUF			0b11111011 	// ADC voltage positive source VREF+ = FVR BUF
//************** Negetive Voltage Reference Configuration *************************
#define ADC_REF_VDD_VSS		    0b11111100 	// ADC voltage negetive source VREF- = AVSS
#define ADC_REF_VDD_VREFMINUS	0b11111101 	// ADC voltage negetive source VREF- = ext. source at VREF-
#else //USE_OR_MASKS
//************** Positive Voltage Reference Configuration *************************
#define ADC_REF_VDD_VDD			0b00000000 	// ADC voltage positive source VREF+ = AVDD
#define ADC_REF_VDD_VREFPLUS	0b00000100 	// ADC voltage positive source VREF+ = ext. source at VREF+
#define ADC_REF_FVR_BUF			0b00001000 	// ADC voltage positive source VREF+ = FVR BUF
#define ADC_REF_POS_MASK		(~0b00001100)			//Mask ADC positive voltage source selection bits
//************** Negetive Voltage Reference Configuration *************************
#define ADC_REF_VDD_VSS		    0b00000000 	// ADC voltage negetive source VREF- = AVSS
#define ADC_REF_VDD_VREFMINUS	0b00001001 	// ADC voltage negetive source VREF- = ext. source at VREF-
#define ADC_REF_NEG_MASK		(~0b00000011)			//Mask ADC negetive voltage source selection bits
#endif //USE_OR_MASKS

#ifndef USE_OR_MASKS
//**************** Special Trigger Select bit *********************************
#define ADC_TRIG_CTMU           0b11111111 	//Special trigger from the CTMU
#if defined (ADC_V14) || defined (ADC_V14_1)
#define ADC_TRIG_CCP5           0b01111111 	//Special trigger from CCP5
#endif
#if defined (ADC_V14_2) || defined (ADC_V14_3)
#define ADC_TRIG_CCP2           0b01111111 	//Special trigger from CCP2  
#endif
#else //USE_OR_MASKS
//**************** Special Trigger Select bit *********************************
#define ADC_TRIG_CTMU           0b10000000 	//Special trigger from the CTMU
#if defined (ADC_V14) || defined (ADC_V14_1)
#define ADC_TRIG_CCP5           0b00000000 	//Special trigger from CCP5
#endif
#if defined (ADC_V14_2) || defined (ADC_V14_3)
#define ADC_TRIG_CCP2           0b00000000 	//Special trigger from CCP2 
#endif
#define ADC_TRIG_MASK           (~ADC_TRIG_CTMU)	//Mask ADC Special Trigger Select bit
#endif //USE_OR_MASKS

#ifndef USE_OR_MASKS
#define ADC_CH0          0b10000011  			//Select Channel 0
#define ADC_CH1          0b10000111  			//Select Channel 1
#define ADC_CH2          0b10001011  			//Select Channel 2
#define ADC_CH3          0b10001111  			//Select Channel 3
#define ADC_CH4          0b10010011  			//Select Channel 4
#if defined (ADC_V14) || defined (ADC_V14_2)
#define ADC_CH5          0b10010111  			//Select Channel 5
#define ADC_CH6          0b10011011  			//Select Channel 6
#define ADC_CH7          0b10011111  			//Select Channel 7
#endif
#define ADC_CH8          0b10100011  			//Select Channel 8
#define ADC_CH9          0b10100111  			//Select Channel 9
#define ADC_CH10         0b10101011  			//Select Channel 10
#define ADC_CH11         0b10101111  			//Select Channel  11
#define ADC_CH12         0b10110011  			//Select Channel 12
#define ADC_CH13         0b10110111  			//Select Channel 13
#define ADC_CH14         0b10111011  			//Select Channel 14
#if defined (ADC_V14) || defined (ADC_V14_1)
#define ADC_CH15         0b10111111  			//Select Channel 15
#define ADC_CH16         0b11000011  			//Select Channel 16
#define ADC_CH17         0b11000111  			//Select Channel  17
#endif
#if defined (ADC_V14) || defined (ADC_V14_1) || defined (ADC_V14_2) || defined (ADC_V14_3)
#define ADC_CH18         0b11001011  			//Select Channel 18
#define ADC_CH19         0b11001111  			//Select Channel 19
#endif
#if defined (ADC_V14) || defined (ADC_V14_1) || defined (ADC_V14_2)
#define ADC_CH20         0b11010011  			//Select Channel 20
#endif
#if defined (ADC_V14) || defined (ADC_V14_2)
#define ADC_CH21         0b11010111  			//Select Channel 21
#define ADC_CH22         0b11011011  			//Select Channel 22
#define ADC_CH23         0b11011111  			//Select Channel 23
#define ADC_CH24         0b11100011  			//Select Channel 24
#define ADC_CH25         0b11100111  			//Select Channel 25
#define ADC_CH26         0b11101011  			//Select Channel 26
#define ADC_CH27         0b11101111  			//Select Channel 27
#endif
#if defined (ADC_V14_2) || defined (ADC_V14_3)
#define ADC_CH_TEMP_DI   0b11110011  			//Select Channel 28 for Temperature Diode
#endif
#define ADC_CH_CTMU      0b11110111  			//Select Channel 29 for CTMU
#define ADC_CH_DAC       0b11111011  			//Select Channel 30 for DAC
#define ADC_CH_FRV       0b11111111  			//Select Channel 31 for FRV
#else
#define ADC_CH0          0b00000000  			//Select Channel 0
#define ADC_CH1          0b00000100  			//Select Channel 1
#define ADC_CH2          0b00001000  			//Select Channel 2
#define ADC_CH3          0b00001100  			//Select Channel 3
#define ADC_CH4          0b00010000  			//Select Channel 4
#if defined (ADC_V14) || defined (ADC_V14_2)
#define ADC_CH5          0b00010100  			//Select Channel 5
#define ADC_CH6          0b00011000  			//Select Channel 6
#define ADC_CH7          0b00011100  			//Select Channel 7
#endif
#define ADC_CH8          0b00100000  			//Select Channel 8
#define ADC_CH9          0b00100100  			//Select Channel 9
#define ADC_CH10         0b00101000  			//Select Channel 10
#define ADC_CH11         0b00101100  			//Select Channel  11
#define ADC_CH12         0b00110000  			//Select Channel 12
#define ADC_CH13         0b00110100  			//Select Channel 13
#define ADC_CH14         0b00111000  			//Select Channel 14
#if defined (ADC_V14) || defined (ADC_V14_1)
#define ADC_CH15         0b00111100  			//Select Channel 15
#define ADC_CH16         0b01000000  			//Select Channel 16
#define ADC_CH17         0b01000100  			//Select Channel  17
#endif
#if defined (ADC_V14) || defined (ADC_V14_1) || defined (ADC_V14_2) || defined (ADC_V14_3)
#define ADC_CH18         0b01001000  			//Select Channel 18
#define ADC_CH19         0b01001100  			//Select Channel 19
#endif
#if defined (ADC_V14) || defined (ADC_V14_1) || defined (ADC_V14_2)
#define ADC_CH20         0b01010000  			//Select Channel 20
#endif
#if defined (ADC_V14) || defined (ADC_V14_2)
#define ADC_CH21         0b01010100  			//Select Channel 21
#define ADC_CH22         0b01011000  			//Select Channel 22
#define ADC_CH23         0b01011100  			//Select Channel 23
#define ADC_CH24         0b01100000  			//Select Channel 24
#define ADC_CH25         0b01100100  			//Select Channel 25
#define ADC_CH26         0b01101000  			//Select Channel 26
#define ADC_CH27         0b01101100  			//Select Channel 27
#endif
#if defined (ADC_V14_2) || defined (ADC_V14_3)
#define ADC_CH_TEMP_DI   0b01110000  			//Select Channel 28 for Temperature Diode
#endif
#define ADC_CH_CTMU      0b01110100  			//Select Channel 29 for CTMU
#define ADC_CH_DAC       0b01111000  			//Select Channel 30 for DAC
#define ADC_CH_FRV       0b01111100  			//Select Channel 31 for FRV
#define ADC_CH_MASK		 (~0b01111100)			//Mask ADC channel selection bits
#endif

#endif

#if	defined (ADC_V15) || defined (ADC_V15_1)

#ifndef USE_AND_OR
/***** ADCON1H register definition ****/
#define ADC_12BIT_MODE              0b11111111 /*12-bit A/D operation*/
#define ADC_10BIT_MODE              0b10111111 /*10-bit A/D operation*/

#define ADC_FORMAT_SIGN_FRACT       0b11111111 /* A/D data format signed fractional */
#define ADC_FORMAT_FRACT            0b11111110 /* A/D data format fractional */
#define ADC_FORMAT_SIGN_INT         0b11111101 /* A/D data format signed integer */
#define ADC_FORMAT_INTG             0b11111100 /* A/D data format integer */

/***** ADCON1L register definition ****/
#define ADC_TRIG_AUTO              	0b01111111 /*The SAMP bit is cleared after SAMC<4:0> number of TAD clocks following 
                                           the SAMP bit being set.No Extended Sample Time is present.*/										   
#define ADC_TRIG_CTMU                0b01001111 /* CTMU event ends sampling and starts conversion */
#define ADC_TRIG_TMR_5                0b00111111 /* Timer5 compare ends sampling and starts conversion */
#define ADC_TRIG_TMR_3                0b00101111 /* Timer3 compare ends sampling and starts conversion */
#define ADC_TRIG_INT0                0b00011111 /* Active transition on INT0 ends sampling and starts conversion */
#define ADC_TRIG_TIMER1                0b01011111 /* Timer1 compare ends sampling and starts conversion */
#define ADC_TRIG_CLEAR           	0b00001111 /*The SAMP bit must be cleared by software*/

#define ADC_AUTO_SAMPLING_ON        0b11111111 /* Sampling begins immediately after last conversion */
#define ADC_AUTO_SAMPLING_OFF       0b11111011 /* Sampling begins when SAMP bit is set */

#define ADC_SAMP_ON                 0b11111111 /* sample / hold amplifiers are sampling */
#define ADC_SAMP_OFF                0b11111101 /* sample / hold amplifiers are holding */

/***** ADCON2H control register definition ****/
#define ADC_REF_VDD_VREFPLUS       0b01111111 /*Converter Positive Voltage Reference - External VREF+*/
#define ADC_REF_VDD_VDD	           0b00001111 /*Converter Positive Voltage Reference - AVDD*/

#define ADC_REF_VDD_VREFMINUS      0b11111111 /*Converter Negative Voltage Reference - External VREF- */
#define ADC_REF_VDD_VSS            0b11011111 /*Converter Negative Voltage Reference - AVSS */

#define ADC_BUF_REG_ENABLE          0b11111111 /* Conversion result is loaded into buffer location determined by the converted channel*/
#define ADC_BUF_REG_DISABLE         0b11110111 /* A/D result buffer is treated as a FIFO */

#define ADC_OFFSET_CAL_ON           0b11111111 /* Converts to get the Offset calibration value */
#define ADC_OFFSET_CAL_OFF         	0b11101111 /* Coverts to get the actual input value */

#define ADC_SCAN_ON                 0b11111111 /* A/D Scan Input Selections for CH0 during SAMPLE A */
#define ADC_SCAN_OFF                0b11111011 /* A/D Do notScan Input Selections for CH0+ during SAMPLE A */

/***** ADCON2L control register definition ****/
#define ADC_INTR_EACH_CONV          0b10000011 /* Interrupts at the completion of conversion of each sample */
#define ADC_INTR_2_CONV             0b10000111 /* Interrupts at the completion of conversion of 2 samples */
#define ADC_INTR_3_CONV             0b10001011 /* Interrupts at the completion of conversion of 3 samples */
#define ADC_INTR_4_CONV             0b10001111 /* Interrupts at the completion of conversion of 4 samples */
#define ADC_INTR_5_CONV             0b10010011 /* Interrupts at the completion of conversion of 5 samples */
#define ADC_INTR_6_CONV             0b10010111 /* Interrupts at the completion of conversion of 6 samples */
#define ADC_INTR_7_CONV             0b10011011 /* Interrupts at the completion of conversion of 7 samples */
#define ADC_INTR_8_CONV             0b10011111 /* Interrupts at the completion of conversion of 8 samples */
#define ADC_INTR_9_CONV             0b10100011 /* Interrupts at the completion of conversion of 9 samples */
#define ADC_INTR_10_CONV            0b10100111 /* Interrupts at the completion of conversion of 10 samples */
#define ADC_INTR_11_CONV            0b10101011 /* Interrupts at the completion of conversion of 11 samples */
#define ADC_INTR_12_CONV            0b10101111 /* Interrupts at the completion of conversion of 12 samples */
#define ADC_INTR_13_CONV            0b10110011 /* Interrupts at the completion of conversion of 13 samples */
#define ADC_INTR_14_CONV            0b10110111 /* Interrupts at the completion of conversion of 14 samples */
#define ADC_INTR_15_CONV            0b10111011 /* Interrupts at the completion of conversion of 15 samples */
#define ADC_INTR_16_CONV            0b10111111 /* Interrupts at the completion of conversion of 16 samples */
#define ADC_INTR_17_CONV            0b11000011 /* Interrupts at the completion of conversion of 17 samples */
#define ADC_INTR_18_CONV            0b11000111 /* Interrupts at the completion of conversion of 18 samples */
#define ADC_INTR_19_CONV            0b11001011 /* Interrupts at the completion of conversion of 19 samples */
#define ADC_INTR_20_CONV            0b11001111 /* Interrupts at the completion of conversion of 20 samples */
#define ADC_INTR_21_CONV            0b11010011 /* Interrupts at the completion of conversion of 21 samples */
#define ADC_INTR_22_CONV            0b11010111 /* Interrupts at the completion of conversion of 22 samples */
#define ADC_INTR_23_CONV            0b11011011 /* Interrupts at the completion of conversion of 23 samples */
#define ADC_INTR_24_CONV            0b11011111 /* Interrupts at the completion of conversion of 24 samples */
#define ADC_INTR_25_CONV            0b11100011 /* Interrupts at the completion of conversion of 25 samples */
#define ADC_INTR_26_CONV            0b11100111 /* Interrupts at the completion of conversion of 26 samples */
#define ADC_INTR_27_CONV            0b11101011 /* Interrupts at the completion of conversion of 27 samples */
#define ADC_INTR_28_CONV            0b11101111 /* Interrupts at the completion of conversion of 28 samples */
#define ADC_INTR_29_CONV            0b11110011 /* Interrupts at the completion of conversion of 29 samples */
#define ADC_INTR_30_CONV            0b11110111 /* Interrupts at the completion of conversion of 30 samples */
#define ADC_INTR_31_CONV            0b11111011 /* Interrupts at the completion of conversion of 31 samples */
#define ADC_INTR_32_CONV            0b11111111 /* Interrupts at the completion of conversion of 32 samples */

#define ADC_ALT_BUF_ON              0b11111111 /* Buffer configured as 2 8-word buffers */
#define ADC_ALT_BUF_OFF             0b11111101 /* Buffer configured as 1 16-word buffer */

#define ADC_ALT_INPUT_ON            0b11111111 /* alternate between MUXA and MUXB */
#define ADC_ALT_INPUT_OFF           0b11111110 /* use MUXA only */

/**** ADCON3H register definition ****/
#define ADC_CONV_CLK_INTERNAL_RC    0b11111111 /* A/D Conversion Clock Source internal RC Clock */
#define ADC_CONV_CLK_SYSTEM         0b01111111 /* A/D Conversion Clock Source Clock derived from system clock */

#define ADC_EXT_SAMP_ON             0b11111111 /*A/D is still sampling after SAMP = 0*/
#define ADC_EXT_SAMP_OFF            0b10111111 /*A/D is finished sampling*/

#define ADC_CHARGE_PUMP_ENABLE      0b11111111 /*Charge pump for switches is enabled*/
#define ADC_CHARGE_PUMP_DISABLE     0b11011111 /*Charge pump for switches is enabled*/

//************** A/D Acquisition Time Selection *******************************
#define ADC_0_TAD		            0b11100000 /* A/D Auto Sample Time 0 Tad */
#define ADC_1_TAD		            0b11100001 /* A/D Auto Sample Time 1 Tad */
#define ADC_2_TAD		            0b11100010 /* A/D Auto Sample Time 2 Tad */
#define ADC_3_TAD		            0b11100011 /* A/D Auto Sample Time 3 Tad */
#define ADC_4_TAD		            0b11100100 /* A/D Auto Sample Time 4 Tad */
#define ADC_5_TAD		            0b11100101 /* A/D Auto Sample Time 5 Tad */
#define ADC_6_TAD		            0b11100110 /* A/D Auto Sample Time 6 Tad */
#define ADC_7_TAD		            0b11100111 /* A/D Auto Sample Time 7 Tad */
#define ADC_8_TAD		            0b11101000 /* A/D Auto Sample Time 8 Tad */
#define ADC_9_TAD		            0b11101001 /* A/D Auto Sample Time 9 Tad */
#define ADC_10_TAD		            0b11101010 /* A/D Auto Sample Time 10 Tad */
#define ADC_11_TAD		            0b11101010 /* A/D Auto Sample Time 11 Tad */
#define ADC_12_TAD		            0b11101100 /* A/D Auto Sample Time 12 Tad */
#define ADC_13_TAD		            0b11101101 /* A/D Auto Sample Time 13 Tad */
#define ADC_14_TAD		            0b11101110 /* A/D Auto Sample Time 14 Tad */
#define ADC_15_TAD		            0b11101111 /* A/D Auto Sample Time 15 Tad */
#define ADC_16_TAD		            0b11110000 /* A/D Auto Sample Time 16 Tad */
#define ADC_17_TAD		            0b11110001 /* A/D Auto Sample Time 17 Tad */
#define ADC_18_TAD		            0b11110010 /* A/D Auto Sample Time 18 Tad */
#define ADC_19_TAD		            0b11110011 /* A/D Auto Sample Time 19 Tad */
#define ADC_20_TAD		            0b11110100 /* A/D Auto Sample Time 20 Tad */
#define ADC_21_TAD		            0b11110101 /* A/D Auto Sample Time 21 Tad */
#define ADC_22_TAD		            0b11110110 /* A/D Auto Sample Time 22 Tad */
#define ADC_23_TAD		            0b11110111 /* A/D Auto Sample Time 23 Tad */
#define ADC_24_TAD		            0b11111000 /* A/D Auto Sample Time 24 Tad */
#define ADC_25_TAD		            0b11111001 /* A/D Auto Sample Time 25 Tad */
#define ADC_26_TAD		            0b11111010 /* A/D Auto Sample Time 26 Tad */
#define ADC_27_TAD		            0b11111010 /* A/D Auto Sample Time 27 Tad */
#define ADC_28_TAD		            0b11111100 /* A/D Auto Sample Time 28 Tad */
#define ADC_29_TAD		            0b11111101 /* A/D Auto Sample Time 29 Tad */
#define ADC_30_TAD		            0b11111110 /* A/D Auto Sample Time 30 Tad */
#define ADC_31_TAD		            0b11111111 /* A/D Auto Sample Time 31 Tad */

/**** ADCON3L register definition ****/
//*************** A/D Conversion Clock Selection *****************************
#define ADC_CONV_CLK_1Tcy          0b00000000/* A/D Conversion Clock is Tcy */
#define ADC_CONV_CLK_2Tcy          0b00000001 /* A/D Conversion Clock is 2*Tcy */
#define ADC_CONV_CLK_3Tcy          0b00000010 /* A/D Conversion Clock is 3*Tcy */
#define ADC_CONV_CLK_4Tcy          0b00000011 /* A/D Conversion Clock is 4*Tcy */
#define ADC_CONV_CLK_5Tcy          0b00000100 /* A/D Conversion Clock is 5*Tcy */
#define ADC_CONV_CLK_6Tcy          0b00000101 /* A/D Conversion Clock is 6*Tcy */
#define ADC_CONV_CLK_7Tcy          0b00000110 /* A/D Conversion Clock is 7*Tcy */
#define ADC_CONV_CLK_8Tcy          0b00000111 /* A/D Conversion Clock is 8*Tcy */
#define ADC_CONV_CLK_9Tcy          0b00001000 /* A/D Conversion Clock is 9*Tcy */
#define ADC_CONV_CLK_10Tcy         0b00001001 /* A/D Conversion Clock is 10*Tcy */
#define ADC_CONV_CLK_11Tcy         0b00001010 /* A/D Conversion Clock is 11*Tcy */
#define ADC_CONV_CLK_12Tcy         0b00001011 /* A/D Conversion Clock is 12*Tcy */
#define ADC_CONV_CLK_13Tcy         0b00001100 /* A/D Conversion Clock is 13*Tcy */
#define ADC_CONV_CLK_14Tcy         0b00001101 /* A/D Conversion Clock is 14*Tcy */
#define ADC_CONV_CLK_15Tcy         0b00001110 /* A/D Conversion Clock is 15*Tcy */
#define ADC_CONV_CLK_16Tcy         0b00001111 /* A/D Conversion Clock is 16*Tcy */
#define ADC_CONV_CLK_17Tcy         0b00010000 /* A/D Conversion Clock is 17*Tcy */
#define ADC_CONV_CLK_18Tcy         0b00010001 /* A/D Conversion Clock is 18*Tcy */
#define ADC_CONV_CLK_19Tcy         0b00010010 /* A/D Conversion Clock is 19*Tcy */
#define ADC_CONV_CLK_20Tcy         0b00010011 /* A/D Conversion Clock is 20*Tcy */
#define ADC_CONV_CLK_21Tcy         0b00010100 /* A/D Conversion Clock is 21*Tcy */
#define ADC_CONV_CLK_22Tcy         0b00010101 /* A/D Conversion Clock is 22*Tcy */
#define ADC_CONV_CLK_23Tcy         0b00010110 /* A/D Conversion Clock is 23*Tcy */
#define ADC_CONV_CLK_24Tcy         0b00010111 /* A/D Conversion Clock is 24*Tcy */
#define ADC_CONV_CLK_25Tcy         0b00011000 /* A/D Conversion Clock is 25*Tcy */
#define ADC_CONV_CLK_26Tcy         0b00011001 /* A/D Conversion Clock is 26*Tcy */
#define ADC_CONV_CLK_27Tcy         0b00011010 /* A/D Conversion Clock is 27*Tcy */
#define ADC_CONV_CLK_28Tcy         0b00011011 /* A/D Conversion Clock is 28*Tcy */
#define ADC_CONV_CLK_29Tcy         0b00011100 /* A/D Conversion Clock is 29*Tcy */
#define ADC_CONV_CLK_30Tcy         0b00011101 /* A/D Conversion Clock is 40*Tcy */
#define ADC_CONV_CLK_31Tcy         0b00011110 /* A/D Conversion Clock is 31*Tcy */
#define ADC_CONV_CLK_32Tcy         0b00011111 /* A/D Conversion Clock is 32*Tcy */
#define ADC_CONV_CLK_33Tcy         0b00100000 /* A/D Conversion Clock is 33*Tcy */
#define ADC_CONV_CLK_34Tcy         0b00100001 /* A/D Conversion Clock is 34*Tcy */
#define ADC_CONV_CLK_35Tcy         0b00100010 /* A/D Conversion Clock is 35*Tcy */
#define ADC_CONV_CLK_36Tcy         0b00100011 /* A/D Conversion Clock is 36*Tcy */
#define ADC_CONV_CLK_37Tcy         0b00100100 /* A/D Conversion Clock is 37*Tcy */
#define ADC_CONV_CLK_38Tcy         0b00100101 /* A/D Conversion Clock is 38*Tcy */
#define ADC_CONV_CLK_39Tcy         0b00100110 /* A/D Conversion Clock is 39*Tcy */
#define ADC_CONV_CLK_40Tcy         0b00100111 /* A/D Conversion Clock is 40*Tcy */
#define ADC_CONV_CLK_41Tcy         0b00101000 /* A/D Conversion Clock is 41*Tcy */
#define ADC_CONV_CLK_42Tcy         0b00101001 /* A/D Conversion Clock is 42*Tcy */
#define ADC_CONV_CLK_43Tcy         0b00101010 /* A/D Conversion Clock is 43*Tcy */
#define ADC_CONV_CLK_44Tcy         0b00101011 /* A/D Conversion Clock is 44*Tcy */
#define ADC_CONV_CLK_45Tcy         0b00101100 /* A/D Conversion Clock is 45*Tcy */
#define ADC_CONV_CLK_46Tcy         0b00101101 /* A/D Conversion Clock is 46*Tcy */
#define ADC_CONV_CLK_47Tcy         0b00101110 /* A/D Conversion Clock is 47*Tcy */
#define ADC_CONV_CLK_48Tcy         0b00101111 /* A/D Conversion Clock is 48*Tcy */
#define ADC_CONV_CLK_49Tcy         0b00110000 /* A/D Conversion Clock is 49*Tcy */
#define ADC_CONV_CLK_50Tcy         0b00110001 /* A/D Conversion Clock is 50*Tcy */
#define ADC_CONV_CLK_51Tcy         0b00110010 /* A/D Conversion Clock is 51*Tcy */
#define ADC_CONV_CLK_52Tcy         0b00110011 /* A/D Conversion Clock is 52*Tcy */
#define ADC_CONV_CLK_53Tcy         0b00110100 /* A/D Conversion Clock is 53*Tcy */
#define ADC_CONV_CLK_54Tcy         0b00110101 /* A/D Conversion Clock is 54*Tcy */
#define ADC_CONV_CLK_55Tcy         0b00110110 /* A/D Conversion Clock is 55*Tcy */
#define ADC_CONV_CLK_56Tcy         0b00110111 /* A/D Conversion Clock is 56*Tcy */
#define ADC_CONV_CLK_57Tcy         0b00111000 /* A/D Conversion Clock is 57*Tcy */
#define ADC_CONV_CLK_58Tcy         0b00111001 /* A/D Conversion Clock is 58*Tcy */
#define ADC_CONV_CLK_59Tcy         0b00111010 /* A/D Conversion Clock is 59*Tcy */
#define ADC_CONV_CLK_60Tcy         0b00111011 /* A/D Conversion Clock is 60*Tcy */
#define ADC_CONV_CLK_61Tcy         0b00111100 /* A/D Conversion Clock is 61*Tcy */
#define ADC_CONV_CLK_62Tcy         0b00111101 /* A/D Conversion Clock is 62*Tcy */
#define ADC_CONV_CLK_63Tcy         0b00111110 /* A/D Conversion Clock is 63*Tcy */
#define ADC_CONV_CLK_64Tcy         0b00111111 /* A/D Conversion Clock is 64*Tcy */

/**** ADCON5H register definition ****/
#define ADC_AUTO_SCAN_ENABLE        0b11111111 /*Auto-Scan is enabled*/
#define ADC_AUTO_SCAN_DISABLE       0b01111111 /*Auto-Scan is disabled*/

#define ADC_LOW_POWER_ENABLE        0b11111111 /*Low power enabled after scan*/
#define ADC_LOW_POWER_DISABLE       0b10111111 /*Full power enabled after scan*/

#define ADC_CTMU_ENABLE             0b11111111 /*CTMU is enabled when the ADC is enabled and active*/
#define ADC_CTMU_DISABLE            0b11011111 /*CTMU is not enabled by the ADC*/

#define ADC_AUTO_INT_THRES_COMP    	0b11111111 /*Interrupt occurs after sampling is completed and valid compare has occured*/
#define ADC_AUTO_INT_COMP    		0b11111110/*Interrupt occurs after valid compare has occured*/
#define ADC_INT_THRES    			0b11111101 /*Interrupt occurs after sampling is completed*/
#define ADC_AUTO_SCAN	    		0b11111100 /*No Interrupt*/

/**** ADCON5L register definition ****/
#define ADC_WRITE_AUTO_COMPARE      0b11111010 /*conversion results not saved, but interrupts are generated when a valid match as defined by CM and ASINT bits occurs*/
#define ADC_WRITE_CONVERT_SAVE      0b11110111 /*conversion results saved to locations as determined by register bits when a match as defined by CM bits occurs*/
#define ADC_WRITE_LEGACY            0b11110011 /*conversion data saved to location determined by buffer register bits */

#define ADC_CMP_OUTSIDE_MODE        0b11111111 /*valid match occurs when conversion result is outside of the window*/
#define ADC_CMP_INSIDE_MODE         0b11111110 /*valid match occurs when conversion result is inside the window*/
#define ADC_CMP_GREATER_MODE        0b11111101 /*valid match occurs when result is greater than corresponding buffer register*/
#define ADC_CMP_LESS_MODE           0b11111100 /*valid match occurs when result is less than corresponding buffer register*/

/**** ADCHS0H register definition ****/
#define ADC_CH0_NEG_SAMPLEB_VREFN   0b00011111  /* CH0 negative input is VREF- */
#define ADC_CH0_NEG_SAMPLEB_AN1     0b01011111 /* CH0 negative input is AN1 */

#define ADC_CH0_POS_SAMPLEB_AN0     0b11100000 /* A/D CH0 pos i/p sel for SAMPLE B is AN0 */
#define ADC_CH0_POS_SAMPLEB_AN1     0b11100001 /* A/D CH0 pos i/p sel for SAMPLE B is AN1 */
#define ADC_CH0_POS_SAMPLEB_AN2     0b11100010 /* A/D CH0 pos i/p sel for SAMPLE B is AN2 */
#define ADC_CH0_POS_SAMPLEB_AN3     0b11100011 /* A/D CH0 pos i/p sel for SAMPLE B is AN3 */
#define ADC_CH0_POS_SAMPLEB_AN4     0b11100100 /* A/D CH0 pos i/p sel for SAMPLE B is AN4 */
#define ADC_CH0_POS_SAMPLEB_AN5     0b11100101 /* A/D CH0 pos i/p sel for SAMPLE B is AN5 */
#define ADC_CH0_POS_SAMPLEB_AN6     0b11100110 /* A/D CH0 pos i/p sel for SAMPLE B is AN6 */
#define ADC_CH0_POS_SAMPLEB_AN7     0b11100111 /* A/D CH0 pos i/p sel for SAMPLE B is AN7 */
#define ADC_CH0_POS_SAMPLEB_AN8     0b11101000 /* A/D CH0 pos i/p sel for SAMPLE B is AN8 */
#define ADC_CH0_POS_SAMPLEB_AN9     0b11101001 /* A/D CH0 pos i/p sel for SAMPLE B is AN9 */
#define ADC_CH0_POS_SAMPLEB_AN10    0b11101010 /* A/D CH0 pos i/p sel for SAMPLE B is AN9 */
#define ADC_CH0_POS_SAMPLEB_AN11    0b11101011 /* A/D CH0 pos i/p sel for SAMPLE B is AN11 */
#define ADC_CH0_POS_SAMPLEB_AN12    0b11101100 /* A/D CH0 pos i/p sel for SAMPLE B is AN12 */
#define ADC_CH0_POS_SAMPLEB_AN13    0b11101101 /* A/D CH0 pos i/p sel for SAMPLE B is AN13 */
#define ADC_CH0_POS_SAMPLEB_AN14    0b11101110 /* A/D CH0 pos i/p sel for SAMPLE B is AN14 */
#define ADC_CH0_POS_SAMPLEB_AN15    0b11101111 /* A/D CH0 pos i/p sel for SAMPLE B is AN15 */
#if	defined (ADC_V15_1)
#define ADC_CH0_POS_SAMPLEB_AN16    0b11110000  /* A/D CH0 pos i/p sel for SAMPLE B is AN16 */
#define ADC_CH0_POS_SAMPLEB_AN17    0b11110001 /* A/D CH0 pos i/p sel for SAMPLE B is AN17 */
#define ADC_CH0_POS_SAMPLEB_AN18    0b11110010 /* A/D CH0 pos i/p sel for SAMPLE B is AN18 */
#define ADC_CH0_POS_SAMPLEB_AN19    0b11110011 /* A/D CH0 pos i/p sel for SAMPLE B is AN19 */
#define ADC_CH0_POS_SAMPLEB_AN20    0b11110100 /* A/D CH0 pos i/p sel for SAMPLE B is AN20 */
#define ADC_CH0_POS_SAMPLEB_AN21    0b11110101 /* A/D CH0 pos i/p sel for SAMPLE B is AN21 */
#define ADC_CH0_POS_SAMPLEB_AN22    0b11110110 /* A/D CH0 pos i/p sel for SAMPLE B is AN22 */
#define ADC_CH0_POS_SAMPLEB_AN23    0b11110111 /* A/D CH0 pos i/p sel for SAMPLE B is AN23 */
#endif
#define ADC_CH0_POS_SAMPLEB_CTMU_TEMP   0b11111000 /* No Channel used; all input floating; used for CTMU Temperature Sensor input*/
#define ADC_CH0_POS_SAMPLEB_CTMU     	0b11111001 /* No Channel used; all input floating; used for CTMU*/
#define ADC_CH0_POS_SAMPLEB_VBGDIV6  0b11111010 /* A/D CH0 pos i/p sel for SAMPLE B is band gap divided-by-six-reference (VBG/6) */
#define ADC_CH0_POS_SAMPLEB_VBGDIV2  0b11111011 /* A/D CH0 pos i/p sel for SAMPLE B is band gap divided-by-two-reference (VBG/2) */
#define ADC_CH0_POS_SAMPLEB_VBG		 0b11111100 /* A/D CH0 pos i/p sel for SAMPLE B is band gap reference (VBG) */
#define ADC_CH0_POS_SAMPLEB_AVSS     0b11111101 /* A/D CH0 pos i/p sel for SAMPLE B is AVSS */
#define ADC_CH0_POS_SAMPLEB_AVDD     0b11111110 /* A/D CH0 pos i/p sel for SAMPLE B is AVDD */
#define ADC_CH0_POS_SAMPLEB_VBAT     0b11111111 /* A/D CH0 pos i/p sel for SAMPLE B is VBAT */

/**** ADCHS0L register definition ****/
#define ADC_CH0_NEG_SAMPLEA_VREFN   0b00011111  /* CH0 negative input is VREF- */
#define ADC_CH0_NEG_SAMPLEA_AN1     0b01011111 /* CH0 negative input is AN1 */

#define ADC_CH0_POS_SAMPLEA_AN0     0b11100000 /* A/D Chan 0 pos i/p sel for SAMPLE A is AN0 */
#define ADC_CH0_POS_SAMPLEA_AN1     0b11100001 /* A/D Chan 0 pos i/p sel for SAMPLE A is AN1 */
#define ADC_CH0_POS_SAMPLEA_AN2     0b11100010 /* A/D Chan 0 pos i/p sel for SAMPLE A is AN2 */
#define ADC_CH0_POS_SAMPLEA_AN3     0b11100011 /* A/D Chan 0 pos i/p sel for SAMPLE A is AN3 */
#define ADC_CH0_POS_SAMPLEA_AN4     0b11100100 /* A/D Chan 0 pos i/p sel for SAMPLE A is AN4 */
#define ADC_CH0_POS_SAMPLEA_AN5     0b11100101 /* A/D Chan 0 pos i/p sel for SAMPLE A is AN5 */
#define ADC_CH0_POS_SAMPLEA_AN6     0b11100110 /* A/D Chan 0 pos i/p sel for SAMPLE A is AN6 */
#define ADC_CH0_POS_SAMPLEA_AN7     0b11100111 /* A/D Chan 0 pos i/p sel for SAMPLE A is AN7 */
#define ADC_CH0_POS_SAMPLEA_AN8     0b11101000 /* A/D Chan 0 pos i/p sel for SAMPLE A is AN8 */
#define ADC_CH0_POS_SAMPLEA_AN9     0b11101001 /* A/D CH0 pos i/p sel for SAMPLE B is AN9 */
#define ADC_CH0_POS_SAMPLEA_AN10    0b11101010 /* A/D Chan 0 pos i/p sel for SAMPLE A is AN10 */
#define ADC_CH0_POS_SAMPLEA_AN11    0b11101011 /* A/D CH0 pos i/p sel for SAMPLE B is AN11 */
#define ADC_CH0_POS_SAMPLEA_AN12    0b11101100 /* A/D CH0 pos i/p sel for SAMPLE B is AN12 */
#define ADC_CH0_POS_SAMPLEA_AN13    0b11101101 /* A/D CH0 pos i/p sel for SAMPLE B is AN13 */
#define ADC_CH0_POS_SAMPLEA_AN14    0b11101110 /* A/D Chan 0 pos i/p sel for SAMPLE A is AN14 */
#define ADC_CH0_POS_SAMPLEA_AN15    0b11101111 /* A/D Chan 0 pos i/p sel for SAMPLE A is AN15 */
#if defined (ADC_V15_1) 
#define ADC_CH0_POS_SAMPLEA_AN16    0b11110000 /* A/D CH0 pos i/p sel for SAMPLE A is AN16 */
#define ADC_CH0_POS_SAMPLEA_AN17    0b11110001 /* A/D CH0 pos i/p sel for SAMPLE A is AN17 */
#define ADC_CH0_POS_SAMPLEA_AN18    0b11110010 /* A/D CH0 pos i/p sel for SAMPLE A is AN18 */
#define ADC_CH0_POS_SAMPLEA_AN19    0b11110011 /* A/D CH0 pos i/p sel for SAMPLE A is AN19 */
#define ADC_CH0_POS_SAMPLEA_AN20    0b11110100 /* A/D CH0 pos i/p sel for SAMPLE A is AN20 */
#define ADC_CH0_POS_SAMPLEA_AN21    0b11110101 /* A/D CH0 pos i/p sel for SAMPLE A is AN21 */
#define ADC_CH0_POS_SAMPLEA_AN22    0b11110110 /* A/D CH0 pos i/p sel for SAMPLE A is AN22 */
#define ADC_CH0_POS_SAMPLEA_AN23    0b11110111 /* A/D CH0 pos i/p sel for SAMPLE A is AN23 */
#endif
#define ADC_CH0_POS_SAMPLEA_CTMU_TEMP   0b11111000 /* No Channel used; all input floating; used for CTMU Temperature Sensor input*/
#define ADC_CH0_POS_SAMPLEA_CTMU     	0b11111001 /* No Channel used; all input floating; used for CTMU*/
#define ADC_CH0_POS_SAMPLEA_VBGDIV6  0b11111010 /* A/D CH0 pos i/p sel for SAMPLE B is band gap divided-by-six-reference (VBG/6) */
#define ADC_CH0_POS_SAMPLEA_VBGDIV2  0b11111011 /* A/D CH0 pos i/p sel for SAMPLE B is band gap divided-by-two-reference (VBG/2) */
#define ADC_CH0_POS_SAMPLEA_VBG		 0b11111100 /* A/D CH0 pos i/p sel for SAMPLE B is band gap reference (VBG) */
#define ADC_CH0_POS_SAMPLEA_AVSS     0b11111101 /* A/D CH0 pos i/p sel for SAMPLE A is AVSS */
#define ADC_CH0_POS_SAMPLEA_AVDD     0b11111110 /* A/D CH0 pos i/p sel for SAMPLE A is AVDD */
#define ADC_CH0_POS_SAMPLEA_VBAT     0b11111111 /* A/D CH0 pos i/p sel for SAMPLE A is VBAT */

/**** ADCSS0L control register definition ****/
#define ADC_SCAN_AN0      			0b11111111 /*Enable Input Scan AN0 */
#define ADC_SKIP_SCAN_AN0      		0b11111110 /* Disable Input Scan AN0 */
#define ADC_SCAN_AN1      			0b11111111 /*Enable Input Scan AN1 */
#define ADC_SKIP_SCAN_AN1      		0b11111101 /* Disable Input Scan AN1 */
#define ADC_SCAN_AN2      			0b11111111 /*Enable Input Scan AN2 */
#define ADC_SKIP_SCAN_AN2      		0b11111011 /* Disable Input Scan AN2 */
#define ADC_SCAN_AN3      			0b11111111 /*Enable Input Scan AN3 */
#define ADC_SKIP_SCAN_AN3      		0b11110111 /* Disable Input Scan AN3 */
#define ADC_SCAN_AN4      			0b11111111 /*Enable Input Scan AN4 */
#define ADC_SKIP_SCAN_AN4      		0b11101111 /* Disable Input Scan AN4 */
#define ADC_SCAN_AN5      			0b11111111 /*Enable Input Scan AN5 */
#define ADC_SKIP_SCAN_AN5      		0b11011111 /* Disable Input Scan AN5 */
#define ADC_SCAN_AN6      			0b11111111 /*Enable Input Scan AN6 */
#define ADC_SKIP_SCAN_AN6     		0b10111111 /* Disable Input Scan AN6 */
#define ADC_SCAN_AN7      			0b11111111 /*Enable Input Scan AN7 */
#define ADC_SKIP_SCAN_AN7      		0b01111111 /* Disable Input Scan AN7 */
#define ENABLE_ALL_INPUT_SCAN       0b11111111 /*Enable Input Scan AN0-AN15 */
#define DISABLE_ALL_INPUT_SCAN      0x00 /*Disable Input Scan AN0-AN15 */

/**** ADCSS0H control register definition ****/
#define ADC_SCAN_AN8      			0b11111111 /*Enable Input Scan AN8 */
#define ADC_SKIP_SCAN_AN8      		0b11111110 /* Disable Input Scan AN8 */
#define ADC_SCAN_AN9      		    0b11111111 /*Enable Input Scan AN9 */
#define ADC_SKIP_SCAN_AN9      		0b11111101 /* Disable Input Scan AN9 */
#define ADC_SCAN_AN10     			0b11111111 /*Enable Input Scan AN10 */
#define ADC_SKIP_SCAN_AN10     		0b11111011 /* Disable Input Scan AN10 */
#define ADC_SCAN_AN11     			0b11111111 /*Enable Input Scan AN11 */
#define ADC_SKIP_SCAN_AN11     		0b11110111 /* Disable Input Scan AN11 */
#define ADC_SCAN_AN12     			0b11111111 /*Enable Input Scan AN12 */
#define ADC_SKIP_SCAN_AN12          0b11101111 /* Disable Input Scan AN12 */
#define ADC_SCAN_AN13    			0b11111111 /*Enable Input Scan AN13 */
#define ADC_SKIP_SCAN_AN13     		0b11011111 /* Disable Input Scan AN13 */
#define ADC_SCAN_AN14    			0b11111111 /*Enable Input Scan AN14 */
#define ADC_SKIP_SCAN_AN14     		0b10111111 /* Disable Input Scan AN14 */
#define ADC_SCAN_AN15    			0b11111111 /*Enable Input Scan AN15 */
#define ADC_SKIP_SCAN_AN15     		0b01111111 /* Disable Input Scan AN15 */
#define ENABLE_ALL_INPUT_SCAN       0b11111111 /*Enable Input Scan AN0-AN15 */
#define DISABLE_ALL_INPUT_SCAN      0x00 /*Disable Input Scan AN0-AN15 */

/**** ADCSS1L register definition ****/
#define ADC_SCAN_AN16     			0b11111111 /*Enable Input Scan AN16 */
#define ADC_SKIP_SCAN_AN16    		0b11111110 /* Disable Input Scan AN16 */
#define ADC_SCAN_AN17     			0b11111111 /*Enable Input Scan AN17 */
#define ADC_SKIP_SCAN_AN17    		0b11111101 /* Disable Input Scan AN17 */
#define ADC_SCAN_AN18     			0b11111111 /*Enable Input Scan AN18 */
#define ADC_SKIP_SCAN_AN18    		0b11111011 /* Disable Input Scan AN18 */
#define ADC_SCAN_AN19     			0b11111111 /*Enable Input Scan AN19 */
#define ADC_SKIP_SCAN_AN19    		0b11110111 /* Disable Input Scan AN19 */
#define ADC_SCAN_AN20     			0b11111111 /*Enable Input Scan AN20 */
#define ADC_SKIP_SCAN_AN20   		0b11101111 /* Disable Input Scan AN20 */
#define ADC_SCAN_AN21     			0b11111111 /*Enable Input Scan AN21 */
#define ADC_SKIP_SCAN_AN21    		0b11011111 /* Disable Input Scan AN21 */
#define ADC_SCAN_AN22     			0b11111111 /*Enable Input Scan AN22 */
#define ADC_SKIP_SCAN_AN22    		0b10111111 /* Disable Input Scan AN22 */
#define ADC_SCAN_AN23     			0b11111111 /*Enable Input Scan AN23 */
#define ADC_SKIP_SCAN_AN23    		0b01111111 /* Disable Input Scan AN23 */
#define ENABLE_ALL_INPUT_SCAN       0b11111111 /*Enable Input Scan AN0-AN15 */
#define DISABLE_ALL_INPUT_SCAN      0x00 /*Disable Input Scan AN0-AN15 */

/**** ADCSS1H register definition ****/
#define ADC_SCAN_AN24     			0b11111111 /*Enable Input Scan AN24 */
#define ADC_SKIP_SCAN_AN24    		0b11111110 /* Disable Input Scan AN24 */
#define ADC_SCAN_AN25     			0b11111111 /*Enable Input Scan AN25 */
#define ADC_SKIP_SCAN_AN25    		0b11111101 /* Disable Input Scan AN25 */
#define ADC_SCAN_AN26     			0b11111111 /*Enable Input Scan AN26 */
#define ADC_SKIP_SCAN_AN26    		0b11111011 /* Disable Input Scan AN26 */
#define ADC_SCAN_AN27     			0b11111111 /*Enable Input Scan AN27 */
#define ADC_SKIP_SCAN_AN27    		0b11110111/* Disable Input Scan AN27 */
#define ADC_SCAN_AN28     			0b11111111 /*Enable Input Scan AN28 */
#define ADC_SKIP_SCAN_AN28    		0b11101111 /* Disable Input Scan AN28 */
#define ADC_SCAN_AN29     			0b11111111 /*Enable Input Scan AN29 */
#define ADC_SKIP_SCAN_AN29    		0b11011111/* Disable Input Scan AN29 */
#define ADC_SCAN_AN30     			0b11111111 /*Enable Input Scan AN30 */
#define ADC_SKIP_SCAN_AN30    		0b10111111/* Disable Input Scan AN30 */
#define ENABLE_ALL_INPUT_SCAN       0b11111111 /*Enable Input Scan AN0-AN15 */
#define DISABLE_ALL_INPUT_SCAN      0x00 /*Disable Input Scan AN0-AN15 */

/*****ADCTMUEN0L register definition***********/
#define ADC_CTMU_AN0     			0b11111111 /*CTMU enabled and connected to AN0 */
#define ADC_SKIP_CTMU_AN0    		0b11111110 /*CTMU not connected to AN0*/
#define ADC_CTMU_AN1     			0b11111111 /*CTMU enabled and connected to AN1 */
#define ADC_SKIP_CTMU_AN1    		0b11111101 /*CTMU not connected to AN1*/
#define ADC_CTMU_AN2     			0b11111111 /*CTMU enabled and connected to AN2*/
#define ADC_SKIP_CTMU_AN2    		0b11111011 /*CTMU not connected to AN2*/
#define ADC_CTMU_AN3     			0b11111111 /*CTMU enabled and connected to AN3 */
#define ADC_SKIP_CTMU_AN3    		0b11110111 /*CTMU not connected to AN3*/
#define ADC_CTMU_AN4     			0b11111111 /*CTMU enabled and connected to AN4*/
#define ADC_SKIP_CTMU_AN4    		0b11101111 /*CTMU not connected to AN4*/
#define ADC_CTMU_AN5     			0b11111111 /*CTMU enabled and connected to AN5 */
#define ADC_SKIP_CTMU_AN5    		0b11011111 /*CTMU not connected to AN5*/
#define ADC_CTMU_AN6     			0b11111111 /*CTMU enabled and connected to AN6*/
#define ADC_SKIP_CTMU_AN6    		0b10111111 /*CTMU not connected to AN6*/
#define ADC_CTMU_AN7     			0b11111111 /*CTMU enabled and connected to AN7 */
#define ADC_SKIP_CTMU_AN7    		0b01111111 /*CTMU not connected to AN7*/
#define ENABLE_ALL_INPUT_SCAN       0b11111111 /*Enable Input Scan AN0-AN15 */
#define DISABLE_ALL_INPUT_SCAN      0x00 /*Disable Input Scan AN0-AN15 */

/*****ADCTMUEN0H register definition***********/
#define ADC_CTMU_AN8     			0b11111111 /*CTMU enabled and connected to AN8 */
#define ADC_SKIP_CTMU_AN8    		0b11111110 /*CTMU not connected to AN8*/
#define ADC_CTMU_AN9     			0b11111111 /*CTMU enabled and connected to AN9*/
#define ADC_SKIP_CTMU_AN9    		0b11111101 /*CTMU not connected to AN9*/
#define ADC_CTMU_AN10     			0b11111111 /*CTMU enabled and connected to AN10*/
#define ADC_SKIP_CTMU_AN10    		0b11111011 /*CTMU not connected to AN10*/
#define ADC_CTMU_AN11     			0b11111111 /*CTMU enabled and connected to AN11*/
#define ADC_SKIP_CTMU_AN11    		0b11110111 /*CTMU not connected to AN11*/
#define ADC_CTMU_AN12     			0b11111111 /*CTMU enabled and connected to AN12*/
#define ADC_SKIP_CTMU_AN12    		0b11101111 /*CTMU not connected to AN12*/
#define ADC_CTMU_AN13     			0b11111111 /*CTMU enabled and connected to AN13*/
#define ADC_SKIP_CTMU_AN13    		0b11011111 /*CTMU not connected to AN13*/
#define ADC_CTMU_AN14     			0b11111111 /*CTMU enabled and connected to AN14*/
#define ADC_SKIP_CTMU_AN14    		0b10111111 /*CTMU not connected to AN14*/
#define ADC_CTMU_AN15     			0b11111111 /*CTMU enabled and connected to AN15*/
#define ADC_SKIP_CTMU_AN15    		0b01111111 /*CTMU not connected to AN15*/
#define ENABLE_ALL_INPUT_SCAN       0b11111111 /*Enable Input Scan AN0-AN15 */
#define DISABLE_ALL_INPUT_SCAN      0x00 /*Disable Input Scan AN0-AN15 */

/*****ADCTMUEN1L register definition***********/
#define ADC_CTMU_AN16     			0b11111111 /*CTMU enabled and connected to AN16 */
#define ADC_SKIP_CTMU_AN16    		0b11111110 /*CTMU not connected to AN16*/
#define ADC_CTMU_AN17     			0b11111111 /*CTMU enabled and connected to AN17 */
#define ADC_SKIP_CTMU_AN17    		0b11111101 /*CTMU not connected to AN17*/
#define ADC_CTMU_AN18     			0b11111111 /*CTMU enabled and connected to AN18 */
#define ADC_SKIP_CTMU_AN18    		0b11111011 /*CTMU not connected to AN18*/
#define ADC_CTMU_AN19     			0b11111111 /*CTMU enabled and connected to AN19 */
#define ADC_SKIP_CTMU_AN19    		0b11110111 /*CTMU not connected to AN19*/
#define ADC_CTMU_AN20     			0b11111111 /*CTMU enabled and connected to AN20 */
#define ADC_SKIP_CTMU_AN20    		0b11101111 /*CTMU not connected to AN20*/
#define ADC_CTMU_AN21     			0b11111111 /*CTMU enabled and connected to AN21 */
#define ADC_SKIP_CTMU_AN21    		0b11011111 /*CTMU not connected to AN21*/
#define ADC_CTMU_AN22     			0b11111111 /*CTMU enabled and connected to AN22 */
#define ADC_SKIP_CTMU_AN22    		0b10111111 /*CTMU not connected to AN22*/
#define ADC_CTMU_AN23    			0b11111111 /*CTMU enabled and connected to AN23 */
#define ADC_SKIP_CTMU_AN23   		0b01111111 /*CTMU not connected to AN23*/
#define ENABLE_ALL_INPUT_SCAN       0b11111111 /*Enable Input Scan AN0-AN15 */
#define DISABLE_ALL_INPUT_SCAN      0x00 /*Disable Input Scan AN0-AN15 */

/*****ADCTMUEN1H register definition***********/
#define ADC_CTMU_AN24    			0b11111111 /*CTMU enabled and connected to AN24 */
#define ADC_SKIP_CTMU_AN24   		0b11111110 /*CTMU not connected to AN24*/
#define ADC_CTMU_AN25    			0b11111111 /*CTMU enabled and connected to AN25 */
#define ADC_SKIP_CTMU_AN25   		0b11111101 /*CTMU not connected to AN25*/
#define ADC_CTMU_AN26     			0b11111111 /*CTMU enabled and connected to AN26 */
#define ADC_SKIP_CTMU_AN26    		0b11111011 /*CTMU not connected to AN26*/
#define ADC_CTMU_AN27     			0b11111111 /*CTMU enabled and connected to AN27 */
#define ADC_SKIP_CTMU_AN27    		0b11110111 /*CTMU not connected to AN27*/
#define ADC_CTMU_AN28     			0b11111111 /*CTMU enabled and connected to AN28 */
#define ADC_SKIP_CTMU_AN28    		0b11101111 /*CTMU not connected to AN28*/
#define ADC_CTMU_AN29     			0b11111111 /*CTMU enabled and connected to AN29 */
#define ADC_SKIP_CTMU_AN29    		0b11011111 /*CTMU not connected to AN29*/
#define ADC_CTMU_AN30     			0b11111111 /*CTMU enabled and connected to AN30 */
#define ADC_SKIP_CTMU_AN30    		0b10111111 /*CTMU not connected to AN30*/

#else

/***** ADCON1H register definition ****/
#define ADC_12BIT_MODE              0b00100000 /*12-bit A/D operation*/
#define ADC_10BIT_MODE              0b0000000 /*10-bit A/D operation*/
#define ADC_IDLE_MASK               (~ADC_IDLE_CONTINUE) /* A/D Idle mode mask */

#define ADC_FORMAT_SIGN_FRACT       0b00000011 /* A/D data format signed fractional */
#define ADC_FORMAT_FRACT            0b00000010 /* A/D data format fractional */
#define ADC_FORMAT_SIGN_INT         0b00000001 /* A/D data format signed integer */
#define ADC_FORMAT_INTG             0b00000000 /* A/D data format integer */
#define ADC_FORMAT_MASK             (~ADC_FORMAT_SIGN_FRACT)/* A/D format mask */

/***** ADCON1L register definition ****/
#define ADC_TRIG_AUTO              	0b01110000 /*The SAMP bit is cleared after SAMC<4:0> number of TAD clocks following 
                                           the SAMP bit being set.No Extended Sample Time is present.*/										   
#define ADC_TRIG_CTMU                0b01000000 /* CTMU event ends sampling and starts conversion */
#define ADC_TRIG_TMR_5                0b00110000 /* Timer5 compare ends sampling and starts conversion */
#define ADC_TRIG_TMR_3                0b00100000 /* Timer3 compare ends sampling and starts conversion */
#define ADC_TRIG_INT0                0b00010000 /* Active transition on INT0 ends sampling and starts conversion */
#define ADC_TRIG_TIMER1                0b01010000 /* Timer1 compare ends sampling and starts conversion */
#define ADC_TRIG_CLEAR           	0b00000000 /*The SAMP bit must be cleared by software*/
#define ADC_TRIG_MASK                (~ADC_TRIG_AUTO) /* A/D clock mask */

#define ADC_AUTO_SAMPLING_ON        0b00000100 /* Sampling begins immediately after last conversion */
#define ADC_AUTO_SAMPLING_OFF       0b00000000 /* Sampling begins when SAMP bit is set */
#define ADC_AUTO_SAMPLING_MASK      (~ADC_AUTO_SAMPLING_ON) /* A/D auto sampling mask */

#define ADC_SAMP_ON                 0b00000010 /* sample / hold amplifiers are sampling */
#define ADC_SAMP_OFF                0b00000000 /* sample / hold amplifiers are holding */
#define ADC_SAMP_MASK               (~ADC_SAMP_ON) /* A/D sampling mask */

/***** ADCON2H control register definition ****/
#define ADC_REF_VDD_VREFPLUS       0b01000000 /*Converter Positive Voltage Reference - External VREF+*/
#define ADC_REF_VDD_VDD            0b00000000 /*Converter Positive Voltage Reference - AVDD*/
#define ADC_REF_VDD_POS_MASK          (~ADC_REF_VDD_VREFPLUS)

#define ADC_REF_VDD_VREFMINUS      0b00100000 /*Converter Negative Voltage Reference - External VREF- */
#define ADC_REF_VDD_VSS          0b00000000 /*Converter Negative Voltage Reference - AVSS */
#define ADC_REF_VDD_NEG_MASK          (~ADC_REF_VDD_VREFMINUS)

#define ADC_BUF_REG_ENABLE          0b00001000 /* Conversion result is loaded into buffer location determined by the converted channel*/
#define ADC_BUF_REG_DISABLE         0b00000000 /* A/D result buffer is treated as a FIFO */
#define ADC_BUF_REG_MASK 			(~ADC_BUF_REG_ENABLE)

#define ADC_OFFSET_CAL_ON           0b00010000 /* Converts to get the Offset calibration value */
#define ADC_OFFSET_CAL_OFF          0b00000000 /* Coverts to get the actual input value */
#define ADC_OFFSET_CAL_MASK 		(~ADC_OFFSET_CAL_ON)	

#define ADC_SCAN_ON                 0b00000100 /* A/D Scan Input Selections for CH0 during SAMPLE A */
#define ADC_SCAN_OFF                0b00000000 /* A/D Do notScan Input Selections for CH0+ during SAMPLE A */
#define ADC_SCAN_ON_OFF_MASK        (~ADC_SCAN_ON)

/***** ADCON2L control register definition ****/
#define ADC_INTR_EACH_CONV          0b00000000 /* Interrupts at the completion of conversion of each sample */
#define ADC_INTR_2_CONV             0b00000100 /* Interrupts at the completion of conversion of 2 samples */
#define ADC_INTR_3_CONV             0b00001000/* Interrupts at the completion of conversion of 3 samples */
#define ADC_INTR_4_CONV             0b00001100 /* Interrupts at the completion of conversion of 4 samples */
#define ADC_INTR_5_CONV             0b00010000 /* Interrupts at the completion of conversion of 5 samples */
#define ADC_INTR_6_CONV             0b00010100 /* Interrupts at the completion of conversion of 6 samples */
#define ADC_INTR_7_CONV             0b00011000 /* Interrupts at the completion of conversion of 7 samples */
#define ADC_INTR_8_CONV             0b00011100 /* Interrupts at the completion of conversion of 8 samples */
#define ADC_INTR_9_CONV             0b00100000 /* Interrupts at the completion of conversion of 9 samples */
#define ADC_INTR_10_CONV            0b00100100 /* Interrupts at the completion of conversion of 10 samples */
#define ADC_INTR_11_CONV            0b00101000 /* Interrupts at the completion of conversion of 11 samples */
#define ADC_INTR_12_CONV            0b00101100 /* Interrupts at the completion of conversion of 12 samples */
#define ADC_INTR_13_CONV            0b00110000 /* Interrupts at the completion of conversion of 13 samples */
#define ADC_INTR_14_CONV            0b00110100 /* Interrupts at the completion of conversion of 14 samples */
#define ADC_INTR_15_CONV            0b00111000 /* Interrupts at the completion of conversion of 15 samples */
#define ADC_INTR_16_CONV            0b00111100 /* Interrupts at the completion of conversion of 16 samples */
#define ADC_INTR_17_CONV            0b01000000 /* Interrupts at the completion of conversion of 17 samples */
#define ADC_INTR_18_CONV            0b01000100 /* Interrupts at the completion of conversion of 18 samples */
#define ADC_INTR_19_CONV            0b01001000 /* Interrupts at the completion of conversion of 19 samples */
#define ADC_INTR_20_CONV            0b01001100 /* Interrupts at the completion of conversion of 20 samples */
#define ADC_INTR_21_CONV            0b01010000 /* Interrupts at the completion of conversion of 21 samples */
#define ADC_INTR_22_CONV            0b01010100 /* Interrupts at the completion of conversion of 22 samples */
#define ADC_INTR_23_CONV            0b01011000 /* Interrupts at the completion of conversion of 23 samples */
#define ADC_INTR_24_CONV            0b01011100 /* Interrupts at the completion of conversion of 24 samples */
#define ADC_INTR_25_CONV            0b01100000 /* Interrupts at the completion of conversion of 25 samples */
#define ADC_INTR_26_CONV            0b01100100 /* Interrupts at the completion of conversion of 26 samples */
#define ADC_INTR_27_CONV            0b01101000 /* Interrupts at the completion of conversion of 27 samples */
#define ADC_INTR_28_CONV            0b01101100 /* Interrupts at the completion of conversion of 28 samples */
#define ADC_INTR_29_CONV            0b01110000 /* Interrupts at the completion of conversion of 29 samples */
#define ADC_INTR_30_CONV            0b01110100 /* Interrupts at the completion of conversion of 30 samples */
#define ADC_INTR_31_CONV            0b01111000 /* Interrupts at the completion of conversion of 31 samples */
#define ADC_INTR_32_CONV            0b01111100 /* Interrupts at the completion of conversion of 32 samples */
#define ADC_INTR_MASK               (~ADC_INTR_32_CONV)

#define ADC_ALT_BUF_ON              0b00000010 /* Buffer configured as 2 8-word buffers */
#define ADC_ALT_BUF_OFF             0b00000000 /* Buffer configured as 1 16-word buffer */
#define ADC_ALT_BUF_MASK            (~ADC_ALT_BUF_ON)

#define ADC_ALT_INPUT_ON            0b00000001 /* alternate between MUXA and MUXB */
#define ADC_ALT_INPUT_OFF           0b00000000 /* use MUXA only */
#define ADC_ALT_MASK                (~ADC_ALT_INPUT_ON)

/**** ADCON3H register definition ****/
#define ADC_CONV_CLK_INTERNAL_RC    0b10000000 /* A/D Conversion Clock Source internal RC Clock */
#define ADC_CONV_CLK_SYSTEM         0b00000000 /* A/D Conversion Clock Source Clock derived from system clock */
#define ADC_CONV_CLK_SOURCE_MASK    (~ADC_CONV_CLK_INTERNAL_RC)

#define ADC_EXT_SAMP_ON             0b01000000 /*A/D is still sampling after SAMP = 0*/
#define ADC_EXT_SAMP_OFF            0b00000000 /*A/D is finished sampling*/
#define ADC_EXT_SAMP_MASK			(~ADC_EXT_SAMP_MASK)

#define ADC_CHARGE_PUMP_ENABLE      0b00100000 /*Charge pump for switches is enabled*/
#define ADC_CHARGE_PUMP_DISABLE     0b00000000 /*Charge pump for switches is enabled*/
#define ADC_CHARGE_PUMP_MASK 		(~ADC_CHARGE_PUMP_MASK)	

//************** A/D Acquisition Time Selection *******************************
#define ADC_0_TAD		            0b00000000 /* A/D Auto Sample Time 0 Tad */
#define ADC_1_TAD		            0b00000001 /* A/D Auto Sample Time 1 Tad */
#define ADC_2_TAD           		0b00000010 /* A/D Auto Sample Time 2 Tad */
#define ADC_3_TAD           		0b00000011 /* A/D Auto Sample Time 3 Tad */
#define ADC_4_TAD           		0b00000100 /* A/D Auto Sample Time 4 Tad */
#define ADC_5_TAD           		0b00000101 /* A/D Auto Sample Time 5 Tad */
#define ADC_6_TAD           		0b00000110 /* A/D Auto Sample Time 6 Tad */
#define ADC_7_TAD           		0b00000111 /* A/D Auto Sample Time 7 Tad */
#define ADC_8_TAD           		0b00001000 /* A/D Auto Sample Time 8 Tad */
#define ADC_9_TAD           		0b00001001 /* A/D Auto Sample Time 9 Tad */
#define ADC_10_TAD           		0b00001010 /* A/D Auto Sample Time 10 Tad */
#define ADC_11_TAD           		0b00001011 /* A/D Auto Sample Time 11 Tad */
#define ADC_12_TAD           		0b00001100 /* A/D Auto Sample Time 12 Tad */
#define ADC_13_TAD           		0b00001101 /* A/D Auto Sample Time 13 Tad */
#define ADC_14_TAD           		0b00001110 /* A/D Auto Sample Time 14 Tad */
#define ADC_15_TAD           		0b00001111 /* A/D Auto Sample Time 15 Tad */
#define ADC_16_TAD           		0b00010000 /* A/D Auto Sample Time 16 Tad */
#define ADC_17_TAD           		0b00010001 /* A/D Auto Sample Time 17 Tad */
#define ADC_18_TAD           		0b00010010 /* A/D Auto Sample Time 18 Tad */
#define ADC_19_TAD           		0b00010011 /* A/D Auto Sample Time 19 Tad */
#define ADC_20_TAD           		0b00010100 /* A/D Auto Sample Time 20 Tad */
#define ADC_21_TAD           		0b00010101 /* A/D Auto Sample Time 21 Tad */
#define ADC_22_TAD           		0b00010110 /* A/D Auto Sample Time 22 Tad */
#define ADC_23_TAD           		0b00010111 /* A/D Auto Sample Time 23 Tad */
#define ADC_24_TAD           		0b00011000 /* A/D Auto Sample Time 24 Tad */
#define ADC_25_TAD           		0b00011001 /* A/D Auto Sample Time 25 Tad */
#define ADC_26_TAD           		0b00011010 /* A/D Auto Sample Time 26 Tad */
#define ADC_27_TAD           		0b00011011 /* A/D Auto Sample Time 27 Tad */
#define ADC_28_TAD           		0b00011100 /* A/D Auto Sample Time 28 Tad */
#define ADC_29_TAD           		0b00011101 /* A/D Auto Sample Time 29 Tad */
#define ADC_30_TAD           		0b00011110 /* A/D Auto Sample Time 30 Tad */
#define ADC_31_TAD           		0b00011111 /* A/D Auto Sample Time 31 Tad */
#define ADC_TAD_MASK				(~ADC_31_TAD)

/**** ADCON3L register definition ****/
#define ADC_CONV_CLK_1Tcy          0b00000000 /* A/D Conversion Clock is Tcy */
#define ADC_CONV_CLK_2Tcy          0b00000001 /* A/D Conversion Clock is 2*Tcy */
#define ADC_CONV_CLK_3Tcy          0b00000010 /* A/D Conversion Clock is 3*Tcy */
#define ADC_CONV_CLK_4Tcy          0b00000011 /* A/D Conversion Clock is 4*Tcy */
#define ADC_CONV_CLK_5Tcy          0b00000100 /* A/D Conversion Clock is 5*Tcy */
#define ADC_CONV_CLK_6Tcy          0b00000101 /* A/D Conversion Clock is 6*Tcy */
#define ADC_CONV_CLK_7Tcy          0b00000110 /* A/D Conversion Clock is 7*Tcy */
#define ADC_CONV_CLK_8Tcy          0b00000111 /* A/D Conversion Clock is 8*Tcy */
#define ADC_CONV_CLK_9Tcy          0b00001000 /* A/D Conversion Clock is 9*Tcy */
#define ADC_CONV_CLK_10Tcy         0b00001001 /* A/D Conversion Clock is 10*Tcy */
#define ADC_CONV_CLK_11Tcy         0b00001010 /* A/D Conversion Clock is 11*Tcy */
#define ADC_CONV_CLK_12Tcy         0b00001011 /* A/D Conversion Clock is 12*Tcy */
#define ADC_CONV_CLK_13Tcy         0b00001100 /* A/D Conversion Clock is 13*Tcy */
#define ADC_CONV_CLK_14Tcy         0b00001101 /* A/D Conversion Clock is 14*Tcy */
#define ADC_CONV_CLK_15Tcy         0b00001110 /* A/D Conversion Clock is 15*Tcy */
#define ADC_CONV_CLK_16Tcy         0b00001111 /* A/D Conversion Clock is 16*Tcy */
#define ADC_CONV_CLK_17Tcy         0b00010000 /* A/D Conversion Clock is 17*Tcy */
#define ADC_CONV_CLK_18Tcy         0b00010001 /* A/D Conversion Clock is 18*Tcy */
#define ADC_CONV_CLK_19Tcy         0b00010010 /* A/D Conversion Clock is 19*Tcy */
#define ADC_CONV_CLK_20Tcy         0b00010011 /* A/D Conversion Clock is 20*Tcy */
#define ADC_CONV_CLK_21Tcy         0b00010100 /* A/D Conversion Clock is 21*Tcy */
#define ADC_CONV_CLK_22Tcy         0b00010101 /* A/D Conversion Clock is 22*Tcy */
#define ADC_CONV_CLK_23Tcy         0b00010110 /* A/D Conversion Clock is 23*Tcy */
#define ADC_CONV_CLK_24Tcy         0b00010111 /* A/D Conversion Clock is 24*Tcy */
#define ADC_CONV_CLK_25Tcy         0b00011000 /* A/D Conversion Clock is 25*Tcy */
#define ADC_CONV_CLK_26Tcy         0b00011001 /* A/D Conversion Clock is 26*Tcy */
#define ADC_CONV_CLK_27Tcy         0b00011010 /* A/D Conversion Clock is 27*Tcy */
#define ADC_CONV_CLK_28Tcy         0b00011011 /* A/D Conversion Clock is 28*Tcy */
#define ADC_CONV_CLK_29Tcy         0b00011100 /* A/D Conversion Clock is 29*Tcy */
#define ADC_CONV_CLK_30Tcy         0b00011101 /* A/D Conversion Clock is 40*Tcy */
#define ADC_CONV_CLK_31Tcy         0b00011110 /* A/D Conversion Clock is 31*Tcy */
#define ADC_CONV_CLK_32Tcy         0b00011111 /* A/D Conversion Clock is 32*Tcy */
#define ADC_CONV_CLK_33Tcy         0b00100000 /* A/D Conversion Clock is 33*Tcy */
#define ADC_CONV_CLK_34Tcy         0b00100001 /* A/D Conversion Clock is 34*Tcy */
#define ADC_CONV_CLK_35Tcy         0b00100010 /* A/D Conversion Clock is 35*Tcy */
#define ADC_CONV_CLK_36Tcy         0b00100011 /* A/D Conversion Clock is 36*Tcy */
#define ADC_CONV_CLK_37Tcy         0b00100100 /* A/D Conversion Clock is 37*Tcy */
#define ADC_CONV_CLK_38Tcy         0b00100101 /* A/D Conversion Clock is 38*Tcy */
#define ADC_CONV_CLK_39Tcy         0b00100110 /* A/D Conversion Clock is 39*Tcy */
#define ADC_CONV_CLK_40Tcy         0b00100111 /* A/D Conversion Clock is 40*Tcy */
#define ADC_CONV_CLK_41Tcy         0b00101000 /* A/D Conversion Clock is 41*Tcy */
#define ADC_CONV_CLK_42Tcy         0b00101001 /* A/D Conversion Clock is 42*Tcy */
#define ADC_CONV_CLK_43Tcy         0b00101010 /* A/D Conversion Clock is 43*Tcy */
#define ADC_CONV_CLK_44Tcy         0b00101011 /* A/D Conversion Clock is 44*Tcy */
#define ADC_CONV_CLK_45Tcy         0b00101100 /* A/D Conversion Clock is 45*Tcy */
#define ADC_CONV_CLK_46Tcy         0b00101101 /* A/D Conversion Clock is 46*Tcy */
#define ADC_CONV_CLK_47Tcy         0b00101110 /* A/D Conversion Clock is 47*Tcy */
#define ADC_CONV_CLK_48Tcy         0b00101111 /* A/D Conversion Clock is 48*Tcy */
#define ADC_CONV_CLK_49Tcy         0b00110000 /* A/D Conversion Clock is 49*Tcy */
#define ADC_CONV_CLK_50Tcy         0b00110001 /* A/D Conversion Clock is 50*Tcy */
#define ADC_CONV_CLK_51Tcy         0b00110010 /* A/D Conversion Clock is 51*Tcy */
#define ADC_CONV_CLK_52Tcy         0b00110011 /* A/D Conversion Clock is 52*Tcy */
#define ADC_CONV_CLK_53Tcy         0b00110100 /* A/D Conversion Clock is 53*Tcy */
#define ADC_CONV_CLK_54Tcy         0b00110101 /* A/D Conversion Clock is 54*Tcy */
#define ADC_CONV_CLK_55Tcy         0b00110110 /* A/D Conversion Clock is 55*Tcy */
#define ADC_CONV_CLK_56Tcy         0b00110111 /* A/D Conversion Clock is 56*Tcy */
#define ADC_CONV_CLK_57Tcy         0b00111000 /* A/D Conversion Clock is 57*Tcy */
#define ADC_CONV_CLK_58Tcy         0b00111001 /* A/D Conversion Clock is 58*Tcy */
#define ADC_CONV_CLK_59Tcy         0b00111010 /* A/D Conversion Clock is 59*Tcy */
#define ADC_CONV_CLK_60Tcy         0b00111011 /* A/D Conversion Clock is 60*Tcy */
#define ADC_CONV_CLK_61Tcy         0b00111100 /* A/D Conversion Clock is 61*Tcy */
#define ADC_CONV_CLK_62Tcy         0b00111101 /* A/D Conversion Clock is 62*Tcy */
#define ADC_CONV_CLK_63Tcy         0b00111110 /* A/D Conversion Clock is 63*Tcy */
#define ADC_CONV_CLK_64Tcy         0b00111111 /* A/D Conversion Clock is 64*Tcy */
#define ADC_CONV_CLK_MASK          (~ADC_CONV_CLK_64Tcy)

/**** ADCON5H register definition ****/
#define ADC_AUTO_SCAN_ENABLE        0b10000000 /*Auto-Scan is enabled*/
#define ADC_AUTO_SCAN_DISABLE       0b00000000 /*Auto-Scan is disabled*/
#define ADC_AUTO_SCAN_MASK          (~ADC_AUTO_SCAN_ENABLE)

#define ADC_LOW_POWER_ENABLE        0b01000000 /*Low power enabled after scan*/
#define ADC_LOW_POWER_DISABLE       0b00000000 /*Full power enabled after scan*/
#define ADC_LOW_POWER_MASK          (~ADC_LOW_POWER_ENABLE)

#define ADC_CTMU_ENABLE             0b00100000 /*CTMU is enabled when the ADC is enabled and active*/
#define ADC_CTMU_DISABLE            0b00000000 /*CTMU is not enabled by the ADC*/
#define ADC_CTMU_MASK               (~ADC_CTMU_ENABLE)

#define ADC_BG_ENABLE               0b00010000 /*Band gap is enabled when the ADC is enabled and active*/
#define ADC_BG_DISABLE              0b00000000 /*Band gap is not enabled by the ADC*/
#define ADC_BG_MASK                 (~ADC_BG_ENABLE)

#define ADC_AUTO_INT_THRES_COMP    	0b00000000 /*Interrupt occurs after sampling is completed and valid compare has occured*/
#define ADC_AUTO_INT_COMP    		0b00000001/*Interrupt occurs after valid compare has occured*/
#define ADC_INT_THRES    			0b00000010 /*Interrupt occurs after sampling is completed*/
#define ADC_AUTO_SCAN	    		0b00000011 /*No Interrupt*/
#define ADC_AUTO_INT_MASK           (~ADC_AUTO_INT_THRES_COMP)

/**** ADCON5L register definition ****/
#define ADC_WRITE_AUTO_COMPARE      0b00001000 /*conversion results not saved, but interrupts are generated when a valid match as defined by CM and ASINT bits occurs*/
#define ADC_WRITE_CONVERT_SAVE      0b00000100 /*conversion results saved to locations as determined by register bits when a match as defined by CM bits occurs*/
#define ADC_WRITE_LEGACY            0b00000000 /*conversion data saved to location determined by buffer register bits */
#define ADC_WRITE_MASK              (~ADC_WRITE_AUTO_COMPARE)

#define ADC_CMP_OUTSIDE_MODE        0b00000011 /*valid match occurs when conversion result is outside of the window*/
#define ADC_CMP_INSIDE_MODE         0b00000010 /*valid match occurs when conversion result is inside the window*/
#define ADC_CMP_GREATER_MODE        0b00000001 /*valid match occurs when result is greater than corresponding buffer register*/
#define ADC_CMP_LESS_MODE           0b00000000 /*valid match occurs when result is less than corresponding buffer register*/
#define ADC_CMP_MASK                (~ADC_CMP_OUTSIDE_MODE)

/**** ADCHS0H register definition ****/
#define ADC_CH0_NEG_SAMPLEB_VREFN   0b00000000  /* CH0 negative input is VREF- */
#define ADC_CH0_NEG_SAMPLEB_AN1     0b01000000 /* CH0 negative input is AN1 */
#define ADC_CH0_NEG_SAMPLEB_MASK    (~ADC_CH0_NEG_SAMPLEB_AN1)

#define ADC_CH0_POS_SAMPLEB_AN0     0b00000000 /* A/D CH0 pos i/p sel for SAMPLE B is AN0 */
#define ADC_CH0_POS_SAMPLEB_AN1     0b00000001 /* A/D CH0 pos i/p sel for SAMPLE B is AN1 */
#define ADC_CH0_POS_SAMPLEB_AN2     0b00000010 /* A/D CH0 pos i/p sel for SAMPLE B is AN2 */
#define ADC_CH0_POS_SAMPLEB_AN3     0b00000011 /* A/D CH0 pos i/p sel for SAMPLE B is AN3 */
#define ADC_CH0_POS_SAMPLEB_AN4     0b00000100 /* A/D CH0 pos i/p sel for SAMPLE B is AN4 */
#define ADC_CH0_POS_SAMPLEB_AN5     0b00000101 /* A/D CH0 pos i/p sel for SAMPLE B is AN5 */
#define ADC_CH0_POS_SAMPLEB_AN6     0b00000110 /* A/D CH0 pos i/p sel for SAMPLE B is AN6 */
#define ADC_CH0_POS_SAMPLEB_AN7     0b00000111 /* A/D CH0 pos i/p sel for SAMPLE B is AN7 */
#define ADC_CH0_POS_SAMPLEB_AN8     0b00001000 /* A/D CH0 pos i/p sel for SAMPLE B is AN8 */
#define ADC_CH0_POS_SAMPLEB_AN9     0b00001001 /* A/D CH0 pos i/p sel for SAMPLE B is AN9 */
#define ADC_CH0_POS_SAMPLEB_AN10    0b00001010 /* A/D CH0 pos i/p sel for SAMPLE B is AN9 */
#define ADC_CH0_POS_SAMPLEB_AN11    0b00001011 /* A/D CH0 pos i/p sel for SAMPLE B is AN11 */
#define ADC_CH0_POS_SAMPLEB_AN12    0b00001100 /* A/D CH0 pos i/p sel for SAMPLE B is AN12 */
#define ADC_CH0_POS_SAMPLEB_AN13    0b00001101 /* A/D CH0 pos i/p sel for SAMPLE B is AN13 */
#define ADC_CH0_POS_SAMPLEB_AN14    0b00001110 /* A/D CH0 pos i/p sel for SAMPLE B is AN14 */
#define ADC_CH0_POS_SAMPLEB_AN15   	0b00001111 /* A/D CH0 pos i/p sel for SAMPLE B is AN15 */
#if	defined (ADC_V15_1)
#define ADC_CH0_POS_SAMPLEB_AN16    0b00010000  /* A/D CH0 pos i/p sel for SAMPLE B is AN16 */
#define ADC_CH0_POS_SAMPLEB_AN17    0b00010001 /* A/D CH0 pos i/p sel for SAMPLE B is AN17 */
#define ADC_CH0_POS_SAMPLEB_AN18    0b00010010 /* A/D CH0 pos i/p sel for SAMPLE B is AN18 */
#define ADC_CH0_POS_SAMPLEB_AN19    0b00010011 /* A/D CH0 pos i/p sel for SAMPLE B is AN19 */
#define ADC_CH0_POS_SAMPLEB_AN20    0b00010100 /* A/D CH0 pos i/p sel for SAMPLE B is AN20 */
#define ADC_CH0_POS_SAMPLEB_AN21    0b00010101 /* A/D CH0 pos i/p sel for SAMPLE B is AN21 */
#define ADC_CH0_POS_SAMPLEB_AN22    0b00010110 /* A/D CH0 pos i/p sel for SAMPLE B is AN22 */
#define ADC_CH0_POS_SAMPLEB_AN23    0b00010111 /* A/D CH0 pos i/p sel for SAMPLE B is AN23 */
#endif
#define ADC_CH0_POS_SAMPLEB_CTMU_TEMP   0b00011000 /* No Channel used; all input floating; used for CTMU Temperature Sensor input*/
#define ADC_CH0_POS_SAMPLEB_CTMU     	0b00011001 /* No Channel used; all input floating; used for CTMU*/
#define ADC_CH0_POS_SAMPLEB_VBGDIV6  0b00011010 /* A/D CH0 pos i/p sel for SAMPLE B is band gap divided-by-six-reference (VBG/6) */
#define ADC_CH0_POS_SAMPLEB_VBGDIV2  0b00011011 /* A/D CH0 pos i/p sel for SAMPLE B is band gap divided-by-two-reference (VBG/2) */
#define ADC_CH0_POS_SAMPLEB_VBG		 0b00011100 /* A/D CH0 pos i/p sel for SAMPLE B is band gap reference (VBG) */
#define ADC_CH0_POS_SAMPLEB_AVSS     0b00011101 /* A/D CH0 pos i/p sel for SAMPLE B is AVSS */
#define ADC_CH0_POS_SAMPLEB_AVDD     0b00011110 /* A/D CH0 pos i/p sel for SAMPLE B is AVDD */
#define ADC_CH0_POS_SAMPLEB_VBAT     0b00011111 /* A/D CH0 pos i/p sel for SAMPLE B is VBAT */
#define ADC_CH0_POS_SAMPLEB_MASK    (~ADC_CH0_POS_SAMPLEB_VBAT)

/**** ADCHS0L register definition ****/
#define ADC_CH0_NEG_SAMPLEA_VREFN   0b00000000  /* CH0 negative input is VREF- */
#define ADC_CH0_NEG_SAMPLEA_AN1     0b01000000 /* CH0 negative input is AN1 */
#define ADC_CH0_NEG_SAMPLEA_MASK    (~ADC_CH0_NEG_SAMPLEA_AN1)

#define ADC_CH0_POS_SAMPLEA_AN0     0b00000000 /* A/D Chan 0 pos i/p sel for SAMPLE A is AN0 */
#define ADC_CH0_POS_SAMPLEA_AN1     0b00000001 /* A/D Chan 0 pos i/p sel for SAMPLE A is AN1 */
#define ADC_CH0_POS_SAMPLEA_AN2     0b00000010 /* A/D Chan 0 pos i/p sel for SAMPLE A is AN2 */
#define ADC_CH0_POS_SAMPLEA_AN3     0b00000011 /* A/D Chan 0 pos i/p sel for SAMPLE A is AN3 */
#define ADC_CH0_POS_SAMPLEA_AN4     0b00000100 /* A/D Chan 0 pos i/p sel for SAMPLE A is AN4 */
#define ADC_CH0_POS_SAMPLEA_AN5     0b00000101 /* A/D Chan 0 pos i/p sel for SAMPLE A is AN5 */
#define ADC_CH0_POS_SAMPLEA_AN6     0b00000110 /* A/D Chan 0 pos i/p sel for SAMPLE A is AN6 */
#define ADC_CH0_POS_SAMPLEA_AN7     0b00000111 /* A/D Chan 0 pos i/p sel for SAMPLE A is AN7 */
#define ADC_CH0_POS_SAMPLEA_AN8     0b00001000 /* A/D Chan 0 pos i/p sel for SAMPLE A is AN8 */
#define ADC_CH0_POS_SAMPLEA_AN9     0b00001001 /* A/D CH0 pos i/p sel for SAMPLE B is AN9 */
#define ADC_CH0_POS_SAMPLEA_AN10    0b00001010 /* A/D Chan 0 pos i/p sel for SAMPLE A is AN10 */
#define ADC_CH0_POS_SAMPLEA_AN11    0b00001011 /* A/D CH0 pos i/p sel for SAMPLE B is AN11 */
#define ADC_CH0_POS_SAMPLEA_AN12    0b00001100 /* A/D CH0 pos i/p sel for SAMPLE B is AN12 */
#define ADC_CH0_POS_SAMPLEA_AN13    0b00001101 /* A/D CH0 pos i/p sel for SAMPLE B is AN13 */
#define ADC_CH0_POS_SAMPLEA_AN14    0b00001110 /* A/D Chan 0 pos i/p sel for SAMPLE A is AN14 */
#define ADC_CH0_POS_SAMPLEA_AN15    0b00001111 /* A/D Chan 0 pos i/p sel for SAMPLE A is AN15 */
#if defined (ADC_V15_1) 
#define ADC_CH0_POS_SAMPLEA_AN16    0b00010000 /* A/D CH0 pos i/p sel for SAMPLE A is AN16 */
#define ADC_CH0_POS_SAMPLEA_AN17    0b00010001 /* A/D CH0 pos i/p sel for SAMPLE A is AN17 */
#define ADC_CH0_POS_SAMPLEA_AN18    0b00010010 /* A/D CH0 pos i/p sel for SAMPLE A is AN18 */
#define ADC_CH0_POS_SAMPLEA_AN19    0b00010011 /* A/D CH0 pos i/p sel for SAMPLE A is AN19 */
#define ADC_CH0_POS_SAMPLEA_AN20    0b00010100 /* A/D CH0 pos i/p sel for SAMPLE A is AN20 */
#define ADC_CH0_POS_SAMPLEA_AN21    0b00010101 /* A/D CH0 pos i/p sel for SAMPLE A is AN21 */
#define ADC_CH0_POS_SAMPLEA_AN22    0b00010110 /* A/D CH0 pos i/p sel for SAMPLE A is AN22 */
#define ADC_CH0_POS_SAMPLEA_AN23    0b00010111 /* A/D CH0 pos i/p sel for SAMPLE A is AN23 */
#endif
#define ADC_CH0_POS_SAMPLEA_CTMU_TEMP   0b00011000 /* No Channel used; all input floating; used for CTMU Temperature Sensor input*/
#define ADC_CH0_POS_SAMPLEA_CTMU     	0b00011001 /* No Channel used; all input floating; used for CTMU*/
#define ADC_CH0_POS_SAMPLEA_VBGDIV6  0b00011010 /* A/D CH0 pos i/p sel for SAMPLE B is band gap divided-by-six-reference (VBG/6) */
#define ADC_CH0_POS_SAMPLEA_VBGDIV2  0b00011011 /* A/D CH0 pos i/p sel for SAMPLE B is band gap divided-by-two-reference (VBG/2) */
#define ADC_CH0_POS_SAMPLEA_VBG		 0b00011100 /* A/D CH0 pos i/p sel for SAMPLE B is band gap reference (VBG) */
#define ADC_CH0_POS_SAMPLEA_AVSS     0b00011101 /* A/D CH0 pos i/p sel for SAMPLE A is AVSS */
#define ADC_CH0_POS_SAMPLEA_AVDD     0b00011110 /* A/D CH0 pos i/p sel for SAMPLE A is AVDD */
#define ADC_CH0_POS_SAMPLEA_VBAT     0b00011111 /* A/D CH0 pos i/p sel for SAMPLE A is VBAT */
#define ADC_CH0_POS_SAMPLEA_MASK    (~ADC_CH0_POS_SAMPLEA_VBAT )

/**** ADCSS0L control register definition ****/
#define ADC_SCAN_AN0      			0b00000001 /*Enable Input Scan AN0 */
#define ADC_SKIP_SCAN_AN0      		0b00000000 /* Disable Input Scan AN0 */
#define ADC_SCAN_AN1      			0b00000010 /*Enable Input Scan AN1 */
#define ADC_SKIP_SCAN_AN1      		0b00000000 /* Disable Input Scan AN1 */
#define ADC_SCAN_AN2      			0b00000100 /*Enable Input Scan AN2 */
#define ADC_SKIP_SCAN_AN2      		0b00000000 /* Disable Input Scan AN2 */
#define ADC_SCAN_AN3      			0b00001000 /*Enable Input Scan AN3 */
#define ADC_SKIP_SCAN_AN3      		0b00000000 /* Disable Input Scan AN3 */
#define ADC_SCAN_AN4      			0b00010000 /*Enable Input Scan AN4 */
#define ADC_SKIP_SCAN_AN4      		0b00000000 /* Disable Input Scan AN4 */
#define ADC_SCAN_AN5      			0b00100000 /*Enable Input Scan AN5 */
#define ADC_SKIP_SCAN_AN5      		0b00000000 /* Disable Input Scan AN5 */
#define ADC_SCAN_AN6      			0b01000000 /*Enable Input Scan AN6 */
#define ADC_SKIP_SCAN_AN6     		0b00000000 /* Disable Input Scan AN6 */
#define ADC_SCAN_AN7      			0b10000000 /*Enable Input Scan AN7 */
#define ADC_SKIP_SCAN_AN7      		0b00000000 /* Disable Input Scan AN7 */
#define ENABLE_ALL_INPUT_SCAN       0b11111111 /*Enable Input Scan AN0-AN15 */
#define DISABLE_ALL_INPUT_SCAN      0b00000000 /*Disable Input Scan AN0-AN15 */

/**** ADCSS0H control register definition ****/
#define ADC_SCAN_AN8      			0b00000001 /*Enable Input Scan AN8 */
#define ADC_SKIP_SCAN_AN8      		0b00000000 /* Disable Input Scan AN8 */
#define ADC_SCAN_AN9      		    0b00000010 /*Enable Input Scan AN9 */
#define ADC_SKIP_SCAN_AN9      		0b00000000 /* Disable Input Scan AN9 */
#define ADC_SCAN_AN10     			0b00000100 /*Enable Input Scan AN10 */
#define ADC_SKIP_SCAN_AN10     		0b00000000 /* Disable Input Scan AN10 */
#define ADC_SCAN_AN11     			0b00001000 /*Enable Input Scan AN11 */
#define ADC_SKIP_SCAN_AN11     		0b00000000 /* Disable Input Scan AN11 */
#define ADC_SCAN_AN12     			0b00010000 /*Enable Input Scan AN12 */
#define ADC_SKIP_SCAN_AN12          0b00000000 /* Disable Input Scan AN12 */
#define ADC_SCAN_AN13    			0b00100000 /*Enable Input Scan AN13 */
#define ADC_SKIP_SCAN_AN13     		0b00000000 /* Disable Input Scan AN13 */
#define ADC_SCAN_AN14    			0b01000000 /*Enable Input Scan AN14 */
#define ADC_SKIP_SCAN_AN14     		0b00000000 /* Disable Input Scan AN14 */
#define ADC_SCAN_AN15    			0b10000000 /*Enable Input Scan AN15 */
#define ADC_SKIP_SCAN_AN15     		0b00000000 /* Disable Input Scan AN15 */
#define ENABLE_ALL_INPUT_SCAN       0b11111111 /*Enable Input Scan AN0-AN15 */
#define DISABLE_ALL_INPUT_SCAN      0b00000000 /*Disable Input Scan AN0-AN15 */

/**** ADCSS1L register definition ****/
#define ADC_SCAN_AN16     			0b00000001 /*Enable Input Scan AN16 */
#define ADC_SKIP_SCAN_AN16    		0b00000000 /* Disable Input Scan AN16 */
#define ADC_SCAN_AN17     			0b00000010 /*Enable Input Scan AN17 */
#define ADC_SKIP_SCAN_AN17    		0b00000000 /* Disable Input Scan AN17 */
#define ADC_SCAN_AN18     			0b00000100 /*Enable Input Scan AN18 */
#define ADC_SKIP_SCAN_AN18    		0b00000000 /* Disable Input Scan AN18 */
#define ADC_SCAN_AN19     			0b00001000 /*Enable Input Scan AN19 */
#define ADC_SKIP_SCAN_AN19    		0b00000000 /* Disable Input Scan AN19 */
#define ADC_SCAN_AN20     			0b00010000 /*Enable Input Scan AN20 */
#define ADC_SKIP_SCAN_AN20   		0b00000000 /* Disable Input Scan AN20 */
#define ADC_SCAN_AN21     			0b00100000 /*Enable Input Scan AN21 */
#define ADC_SKIP_SCAN_AN21    		0b00000000 /* Disable Input Scan AN21 */
#define ADC_SCAN_AN22     			0b01000000 /*Enable Input Scan AN22 */
#define ADC_SKIP_SCAN_AN22    		0b00000000 /* Disable Input Scan AN22 */
#define ADC_SCAN_AN23     			0b10000000 /*Enable Input Scan AN23 */
#define ADC_SKIP_SCAN_AN23    		0b00000000 /* Disable Input Scan AN23 */
#define ENABLE_ALL_INPUT_SCAN       0b11111111 /*Enable Input Scan AN0-AN15 */
#define DISABLE_ALL_INPUT_SCAN      0b00000000 /*Disable Input Scan AN0-AN15 */

/**** ADCSS1H register definition ****/
#define ADC_SCAN_AN24     			0b00000001 /*Enable Input Scan AN24 */
#define ADC_SKIP_SCAN_AN24    		0b00000000 /* Disable Input Scan AN24 */
#define ADC_SCAN_AN25     			0b00000010 /*Enable Input Scan AN25 */
#define ADC_SKIP_SCAN_AN25    		0b00000000 /* Disable Input Scan AN25 */
#define ADC_SCAN_AN26     			0b00000100 /*Enable Input Scan AN26 */
#define ADC_SKIP_SCAN_AN26    		0b00000000 /* Disable Input Scan AN26 */
#define ADC_SCAN_AN27     			0b00001000 /*Enable Input Scan AN27 */
#define ADC_SKIP_SCAN_AN27    		0b00000000/* Disable Input Scan AN27 */
#define ADC_SCAN_AN28     			0b00010000 /*Enable Input Scan AN28 */
#define ADC_SKIP_SCAN_AN28    		0b00000000 /* Disable Input Scan AN28 */
#define ADC_SCAN_AN29     			0b00100000 /*Enable Input Scan AN29 */
#define ADC_SKIP_SCAN_AN29    		0b00000000/* Disable Input Scan AN29 */
#define ADC_SCAN_AN30     			0b01000000 /*Enable Input Scan AN30 */
#define ADC_SKIP_SCAN_AN30    		0b00000000/* Disable Input Scan AN30 */
#define ENABLE_ALL_INPUT_SCAN       0b11111111 /*Enable Input Scan AN0-AN15 */
#define DISABLE_ALL_INPUT_SCAN      0b00000000 /*Disable Input Scan AN0-AN15 */

/*****ADCTMUEN0L register definition***********/
#define ADC_CTMU_AN0     			0b00000001 /*CTMU enabled and connected to AN0 */
#define ADC_SKIP_CTMU_AN0    		0b00000000 /*CTMU not connected to AN0*/
#define ADC_CTMU_AN1     			0b00000010 /*CTMU enabled and connected to AN1 */
#define ADC_SKIP_CTMU_AN1    		0b00000000 /*CTMU not connected to AN1*/
#define ADC_CTMU_AN2     			0b00000100 /*CTMU enabled and connected to AN2*/
#define ADC_SKIP_CTMU_AN2    		0b00000000 /*CTMU not connected to AN2*/
#define ADC_CTMU_AN3     			0b00001000 /*CTMU enabled and connected to AN3 */
#define ADC_SKIP_CTMU_AN3    		0b00000000 /*CTMU not connected to AN3*/
#define ADC_CTMU_AN4     			0b00010000 /*CTMU enabled and connected to AN4*/
#define ADC_SKIP_CTMU_AN4    		0b00000000 /*CTMU not connected to AN4*/
#define ADC_CTMU_AN5     			0b00100000 /*CTMU enabled and connected to AN5 */
#define ADC_SKIP_CTMU_AN5    		0b00000000 /*CTMU not connected to AN5*/
#define ADC_CTMU_AN6     			0b01000000 /*CTMU enabled and connected to AN6*/
#define ADC_SKIP_CTMU_AN6    		0b00000000 /*CTMU not connected to AN6*/
#define ADC_CTMU_AN7     			0b10000000 /*CTMU enabled and connected to AN7 */
#define ADC_SKIP_CTMU_AN7    		0b00000000 /*CTMU not connected to AN7*/

/*****ADCTMUEN0H register definition***********/
#define ADC_CTMU_AN8     			0b00000001 /*CTMU enabled and connected to AN8 */
#define ADC_SKIP_CTMU_AN8    		0b00000000 /*CTMU not connected to AN8*/
#define ADC_CTMU_AN9     			0b00000010 /*CTMU enabled and connected to AN9*/
#define ADC_SKIP_CTMU_AN9    		0b00000000 /*CTMU not connected to AN9*/
#define ADC_CTMU_AN10     			0b00000100 /*CTMU enabled and connected to AN10*/
#define ADC_SKIP_CTMU_AN10    		0b00000000 /*CTMU not connected to AN10*/
#define ADC_CTMU_AN11     			0b00001000 /*CTMU enabled and connected to AN11*/
#define ADC_SKIP_CTMU_AN11    		0b00000000 /*CTMU not connected to AN11*/
#define ADC_CTMU_AN12     			0b00010000 /*CTMU enabled and connected to AN12*/
#define ADC_SKIP_CTMU_AN12    		0b00000000 /*CTMU not connected to AN12*/
#define ADC_CTMU_AN13     			0b00100000 /*CTMU enabled and connected to AN13*/
#define ADC_SKIP_CTMU_AN13    		0b00000000 /*CTMU not connected to AN13*/
#define ADC_CTMU_AN14     			0b01000000 /*CTMU enabled and connected to AN14*/
#define ADC_SKIP_CTMU_AN14    		0b00000000 /*CTMU not connected to AN14*/
#define ADC_CTMU_AN15     			0b10000000 /*CTMU enabled and connected to AN15*/
#define ADC_SKIP_CTMU_AN15    		0b00000000 /*CTMU not connected to AN15*/

/*****ADCTMUEN1L register definition***********/
#define ADC_CTMU_AN16     			0b00000001 /*CTMU enabled and connected to AN16 */
#define ADC_SKIP_CTMU_AN16    		0b00000000 /*CTMU not connected to AN16*/
#define ADC_CTMU_AN17     			0b00000010 /*CTMU enabled and connected to AN17 */
#define ADC_SKIP_CTMU_AN17    		0b00000000 /*CTMU not connected to AN17*/
#define ADC_CTMU_AN18     			0b00000100 /*CTMU enabled and connected to AN18 */
#define ADC_SKIP_CTMU_AN18    		0b00000000 /*CTMU not connected to AN18*/
#define ADC_CTMU_AN19     			0b00001000 /*CTMU enabled and connected to AN19 */
#define ADC_SKIP_CTMU_AN19    		0b00000000 /*CTMU not connected to AN19*/
#define ADC_CTMU_AN20     			0b00010000 /*CTMU enabled and connected to AN20 */
#define ADC_SKIP_CTMU_AN20    		0b00000000 /*CTMU not connected to AN20*/
#define ADC_CTMU_AN21     			0b00100000 /*CTMU enabled and connected to AN21 */
#define ADC_SKIP_CTMU_AN21    		0b00000000 /*CTMU not connected to AN21*/
#define ADC_CTMU_AN22     			0b01000000  /*CTMU enabled and connected to AN22 */
#define ADC_SKIP_CTMU_AN22    		0b00000000 /*CTMU not connected to AN22*/
#define ADC_CTMU_AN23    			0b10000000 /*CTMU enabled and connected to AN23 */
#define ADC_SKIP_CTMU_AN23   		0b00000000 /*CTMU not connected to AN23*/

/*****ADCTMUEN1H register definition***********/
#define ADC_CTMU_AN24    			0b00000001 /*CTMU enabled and connected to AN24 */
#define ADC_SKIP_CTMU_AN24   		0b00000000 /*CTMU not connected to AN24*/
#define ADC_CTMU_AN25    			0b00000010 /*CTMU enabled and connected to AN25 */
#define ADC_SKIP_CTMU_AN25   		0b00000000 /*CTMU not connected to AN25*/
#define ADC_CTMU_AN26     			0b00000100 /*CTMU enabled and connected to AN26 */
#define ADC_SKIP_CTMU_AN26    		0b00000000 /*CTMU not connected to AN26*/
#define ADC_CTMU_AN27     			0b00001000 /*CTMU enabled and connected to AN27 */
#define ADC_SKIP_CTMU_AN27    		0b00000000 /*CTMU not connected to AN27*/
#define ADC_CTMU_AN28     			0b00010000 /*CTMU enabled and connected to AN28 */
#define ADC_SKIP_CTMU_AN28    		0b00000000 /*CTMU not connected to AN28*/
#define ADC_CTMU_AN29     			0b00100000 /*CTMU enabled and connected to AN29 */
#define ADC_SKIP_CTMU_AN29    		0b00000000 /*CTMU not connected to AN29*/
#define ADC_CTMU_AN30     			0b01000000 /*CTMU enabled and connected to AN30 */
#define ADC_SKIP_CTMU_AN30    		0b00000000 /*CTMU not connected to AN30*/
#endif

/*ADC Port Configuration register definition*/
#define ENABLE_AN0_DIG()              ANCON1bits.ANSEL0=1 /*Enable AN0 in digital mode */
#define ENABLE_AN0_ANA()              ANCON1bits.ANSEL0=0 /*Enable AN0 in analog mode */
#define ENABLE_AN1_DIG()              ANCON1bits.ANSEL1=1 /*Enable AN1 in digital mode */
#define ENABLE_AN1_ANA()              ANCON1bits.ANSEL1=0 /*Enable AN1 in analog mode */
#define ENABLE_AN2_DIG()              ANCON1bits.ANSEL2=1 /*Enable AN2 in digital mode */
#define ENABLE_AN2_ANA()              ANCON1bits.ANSEL2=0 /*Enable AN2 in analog mode */
#define ENABLE_AN3_DIG()              ANCON1bits.ANSEL3=1 /*Enable AN3 in digital mode */
#define ENABLE_AN3_ANA()              ANCON1bits.ANSEL3=0 /*Enable AN3 in analog mode */
#define ENABLE_AN4_DIG()              ANCON1bits.ANSEL4=1 /*Enable AN4 in digital mode */
#define ENABLE_AN4_ANA()              ANCON1bits.ANSEL4=0 /*Enable AN4 in analog mode */
#define ENABLE_AN5_DIG()              ANCON1bits.ANSEL5=1 /*Enable AN5 in digital mode */
#define ENABLE_AN5_ANA()              ANCON1bits.ANSEL5=0 /*Enable AN5 in analog mode */
#define ENABLE_AN6_DIG()              ANCON1bits.ANSEL6=1 /*Enable AN6 in digital mode */
#define ENABLE_AN6_ANA()              ANCON1bits.ANSEL6=0 /*Enable AN6 in analog mode */
#define ENABLE_AN7_DIG()              ANCON1bits.ANSEL7=1 /*Enable AN7 in digital mode */
#define ENABLE_AN7_ANA()              ANCON1bits.ANSEL7=0 /*Enable AN7 in analog mode */
#define ENABLE_ALL_ANA_0_7()          ANCON1=0x00 /*Enable AN0-AN7 in analog mode */
#define ENABLE_ALL_DIG_0_7()          ANCON1=0xFF /*Enable AN0-AN7 in Digital mode */

#define ENABLE_AN8_DIG()              ANCON1bits.ANSEL8=1 /*Enable AN8 in digital mode */
#define ENABLE_AN8_ANA()              ANCON1bits.ANSEL8=0 /*Enable AN8 in analog mode */
#define ENABLE_AN9_DIG()              ANCON1bits.ANSEL9=1 /*Enable AN9 in digital mode */
#define ENABLE_AN9_ANA()              ANCON1bits.ANSEL9=0 /*Enable AN9 in analog mode */
#define ENABLE_AN10_DIG()             ANCON1bits.ANSEL10=1 /*Enable AN10 in digital mode */
#define ENABLE_AN10_ANA()             ANCON1bits.ANSEL10=0 /*Enable AN10 in analog mode */
#define ENABLE_AN11_DIG()             ANCON1bits.ANSEL11=1 /*Enable AN11 in digital mode */
#define ENABLE_AN11_ANA()             ANCON1bits.ANSEL11=0 /*Enable AN11 in analog mode */
#define ENABLE_AN12_DIG()             ANCON1bits.ANSEL12=1 /*Enable AN12 in digital mode */
#define ENABLE_AN12_ANA()             ANCON1bits.ANSEL12=0 /*Enable AN12 in analog mode */
#define ENABLE_AN13_DIG()             ANCON1bits.ANSEL13=1 /*Enable AN13 in digital mode */
#define ENABLE_AN13_ANA()             ANCON1bits.ANSEL13=0 /*Enable AN13 in analog mode */
#define ENABLE_AN14_DIG()             ANCON1bits.ANSEL14=1 /*Enable AN14 in digital mode */
#define ENABLE_AN14_ANA()             ANCON1bits.ANSEL14=0 /*Enable AN14 in analog mode */
#define ENABLE_AN15_DIG()             ANCON1bits.ANSEL15=1 /*Enable AN15 in digital mode */
#define ENABLE_AN15_ANA()             ANCON1bits.ANSEL15=0 /*Enable AN15 in analog mode */
#define ENABLE_ALL_ANA_8_15()         ANCON1=0x00 /*Enable AN8-AN15 in analog mode */
#define ENABLE_ALL_DIG_8_15()         ANCON1=0xFF /*Enable AN8-AN15 in Digital mode */

#define ENABLE_AN16_DIG()             ANCON2bits.ANSEL16=1 /*Enable AN16 in digital mode */
#define ENABLE_AN16_ANA()             ANCON2bits.ANSEL16=0 /*Enable AN16 in analog mode */
#define ENABLE_AN17_DIG()             ANCON2bits.ANSEL17=1 /*Enable AN17 in digital mode */
#define ENABLE_AN17_ANA()             ANCON2bits.ANSEL17=0 /*Enable AN17 in analog mode */
#define ENABLE_AN18_DIG()             ANCON2bits.ANSEL18=1 /*Enable AN18 in digital mode */
#define ENABLE_AN18_ANA()             ANCON2bits.ANSEL18=0 /*Enable AN18 in analog mode */
#define ENABLE_AN19_DIG()             ANCON2bits.ANSEL19=1 /*Enable AN19 in digital mode */
#define ENABLE_AN19_ANA()             ANCON2bits.ANSEL19=0 /*Enable AN19 in analog mode */
#define ENABLE_AN20_DIG()             ANCON2bits.ANSEL20=1 /*Enable AN20 in digital mode */
#define ENABLE_AN20_ANA()             ANCON2bits.ANSEL20=0 /*Enable AN20 in analog mode */
#define ENABLE_AN21_DIG()             ANCON2bits.ANSEL21=1 /*Enable AN21 in digital mode */
#define ENABLE_AN21_ANA()             ANCON2bits.ANSEL21=0 /*Enable AN21 in analog mode */
#define ENABLE_AN22_DIG()             ANCON2bits.ANSEL22=1 /*Enable AN22 in digital mode */
#define ENABLE_AN22_ANA()             ANCON2bits.ANSEL22=0 /*Enable AN22 in analog mode */
#define ENABLE_AN23_DIG()             ANCON2bits.ANSEL23=1 /*Enable AN23 in digital mode */
#define ENABLE_AN23_ANA()             ANCON2bits.ANSEL23=0 /*Enable AN23 in analog mode */
#define ENABLE_ALL_ANA_16_23()        ANCON2=0x00 /*Enable AN16-AN23 in analog mode */
#define ENABLE_ALL_DIG_16_23()        ANCON2=0xFF /*Enable AN16-AN23 in Digital mode */

#endif

/* Stores the result of an A/D conversion. */
union ADCResult
{
	int lr;			//holds the 10-bit ADC Conversion value as integer
 	char br[2];		//holds the 10-bit ADC Conversion value as two byte values
};

char BusyADC (void);

void ConvertADC (void);

void CloseADC(void);

#if	defined (ADC_V15) || defined (ADC_V15_1)	

unsigned int ReadADC(unsigned char );
				  
#else

int ReadADC(void);

#endif

#if defined (ADC_V1) || defined (ADC_V2)

void OpenADC ( unsigned char ,
               unsigned char );

#elif defined (ADC_V3) || defined (ADC_V4) || defined (ADC_V5) || defined (ADC_V6) ||\
      defined (ADC_V7) || defined (ADC_V7_1)|| defined (ADC_V12) || defined (ADC_V13)\
	  || defined (ADC_V13_1) || defined (ADC_V13_2) || defined (ADC_V13_3) || \
	  defined (ADC_V14) || defined (ADC_V14_1) || defined (ADC_V14_2) || defined (ADC_V14_3)

void OpenADC ( unsigned char ,
               unsigned char ,
               unsigned char );

#elif defined (ADC_V8) || defined (ADC_V9) || defined (ADC_V9_1) 

void OpenADC ( unsigned char ,
               unsigned char ,
               unsigned int );

#elif defined (ADC_V10) || defined (ADC_V11_1) 

void OpenADC ( unsigned char ,
               unsigned char ,
               unsigned char ,
               unsigned int );
			  
#elif defined (ADC_V11)

void OpenADC ( unsigned char ,
               unsigned char ,
               unsigned int );
			   
#elif	defined (ADC_V15) || defined (ADC_V15_1)	

void OpenADC( unsigned char ,
			  unsigned char ,	
			  unsigned char ,
              unsigned char ,
              unsigned char ,
			  unsigned char ,
			  unsigned char ,
              unsigned char );
		   
#endif

 
#if defined (ADC_V1) || defined (ADC_V2) || defined (ADC_V3) ||\
    defined (ADC_V4) || defined ( ADC_V5 ) || defined ( ADC_V6 )||\
	defined ( ADC_V8 ) || defined ( ADC_V9) || defined (ADC_V9_1) || defined ( ADC_V10)||\
	defined ( ADC_V11) || defined (ADC_V12) || defined (ADC_V13) || \
	defined (ADC_V13_1) || defined ( ADC_V11_1) || defined (ADC_V13_2)\
	|| defined (ADC_V13_3) || defined (ADC_V14) || defined (ADC_V14_1) || defined (ADC_V14_2) || defined (ADC_V14_3)

void SetChanADC(unsigned char );

#elif	defined (ADC_V15) || defined (ADC_V15_1)	

void SetChanADC ( unsigned char ,
                  unsigned char );

#endif

#if	defined (ADC_V15) || defined (ADC_V15_1)	

void SelChanConvADC ( unsigned char ,
					  unsigned char );
				  
#else

void SelChanConvADC( unsigned char );

#endif



#if defined (ADC_V4)

/***********************************************************************************
Macro       : ADC_SEVT_ENABLE()
Overview : Macro enables Special Event Trigger from Power Control PWM module
Parameters   : None
Remarks     : Functions in coordination with PCPWM Module
***********************************************************************************/
#define ADC_SEVT_ENABLE()    (ADCON0bits.SEVTEN=1)

/***********************************************************************************
Macro       : ADC_SEVT_DISABLE()
Overview : Macro disables Special Event Trigger from Power Control PWM module
Parameters   : None
Remarks     : Functions in coordination with PCPWM Module
***********************************************************************************/
#define ADC_SEVT_DISABLE()   (ADCON0bits.SEVTEN=0)

#endif


#if defined (ADC_V6) || defined (ADC_V12)

/***********************************************************************************
Macro       : ADC_CALIB()
Overview : Macro performs the Calibration on next A/D conversion
Parameters   : None
Remarks     : None
***********************************************************************************/
#define	ADC_CALIB()	    (ADCON0bits.ADCAL=1)

/***********************************************************************************
Macro       : ADC_NO_CALIB()
Overview : Macro performs the Normal A/D converter operation with no Calibration
Parameters   : None
Remarks     : None
***********************************************************************************/
#define	ADC_NO_CALIB()	(ADCON0bits.ADCAL=0)


#elif defined (ADC_V9) || defined (ADC_V9_1)

/***********************************************************************************
Macro       : ADC_CALIB()
Overview : Macro performs the Calibration on next A/D conversion
Parameters   : None
Remarks     : None
***********************************************************************************/
#define	ADC_CALIB()	    (WDTCONbits.DEVCFG=0, ADCON1bits.ADCAL=1)

/***********************************************************************************
Macro       : ADC_NO_CALIB()
Overview : Macro performs the Normal A/D converter operation with no Calibration
Parameters   : None
Remarks     : None
***********************************************************************************/
#define ADC_NO_CALIB()	(WDTCONbits.DEVCFG=0, ADCON1bits.ADCAL=0)

#elif defined (ADC_V11)

/***********************************************************************************
Macro       : ADC_CALIB()
Overview : Macro performs the Calibration on next A/D conversion
Parameters   : None
Remarks     : None
***********************************************************************************/
#define	ADC_CALIB()	    (ADCON1bits.ADCAL=1)

/***********************************************************************************
Macro       : ADC_NO_CALIB()
Overview : Macro performs the Normal A/D converter operation with no Calibration
Parameters   : None
Remarks     : None
***********************************************************************************/
#define ADC_NO_CALIB()	(ADCON1bits.ADCAL=0)

#endif

//---------------------------------/
#if defined (ADC_V7) || defined (ADC_V7_1)
/******* A/D channel from Gruop A *******/
#define ADC_CH_GRA_SEL_AN0   0
/******* A/D channel from Gruop A *******/
#define ADC_CH_GRA_SEL_AN4   4
/******* A/D channel from Gruop B *******/
#define ADC_CH_GRB_SEL_AN1   1
/******* A/D channel from Gruop C *******/
#define ADC_CH_GRC_SEL_AN2   2
/******* A/D channel from Gruop D *******/
#define ADC_CH_GRD_SEL_AN3   3

/***********************************************************************************
Macro       : ADC_CH_GRA_AN0()
Overview : Macro  select AN0 as analog in Group A
Parameters   : None
Remarks     : None
***********************************************************************************/
#define ADC_CH_GRA_AN0()	{ANSEL0|=0b00000001; ADCHS|=0b00000011; ADCHS&=0b11111100;}

/***********************************************************************************
Macro       : ADC_CH_GRA_AN4()
Overview : Macro  select AN4 as analog in Group A
Parameters   : None
Remarks     : None
***********************************************************************************/
#define ADC_CH_GRA_AN4()	{ANSEL0|=0b00010000; ADCHS|=0b00000011; ADCHS&=0b11111101;}

/***********************************************************************************
Macro       : ADC_CH_GRB_AN1()
Overview : Macro  select AN1 as analog in Group B
Parameters   : None
Remarks     : None
***********************************************************************************/
#define ADC_CH_GRB_AN1()	{ANSEL0|=0b00000010; ADCHS|=0b00110000; ADCHS&=0b11001111;}

/***********************************************************************************
Macro       : ADC_CH_GRC_AN2()
Overview : Macro  select AN2 as analog in Group C
Parameters   : None
Remarks     : None
***********************************************************************************/
#define ADC_CH_GRC_AN2()	{ANSEL0|=0b00000100; ADCHS|=0b00001100; ADCHS&=0b11110011;}

/***********************************************************************************
Macro       : ADC_CH_GRD_AN3()
Overview : Macro  select AN3 as analog in Group D
Parameters   : None
Remarks     : None
***********************************************************************************/
#define ADC_CH_GRD_AN3()	{ANSEL0|=0b00001000; ADCHS|=0b11000000; ADCHS&=0b00111111;}

#endif

#if defined (ADC_V7)
/****** A/D channel from Gruop B ******/
#define ADC_CH_GRB_SEL_AN5   5
/****** A/D channel from Gruop C ******/
#define ADC_CH_GRC_SEL_AN6   6
/****** A/D channel from Gruop D ******/
#define ADC_CH_GRD_SEL_AN7   7
/****** A/D channel from Gruop A ******/	
#define ADC_CH_GRA_SEL_AN8   8

/***********************************************************************************
Macro       : ADC_CH_GRB_AN5()
Overview : Macro  select AN5 as analog in Group B
Parameters   : None
Remarks     : None
***********************************************************************************/	
#define ADC_CH_GRB_AN5()	{ANSEL0|=0b00100000; ADCHS|=0b00110000; ADCHS&=0b11011111;}

/***********************************************************************************
Macro       : ADC_CH_GRC_AN6()
Overview : Macro  select AN6 as analog in Group C
Parameters   : None
Remarks     : None
***********************************************************************************/
#define ADC_CH_GRC_AN6()	{ANSEL0|=0b01000000; ADCHS|=0b00001100; ADCHS&=0b11110111;}

/***********************************************************************************
Macro       : ADC_CH_GRD_AN7()
Overview : Macro  select AN7 as analog in Group D
Parameters   : None
Remarks     : None
***********************************************************************************/			
#define ADC_CH_GRD_AN7()	{ANSEL0|=0b10000000; ADCHS|=0b11000000; ADCHS&=0b01111111;}

/***********************************************************************************
Macro       : ADC_CH_GRA_AN8()
Overview : Macro  select AN8 as analog in Group A
Parameters   : None
Remarks     : None
***********************************************************************************/										
#define ADC_CH_GRA_AN8()	{ANSEL1|=0b00000001; ADCHS|=0b00000011; ADCHS&=0b11111110;}

/***********************************************************************************
Macro       : ALL_CH_DIGITAL()
Overview : Macro  configures all channels as Digital
Parameters   : None
Remarks     : None
***********************************************************************************/	
#define ALL_CH_DIGITAL()	{ANSEL0=0; ANSEL1=0;}

#endif


/*Macros for backward compatibility*/ 
#if defined (ADC_V8)

#define ADC_CHAN0   0b1111111111111110  // AN0
#define ADC_CHAN1   0b1111111111111101  // AN1
#define ADC_CHAN2   0b1111111111111011  // AN2
#define ADC_CHAN3   0b1111111111110111  // AN3
#define ADC_CHAN4   0b1111111111101111  // AN4
#define ADC_CHAN5   0b1111111111011111  // AN5
#define ADC_CHAN6   0b1111111110111111  // AN6
#define ADC_CHAN7   0b1111111101111111  // AN7
#define ADC_CHAN8   0b1111111011111111  // AN8
#define ADC_CHAN9   0b1111110111111111  // AN9
#define ADC_CHAN10  0b1111101111111111  // AN10
#define ADC_CHAN11  0b1111011111111111  // AN11
#define ADC_CHAN12  0b1110111111111111  // AN12
#define ADC_CHAN13  0b1101111111111111  // AN13
#define ADC_CHAN14  0b1011111111111111  // AN14
#define ADC_CHAN15  0b0111111111111111  // AN15

#endif

#if defined ( ADC_V2 ) || defined (ADC_V3) || defined (ADC_V4 ) ||\
    defined ( ADC_V5 ) || defined ( ADC_V6 ) || defined (ADC_V7) ||\
	defined (ADC_V7_1) || defined ( ADC_V8 ) || defined (ADC_V9) || defined (ADC_V9_1) ||\
	defined (ADC_V11) || defined (ADC_V12)
#define ADC_VREFPLUS_VDD	ADC_REF_VDD_VREFMINUS      	// VREF+ = AVDD
#define ADC_VREFPLUS_EXT	ADC_REF_VREFPLUS_VREFMINUS 	// VREF+ = external
#define ADC_VREFMINUS_VSS	ADC_REF_VREFPLUS_VSS       	// VREF- = AVSS
#define ADC_VREFMINUS_EXT	ADC_REF_VREFPLUS_VREFMINUS 	// VREF- = external

#elif defined (ADC_V10) || defined (ADC_V15) || defined (ADC_V15_1)
#define ADC_VREFPLUS_VDD	ADC_REF_VDD_VDD      		// VREF+ = AVDD
#define ADC_VREFPLUS_EXT	ADC_REF_VDD_VREFPLUS 		// VREF+ = external
#define ADC_VREFMINUS_VSS	ADC_REF_VDD_VSS       		// VREF- = AVSS
#define ADC_VREFMINUS_EXT	ADC_REF_VDD_VREFMINUS 		// VREF- = external

#endif

#endif
