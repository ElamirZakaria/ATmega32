/**********************************/
/* Author    : Elamir Galal       */
/* SWC       : LCD		          */
/* Layer     : HAL	 		      */
/* Version   : 1.0                */
/* Date      : December 4,2023    */
/* Last Edit : December 4,2023    */
/**********************************/




#ifndef HLCD_INTERFACE_H	
#define HLCD_INTERFACE_H	

#define HLCD_PORTA		0
#define HLCD_PORTB		1
#define HLCD_PORTC		2
#define HLCD_PORTD		3


#define HLCD_PIN0		0
#define HLCD_PIN1		1
#define HLCD_PIN2		2
#define HLCD_PIN3		3
#define HLCD_PIN4		4
#define HLCD_PIN5		5
#define HLCD_PIN6		6
#define HLCD_PIN7		7



#define HLCD_4_BIT_MODE 4
#define HLCD_8_BIT_MODE 8


static STD_error_t HLCD_stderrSendCommand(u8 ARG_u8Command);
static STD_error_t HLCD_stderrSendData(u8 ARG_u8Data);
void HLCD_voidInit(void);
void HLCD_voidClearDisplay(void);
void HLCD_voidDisplayString(const char * ccharpString);
void HLCD_voidGoToXY(u8 ARG_u8XPosition,u8 ARG_u8YPosition);
void HLCD_voidWriteSpecialCharacter(u8 * ARG_pu8Pattern, u8 Copy_u8PatternNumber, u8 ARG_u8XPosition,u8 ARG_u8YPosition);
void HLCD_voidShiftLeft(void);
void HLCD_voidWriteNumber(u32 ARG_u32Number);


#endif
