/**********************************/
/* Author    : Elamir Galal       */
/* SWC       : DIO		          */
/* Layer     : MCAL	 		      */
/* Version   : 1.0                */
/* Date      : November 25,2023   */
/* Last Edit : November 25,2023   */
/**********************************/

#include "LBIT_Math.h"
#include "LSTD_Types.h"


#include "MDIO_Interface.h"
#include "MDIO_Private.h"
#include "MDIO_Config.h"

STD_error_t MDIO_stderrSetPortDirection(u8 ARG_u8Port, u8 ARG_u8Direction)
{
	STD_error_t L_stderrStatus = E_OK ;
	if (ARG_u8Port <= MDIO_PORTD)
	{
		switch(ARG_u8Port)
		{
			case MDIO_PORTA : DDRA =  ARG_u8Direction ;break ;
			case MDIO_PORTB : DDRB =  ARG_u8Direction ;break ;
			case MDIO_PORTC : DDRC =  ARG_u8Direction ;break ;
			case MDIO_PORTD : DDRD =  ARG_u8Direction ;break ;
			default : L_stderrStatus = E_NOK ;
		}
	}
	else 
	{
		L_stderrStatus = E_NOK ;
	}
	return L_stderrStatus;
}
STD_error_t MDIO_stderrSetPortValue	  (u8 ARG_u8Port,  u8 ARG_u8PortValue)
{
	STD_error_t L_stderrStatus = E_OK ;
	if(ARG_u8Port<=MDIO_PORTD )
	{
		switch(ARG_u8Port)
		{
		case MDIO_PORTA : PORTA =  ARG_u8PortValue ; break  ;
		case MDIO_PORTB : PORTB =  ARG_u8PortValue ; break  ;
		case MDIO_PORTC : PORTC =  ARG_u8PortValue ; break  ;
		case MDIO_PORTD : PORTD =  ARG_u8PortValue ; break  ;
		}
	}
	else 
	{
		L_stderrStatus = E_NOK ;
	}
	return L_stderrStatus;
}
STD_error_t MDIO_stderrGetPortValue	  (u8 ARG_u8Port,  u8 *ARG_u8PortValue)
{
	STD_error_t L_stderrStatus = E_OK ;
	if(ARG_u8Port <= MDIO_PORTD)
	{
		switch(ARG_u8Port)
		{
			case MDIO_PORTA: *ARG_u8PortValue = PINA ; break ;
			case MDIO_PORTB: *ARG_u8PortValue = PINB ; break ;
			case MDIO_PORTC: *ARG_u8PortValue = PINC ; break ;
			case MDIO_PORTD: *ARG_u8PortValue = PIND ; break ; 
		}
	}
	else 
	{
		L_stderrStatus =E_NOK ;
	}
	return L_stderrStatus;
}
STD_error_t MDIO_stderrTogglePort	  (u8 ARG_u8Port)
{
	STD_error_t L_stderrStatus = E_OK ;
	if(ARG_u8Port<=MDIO_PORTD)
	{
		switch(ARG_u8Port)
		{
			case MDIO_PORTA: 
				TOGGLE_BIT(PORTA,MDIO_PIN0) ;
				TOGGLE_BIT(PORTA,MDIO_PIN1) ;
				TOGGLE_BIT(PORTA,MDIO_PIN2) ;
				TOGGLE_BIT(PORTA,MDIO_PIN3) ;
				TOGGLE_BIT(PORTA,MDIO_PIN4) ;
				TOGGLE_BIT(PORTA,MDIO_PIN5) ;
				TOGGLE_BIT(PORTA,MDIO_PIN6) ;
				TOGGLE_BIT(PORTA,MDIO_PIN7) ;
				break ; 
			case MDIO_PORTB:  
				TOGGLE_BIT(PORTB,MDIO_PIN0) ;
				TOGGLE_BIT(PORTB,MDIO_PIN1) ;
				TOGGLE_BIT(PORTB,MDIO_PIN2) ;
				TOGGLE_BIT(PORTB,MDIO_PIN3) ;
				TOGGLE_BIT(PORTB,MDIO_PIN4) ;
				TOGGLE_BIT(PORTB,MDIO_PIN5) ;
				TOGGLE_BIT(PORTB,MDIO_PIN6) ;
				TOGGLE_BIT(PORTB,MDIO_PIN7) ;
				break ; 
			case MDIO_PORTC:  
				TOGGLE_BIT(PORTC,MDIO_PIN0) ;
				TOGGLE_BIT(PORTC,MDIO_PIN1) ;
				TOGGLE_BIT(PORTC,MDIO_PIN2) ;
				TOGGLE_BIT(PORTC,MDIO_PIN3) ;
				TOGGLE_BIT(PORTC,MDIO_PIN4) ;
				TOGGLE_BIT(PORTC,MDIO_PIN5) ;
				TOGGLE_BIT(PORTC,MDIO_PIN6) ;
				TOGGLE_BIT(PORTC,MDIO_PIN7) ;
				break ; 
			case MDIO_PORTD:  
				TOGGLE_BIT(PORTD,MDIO_PIN0) ;
				TOGGLE_BIT(PORTD,MDIO_PIN1) ;
				TOGGLE_BIT(PORTD,MDIO_PIN2) ;
				TOGGLE_BIT(PORTD,MDIO_PIN3) ;
				TOGGLE_BIT(PORTD,MDIO_PIN4) ;
				TOGGLE_BIT(PORTD,MDIO_PIN5) ;
				TOGGLE_BIT(PORTD,MDIO_PIN6) ;
				TOGGLE_BIT(PORTD,MDIO_PIN7) ;
				break ; 
			default :L_stderrStatus =E_NOK  ;	
		}
	}
	else 
	{
		L_stderrStatus =E_NOK ;		
	}
	return L_stderrStatus;
}	





STD_error_t MDIO_stderrSetPinDirection(u8 ARG_u8Port, u8 ARG_u8Pin, u8 ARG_u8Direction)
{
	STD_error_t L_stderrStatus = E_OK ;
	if(ARG_u8Pin<=MDIO_PIN7 && ((ARG_u8Direction == MDIO_PIN_INPUT)||(ARG_u8Direction == MDIO_PIN_OUTPUT)))
	{
		switch(ARG_u8Port)
		{
			case MDIO_PORTA: 
				if(ARG_u8Direction == MDIO_PIN_OUTPUT)
				{
					SET_BIT(DDRA,ARG_u8Pin);
				}
				else 
				{
					CLEAR_BIT(DDRA,ARG_u8Pin);
				}
				break ; 
			case MDIO_PORTB: 
				if(ARG_u8Direction == MDIO_PIN_OUTPUT)
				{
					SET_BIT(DDRB,ARG_u8Pin);
				}
				else 
				{
					CLEAR_BIT(DDRB,ARG_u8Pin);
				}
				break ; 
			case MDIO_PORTC:
				if(ARG_u8Direction == MDIO_PIN_OUTPUT)
				{
					SET_BIT(DDRC, ARG_u8Pin);
				}
				else 
				{
					CLEAR_BIT(DDRC,ARG_u8Pin);
				}
				break ; 			
			case MDIO_PORTD: 
				if(ARG_u8Direction == MDIO_PIN_OUTPUT)
				{
					SET_BIT(DDRD, ARG_u8Pin);
				}
				else 
				{
					CLEAR_BIT(DDRD, ARG_u8Pin);
				}
				break ; 
			default : L_stderrStatus = E_NOK;
		}
	}
	else 
	{
		L_stderrStatus = E_NOK;
	}

	return L_stderrStatus;
}
STD_error_t MDIO_stderrSetPinValue	  (u8 ARG_u8Port, u8 ARG_u8Pin, u8 ARG_u8PinValue)
{
	STD_error_t L_stderrStatus = E_OK ;
	if(ARG_u8Pin<=MDIO_PIN7 && ((ARG_u8PinValue == MDIO_PIN_LOW)||(ARG_u8PinValue == MDIO_PIN_HIGH)||(ARG_u8PinValue == MDIO_PIN_INPUT_PULLUP)))
	{
		switch(ARG_u8Port)
		{
			case MDIO_PORTA:
				if(ARG_u8PinValue == MDIO_PIN_HIGH || ARG_u8PinValue == MDIO_PIN_INPUT_PULLUP)
				{
					SET_BIT(PORTA, ARG_u8Pin);
				}
				else 
				{
					CLEAR_BIT(PORTA, ARG_u8Pin);
				
				}
				break ; 
			case MDIO_PORTB:
				if(ARG_u8PinValue == MDIO_PIN_HIGH || ARG_u8PinValue == MDIO_PIN_INPUT_PULLUP)
				{
					SET_BIT(PORTB, ARG_u8Pin);
				}
				else 
				{
					CLEAR_BIT(PORTB, ARG_u8Pin);
				}
				break ; 
			case MDIO_PORTC: 
				if(ARG_u8PinValue == MDIO_PIN_HIGH || ARG_u8PinValue == MDIO_PIN_INPUT_PULLUP)
				{
					SET_BIT(PORTC, ARG_u8Pin);
				}
				else 
				{
					CLEAR_BIT(PORTC, ARG_u8Pin);
				}
				break ; 
			case MDIO_PORTD: 
				if(ARG_u8PinValue == MDIO_PIN_HIGH || ARG_u8PinValue == MDIO_PIN_INPUT_PULLUP)
				{
					SET_BIT(PORTD, ARG_u8Pin);
				}
				else 
				{
					CLEAR_BIT(PORTD, ARG_u8Pin);
				}
				break ; 
			default : break ; 
		}
	}
	else 
	{
		L_stderrStatus = E_NOK ; 
	}
	
	
	return L_stderrStatus;
}
STD_error_t MDIO_stderrGetPinValue	  (u8 ARG_u8Port, u8 ARG_u8Pin, u8 *ARG_u8PinValue)
{
	STD_error_t L_stderrStatus = E_OK ;
	if(ARG_u8Pin<=MDIO_PIN7)
	{
		switch(ARG_u8Port)
		{
			case MDIO_PORTA: *ARG_u8PinValue = GET_BIT(PINA,ARG_u8Pin); break ; 
			case MDIO_PORTB: *ARG_u8PinValue = GET_BIT(PINB,ARG_u8Pin); break ; 
			case MDIO_PORTC: *ARG_u8PinValue = GET_BIT(PINC,ARG_u8Pin); break ; 
			case MDIO_PORTD: *ARG_u8PinValue = GET_BIT(PIND,ARG_u8Pin); break ; 
			default : L_stderrStatus = E_NOK ; break ;
		}
	}
	else 
	{
		L_stderrStatus = E_NOK ; 
	}
	return L_stderrStatus;
}
STD_error_t MDIO_stderrTogglePin	  (u8 ARG_u8Port, u8 ARG_u8Pin)
{
	STD_error_t L_stderrStatus = E_OK ;
	if(ARG_u8Pin<=MDIO_PIN7)
	{
		switch(ARG_u8Port)
		{
			case MDIO_PORTA: TOGGLE_BIT(PORTA, ARG_u8Pin) ; break ;
			case MDIO_PORTB: TOGGLE_BIT(PORTB, ARG_u8Pin) ; break ;
			case MDIO_PORTC: TOGGLE_BIT(PORTC, ARG_u8Pin) ; break ;
			case MDIO_PORTD: TOGGLE_BIT(PORTD, ARG_u8Pin) ; break ;
			default : L_stderrStatus = E_NOK ;
		}
	}
	else 
	{
		L_stderrStatus = E_NOK; 
	}
	return L_stderrStatus;
}
