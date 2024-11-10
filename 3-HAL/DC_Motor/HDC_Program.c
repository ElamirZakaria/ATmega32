/**********************************/
/* Author    : Elamir Galal       */
/* SWC       : DC Motor	          */
/* Layer     : HAL	 	  */
/* Version   : 1.0                */
/* Date      : December 5,2023    */
/* Last Edit : December 5,2023    */
/**********************************/


#include "LSTD_Types.h"
#include "MDIO_Interface.h"
#include "HDC_Config.h"
#include "HDC_Interface.h"

STD_error_t HDC_stderrInit(u8 ARG_u8Port, u8 ARG_u8Pin)
{
	STD_error_t L_stderrStatus = E_OK ;
	L_stderrStatus = MDIO_stderrSetPinDirection(ARG_u8Port,ARG_u8Pin,MDIO_PIN_OUTPUT);
	return L_stderrStatus ;
}
STD_error_t HDC_stderrOn(u8 ARG_u8Port, u8 ARG_u8Pin)
{
	STD_error_t L_stderrStatus = E_OK ;
	L_stderrStatus = MDIO_stderrSetPinValue(ARG_u8Port,ARG_u8Pin,MDIO_PIN_HIGH);
	return L_stderrStatus ;
}
STD_error_t HDC_stderrOff(u8 ARG_u8Port, u8 ARG_u8Pin)
{
	STD_error_t L_stderrStatus = E_OK ;
	L_stderrStatus = MDIO_stderrSetPinValue(ARG_u8Port,ARG_u8Pin,MDIO_PIN_LOW);
	return L_stderrStatus ;
}
STD_error_t HDC_stderrRotateCW(u8 ARG_u8Port, u8 ARG_u8FirstPin, u8 ARG_u8SecondPin)
{
	STD_error_t L_stderrStatus = E_OK ;
	L_stderrStatus = MDIO_stderrSetPinValue(ARG_u8Port,ARG_u8FirstPin,MDIO_PIN_LOW);
	L_stderrStatus = MDIO_stderrSetPinValue(ARG_u8Port,ARG_u8SecondPin,MDIO_PIN_HIGH);
	return L_stderrStatus ;
}
STD_error_t HDC_stderrRotateCCW(u8 ARG_u8Port, u8 ARG_u8FirstPin, u8 ARG_u8SecondPin)
{
	STD_error_t L_stderrStatus = E_OK ;
	L_stderrStatus = MDIO_stderrSetPinValue(ARG_u8Port,ARG_u8SecondPin,MDIO_PIN_LOW);
	L_stderrStatus = MDIO_stderrSetPinValue(ARG_u8Port,ARG_u8FirstPin,MDIO_PIN_HIGH);
	return L_stderrStatus ;
}

