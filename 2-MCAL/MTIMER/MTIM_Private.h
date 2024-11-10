/**********************************/
/* Author    : Elamir Galal       */
/* SWC       : Timer	          */
/* Layer     : MCAL	 		      */
/* Version   : 1.0                */
/* Date      : December 12,2023   */
/* Last Edit : December 12,2023   */
/**********************************/


#ifndef _MTIM_PRIVATE_H_
#define _MTIM_PRIVATE_H_



/****************TCCR0 Register****************/
/*!Comment: This is timer 0 control Register*/
#define TCCR0 				*((volatile u8*)0x53)
#define FOC0				7 /*!Comment: Force Output Compare Bit*/
#define WGM00				6 /*!Comment: Waveform Generation Mode (Timer Mode)*/
#define COM01				5 /*!Comment: Compare Match Output Mode*/
#define COM00				4 /*!Comment: Compare Match Output Mode*/
#define WGM01				3 /*!Comment: Waveform Generation Mode (Timer Mode)*/
#define CS02				2 /*!Comment: Clock Select*/
#define CS01				1 /*!Comment: Clock Select*/
#define CS00				0 /*!Comment: Clock Select*/

/****************TCNT0 Register****************/
/*!Comment: This is timer 0 counting register*/
#define TCNT0				*((volatile u8*)0x52)

/****************OCR0 Registers****************/
/*!Comment: This is timer 0 output compare register*/
#define OCR0				*((volatile u8*)0x5C)


/****************TCCR1A Register****************/
/*!Comment: This is timer 1 control Register A*/
#define TCCR1A 				*((volatile u8*)0x4F)
#define COM1A1				7 /*!Comment: Compare Match Output Mode for Compare unit A*/
#define COM1A0				6 /*!Comment: Compare Match Output Mode for Compare unit A*/
#define COM1B1				5 /*!Comment: Compare Match Output Mode for Compare unit B*/
#define COM1B0				4 /*!Comment: Compare Match Output Mode for Compare unit B*/
#define FOC1A				3 /*!Comment: Force Output Compare Bit*/
#define FOC1B				2 /*!Comment: Force Output Compare Bit*/
#define WGM11				1 /*!Comment: Clock Select*/
#define WGM10				0 /*!Comment: Clock Select*/

/****************TCCR1B Register****************/
/*!Comment: This is timer 1 control Register B*/
#define TCCR1B 				*((volatile u8*)0x4E)
#define ICNC1				7 /*!Comment: Force Output Compare Bit*/
#define ICES1				6 /*!Comment: Waveform Generation Mode (Timer Mode)*/
#define RES					5 /*!Comment: Compare Match Output Mode*/
#define WGM13				4 /*!Comment: Compare Match Output Mode*/
#define WGM12				3 /*!Comment: Waveform Generation Mode (Timer Mode)*/
#define CS12				2 /*!Comment: Clock Select*/
#define CS11				1 /*!Comment: Clock Select*/
#define CS10				0 /*!Comment: Clock Select*/
/****************TCNT1 Register****************/
/*!Comment: This is timer 1 counting register*/
#define TCNT1H				*((volatile u8*)0x4D)
#define TCNT1L				*((volatile u8*)0x4C)
#define TCNT1				*((volatile u16*)0x4C)

/****************OCR1 Registers****************/
/*!Comment: This is timer 1 output compare register*/
#define OCR1AH				*((volatile u8*)0x4B)
#define OCR1AL				*((volatile u8*)0x4A)
#define OCR1A				*((volatile u16*)0x4A)

#define OCR1BH				*((volatile u8*)0x49)
#define OCR1BL				*((volatile u8*)0x48)
#define OCR1B				*((volatile u16*)0x48)
/****************ICR1 Registers****************/
/*!Comment: This is timer 1 output compare register*/
#define ICRR1H				*((volatile u8*)0x47)
#define ICRR1L				*((volatile u8*)0x46)
#define ICRR1				*((volatile u16*)0x46)








/****************TCCR2 Register****************/
/*!Comment: This is timer 2 control Register*/
#define TCCR2 				*((volatile u8*)0x45)
#define FOC2				7 /*!Comment: Force Output Compare Bit*/
#define WGM20				6 /*!Comment: Waveform Generation Mode (Timer Mode)*/
#define COM21				5 /*!Comment: Compare Match Output Mode*/
#define COM20				4 /*!Comment: Compare Match Output Mode*/
#define WGM21				3 /*!Comment: Waveform Generation Mode (Timer Mode)*/
#define CS22				2 /*!Comment: Clock Select*/
#define CS21				1 /*!Comment: Clock Select*/
#define CS20				0 /*!Comment: Clock Select*/

/****************TCNT2 Register****************/
/*!Comment: This is timer 0 counting register*/
#define TCNT2				*((volatile u8*)0x44)

/****************OCR2 Registers****************/
/*!Comment: This is timer 2 output compare register*/
#define OCR2				*((volatile u8*)0x43)



/****************TIMSK Registers****************/
/*!Comment: This is timer 0 interrupt mask register*/
#define TIMSK				*((volatile u8*)0x59)
#define OCIE2				7
#define TOIE2				6
#define TICIE1				5
#define OCIE1A				4
#define OCIE1B				3
#define TOIE1				2
#define OCIE0				1
#define TOIE0				0

/****************TIMSK Registers****************/
/*!Comment: This is timer 0 interrupt flag register*/
#define TIFR 				*((volatile u8*)0x58)
#define OCF2				7
#define TOV2				6
#define ICF1				5
#define OCF1A				4
#define OCF1B				3
#define TOV1				2
#define OCF0				1
#define TOV0				0





#endif
