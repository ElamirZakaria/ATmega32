/**********************************/
/* Author    : Elamir Galal       */
/* SWC       : LED				  */
/* Layer     : HAL	 		      */
/* Version   : 1.0                */
/* Date      : Dec 3,2023 		  */
/* Last Edit : Dec 3,2023 		  */
/**********************************/

#include "LBIT_Math.h"
#include "LSTD_Types.h"

#include "MDIO_Interface.h"


#include "HLED_Config.h"
#include "HLED_Interface.h"
#include "HLED_Private.h"


STD_error_t HLED_stderrLedInit(u8 ARG_u8Port, u8 ARG_u8Pin)
{
	STD_error_t L_stderrStatus = E_OK;
	L_stderrStatus = MDIO_stderrSetPinDirection(ARG_u8Port, ARG_u8Pin, MDIO_PIN_OUTPUT);
	return L_stderrStatus;
}
STD_error_t HLED_stderrLedOn(u8 ARG_u8Port, u8 ARG_u8Pin)
{
	STD_error_t L_stderrStatus = E_OK;
	L_stderrStatus = MDIO_stderrSetPinValue(ARG_u8Port, ARG_u8Pin, MDIO_PIN_HIGH);
	return L_stderrStatus;
}
STD_error_t HLED_stderrLedOff(u8 ARG_u8Port, u8 ARG_u8Pin)
{
	STD_error_t L_stderrStatus = E_OK;
	L_stderrStatus = MDIO_stderrSetPinValue(ARG_u8Port, ARG_u8Pin, MDIO_PIN_LOW);
	return L_stderrStatus;
}
STD_error_t HLED_stderrLedToggle(u8 ARG_u8Port, u8 ARG_u8Pin)
{
	STD_error_t L_stderrStatus = E_OK;
	L_stderrStatus = MDIO_stderrTogglePin(ARG_u8Port, ARG_u8Pin);
	return L_stderrStatus;
}







