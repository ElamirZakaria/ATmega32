/************************************/
/*	Author	  :	Elamir Galal		*/
/*	SWC		  : ADC					*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	Dec	 11, 2023		*/
/*	Last Edit :	N/A					*/
/************************************/


#ifndef _MADC_PRIVATE_H_
#define _MADC_PRIVATE_H_


/*!:Comment Registers and Bits Definition*/

/*!:Comment ADC Multiplexer Selection Register*/
#define ADMUX	*((volatile u8*)0x27)

/*!:Comment ARef Bits*/
#define REFS1	7
#define REFS0	6

/*!:Comment Left or Right Adjustment Bits*/
#define ADLAR	5

/*!:Comment Channel Selection Bits*/
#define MUX4	4
#define MUX3	3
#define MUX2	2
#define MUX1	1
#define MUX0	0

/*!:Comment ADC Control and Status Register*/
#define ADCSRA *((volatile u8 *)0x26)

/*!:Comment ADC Enable Bit*/
#define	ADEN	7

/*!:Comment ADC Start Conversion Bit*/
#define	ADSC	6

/*!:Comment ADC Auto Trigger Enable*/
#define ADATE	5

/*!:Comment ADC  Interrupt Flag*/
#define ADIF	4

/*!:Comment ADC Interrupt Enable*/
#define	ADIE	3

/*!:Comment ADC Prescaler Select Bit*/
#define ADPS2	2
#define	ADPS1	1
#define ADPS0	0


#define ADCL  			*((volatile u8*)0x24)
#define ADCH			*((volatile u8*)0x25)
#define ADC_RESULT      *((volatile u16*)0x25)

#define SFIOR 	*((volatile u8*)0x50)

static void 		MADC_voidPolling(void);
static void 		MADC_voidClearFlag(void);
/*!:Comment: Masks*/
#define ADMUX_MASK	0x1F
#define ADCSRA_MASK 0xF8
#define ADMUX_CHANNEL_MASK 0xE0
#endif
