/************************************/
/*	Author	  :	Elamir Galal		*/
/*	SWC		  : ADC					*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	Dec	 11, 2023		*/
/*	Last Edit :	N/A					*/
/************************************/


#ifndef _MADC_INTERFACE_H_
#define _MADC_INTERFACE_H_


typedef struct 
{
	u8 *Channel ;
	u16 *Result ; 
	u8 Size 	;
	void (*NotificationFunc)(void);
	
}Chain_t


/*!:Comment ADC References */
#define MADC_AREF							0
#define MADC_AVCC							1
#define MADC_INTERNAL_2_56					3

/*!:Comment ADC Adjustment */
#define MADC_RIGHT_ADJUSTMENT				0
#define MADC_LEFT_ADJUSTMENT				1


/*!:Comment ADC Channels */
#define MADC_CHANNEL_ADC0					0b00000
#define MADC_CHANNEL_ADC1					0b00001
#define MADC_CHANNEL_ADC2					0b00010
#define MADC_CHANNEL_ADC3					0b00011
#define MADC_CHANNEL_ADC4					0b00100
#define MADC_CHANNEL_ADC5					0b00101
#define MADC_CHANNEL_ADC6					0b00110
#define MADC_CHANNEL_ADC7					0b00111

#define MADC_CHANNEL_ADC0_ADC0_10XGAIN		0b01000
#define MADC_CHANNEL_ADC1_ADC0_10XGAIN		0b01001
#define MADC_CHANNEL_ADC0_ADC0_200XGAIN		0b01010
#define MADC_CHANNEL_ADC1_ADC0_200XGAIN		0b01011
#define MADC_CHANNEL_ADC2_ADC2_10XGAIN		0b01100
#define MADC_CHANNEL_ADC3_ADC2_10XGAIN		0b01101
#define MADC_CHANNEL_ADC2_ADC2_200XGAIN		0b01110
#define MADC_CHANNEL_ADC3_ADC2_200XGAIN		0b01111

#define MADC_CHANNEL_ADC0_ADC1				0b10000
#define MADC_CHANNEL_ADC1_ADC1				0b10001
#define MADC_CHANNEL_ADC2_ADC1				0b10010
#define MADC_CHANNEL_ADC3_ADC1				0b10011
#define MADC_CHANNEL_ADC4_ADC1				0b10100
#define MADC_CHANNEL_ADC5_ADC1				0b10101
#define MADC_CHANNEL_ADC6_ADC1				0b10110
#define MADC_CHANNEL_ADC7_ADC1				0b10111
#define MADC_CHANNEL_ADC0_ADC2				0b11000
#define MADC_CHANNEL_ADC1_ADC2				0b11001
#define MADC_CHANNEL_ADC2_ADC2				0b11010
#define MADC_CHANNEL_ADC3_ADC2				0b11011
#define MADC_CHANNEL_ADC4_ADC2				0b11100
#define MADC_CHANNEL_ADC5_ADC2				0b11101
#define MADC_CHANNEL_1_22VBG				0b11110
#define MADC_CHANNEL_0VGND					0b11111

/*!:Comment ADC Enable & Disable */
#define MADC_ENABLE							1
#define MADC_DISABLE						0
/*!:Comment ADC Prescaler */
#define MADC_PRESCALER_2					1
#define MADC_PRESCALER_4					2
#define MADC_PRESCALER_8					3
#define MADC_PRESCALER_16					4
#define MADC_PRESCALER_32					5
#define MADC_PRESCALER_64					6
#define MADC_PRESCALER_128					7
/*!:Comment ADC Auto Trigger Source */
#define MADC_AUTO_TRIGGER_FRM				0
#define MADC_AUTO_TRIGGER_AC				1
#define MADC_AUTO_TRIGGER_EXTI0				2
#define MADC_AUTO_TRIGGER_TIM0_COMP			3
#define MADC_AUTO_TRIGGER_TIM0_OF			4
#define MADC_AUTO_TRIGGER_TIM1_COMPB		5
#define MADC_AUTO_TRIGGER_TIM1_OF			6
#define MADC_AUTO_TRIGGER_TIM1_CE           7



STD_error_t MADC_stderrInit(u8 ARG_u8VRef, u8 ARG_u8Prescaler, u8 ARG_u8Adjustment);
STD_error_t MADC_stderrStartConversion(u8 ARG_u8Channel);
STD_error_t MADC_stderrGetChannelReading(u16 *ARG_pu16Reading, u8 ARG_u8Channel);
void		MADC_voidEnableInterrupt(void);
void		MADC_voidDisableInterrupt(void);
STD_error_t MADC_stderrAutoTriggerEnable(u8 ARG_u8TriggerSource);
void		MADC_voidAutoTriggerDisable(void);
void 		MADC_voidDisableADC(void);
void 		MADC_voidEnableADC(void);
STD_error_t MADC_stderrSetCallBackFunction(void (*ARG_pvoidUsersFunction)(void));
STD_error_t MADC_stderrStartChainAsynch(Chain_t * ARG_pudtChain);
 
#endif
