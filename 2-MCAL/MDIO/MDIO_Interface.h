/**********************************/
/* Author    : Elamir Galal       */
/* SWC       : DIO		          */
/* Layer     : MCAL	 		      */
/* Version   : 1.0                */
/* Date      : November 25,2023   */
/* Last Edit : November 25,2023   */
/**********************************/



#ifndef MDIO_INTERFACE_H	
#define MDIO_INTERFACE_H	


#define MDIO_PORT_INPUT	 		 0x00
#define MDIO_PORT_OUTPUT  		 0xFF

#define MDIO_PORT_INPUT_PULLUP	 0xFF
#define MDIO_PORT_HIGH	 		 0xFF
#define MDIO_PORT_LOW     		 0
					



#define MDIO_PIN_INPUT	 		 0
#define MDIO_PIN_OUTPUT  		 1

#define MDIO_PIN_INPUT_PULLUP	 1
#define MDIO_PIN_HIGH	 		 1
#define MDIO_PIN_LOW     		 0
							 
#define MDIO_PORTA	 		 0
#define MDIO_PORTB	 		 1
#define MDIO_PORTC	 		 2
#define MDIO_PORTD	 		 3
							 
							 
							 
#define MDIO_PIN0	 		 0
#define MDIO_PIN1	 		 1
#define MDIO_PIN2	 		 2
#define MDIO_PIN3	 		 3
#define MDIO_PIN4	 		 4
#define MDIO_PIN5	 		 5
#define MDIO_PIN6	 		 6
#define MDIO_PIN7	 		 7


STD_error_t MDIO_stderrSetPortDirection(u8 ARG_u8Port, u8 ARG_u8Direction);
STD_error_t MDIO_stderrSetPortValue	  (u8 ARG_u8Port,  u8 ARG_u8PortValue);
STD_error_t MDIO_stderrGetPortValue	  (u8 ARG_u8Port,  u8 *ARG_u8PortValue);
STD_error_t MDIO_stderrTogglePort	  (u8 ARG_u8Port); 		





STD_error_t MDIO_stderrSetPinDirection(u8 ARG_u8Port, u8 ARG_u8Pin, u8 ARG_u8Direction);
STD_error_t MDIO_stderrSetPinValue	  (u8 ARG_u8Port, u8 ARG_u8Pin, u8 ARG_u8PinValue);
STD_error_t MDIO_stderrGetPinValue	  (u8 ARG_u8Port, u8 ARG_u8Pin, u8 *ARG_u8PinValue);
STD_error_t MDIO_stderrTogglePin	  (u8 ARG_u8Port, u8 ARG_u8Pin); 		

#endif 