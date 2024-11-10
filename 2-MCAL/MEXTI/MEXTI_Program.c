/**********************************/
/* Author    : Elamir Galal       */
/* SWC       : EXTI		          */
/* Layer     : MCAL	 		      */
/* Version   : 1.0                */
/* Date      : December 6,2023    */
/* Last Edit : December 6,2023    */
/**********************************/

#include "LSTD_Types.h"
#include "LBIT_Math.h"
#include "MEXTI_Interface.h"
#include "MEXTI_Private.h"
#include "MEXTI_Config.h"

static void (*MEXTI_pvoidfUserFunctionINT0)(void) = NULL_POINTER ;
static void (*MEXTI_pvoidfUserFunctionINT1)(void) = NULL_POINTER ;
static void (*MEXTI_pvoidfUserFunctionINT2)(void) = NULL_POINTER ;
STD_error_t MEXTI_stderrInterruptTrigger(u8 ARG_u8Pin, u8 ARG_u8SenseControl)
{
	STD_error_t L_stderrStatus = E_OK ; 
	switch(ARG_u8Pin)
	{
		case MEXTI_INT0: 
		
		switch(ARG_u8SenseControl)
		{
			case MEXIT_RISING_EDGE	: 
			SET_BIT(MCUCR,ISC01);
			SET_BIT(MCUCR,ISC00);
			break ;
			case MEXTI_FALLING_EDGE	: 
			SET_BIT(MCUCR,ISC01);
			CLEAR_BIT(MCUCR,ISC00);
			break ;
			case MEXTI_ON_CHANGE	: 
			CLEAR_BIT(MCUCR,ISC01);
			SET_BIT(MCUCR,ISC00);
			break ;	
			case MEXTI_LOW_LEVEL	:
			CLEAR_BIT(MCUCR,ISC00);
			CLEAR_BIT(MCUCR,ISC01);
			break ;	
			default : L_stderrStatus = E_NOK ; break ; 
		}
		
		break; 
		case MEXTI_INT1: 
		switch(ARG_u8SenseControl)
		{
			case MEXIT_RISING_EDGE	: 
			SET_BIT(MCUCR,ISC11);
			SET_BIT(MCUCR,ISC10);
			break ;
			case MEXTI_FALLING_EDGE	: 
			SET_BIT(MCUCR,ISC11);
			CLEAR_BIT(MCUCR,ISC10);
			break ;
			case MEXTI_ON_CHANGE	: 
			CLEAR_BIT(MCUCR,ISC11);
			SET_BIT(MCUCR,ISC10);
			break ;	
			case MEXTI_LOW_LEVEL	:
			CLEAR_BIT(MCUCR,ISC10);
			CLEAR_BIT(MCUCR,ISC11);
			break ;	
			default : L_stderrStatus = E_NOK ; break ; 
		}
		
		break; 
		case MEXTI_INT2: 
		switch(ARG_u8SenseControl)
		{
			case MEXIT_RISING_EDGE	: 
			SET_BIT(MCUCSR,ISC2);
			break ;
			case MEXTI_FALLING_EDGE	: 
			CLEAR_BIT(MCUCR,ISC2);
			break ;
			default : L_stderrStatus = E_NOK ; break ; 
		}
		
		
		break; 
		default : L_stderrStatus = E_NOK ;  break ;
	}
	
	return L_stderrStatus ;
}
STD_error_t MEXTI_stderrEnableInterrupt(u8 ARG_u8Pin)
{
	STD_error_t L_stderrStatus = E_OK ; 
	switch(ARG_u8Pin)
	{
		case MEXTI_INT0 : 
		SET_BIT(GICR,INT0);
		break ;
		case MEXTI_INT1 : 
		SET_BIT(GICR,INT1);
		break ;
		case MEXTI_INT2 :
		SET_BIT(GICR,INT2);
		break ;
		default: L_stderrStatus = E_NOK ; 
	}
	return L_stderrStatus ;
}
STD_error_t MEXTI_stderrDisableInterrupt(u8 ARG_u8Pin)
{
	STD_error_t L_stderrStatus = E_OK ; 
	switch(ARG_u8Pin)
	{
		case MEXTI_INT0 : 
		CLEAR_BIT(GICR,INT0);
		break ;
		case MEXTI_INT1 : 
		CLEAR_BIT(GICR,INT1);
		break ;
		case MEXTI_INT2 :
		CLEAR_BIT(GICR,INT2);
		break ;
		default: L_stderrStatus = E_NOK ; 
	}
	return L_stderrStatus ;
}
STD_error_t MEXTI_stderrSetCallBackFunction(u8 ARG_u8Pin, void (*ARG_pvoidUsersFunction)(void))
{
	STD_error_t L_stderrStatus = E_NOK;
	if(ARG_pvoidUsersFunction!= NULL_POINTER)
	{
		switch(ARG_u8Pin)
		{
		case MEXTI_INT0:
			MEXTI_pvoidfUserFunctionINT0 = ARG_pvoidUsersFunction;
			break ;
		case MEXTI_INT1:
			MEXTI_pvoidfUserFunctionINT1 = ARG_pvoidUsersFunction;
			break ;
		case MEXTI_INT2:
			MEXTI_pvoidfUserFunctionINT2 = ARG_pvoidUsersFunction;
			break ;
		default :
			L_stderrStatus = E_NOK ;
			break ;


		}
	}
	else
	{
		L_stderrStatus = E_NULL_POINTER;
	}
	return L_stderrStatus;
}




void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if(MEXTI_pvoidfUserFunctionINT0!=NULL_POINTER)
	{
		MEXTI_pvoidfUserFunctionINT0();
	}
	else
	{

	}

}
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if(MEXTI_pvoidfUserFunctionINT1!=NULL_POINTER)
	{
		MEXTI_pvoidfUserFunctionINT1();
	}
	else
	{

	}

}
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if(MEXTI_pvoidfUserFunctionINT2!=NULL_POINTER)
	{
		MEXTI_pvoidfUserFunctionINT2();
	}
	else
	{

	}

}
