/**********************************/
/* Author    : Elamir Galal       */
/* SWC       : LED				  */
/* Layer     : HAL	 		      */
/* Version   : 1.0                */
/* Date      : Dec 3,2023 		  */
/* Last Edit : Dec 3,2023 		  */
/**********************************/

#ifndef HLED_INTERFACE_H
#define HLED_INTERFACE_H


#define HLED_PORTA 		0
#define HLED_PORTB		1
#define HLED_PORTC 		2
#define HLED_PORTD		3

#define HLED_PIN0		0
#define HLED_PIN1		1
#define HLED_PIN2		2
#define HLED_PIN3		3
#define HLED_PIN4		4
#define HLED_PIN5		5
#define HLED_PIN6		6
#define HLED_PIN7		7

STD_error_t HLED_stderrLedInit(u8 ARG_u8Port, u8 ARG_u8Pin);
STD_error_t HLED_stderrLedOn(u8 ARG_u8Port, u8 ARG_u8Pin);
STD_error_t HLED_stderrLedOff(u8 ARG_u8Port, u8 ARG_u8Pin);
STD_error_t HLED_stderrLedToggle(u8 ARG_u8Port, u8 ARG_u8Pin);







#endif
