/**********************************/
/* Author    : Elamir Galal       */
/* SWC       : PORT		          */
/* Layer     : MCAL	 		      */
/* Version   : 1.0                */
/* Date      : December  3,2023   */
/* Last Edit : December  3,2023   */
/**********************************/

#include "MPORT_Config.h"
#include "MPORT_Private.h"
#include "MPORT_Interface.h"


void MPORT_voidInit(void)
{
	DDRA = PORTA_DIR;
	DDRB = PORTB_DIR;
	DDRC = PORTC_DIR;
	DDRD = PORTD_DIR;
	
	
	PORTA = PORTA_INITIAL_VALUE;
	PORTB = PORTB_INITIAL_VALUE;
    PORTC = PORTC_INITIAL_VALUE;
    PORTD = PORTD_INITIAL_VALUE;
}