/**********************************/
/* Author    : Elamir Galal       */
/* SWC       : Push Button		  */
/* Layer     : HAL	 		      */
/* Version   : 1.0                */
/* Date      : Dec 3,2023 		  */
/* Last Edit : Dec 3,2023 		  */
/**********************************/
#include "LBIT_Math.h"
#include "LSTD_Types.h"
#include "MDIO_Interface.h"
#include "HPush_Button_Config.h"
#include "HPush_Button_Private.h"
#include "HPush_Button_Interface.h"
#include "util/delay.h"

STD_error_t HPushButton_stderrInit(u8 ARG_u8Port, u8 ARG_u8Pin, u8 ARG_u8PinState)
{
	STD_error_t L_stderrStatus = E_OK ;
	L_stderrStatus = MDIO_stderrSetPinDirection(ARG_u8Port, ARG_u8Pin, MDIO_PIN_INPUT);
	if(ARG_u8PinState == HPUSH_BUTTON_INPUT)
	{
		/*do nothing*/
	}
	else if(ARG_u8PinState == HPUSH_BUTTON_INPUT_PULLUP)
	{
		MDIO_stderrSetPinValue(ARG_u8Port,ARG_u8Pin,MDIO_PIN_INPUT_PULLUP);
	}
	return L_stderrStatus;
}
STD_error_t HPushButton_stderrGetValue(u8 ARG_u8Port, u8 ARG_u8Pin, u8* ARG_u8pValue)
{
	STD_error_t L_stderrStatus = E_OK ;
	L_stderrStatus = MDIO_stderrGetPinValue(ARG_u8Port, ARG_u8Pin, ARG_u8pValue);
	_delay_ms(150);
	return L_stderrStatus;
}

