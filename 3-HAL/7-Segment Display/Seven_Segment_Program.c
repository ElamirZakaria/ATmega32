/**********************************/
/* Author    : Elamir Galal       */
/* SWC       : 7 Segment Dispaly  */
/* Layer     : HAL	 		      */
/* Version   : 1.0                */
/* Date      : Dec 3,2023 		  */
/* Last Edit : Dec 3,2023 		  */
/**********************************/

#include "LBIT_Math.h"
#include "LSTD_Types.h"


#include "MDIO_Interface.h"
#include "Seven_Segment_Config.h"
#include "Seven_Segment_Interface.h"
#include "Seven_Segment_Private.h"
#include "util/delay.h"




u8 Seven_Segment_Number[10] = {0b0111111,0b0000110,0b1011011,0b1001111,0b1100110,0b1101101,0b1111101,0b0000111,0b1111111,0b1101111};





STD_error_t HSevenSegment_stderrInit(u8 ARG_u8Port)
{
	STD_error_t L_stderrStatus = E_OK;
	if(ARG_u8Port<=HSEVEN_SEGMENT_PORTD)
	{
		MDIO_stderrSetPortDirection(ARG_u8Port,MDIO_PORT_OUTPUT);
	}
	else 
	{
		L_stderrStatus = E_NOK;
	}
	return L_stderrStatus ;
	
}
STD_error_t HSevenSegment_stderrDisplayWithDelay(u8 ARG_u8Port, u16 ARG_u16RequiredDelayBetweenElements)
{
	
		STD_error_t L_stderrStatus = E_OK;
		u8 L_u8Counter = 0 ; 
		if(ARG_u8Port<=HSEVEN_SEGMENT_PORTD)
		{
			while(L_u8Counter<10)
			{
				MDIO_stderrSetPinValue(ARG_u8Port,MDIO_PIN0, GET_BIT(Seven_Segment_Number[L_u8Counter],0));
				MDIO_stderrSetPinValue(ARG_u8Port,MDIO_PIN1, GET_BIT(Seven_Segment_Number[L_u8Counter],1));
				MDIO_stderrSetPinValue(ARG_u8Port,MDIO_PIN2, GET_BIT(Seven_Segment_Number[L_u8Counter],2));
				MDIO_stderrSetPinValue(ARG_u8Port,MDIO_PIN3, GET_BIT(Seven_Segment_Number[L_u8Counter],3));
				MDIO_stderrSetPinValue(ARG_u8Port,MDIO_PIN4, GET_BIT(Seven_Segment_Number[L_u8Counter],4));
				MDIO_stderrSetPinValue(ARG_u8Port,MDIO_PIN5, GET_BIT(Seven_Segment_Number[L_u8Counter],5));
				MDIO_stderrSetPinValue(ARG_u8Port,MDIO_PIN6, GET_BIT(Seven_Segment_Number[L_u8Counter],6));
				_delay_ms(ARG_u16RequiredDelayBetweenElements);
				L_u8Counter++;
			}
		}
		else 
		{
			L_stderrStatus = E_NOK;
		}
		return L_stderrStatus ;
		
}
void HSevenSegment_stderrDisable(u8 ARG_u8Port)
{
	MDIO_stderrSetPortValue(ARG_u8Port,MDIO_PORT_LOW);
}
STD_error_t HSevenSegment_stderrDisplayNumber(u8 ARG_u8Port, u8 ARG_u8Number)
{
	STD_error_t L_stderrStatus = E_OK;
		if(ARG_u8Port<=HSEVEN_SEGMENT_PORTD)
		{
				MDIO_stderrSetPinValue(ARG_u8Port,MDIO_PIN0, GET_BIT(Seven_Segment_Number[ARG_u8Number],0));
				MDIO_stderrSetPinValue(ARG_u8Port,MDIO_PIN1, GET_BIT(Seven_Segment_Number[ARG_u8Number],1));
				MDIO_stderrSetPinValue(ARG_u8Port,MDIO_PIN2, GET_BIT(Seven_Segment_Number[ARG_u8Number],2));
				MDIO_stderrSetPinValue(ARG_u8Port,MDIO_PIN3, GET_BIT(Seven_Segment_Number[ARG_u8Number],3));
				MDIO_stderrSetPinValue(ARG_u8Port,MDIO_PIN4, GET_BIT(Seven_Segment_Number[ARG_u8Number],4));
				MDIO_stderrSetPinValue(ARG_u8Port,MDIO_PIN5, GET_BIT(Seven_Segment_Number[ARG_u8Number],5));
				MDIO_stderrSetPinValue(ARG_u8Port,MDIO_PIN6, GET_BIT(Seven_Segment_Number[ARG_u8Number],6));		
		}
		else 
		{
			L_stderrStatus = E_NOK;
		}
		return L_stderrStatus ;
}
