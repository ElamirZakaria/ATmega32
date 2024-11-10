/*
 * main.c
 *
 *  Created on: Dec 4, 2023
 *      Author: pc
 */

#include "LBIT_Math.h"
#include "LSTD_Types.h"
#include "HLCD_Interface.h"
#include "MDIO_Interface.h"
#include "util/delay.h"


u8 customChar0[] = {
		0B00100,
		0B00100,
		0B00100,
		0B00100,
		0B00100,
		0B00100,
		0B00100,
		0B00100
};
u8 customChar1[] = {
		0B00000,
		0B00001,
		0B10001,
		0B01001,
		0B00101,
		0B00011,
		0B11111,
		0B11111
};
u8 customChar2[] = {
		0B00000,
		0B00000,
		0B11110,
		0B10001,
		0B10001,
		0B01110,
		0B00000,
		0B00000
};
u8 customChar3[] = {
		0B00000,
		0B00100,
		0B00100,
		0B11111,
		0B00000,
		0B11000,
		0B00000,
		0B00000
};
u8 customChar4[] = {
		0B00000,
		0B00000,
		0B00001,
		0B00001,
		0B00010,
		0B00100,
		0B01000,
		0B10000
};



int main(void)
{
//	MDIO_stderrSetPortDirection(MDIO_PORTD,MDIO_PORT_OUTPUT);
//	MDIO_stderrSetPortDirection(MDIO_PORTC,MDIO_PORT_OUTPUT);
	HLCD_voidInit();
	HLCD_voidDisplayString("Elamir Galal I am 24 years old I am an engineer");



	while(1)
	{








//		HLCD_voidWriteSpecialCharacter(customChar0,0,0,15);
//		HLCD_voidWriteSpecialCharacter(customChar1,1,0,14);
//		HLCD_voidWriteSpecialCharacter(customChar2,2,0,13);
//		HLCD_voidWriteSpecialCharacter(customChar3,3,0,12);
//		HLCD_voidWriteSpecialCharacter(customChar4,4,0,11);
//		_delay_ms(1000);
//		HLCD_voidClearDisplay();
//		HLCD_voidWriteSpecialCharacter(customChar0,0,1,13);
//		HLCD_voidWriteSpecialCharacter(customChar1,1,1,12);
//		HLCD_voidWriteSpecialCharacter(customChar2,2,1,11);
//		HLCD_voidWriteSpecialCharacter(customChar3,3,1,10);
//		HLCD_voidWriteSpecialCharacter(customChar4,4,1,9);
//		_delay_ms(1000);
//		HLCD_voidClearDisplay();
//		HLCD_voidWriteSpecialCharacter(customChar0,0,0,7);
//		HLCD_voidWriteSpecialCharacter(customChar1,1,0,6);
//		HLCD_voidWriteSpecialCharacter(customChar2,2,0,5);
//		HLCD_voidWriteSpecialCharacter(customChar3,3,0,4);
//		HLCD_voidWriteSpecialCharacter(customChar4,4,0,3);
//		_delay_ms(1000);
//		HLCD_voidClearDisplay();
//		HLCD_voidWriteSpecialCharacter(customChar0,0,1,1);
//		HLCD_voidWriteSpecialCharacter(customChar1,1,1,15);
//		HLCD_voidWriteSpecialCharacter(customChar2,2,1,14);
//		HLCD_voidWriteSpecialCharacter(customChar3,3,1,13);
//		HLCD_voidWriteSpecialCharacter(customChar4,4,1,12);
//		_delay_ms(1000);
//		HLCD_voidClearDisplay();
	}
	return 0 ;
}
