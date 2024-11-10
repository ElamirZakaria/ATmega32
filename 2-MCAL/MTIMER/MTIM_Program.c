/**********************************/
/* Author    : Elamir Galal       */
/* SWC       : Timer	          */
/* Layer     : MCAL	 		      */
/* Version   : 1.0                */
/* Date      : December 12,2023   */
/* Last Edit : December 12,2023   */
/**********************************/

#include "LBIT_Math.h"
#include "LSTD_Types.h"
#include "MTIM_Interface.h"
#include "MTIM_Private.h"
#include "MTIM_Config.h"
/*!Comment: Timer 1 Global Variables*/
static u8  MTIM_u8Timer0Prescaler    ;
static u32 MTIM_u32Timer0OVFCount    ;
static u32 MTIM_u32Timer0OCRCount    ;
static u8  MTIM_u8Timer0PreloadValue ;

static void (*MTMI0_pvoidfUserFunctionOVF)(void) = NULL_POINTER;
static void (*MTMI0_pvoidfUserFunctionCTC)(void) = NULL_POINTER;

/*!Comment: Timer 1 Global Variables*/

static u8  MTIM_u8Timer1Prescaler    ;
static u32 MTIM_u32Timer1OVFCount    ;
static u32 MTIM_u32Timer1OCRACount    ;
static u32 MTIM_u32Timer1OCRBCount    ;

static u16  MTIM_u16Timer1PreloadValue ;

static void (*MTMI1_pvoidfUserFunctionOVF)(void) = NULL_POINTER;
static void (*MTMI1_pvoidfUserFunctionCTCA)(void) = NULL_POINTER;
static void (*MTMI1_pvoidfUserFunctionCTCB)(void) = NULL_POINTER;
static void (*MTMI1_pvoidfUserFunctionICU)(void) = NULL_POINTER;

/*!Comment: Timer 2 Global Variables*/

static u8  MTIM_u8Timer2Prescaler    ;
static u32 MTIM_u32Timer2OVFCount    ;
static u32 MTIM_u32Timer2OCRCount    ;
static u8  MTIM_u8Timer2PreloadValue ;

static void (*MTMI2_pvoidfUserFunctionOVF)(void) = NULL_POINTER;
static void (*MTMI2_pvoidfUserFunctionCTC)(void) = NULL_POINTER;


STD_error_t MTIM_stderrTimerInit(u8 ARG_u8TimerNo, u8 ARG_u8TimerMode,u8 ARG_u8TimerPrescaler)
{
	STD_error_t L_stderrStatus = E_OK ;
	if(ARG_u8TimerPrescaler<=MTIM0_PRESCALER_EXTERNAL_ON_RISING_EDGE)
	{
		switch(ARG_u8TimerNo)
		{
		case MTIM_TIMER0 :
		{
			switch(ARG_u8TimerMode)
			{
			case MTIM0_NORMAL_MODE :
				CLEAR_BIT(TCCR0,WGM01);
				CLEAR_BIT(TCCR0,WGM00);
				break ;
			case MTIM0_PHASE_CORRECT_PWM_MODE:
				CLEAR_BIT(TCCR0,WGM01);
				SET_BIT(TCCR0,WGM00);
				break ;
			case MTIM0_CTC_MODE:
				SET_BIT(TCCR0,WGM01);
				CLEAR_BIT(TCCR0,WGM00);
				break ;
			case MTIM0_FAST_PWM_MODE:
				SET_BIT(TCCR0,WGM01);
				SET_BIT(TCCR0,WGM00);
				break ;
			default: L_stderrStatus = E_NOK ;
			break ;
			}
			MTIM_u8Timer0Prescaler = ARG_u8TimerPrescaler ;
		}
		break ;
		case MTIM_TIMER1 :
		{
			switch(ARG_u8TimerMode)
			{

			case MTIM1_NORMAL_MODE                                   		  :
				CLEAR_BIT(TCCR1A,WGM11);
				CLEAR_BIT(TCCR1A,WGM10);
				CLEAR_BIT(TCCR1B,WGM13);
				CLEAR_BIT(TCCR1B,WGM12);
				break ;
			case MTIM1_PHASE_CORRECT_PWM_8_BIT_MODE                           :
				CLEAR_BIT(TCCR1A,WGM11);
				SET_BIT(TCCR1A,WGM10);
				CLEAR_BIT(TCCR1B,WGM13);
				CLEAR_BIT(TCCR1B,WGM12);

				break ;
			case MTIM1_PHASE_CORRECT_PWM_9_BIT_MODE                           :
				SET_BIT(TCCR1A,WGM11);
				CLEAR_BIT(TCCR1A,WGM10);
				CLEAR_BIT(TCCR1B,WGM13);
				CLEAR_BIT(TCCR1B,WGM12);
				break ;
			case MTIM1_PHASE_CORRECT_PWM_10_BIT_MODE                          :
				SET_BIT(TCCR1A,WGM11);
				SET_BIT(TCCR1A,WGM10);
				CLEAR_BIT(TCCR1B,WGM13);
				CLEAR_BIT(TCCR1B,WGM12);
				break ;
			case MTIM1_CTC_MODE                                               :
				CLEAR_BIT(TCCR1A,WGM11);
				CLEAR_BIT(TCCR1A,WGM10);
				CLEAR_BIT(TCCR1B,WGM13);
				SET_BIT(TCCR1B,WGM12);
				break ;
			case MTIM1_FAST_PWM_8_BIT_MODE                                    :
				CLEAR_BIT(TCCR1A,WGM11);
				SET_BIT(TCCR1A,WGM10);
				CLEAR_BIT(TCCR1B,WGM13);
				SET_BIT(TCCR1B,WGM12);
				break ;
			case MTIM1_FAST_PWM_9_BIT_MODE                                    :
				SET_BIT(TCCR1A,WGM11);
				CLEAR_BIT(TCCR1A,WGM10);
				CLEAR_BIT(TCCR1B,WGM13);
				SET_BIT(TCCR1B,WGM12);

				break ;
			case MTIM1_FAST_PWM_10_BIT_MODE                                   :
				SET_BIT(TCCR1A,WGM11);
				SET_BIT(TCCR1A,WGM10);
				CLEAR_BIT(TCCR1B,WGM13);
				SET_BIT(TCCR1B,WGM12);
				break ;
			case MTIM1_PHASE_CORRECT_PWM_AND_FREQ_CORRECT_BIT_MODE_TOP_ICR    :
				CLEAR_BIT(TCCR1A,WGM11);
				CLEAR_BIT(TCCR1A,WGM10);
				SET_BIT(TCCR1B,WGM13);
				CLEAR_BIT(TCCR1B,WGM12);
				break ;
			case MTIM1_PHASE_CORRECT_PWM_AND_FREQ_CORRECT_BIT_MODE_TOP_OCR1A  :

				CLEAR_BIT(TCCR1A,WGM11);
				SET_BIT(TCCR1A,WGM10);
				SET_BIT(TCCR1B,WGM13);
				CLEAR_BIT(TCCR1B,WGM12);
				break ;
			case MTIM1_PHASE_CORRECT_PWM_MODE_TOP_ICR1                        :
				SET_BIT(TCCR1A,WGM11);
				CLEAR_BIT(TCCR1A,WGM10);
				SET_BIT(TCCR1B,WGM13);
				CLEAR_BIT(TCCR1B,WGM12);
				break ;
			case MTIM1_PHASE_CORRECT_PWM_MODE_TOP_OCR1A                       :
				SET_BIT(TCCR1A,WGM11);
				SET_BIT(TCCR1A,WGM10);
				SET_BIT(TCCR1B,WGM13);
				CLEAR_BIT(TCCR1B,WGM12);
				break ;
			case MTIM1_CTC_MODE_TOP_ICR1                                      :
				CLEAR_BIT(TCCR1A,WGM11);
				CLEAR_BIT(TCCR1A,WGM10);
				SET_BIT(TCCR1B,WGM13);
				SET_BIT(TCCR1B,WGM12);
				break ;
			case MTIM1_FAST_PWM_TOP_ICR1                                      :
				SET_BIT(TCCR1A,WGM11);
				CLEAR_BIT(TCCR1A,WGM10);
				SET_BIT(TCCR1B,WGM13);
				SET_BIT(TCCR1B,WGM12);
				break ;
			case MTIM1_FAST_PWM_TOP_OCR1A                                     :
				SET_BIT(TCCR1A,WGM11);
				SET_BIT(TCCR1A,WGM10);
				SET_BIT(TCCR1B,WGM13);
				SET_BIT(TCCR1B,WGM12);
				break ;
			default: L_stderrStatus = E_NOK ;
			break ;



			}
			MTIM_u8Timer1Prescaler = ARG_u8TimerPrescaler;

		}
		break ;
		case MTIM_TIMER2 :
		{
			switch(ARG_u8TimerMode)
			{
			case MTIM2_NORMAL_MODE:
				CLEAR_BIT(TCCR2,WGM20);
				CLEAR_BIT(TCCR2,WGM21);
				break ;
			case MTIM2_PHASE_CORRECT_PWM_MODE:
				SET_BIT(TCCR2,WGM20);
				CLEAR_BIT(TCCR2,WGM21);
				break ;
			case MTIM2_CTC_MODE:
				CLEAR_BIT(TCCR2,WGM20);
				SET_BIT(TCCR2,WGM21);
				break ;
			case MTIM2_FAST_PWM_MODE:
				SET_BIT(TCCR2,WGM20);
				SET_BIT(TCCR2,WGM21);
				break ;
			default: L_stderrStatus = E_NOK ; break ;
			}
			MTIM_u8Timer2Prescaler = ARG_u8TimerPrescaler;
		}
		break ;
		default : L_stderrStatus = E_OK  ;
		}
	}
	else
	{
		L_stderrStatus = E_NOK ;
	}
	return L_stderrStatus ;
}
STD_error_t MTIM_stderrEnableInterrupt(u8 ARG_u8TimerNo, u8 ARG_u8TimerInterrupt)
{
	STD_error_t L_stderrStatus = E_OK ;

	switch(ARG_u8TimerNo)
	{
	case MTIM_TIMER0 :
		if(MTIM0_CTC_INTERRUPT == ARG_u8TimerInterrupt)
		{
			SET_BIT(TIMSK,OCIE0);
		}
		else if(MTIM0_OVERFLOW_INTERRUPT == ARG_u8TimerInterrupt)
		{
			SET_BIT(TIMSK,TOIE0);
		}
		else
		{
			L_stderrStatus = E_NOK ;
		}
		break ;
	case MTIM_TIMER1:
		if(MTIM1_CTCA_INTERRUPT == ARG_u8TimerInterrupt)
		{
			SET_BIT(TIMSK,OCIE1A);
		}
		else if(MTIM1_CTCB_INTERRUPT == ARG_u8TimerInterrupt)
		{
			SET_BIT(TIMSK,OCIE1B);
		}
		else if(MTIM1_OVERFLOW_INTERRUPT == ARG_u8TimerInterrupt)
		{
			SET_BIT(TIMSK,TOIE1);
		}
		else if(MTIM1_ICU_INTERRUPT == ARG_u8TimerInterrupt)
		{
			SET_BIT(TIMSK,TICIE1);
		}
		else
		{
			L_stderrStatus = E_NOK ;
		}
		break ;
	case MTIM_TIMER2:
		if(MTIM2_CTC_INTERRUPT== ARG_u8TimerInterrupt)
		{
			SET_BIT(TIMSK,OCIE2);
		}
		else if(MTIM0_OVERFLOW_INTERRUPT == ARG_u8TimerInterrupt)
		{
			SET_BIT(TIMSK,TOIE2);
		}
		else
		{
			L_stderrStatus = E_NOK ;
		}
		break ;

	default: L_stderrStatus = E_NOK ; break ;
	}
	return L_stderrStatus ;
}
STD_error_t MTIM_stderrDisableInterrupt(u8 ARG_u8TimerNo, u8 ARG_u8TimerInterrupt)
{
	STD_error_t L_stderrStatus = E_OK ;
	switch(ARG_u8TimerNo)
	{
	case MTIM_TIMER0 :
		if(MTIM0_CTC_INTERRUPT == ARG_u8TimerInterrupt)
		{
			CLEAR_BIT(TIMSK,OCIE0);
		}
		else if(MTIM0_OVERFLOW_INTERRUPT == ARG_u8TimerInterrupt)
		{
			CLEAR_BIT(TIMSK,TOIE0);
		}
		else
		{
			L_stderrStatus = E_NOK ;
		}
		break ;
	case MTIM_TIMER1:
		if(MTIM1_CTCA_INTERRUPT == ARG_u8TimerInterrupt)
		{
			CLEAR_BIT(TIMSK,OCIE1A);
		}
		else if(MTIM1_CTCB_INTERRUPT == ARG_u8TimerInterrupt)
		{
			CLEAR_BIT(TIMSK,OCIE1B);
		}
		else if(MTIM1_OVERFLOW_INTERRUPT == ARG_u8TimerInterrupt)
		{
			CLEAR_BIT(TIMSK,TOIE1);
		}
		else if(MTIM1_ICU_INTERRUPT == ARG_u8TimerInterrupt)
		{
			CLEAR_BIT(TIMSK,TICIE1);
		}
		else
		{
			L_stderrStatus = E_NOK ;
		}
		break ;
	case MTIM_TIMER2:
		if(MTIM2_CTC_INTERRUPT== ARG_u8TimerInterrupt)
		{
			CLEAR_BIT(TIMSK,OCIE2);
		}
		else if(MTIM0_OVERFLOW_INTERRUPT == ARG_u8TimerInterrupt)
		{
			CLEAR_BIT(TIMSK,TOIE2);
		}
		else
		{
			L_stderrStatus = E_NOK ;
		}
		break ;
		break ;

	default: L_stderrStatus = E_NOK ; break ;
	}
	return L_stderrStatus ;
}
STD_error_t MTIM_stderrStartTimer(u8 ARG_u8TimerNo)
{
	STD_error_t L_stderrStatus = E_OK ;
	switch(ARG_u8TimerNo)
	{
	case MTIM_TIMER0 :
		TCCR0 = (TCCR0 &0xF8) | MTIM_u8Timer0Prescaler ;
		break ;
	case MTIM_TIMER1:
		TCCR1B = (TCCR1B&0xF8) |MTIM_u8Timer1Prescaler;
		break ;
	case MTIM_TIMER2:
		TCCR2 = (TCCR2 &0xF8) | MTIM_u8Timer2Prescaler ;
		break ;

	default: L_stderrStatus = E_NOK ; break ;
	}
	return L_stderrStatus ;
}
STD_error_t MTIM_stderrStopTimer(u8 ARG_u8TimerNo)
{
	STD_error_t L_stderrStatus = E_OK ;
	switch(ARG_u8TimerNo)
	{
	case MTIM_TIMER0 :
		TCCR0 = (TCCR0 &0xF8) | MTIM0_NO_PRESCALER ;
		break ;
	case MTIM_TIMER1:
		TCCR1B = (TCCR1B&0xF8) |MTIM1_NO_PRESCALER;

		break ;
	case MTIM_TIMER2:
		TCCR0 = (TCCR0 &0xF8) | MTIM2_NO_PRESCALER ;
		break ;

	default: L_stderrStatus = E_NOK ; break ;
	}
	return L_stderrStatus ;
}
STD_error_t MTIM_stderrSetCallBackFunction(void (*ARG_pu8CallBackFunction)(void), u8 ARG_u8TimerNo,u8 ARG_u8TimerInterrupt)
{
	STD_error_t L_stderrStatus = E_OK ;
	if(ARG_pu8CallBackFunction!=NULL_POINTER)
	{
		switch(ARG_u8TimerNo)
		{
		case MTIM_TIMER0 :
			if( MTIM0_CTC_INTERRUPT== ARG_u8TimerInterrupt)
			{
				MTMI0_pvoidfUserFunctionCTC = ARG_pu8CallBackFunction ;
			}
			else if(MTIM0_OVERFLOW_INTERRUPT== ARG_u8TimerInterrupt)
			{
				MTMI0_pvoidfUserFunctionOVF = ARG_pu8CallBackFunction;
			}
			else
			{
				L_stderrStatus = E_NOK ;
			}


			break ;
		case MTIM_TIMER1:
			if(MTIM1_CTCA_INTERRUPT == ARG_u8TimerInterrupt)
			{
				MTMI1_pvoidfUserFunctionCTCA = ARG_pu8CallBackFunction;
			}
			else if(MTIM1_CTCB_INTERRUPT == ARG_u8TimerInterrupt)
			{
				MTMI1_pvoidfUserFunctionCTCA = ARG_pu8CallBackFunction;
			}
			else if(MTIM1_OVERFLOW_INTERRUPT == ARG_u8TimerInterrupt)
			{
				MTMI1_pvoidfUserFunctionOVF = ARG_pu8CallBackFunction;
			}
			else if(MTIM1_ICU_INTERRUPT == ARG_u8TimerInterrupt)
			{
				MTMI1_pvoidfUserFunctionICU = ARG_pu8CallBackFunction;
			}
			else
			{
				L_stderrStatus = E_NOK ;
			}
			break ;
		case MTIM_TIMER2:
			if( MTIM2_CTC_INTERRUPT== ARG_u8TimerInterrupt)
			{
				MTMI2_pvoidfUserFunctionCTC = ARG_pu8CallBackFunction ;
			}
			else if(MTIM2_OVERFLOW_INTERRUPT== ARG_u8TimerInterrupt)
			{
				MTMI2_pvoidfUserFunctionOVF = ARG_pu8CallBackFunction;
			}
			else
			{
				L_stderrStatus = E_NOK ;
			}
			break ;

		default: L_stderrStatus = E_NOK ; break ;
		}
	}
	else
	{
		L_stderrStatus = E_NULL_POINTER ; ;
	}
	return L_stderrStatus ;
}
STD_error_t MTIM_stderrSetOCR(u8 ARG_u8TimerOCR, u16 ARG_u16OCRValue)
{
	STD_error_t L_stderrStatus = E_OK ;

	switch(ARG_u8TimerOCR)
	{
	case MTIM0_OCR0:
		OCR0 = ARG_u16OCRValue;
		break ;
	case MTIM1_OCR1A:
		OCR1A = ARG_u16OCRValue ;
		break ;
	case MTIM1_OCR1B:
		OCR1B = ARG_u16OCRValue ;
		break ;

	case MTIM2_OCR2:
		OCR2 = ARG_u16OCRValue ;
		break ;
	default: L_stderrStatus = E_NOK ;
	}

	return L_stderrStatus ;
}
STD_error_t MTIM_stderrSetHWPinMode(u8 ARG_u8TimerNo,u8 ARG_u8HWPinMode)
{
	STD_error_t L_stderrStatus = E_OK ;

	switch(ARG_u8TimerNo)
	{
	case MTIM_TIMER0:
		switch(ARG_u8HWPinMode)
		{
		case MTIM0_FAST_PWM_MODE_DISCONNECTED  :
			CLEAR_BIT(TCCR0,COM00);
			CLEAR_BIT(TCCR0,COM01);
			break ;
		case MTIM0_FAST_PWM_MODE_NON_INVERTING :
			CLEAR_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
			break ;
		case MTIM0_FAST_PWM_MODE_INVERTING     :
			SET_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
			break ;
		case MTIM0_PHASE_CORRECT_PWM_MODE_OC0_DISCONNECTED  :
			CLEAR_BIT(TCCR0,COM00);
			CLEAR_BIT(TCCR0,COM01);
			break ;
		case MTIM0_PHASE_CORRECT_PWM_MODE_OC0_SET_ON_CM :
			CLEAR_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
			break ;
		case MTIM0_PHASE_CORRECT_PWM_MODE_OC0_CLEAR_ON_CM     :
			SET_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
			break ;
		}
		break ;
		case MTIM_TIMER1:
		{
		case MTIM1_FAST_PWM_MODE_DISCONNECTED_OC1A  :
			CLEAR_BIT(TCCR1A,COM1A1);
			CLEAR_BIT(TCCR1A,COM1A0);
			break ;
		case MTIM1_FAST_PWM_MODE_NON_INVERTING_OC1A :
			CLEAR_BIT(TCCR1A,COM1A0);
			SET_BIT(TCCR1A,COM1A1);
			break ;
		case MTIM1_FAST_PWM_MODE_INVERTING_OC1A     :
			SET_BIT(TCCR1A,COM1A1);
			SET_BIT(TCCR1A,COM1A0);
			break ;
		case MTIM1_FAST_PWM_MODE_DISCONNECTED_OC1B  :
			CLEAR_BIT(TCCR1A,COM1B1);
			CLEAR_BIT(TCCR1A,COM1B0);
			break ;
		case MTIM1_FAST_PWM_MODE_NON_INVERTING_OC1B :
			CLEAR_BIT(TCCR1A,COM1B1);
			SET_BIT(TCCR1A,COM1B0);
			break ;
		case MTIM1_FAST_PWM_MODE_INVERTING_OC1B     :
			SET_BIT(TCCR1A,COM1B1);
			SET_BIT(TCCR1A,COM1B0);
			break ;

		case MTIM1_PHASE_CORRECT_PWM_MODE_OC1A_DISCONNECTED  :
			CLEAR_BIT(TCCR1A,COM1A1);
			CLEAR_BIT(TCCR1A,COM1A0);
			break ;
		case MTIM1_PHASE_CORRECT_PWM_MODE_OC1A_CLEAR_ON_CM :
			CLEAR_BIT(TCCR1A,COM1A0);
			SET_BIT(TCCR1A,COM1A1);
			break ;
		case MTIM1_PHASE_CORRECT_PWM_MODE_OC1A_SET_ON_CM     :
			SET_BIT(TCCR1A,COM1A1);
			SET_BIT(TCCR1A,COM1A0);
			break ;
		case MTIM1_PHASE_CORRECT_PWM_MODE_OC1B_DISCONNECTED  :
			CLEAR_BIT(TCCR1A,COM1B1);
			CLEAR_BIT(TCCR1A,COM1B0);
			break ;
		case MTIM1_PHASE_CORRECT_PWM_MODE_OC1B_CLEAR_ON_CM :
			CLEAR_BIT(TCCR1A,COM1B1);
			SET_BIT(TCCR1A,COM1B0);
			break ;
		case MTIM1_PHASE_CORRECT_PWM_MODE_OC1B_SET_ON_CM     :
			SET_BIT(TCCR1A,COM1B1);
			SET_BIT(TCCR1A,COM1B0);
			break ;

		}
		break ;
		case MTIM_TIMER2:
			switch(ARG_u8HWPinMode)
			{
			case MTIM2_FAST_PWM_MODE_DISCONNECTED  :
				CLEAR_BIT(TCCR2,COM20);
				CLEAR_BIT(TCCR2,COM21);
				break ;
			case MTIM2_FAST_PWM_MODE_NON_INVERTING :
				CLEAR_BIT(TCCR2,COM20);
				SET_BIT(TCCR2,COM21);
				break ;
			case MTIM2_FAST_PWM_MODE_INVERTING     :
				SET_BIT(TCCR2,COM20);
				SET_BIT(TCCR2,COM21);
				break ;
			case MTIM2_PHASE_CORRECT_PWM_MODE_OC2_DISCONNECTED  :
				CLEAR_BIT(TCCR2,COM20);
				CLEAR_BIT(TCCR2,COM21);
				break ;
			case MTIM2_PHASE_CORRECT_PWM_MODE_OC2_SET_ON_CM :
				CLEAR_BIT(TCCR2,COM20);
				SET_BIT(TCCR2,COM21);
				break ;
			case MTIM2_PHASE_CORRECT_PWM_MODE_OC2_CLEAR_ON_CM     :
				SET_BIT(TCCR2,COM20);
				SET_BIT(TCCR2,COM21);
				break ;
			}
			break ;
			default: L_stderrStatus = E_NOK ;
	}

	return L_stderrStatus ;
}
STD_error_t MTIM_stderrSetOCRInterrupt(u8 ARG_u8TimerOCR, u16 ARG_u16OCRValue,u32 ARG_u32OCRNOofInterrupts)
{
	STD_error_t L_stderrStatus = E_OK ;

	switch(ARG_u8TimerOCR)
	{
	case MTIM0_OCR0:
		OCR0 = ARG_u16OCRValue;
		MTIM_u32Timer0OCRCount = ARG_u32OCRNOofInterrupts;
		break ;
	case MTIM1_OCR1A:
		OCR1A = ARG_u16OCRValue;
		MTIM_u32Timer1OCRACount = ARG_u32OCRNOofInterrupts;
		break ;
	case MTIM1_OCR1B:
		OCR1B = ARG_u16OCRValue;
		MTIM_u32Timer1OCRBCount = ARG_u32OCRNOofInterrupts;
		break ;

	case MTIM2_OCR2:
		OCR2 = ARG_u16OCRValue;
		MTIM_u32Timer2OCRCount = ARG_u32OCRNOofInterrupts;
		break ;
	default: L_stderrStatus = E_NOK ;
	}

	return L_stderrStatus ;
}
STD_error_t MTIM_stderrTimerDelay(u8 ARG_u8TimerNo, u32 ARG_u32Delay)
{
	STD_error_t L_stderrStatus = E_OK ;
	u16 L_u16Prescaler ;
	f32 L_f32TickTime, L_f32MaxDelay  ;
	switch(ARG_u8TimerNo)
	{
	case MTIM_TIMER0:
		switch(MTIM_u8Timer0Prescaler)
		{
		case MTIM0_PRESCALER_1: L_u16Prescaler = 1 	     ; 	 break ;
		case MTIM0_PRESCALER_8: L_u16Prescaler = 8 	     ;   break ;
		case MTIM0_PRESCALER_64: L_u16Prescaler = 64     ;   break ;
		case MTIM0_PRESCALER_256: L_u16Prescaler = 256   ; 	 break ;
		case MTIM0_PRESCALER_1024: L_u16Prescaler = 1024 ; 	 break ;
		}
		L_f32TickTime =(f32)L_u16Prescaler/MICRO_CONTROLLER_CLCK ;
		L_f32MaxDelay = (f32)L_f32TickTime*MTIMER_TIMER0_RESLOUTION ;
		MTIM_u32Timer0OVFCount = ((f32)ARG_u32Delay)/L_f32MaxDelay ;
		MTIM_u8Timer0PreloadValue = MTIMER_TIMER0_RESLOUTION - (ARG_u32Delay/1000)%(u32)L_f32MaxDelay ;
		TCNT0 = MTIM_u8Timer0PreloadValue ;
		break ;
		case MTIM_TIMER1:
			switch(MTIM_u8Timer1Prescaler)
			{
			case MTIM1_PRESCALER_1: L_u16Prescaler = 1 	     ; 	 break ;
			case MTIM1_PRESCALER_8: L_u16Prescaler = 8 	     ;   break ;
			case MTIM1_PRESCALER_64: L_u16Prescaler = 64     ;   break ;
			case MTIM1_PRESCALER_256: L_u16Prescaler = 256   ; 	 break ;
			case MTIM1_PRESCALER_1024: L_u16Prescaler = 1024 ; 	 break ;
			}
			L_f32TickTime =(f32)L_u16Prescaler/MICRO_CONTROLLER_CLCK ;
			L_f32MaxDelay = (f32)L_f32TickTime*MTIMER_TIMER1_RESLOUTION ;

			MTIM_u32Timer1OVFCount = ((f32)ARG_u32Delay/1000.0)/L_f32MaxDelay ;

			MTIM_u16Timer1PreloadValue = MTIMER_TIMER1_RESLOUTION - MTIMER_TIMER1_RESLOUTION*(((f32)ARG_u32Delay/1000.0)/L_f32MaxDelay) ;
			TCNT1H = (MTIM_u16Timer1PreloadValue) ;





			break ;
			case MTIM_TIMER2:
				switch(MTIM_u8Timer2Prescaler)
				{
				case MTIM2_PRESCALER_1: L_u16Prescaler = 1 	     ; 	 break ;
				case MTIM2_PRESCALER_8: L_u16Prescaler = 8 	     ;   break ;
				case MTIM2_PRESCALER_64: L_u16Prescaler = 64     ;   break ;
				case MTIM2_PRESCALER_256: L_u16Prescaler = 256   ; 	 break ;
				case MTIM2_PRESCALER_1024: L_u16Prescaler = 1024 ; 	 break ;
				}
				L_f32TickTime =(f32)L_u16Prescaler/MICRO_CONTROLLER_CLCK ;
				L_f32MaxDelay = (f32)L_f32TickTime*MTIMER_TIMER2_RESLOUTION ;
				MTIM_u32Timer2OVFCount = ((f32)ARG_u32Delay/1000.0)/L_f32MaxDelay ;
				MTIM_u8Timer2PreloadValue = MTIMER_TIMER2_RESLOUTION - (ARG_u32Delay/1000)%(u32)L_f32MaxDelay ;
				TCNT2 = MTIM_u8Timer2PreloadValue ;
				break ;
				default: L_stderrStatus = E_NOK ;
	}

	return L_stderrStatus ;
}
STD_error_t MTIM_stderrSetTimerValue(u8 ARG_u8TimerNo,u16 ARG_u16TimerValue)
{
	STD_error_t L_stderrStatus = E_OK ;
	switch(ARG_u8TimerNo)
	{
	case MTIM_TIMER0:
		TCNT0 = ARG_u16TimerValue ;
		break ;
	case MTIM_TIMER1:
		TCNT1 = ARG_u16TimerValue;
		break ;
	case MTIM_TIMER2:
		TCNT2 = ARG_u16TimerValue ;
		break ;
	default: L_stderrStatus = E_NOK ;
	}

	return L_stderrStatus ;
}
STD_error_t MTIM_stderrGetTimerValue(u16 *ARG_u16pTimerValue, u8 ARG_u8TimerNo)
{
	STD_error_t L_stderrStatus = E_OK ;
	switch(ARG_u8TimerNo)
	{
	case MTIM_TIMER0:
		*ARG_u16pTimerValue = TCNT0 ;
		break ;
	case MTIM_TIMER1:
		*ARG_u16pTimerValue = TCNT1 ;
		break ;
	case MTIM_TIMER2:
		*ARG_u16pTimerValue = TCNT2 ;
		break ;
	default: L_stderrStatus = E_NOK ;
	}

	return L_stderrStatus ;
}

void MTIM_voidSetICRValue(u16 ARG_u16ICRValue)
{
	ICRR1 =  ARG_u16ICRValue ;
}








/*Timer 2 CTC Interrupt*/
void __vector_4 (void) __attribute__ ((signal));
void __vector_4 (void)
{
	static volatile u32 L_u32CTCCountr = 0 ;
	if(MTMI2_pvoidfUserFunctionCTC!= NULL_POINTER)
	{

		if(L_u32CTCCountr==MTIM_u32Timer2OCRCount)
		{
			MTMI2_pvoidfUserFunctionCTC();
		}
		else
		{
			L_u32CTCCountr++;
		}
	}
	else
	{

	}
}


/*Timer 2 OVF Interrupt*/
void __vector_5 (void) __attribute__ ((signal));
void __vector_5 (void)
{
	static volatile u32 L_u32OverFlowsCount = 0 ;
	if(MTMI2_pvoidfUserFunctionOVF!= NULL_POINTER)
	{
		if(MTIM_u32Timer2OVFCount+1 ==  L_u32OverFlowsCount)
		{
			MTMI2_pvoidfUserFunctionOVF();
			L_u32OverFlowsCount = 0 ;
			TCNT2 = MTIM_u8Timer2PreloadValue;
		}
		else
		{
			L_u32OverFlowsCount++ ;
		}

	}
	else
	{

	}

}

/*Timer 1 ICU Interrupt*/
void __vector_6 (void) __attribute__ ((signal));
void __vector_6 (void)
{
	if(MTMI1_pvoidfUserFunctionICU!= NULL_POINTER)
	{

		MTMI1_pvoidfUserFunctionICU();


	}
	else
	{

	}
}


/*Timer 1 CTC Interrupt*/
void __vector_7 (void) __attribute__ ((signal));
void __vector_7 (void)
{
	static volatile u32 L_u32CTCCountr = 0 ;
	if(MTMI1_pvoidfUserFunctionCTCA!= NULL_POINTER)
	{

		if(L_u32CTCCountr==MTIM_u32Timer1OCRACount)
		{
			MTMI1_pvoidfUserFunctionCTCA();
		}
		else
		{
			L_u32CTCCountr++;
		}
	}
	else
	{

	}

}
/*Timer 1 CTC Interrupt*/
void __vector_8 (void) __attribute__ ((signal));
void __vector_8 (void)
{

	static volatile u32 L_u32CTCCountr = 0 ;
	if(MTMI1_pvoidfUserFunctionCTCB!= NULL_POINTER)
	{

		if(L_u32CTCCountr==MTIM_u32Timer1OCRBCount)
		{
			MTMI1_pvoidfUserFunctionCTCB();
		}
		else
		{
			L_u32CTCCountr++;
		}
	}
	else
	{

	}

}

/*Timer 1 OVF Interrupt*/
void __vector_9 (void) __attribute__ ((signal));
void __vector_9 (void)
{
	static volatile u32 L_u32OverFlowsCount = 0 ;
	if(MTMI1_pvoidfUserFunctionOVF!= NULL_POINTER)
	{
		if(MTIM_u32Timer1OVFCount+1 ==  L_u32OverFlowsCount)
		{
			MTMI1_pvoidfUserFunctionOVF();
			L_u32OverFlowsCount = 0 ;
			TCNT1 = MTIM_u16Timer1PreloadValue;
		}
		else
		{
			L_u32OverFlowsCount++ ;
		}

	}
	else
	{

	}

}




/*Timer 0 CTC Interrupt*/
void __vector_10 (void) __attribute__ ((signal));
void __vector_10 (void)
{
	static volatile u32 L_u32CTCCountr = 0 ;
	if(MTMI0_pvoidfUserFunctionCTC!= NULL_POINTER)
	{

		if(L_u32CTCCountr==MTIM_u32Timer0OCRCount)
		{
			MTMI0_pvoidfUserFunctionCTC();
		}
		else
		{
			L_u32CTCCountr++;
		}
	}
	else
	{

	}
}


/*Timer 0 OVF Interrupt*/
void __vector_11 (void) __attribute__ ((signal));
void __vector_11 (void)
{
	static volatile u32 L_u32OverFlowsCount = 0 ;
	if(MTMI0_pvoidfUserFunctionOVF!= NULL_POINTER)
	{
		if(MTIM_u32Timer0OVFCount+1 ==  L_u32OverFlowsCount)
		{
			MTMI0_pvoidfUserFunctionOVF();
			L_u32OverFlowsCount = 0 ;
			TCNT0 = MTIM_u8Timer0PreloadValue;
		}
		else
		{
			L_u32OverFlowsCount++ ;
		}

	}
	else
	{

	}

}
