/**********************************/
/* Author    : Elamir Galal       */
/* SWC       : Timer	          */
/* Layer     : MCAL	 		      */
/* Version   : 1.0                */
/* Date      : December 12,2023   */
/* Last Edit : December 12,2023   */
/**********************************/


#ifndef _MTIM_INTERFACE_H_
#define _MTIM_INTERFACE_H_


/**************** Timers ****************/
#define MTIM_TIMER0							0
#define MTIM_TIMER1							1
#define MTIM_TIMER2							2


/**************** Timer  0 Modes ****************/
#define MTIM0_NORMAL_MODE					0
#define MTIM0_PHASE_CORRECT_PWM_MODE		1
#define MTIM0_CTC_MODE						2
#define MTIM0_FAST_PWM_MODE					3

/**************** Timer  1 Modes ****************/
#define MTIM1_NORMAL_MODE															0
#define MTIM1_PHASE_CORRECT_PWM_8_BIT_MODE                                          1
#define MTIM1_PHASE_CORRECT_PWM_9_BIT_MODE                                          2
#define MTIM1_PHASE_CORRECT_PWM_10_BIT_MODE                                         3
#define MTIM1_CTC_MODE                                                              4
#define MTIM1_FAST_PWM_8_BIT_MODE                                                   5
#define MTIM1_FAST_PWM_9_BIT_MODE                                                   6
#define MTIM1_FAST_PWM_10_BIT_MODE                                                  7
#define MTIM1_PHASE_CORRECT_PWM_AND_FREQ_CORRECT_BIT_MODE_TOP_ICR                   8
#define MTIM1_PHASE_CORRECT_PWM_AND_FREQ_CORRECT_BIT_MODE_TOP_OCR1A                 9
#define MTIM1_PHASE_CORRECT_PWM_MODE_TOP_ICR1                                       10
#define MTIM1_PHASE_CORRECT_PWM_MODE_TOP_OCR1A                                      11
#define MTIM1_CTC_MODE_TOP_ICR1                                                     12
#define MTIM1_FAST_PWM_TOP_ICR1                                                     13
#define MTIM1_FAST_PWM_TOP_OCR1A                                                    14
/**************** Timer  2 Modes ****************/
#define MTIM2_NORMAL_MODE					0
#define MTIM2_PHASE_CORRECT_PWM_MODE		1
#define MTIM2_CTC_MODE						2
#define MTIM2_FAST_PWM_MODE					3
/**************** Timer 0 OC PIN****************/
#define MTIM0_CTC_MODE_OC0_DISCONNECTED						0
#define MTIM0_CTC_MODE_OC0_TOGGLE_ON_CM						1
#define MTIM0_CTC_MODE_OC0_CLEAR_ON_CM						2
#define MTIM0_CTC_MODE_OC0_SET_ON_CM						3

#define MTIM0_FAST_PWM_MODE_DISCONNECTED					4
#define MTIM0_FAST_PWM_MODE_NON_INVERTING					5
#define MTIM0_FAST_PWM_MODE_INVERTING						6

#define MTIM0_PHASE_CORRECT_PWM_MODE_OC0_DISCONNECTED		7
#define MTIM0_PHASE_CORRECT_PWM_MODE_OC0_CLEAR_ON_CM		8
#define MTIM0_PHASE_CORRECT_PWM_MODE_OC0_SET_ON_CM			9
/**************** Timer 0 OC PIN****************/
#define MTIM1_CTC_MODE_OC1A_DISCONNECTED					0
#define MTIM1_CTC_MODE_OC1A_TOGGLE_ON_CM					1
#define MTIM1_CTC_MODE_OC1A_CLEAR_ON_CM						2
#define MTIM1_CTC_MODE_OC1A_SET_ON_CM						3

#define MTIM1_FAST_PWM_MODE_DISCONNECTED_OC1A				4
#define MTIM1_FAST_PWM_MODE_NON_INVERTING_OC1A				5
#define MTIM1_FAST_PWM_MODE_INVERTING_OC1A					6
#define MTIM1_FAST_PWM_MODE_DISCONNECTED_OC1B				22
#define MTIM1_FAST_PWM_MODE_NON_INVERTING_OC1B				21
#define MTIM1_FAST_PWM_MODE_INVERTING_OC1B					20

#define MTIM1_PHASE_CORRECT_PWM_MODE_OC1A_DISCONNECTED		7
#define MTIM1_PHASE_CORRECT_PWM_MODE_OC1A_CLEAR_ON_CM		8
#define MTIM1_PHASE_CORRECT_PWM_MODE_OC1A_SET_ON_CM			9
#define MTIM1_PHASE_CORRECT_PWM_MODE_OC1B_DISCONNECTED		10
#define MTIM1_PHASE_CORRECT_PWM_MODE_OC1B_CLEAR_ON_CM		11
#define MTIM1_PHASE_CORRECT_PWM_MODE_OC1B_SET_ON_CM			12
/**************** Timer 2 OC PIN****************/
#define MTIM2_CTC_MODE_OC2_DISCONNECTED						0
#define MTIM2_CTC_MODE_OC2_TOGGLE_ON_CM						1
#define MTIM2_CTC_MODE_OC2_CLEAR_ON_CM						2
#define MTIM2_CTC_MODE_OC2_SET_ON_CM						3

#define MTIM2_FAST_PWM_MODE_DISCONNECTED					4
#define MTIM2_FAST_PWM_MODE_NON_INVERTING					5
#define MTIM2_FAST_PWM_MODE_INVERTING						6

#define MTIM2_PHASE_CORRECT_PWM_MODE_OC2_DISCONNECTED		7
#define MTIM2_PHASE_CORRECT_PWM_MODE_OC2_CLEAR_ON_CM		8
#define MTIM2_PHASE_CORRECT_PWM_MODE_OC2_SET_ON_CM			9
/**************** Timer 0 Prescaler****************/
#define	MTIM0_NO_PRESCALER							0
#define MTIM0_PRESCALER_1							1
#define MTIM0_PRESCALER_8							2
#define MTIM0_PRESCALER_64							3
#define MTIM0_PRESCALER_256							4
#define MTIM0_PRESCALER_1024						5
#define MTIM0_PRESCALER_EXTERNAL_ON_FALLING_EDGE	6
#define MTIM0_PRESCALER_EXTERNAL_ON_RISING_EDGE		7
/**************** Timer 0 OCR****************/
#define MTIM0_OCR0									1
/**************** Timer 1 Prescaler****************/
#define	MTIM1_NO_PRESCALER							0
#define MTIM1_PRESCALER_1							1
#define MTIM1_PRESCALER_8							2
#define MTIM1_PRESCALER_64							3
#define MTIM1_PRESCALER_256							4
#define MTIM1_PRESCALER_1024						5
#define MTIM1_PRESCALER_EXTERNAL_ON_FALLING_EDGE	6
#define MTIM1_PRESCALER_EXTERNAL_ON_RISING_EDGE		7
/**************** Timer 1 OCR****************/
#define MTIM1_OCR1A									2
#define MTIM1_OCR1B									3
/**************** Timer 2 Prescaler****************/
#define	MTIM2_NO_PRESCALER							0
#define MTIM2_PRESCALER_1							1
#define MTIM2_PRESCALER_8							2
#define MTIM2_PRESCALER_64							3
#define MTIM2_PRESCALER_256							4
#define MTIM2_PRESCALER_1024						5
#define MTIM2_PRESCALER_EXTERNAL_ON_FALLING_EDGE	6
#define MTIM2_PRESCALER_EXTERNAL_ON_RISING_EDGE		7
/**************** Timer 0 OCR****************/
#define MTIM2_OCR2									4
/**************** Timer 0 Interrupt ****************/

#define	MTIM0_CTC_INTERRUPT							0
#define MTIM0_OVERFLOW_INTERRUPT					1

/**************** Timer 1 Interrupt ****************/

#define	MTIM1_CTCA_INTERRUPT						0
#define MTIM1_CTCB_INTERRUPT						1
#define MTIM1_OVERFLOW_INTERRUPT					2
#define MTIM1_ICU_INTERRUPT							3

/**************** Timer 2 Interrupt ****************/

#define	MTIM2_CTC_INTERRUPT							0
#define MTIM2_OVERFLOW_INTERRUPT					1



#define MTIMER_TIMER0_RESLOUTION 256
#define MTIMER_TIMER1_RESLOUTION 65536
#define MTIMER_TIMER2_RESLOUTION 256



STD_error_t MTIM_stderrTimerInit(u8 ARG_u8TimerNo, u8 ARG_u8TimerMode,u8 ARG_u8TimerPrescaler);
STD_error_t MTIM_stderrEnableInterrupt(u8 ARG_u8TimerNo, u8 ARG_u8TimerInterrupt);
STD_error_t MTIM_stderrDisableInterrupt(u8 ARG_u8TimerNo, u8 ARG_u8TimerInterrupt);
STD_error_t MTIM_stderrTimerDelay(u8 ARG_u8TimerNo, u32 ARG_u32Delay);
STD_error_t MTIM_stderrStartTimer(u8 ARG_u8TimerNo);
STD_error_t MTIM_stderrStopTimer(u8 ARG_u8TimerNo);
STD_error_t MTIM_stderrSetCallBackFunction(void (*ARG_pu8CallBackFunction)(void), u8 ARG_u8TimerNo,u8 ARG_u8TimerInterrupt);
STD_error_t MTIM_stderrSetOCR(u8 ARG_u8TimerNo, u16 ARG_u16OCRValue);
STD_error_t MTIM_stderrSetOCRInterrupt(u8 ARG_u8TimerNo, u16 ARG_u16OCRValue,u32 ARG_u32OCRNOofInterrupts);
STD_error_t MTIM_stderrSetHWPinMode(u8 ARG_u8TimerNo,u8 ARG_u8HWPinMode);
STD_error_t MTIM_stderrTimerDelay(u8 ARG_u8TimerNo, u32 ARG_u32Delay);
STD_error_t MTIM_stderrSetTimerValue(u8 ARG_u8TimerNo,u16 ARG_u16TimerValue);
STD_error_t MTIM_stderrGetTimerValue(u16 *ARG_u16pTimerValue, u8 ARG_u8TimerNo);

void MTIM_voidSetICRValue(u16 ARG_u16ICRValue);


#endif
