/**********************************/
/* Author    : Elamir Galal       */
/* SWC       : DC Motor	          */
/* Layer     : HAL	 		      */
/* Version   : 1.0                */
/* Date      : December 5,2023    */
/* Last Edit : December 5,2023    */
/**********************************/



#ifndef HDC_INTERFACE_H
#define HDC_INTERFACE_H




#define HDC_PORTA		0
#define HDC_PORTB		1
#define HDC_PORTC		2
#define HDC_PORTD		3

#define HDC_PIN0		0
#define HDC_PIN1		1
#define HDC_PIN2		2
#define HDC_PIN3		3
#define HDC_PIN4		4
#define HDC_PIN5		5
#define HDC_PIN6		6
#define HDC_PIN7		7



STD_error_t HDC_stderrInit(u8 ARG_u8Port, u8 ARG_u8Pin);
STD_error_t HDC_stderrOn(u8 ARG_u8Port, u8 ARG_u8Pin);
STD_error_t HDC_stderrOff(u8 ARG_u8Port, u8 ARG_u8Pin);
STD_error_t HDC_stderrRotateCW(u8 ARG_u8Port, u8 ARG_u8FirstPin, u8 ARG_u8SecondPin);
STD_error_t HDC_stderrRotateCCW(u8 ARG_u8Port, u8 ARG_u8FirstPin, u8 ARG_u8SecondPin);




#endif
