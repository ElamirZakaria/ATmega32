/**********************************/
/* Author    : Elamir Galal       */
/* SWC       : LCD		          */
/* Layer     : HAL	 		      */
/* Version   : 1.0                */
/* Date      : December 4,2023    */
/* Last Edit : December 4,2023    */
/**********************************/


#include "LBIT_Math.h"
#include "LSTD_Types.h"
#include "MDIO_Interface.h"
#include "HLCD_Interface.h"
#include "HLCD_Config.h"
#include "HLCD_Private.h"
#include "util/delay.h"




static STD_error_t HLCD_stderrSendCommand(u8 ARG_u8Command)
{
	STD_error_t L_stderrStatus = E_OK ;
	/*Rs Pin is set low to send a command*/
	L_stderrStatus=MDIO_stderrSetPinValue(HLCD_RS_PIN,MDIO_PIN_LOW);
	/*Rw pin is set low to write on LCD*/
	L_stderrStatus=MDIO_stderrSetPinValue(HLCD_RW_PIN,MDIO_PIN_LOW);
#if HLCD_BIT_MODE == HLCD_8_BIT_MODE


	/*Put the command on the Data pins*/
	L_stderrStatus=MDIO_stderrSetPortValue(HLCD_DATA_PORT,ARG_u8Command);
	/*Send a pulse on the Enable pin*/
	L_stderrStatus=MDIO_stderrSetPinValue(HLCD_E_PIN,MDIO_PIN_HIGH);
	_delay_ms(2);
	L_stderrStatus=MDIO_stderrSetPinValue(HLCD_E_PIN,MDIO_PIN_LOW);

#elif HLCD_BIT_MODE == HLCD_4_BIT_MODE
	MDIO_stderrSetPinValue(HLCD_DATA_PORT, HLCD_D4_PIN, GET_BIT(ARG_u8Command,0));
	MDIO_stderrSetPinValue(HLCD_DATA_PORT, HLCD_D5_PIN, GET_BIT(ARG_u8Command,1));
	MDIO_stderrSetPinValue(HLCD_DATA_PORT, HLCD_D6_PIN, GET_BIT(ARG_u8Command,2));
	MDIO_stderrSetPinValue(HLCD_DATA_PORT, HLCD_D7_PIN, GET_BIT(ARG_u8Command,3));
	L_stderrStatus=MDIO_stderrSetPinValue(HLCD_E_PIN,MDIO_PIN_HIGH);
	_delay_ms(2);
	L_stderrStatus=MDIO_stderrSetPinValue(HLCD_E_PIN,MDIO_PIN_LOW);
	MDIO_stderrSetPinValue(HLCD_DATA_PORT, HLCD_D4_PIN, GET_BIT(ARG_u8Command,4));
	MDIO_stderrSetPinValue(HLCD_DATA_PORT, HLCD_D5_PIN, GET_BIT(ARG_u8Command,5));
	MDIO_stderrSetPinValue(HLCD_DATA_PORT, HLCD_D6_PIN, GET_BIT(ARG_u8Command,6));
	MDIO_stderrSetPinValue(HLCD_DATA_PORT, HLCD_D7_PIN, GET_BIT(ARG_u8Command,7));
	L_stderrStatus=MDIO_stderrSetPinValue(HLCD_E_PIN,MDIO_PIN_HIGH);
	_delay_ms(2);
	L_stderrStatus=MDIO_stderrSetPinValue(HLCD_E_PIN,MDIO_PIN_LOW);
#endif

	return L_stderrStatus;
}
static STD_error_t HLCD_stderrSendData(u8 ARG_u8Data)
{
	STD_error_t L_stderrStatus = E_OK ;
#if HLCD_BIT_MODE == HLCD_8_BIT_MODE

	/*Rs Pin is set high to send data*/
	L_stderrStatus=MDIO_stderrSetPinValue(HLCD_RS_PIN,MDIO_PIN_HIGH);
	/*Rw pin is set low to write on LCD*/
	L_stderrStatus=MDIO_stderrSetPinValue(HLCD_RW_PIN,MDIO_PIN_LOW);
	/*Put the command on the Data pins*/
	L_stderrStatus=MDIO_stderrSetPortValue(HLCD_DATA_PORT,ARG_u8Data);
	/*Send a pulse on the Enable pin*/
	L_stderrStatus=MDIO_stderrSetPinValue(HLCD_E_PIN,MDIO_PIN_HIGH);
	_delay_ms(2);
	L_stderrStatus=MDIO_stderrSetPinValue(HLCD_E_PIN,MDIO_PIN_LOW);
#elif HLCD_BIT_MODE == HLCD_4_BIT_MODE
	MDIO_stderrSetPinValue(HLCD_DATA_PORT, HLCD_D4_PIN, GET_BIT(ARG_u8Data,0));
	MDIO_stderrSetPinValue(HLCD_DATA_PORT, HLCD_D5_PIN, GET_BIT(ARG_u8Data,1));
	MDIO_stderrSetPinValue(HLCD_DATA_PORT, HLCD_D6_PIN, GET_BIT(ARG_u8Data,2));
	MDIO_stderrSetPinValue(HLCD_DATA_PORT, HLCD_D7_PIN, GET_BIT(ARG_u8Data,3));
	L_stderrStatus=MDIO_stderrSetPinValue(HLCD_E_PIN,MDIO_PIN_HIGH);
	_delay_ms(2);
	L_stderrStatus=MDIO_stderrSetPinValue(HLCD_E_PIN,MDIO_PIN_LOW);
	MDIO_stderrSetPinValue(HLCD_DATA_PORT, HLCD_D4_PIN, GET_BIT(ARG_u8Data,4));
	MDIO_stderrSetPinValue(HLCD_DATA_PORT, HLCD_D5_PIN, GET_BIT(ARG_u8Data,5));
	MDIO_stderrSetPinValue(HLCD_DATA_PORT, HLCD_D6_PIN, GET_BIT(ARG_u8Data,6));
	MDIO_stderrSetPinValue(HLCD_DATA_PORT, HLCD_D7_PIN, GET_BIT(ARG_u8Data,7));
	L_stderrStatus=MDIO_stderrSetPinValue(HLCD_E_PIN,MDIO_PIN_HIGH);
	_delay_ms(2);
	L_stderrStatus=MDIO_stderrSetPinValue(HLCD_E_PIN,MDIO_PIN_LOW);
#endif
	return L_stderrStatus;
}
void HLCD_voidInit(void)
{
	MDIO_stderrSetPinDirection(HLCD_RS_PIN,MDIO_PIN_OUTPUT);
	MDIO_stderrSetPinDirection(HLCD_RW_PIN,MDIO_PIN_OUTPUT);
	MDIO_stderrSetPinDirection(HLCD_E_PIN,MDIO_PIN_OUTPUT);

#if HLCD_BIT_MODE == HLCD_8_BIT_MODE
	MDIO_stderrSetPortDirection(HLCD_DATA_PORT,MDIO_PORT_HIGH);
#elif HLCD_BIT_MODE == HLCD_4_BIT_MODE
	MDIO_stderrSetPinDirection(HLCD_DATA_PORT, HLCD_D4_PIN, MDIO_PIN_OUTPUT);
	MDIO_stderrSetPinDirection(HLCD_DATA_PORT, HLCD_D5_PIN, MDIO_PIN_OUTPUT);
	MDIO_stderrSetPinDirection(HLCD_DATA_PORT, HLCD_D6_PIN, MDIO_PIN_OUTPUT);
	MDIO_stderrSetPinDirection(HLCD_DATA_PORT, HLCD_D7_PIN, MDIO_PIN_OUTPUT);
#endif
	/*Wait for around 30ms*/
	_delay_ms(40);
	HLCD_stderrSendCommand(HLCD_FUNCTION_SET);
	/*The delay is handled in the enable pulse */
	HLCD_stderrSendCommand(HLCD_DISPLAY_ON);
	HLCD_voidClearDisplay();

}
void HLCD_voidClearDisplay(void)
{
	HLCD_stderrSendCommand(HLCD_CLEAR_DISPLAY);

}
void HLCD_voidDisplayString(const char * ccharpString)
{
	u8 L_u8CounterOfString = 0 ,flag =0;
	if(ccharpString != NULL_POINTER)
	{
		do
		{
			if((L_u8CounterOfString-1)%15==0)
			{
				if(L_u8CounterOfString ==1)
				{
					/*Do nothing*/
				}


				else if(flag == 0)
				{
					_delay_ms(1000);
					HLCD_voidGoToXY(1,0);
					flag = 1 ;
				}
				else
				{
					_delay_ms(1000);
					HLCD_voidGoToXY(0,0);
					flag = 0 ;
				}

			}

			HLCD_stderrSendData(ccharpString[L_u8CounterOfString]);
			L_u8CounterOfString++;
		}while(ccharpString[L_u8CounterOfString] != '\0');
	}
	else
	{
		/*Do nothing Misra*/
	}
}

void HLCD_voidGoToXY(u8 ARG_u8XPosition,u8 ARG_u8YPosition)
{
	u8 L_u8LocalAddress ;
	if(ARG_u8XPosition ==0)
	{
		L_u8LocalAddress = ARG_u8YPosition;
	}
	else if (ARG_u8XPosition == 1)
	{
		L_u8LocalAddress = ARG_u8YPosition + 0x40 ;
	}
	else
	{

	}
	L_u8LocalAddress|=0x80;
	HLCD_stderrSendCommand(L_u8LocalAddress);
}
void HLCD_voidWriteSpecialCharacter(u8 * ARG_pu8Pattern, u8 Copy_u8PatternNumber, u8 ARG_u8XPosition,u8 ARG_u8YPosition)
{
	u8 L_u8CCGRAMAddress = 0, L_u8Iterator=0 ;
	/*Calculate the CGRam address whose block is 8 bytes*/
	L_u8CCGRAMAddress = Copy_u8PatternNumber*8;
	HLCD_stderrSendCommand(L_u8CCGRAMAddress+64);
	/*Write the pattern into the ccgram*/
	for(L_u8Iterator=0;L_u8Iterator<8;L_u8Iterator++)
	{
		HLCD_stderrSendData(ARG_pu8Pattern[L_u8Iterator]);
	}
	/*Go back the the DDRAM to display the pattern*/
	HLCD_voidGoToXY(ARG_u8XPosition,ARG_u8YPosition);
	/*Display the pattern written to in the CCGRAM*/
	HLCD_stderrSendData(Copy_u8PatternNumber);
}
void HLCD_voidShiftLeft(void)
{
	HLCD_stderrSendCommand(HLCD_SHIFT_LEFT);
}
void HLCD_voidWriteNumber(u32 ARG_u32Number)
{
	u8 ArrayToDisplay[10] ;
	s8 L_s8Counter = 0 ;
	if(ARG_u32Number == 0)
	{
		HLCD_stderrSendData('0');
	}
	else
	{


		while(ARG_u32Number!=0)
		{
			ArrayToDisplay[L_s8Counter] =ARG_u32Number%10;
			ARG_u32Number/=10;
			L_s8Counter++;
		}
		L_s8Counter--;
		while(L_s8Counter>=0)
		{
			HLCD_stderrSendData(ArrayToDisplay[L_s8Counter]+'0');
			L_s8Counter--;
		}
	}
}
