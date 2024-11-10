/************************************/
/*	Author	  :	Elamir Galal		*/
/*	SWC		  : ADC					*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	Dec	 11, 2023		*/
/*	Last Edit :	N/A					*/
/************************************/

#include "LBIT_Math.h"
#include "LSTD_Types.h"
#include "MADC_Interface.h"
#include "MADC_Private.h"


static volatile u8 MADC_u8ADCAdjustment ;
static void (*MADC_pvoidfUserFunction)(void) = NULL_POINTER;


static void 		MADC_voidPolling(void)
{
	while(GET_BIT(ADCSRA,ADIF)==0);

}
static void 		MADC_voidClearFlag(void)
{
	SET_BIT(ADCSRA,ADIF);
}



STD_error_t MADC_stderrInit(u8 ARG_u8VRef, u8 ARG_u8Prescaler, u8 ARG_u8Adjustment)
{
	STD_error_t L_stderrStatus = E_OK ;
	if((ARG_u8VRef<=MADC_INTERNAL_2_56) && (ARG_u8Prescaler<=MADC_PRESCALER_128) && (ARG_u8Adjustment<=MADC_LEFT_ADJUSTMENT))
	{
		ADMUX &= ADMUX_MASK;
		ADMUX |= (ARG_u8VRef<<REFS0) | (ARG_u8Adjustment<<ADLAR) ;
		ADCSRA &=(ADCSRA_MASK) ;
		ADCSRA |= ARG_u8Prescaler;
		MADC_u8ADCAdjustment = ARG_u8Adjustment;
	}
	else
	{
		L_stderrStatus = E_NOK;
	}
	return L_stderrStatus;
}
STD_error_t MADC_stderrStartConversion(u8 ARG_u8Channel)
{
	STD_error_t L_stderrStatus = E_OK ;
	if(ARG_u8Channel<=MADC_CHANNEL_0VGND)
	{
		ADMUX &= ADMUX_CHANNEL_MASK;
		ADMUX |=ARG_u8Channel;
		SET_BIT(ADCSRA,ADSC);
	}
	else
	{
		L_stderrStatus = E_NOK;
	}
	return L_stderrStatus;
}
STD_error_t MADC_stderrGetChannelReading(u16 *ARG_pu16Reading, u8 ARG_u8Channel)
{
	STD_error_t L_stderrStatus = E_OK ;
	L_stderrStatus =MADC_stderrStartConversion(ARG_u8Channel);
	if(L_stderrStatus==E_OK)
	{
		MADC_voidPolling();
		MADC_voidClearFlag();
		if(MADC_u8ADCAdjustment== MADC_LEFT_ADJUSTMENT)
		{
//			*ARG_pu16Reading = (ADCH<<2) | (ADCL>>6);
//			*ARG_pu16Reading = ADCH ;
			*ARG_pu16Reading = (ADCL>>6) ;
//			*ARG_pu16Reading = (*ARG_pu16Reading)<<2;
			*ARG_pu16Reading = *ARG_pu16Reading| (ADCH<<2);
		}
		else
		{
//			*ARG_pu16Reading = (ADCH<<8) | (ADCL);
			*ARG_pu16Reading  = ADCL;
			*ARG_pu16Reading  |= (ADCH<<8);
		}

	}
	else
	{
		L_stderrStatus = E_NOK;
	}
	return L_stderrStatus;
}
void		MADC_voidEnableInterrupt(void)
{
			SET_BIT(ADCSRA,ADIE);
}
void		MADC_voidDisableInterrupt(void)
{
			CLEAR_BIT(ADCSRA,ADIE);
}
STD_error_t MADC_stderrAutoTriggerEnable(u8 ARG_u8TriggerSource)
{
	STD_error_t L_stderrStatus = E_OK ;
	if(ARG_u8TriggerSource<=MADC_AUTO_TRIGGER_TIM1_CE)
	{
		SFIOR = (SFIOR & 0x0F) | (ARG_u8TriggerSource<<5);
		SET_BIT(ADCSRA,ADATE);
	}
	else
	{
		L_stderrStatus= E_NOK;
	}
	return L_stderrStatus;
}
void		MADC_voidAutoTriggerDisable(void)
{
			CLEAR_BIT(ADCSRA,ADATE);
}

void MADC_voidEnableADC(void)
{
	SET_BIT(ADCSRA, ADEN);

}
void MADC_voidDisableADC(void)
{
	CLEAR_BIT(ADCSRA, ADEN);

}
STD_error_t MADC_stderrSetCallBackFunction(void (*ARG_pvoidUsersFunction)(void))
{
	STD_error_t L_stderrStatus = E_OK;
	if(ARG_pvoidUsersFunction!=NULL_POINTER)
	{
		MADC_pvoidfUserFunction = ARG_pvoidUsersFunction;
	}
	else
	{

	}
	return L_stderrStatus ;
}


void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
	if(MADC_pvoidfUserFunction!=NULL_POINTER)
	{
		MADC_pvoidfUserFunction();
	}
	else
	{
		/*!Comment: Misra Rule*/
	}
}
