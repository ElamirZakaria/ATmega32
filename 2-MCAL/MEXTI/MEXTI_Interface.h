/**********************************/
/* Author    : Elamir Galal       */
/* SWC       : EXTI		          */
/* Layer     : MCAL	 		      */
/* Version   : 1.0                */
/* Date      : December 6,2023    */
/* Last Edit : December 6,2023    */
/**********************************/



#ifndef MEXTI_Interface_H	
#define MEXTI_Interface_H

#define MEXTI_INT0					0
#define MEXTI_INT1					1
#define MEXTI_INT2					2
#define MEXIT_RISING_EDGE			0
#define MEXTI_FALLING_EDGE			1
#define MEXTI_ON_CHANGE				2
#define MEXTI_LOW_LEVEL				3






STD_error_t MEXTI_stderrInterruptTrigger(u8 ARG_u8Pin, u8 ARG_u8SenseControl);
STD_error_t MEXTI_stderrEnableInterrupt(u8 ARG_u8Pin);
STD_error_t MEXTI_stderrDisableInterrupt(u8 ARG_u8Pin);
STD_error_t MEXTI_stderrSetCallBackFunction(u8 ARG_u8Pin, void (*ARG_pvoidUsersFunction)(void));

#endif	
