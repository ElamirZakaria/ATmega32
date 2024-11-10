/**********************************/
/* Author    : Elamir Galal       */
/* SWC       : Push Button		  */
/* Layer     : HAL	 		      */
/* Version   : 1.0                */
/* Date      : Dec 3,2023 		  */
/* Last Edit : Dec 3,2023 		  */
/**********************************/



#ifndef HPUSH_BUTTON_INTERFACE_H
#define HPUSH_BUTTON_INTERFACE_H


#define HPUSH_BUTTON_PORTA	0
#define HPUSH_BUTTON_PORTB	1
#define HPUSH_BUTTON_PORTC	2
#define HPUSH_BUTTON_PORTD	3

#define HPUSH_BUTTON_PIN0	0
#define HPUSH_BUTTON_PIN1	1
#define HPUSH_BUTTON_PIN2	2
#define HPUSH_BUTTON_PIN3	3
#define HPUSH_BUTTON_PIN4	4
#define HPUSH_BUTTON_PIN5	5
#define HPUSH_BUTTON_PIN6	6
#define HPUSH_BUTTON_PIN7	7


#define HPUSH_BUTTON_INPUT			1
#define HPUSH_BUTTON_INPUT_PULLUP	2

STD_error_t HPushButton_stderrInit(u8 ARG_u8Port, u8 ARG_u8Pin, u8 ARG_u8PinState);
STD_error_t HPushButton_stderrGetValue(u8 ARG_u8Port, u8 ARG_u8Pin, u8* ARG_u8pValue);












#endif
