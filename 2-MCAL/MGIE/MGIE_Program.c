/**********************************/
/* Author    : Elamir Galal       */
/* SWC       : GIE		          */
/* Layer     : MCAL	 		      */
/* Version   : 1.0                */
/* Date      : December 6,2023    */
/* Last Edit : December 6,2023    */
/**********************************/

#include "LSTD_Types.h"
#include "LBIT_Math.h"
#include "MGIE_Interface.h"
#include "MGIE_Private.h"
#include "MGIE_Config.h"


void MGIE_EnableGlobalInterrupt(void)
{
	SET_BIT(SREG,I_BIT);
}
void MGIE_DisableGlobalInterrupt(void)
{
	CLEAR_BIT(SREG,I_BIT);
}
