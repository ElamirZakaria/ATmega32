/**********************************/
/* Author    : Elamir Galal       */
/* SWC       : LCD		          */
/* Layer     : HAL	 		      */
/* Version   : 1.0                */
/* Date      : December 4,2023    */
/* Last Edit : December 4,2023    */
/**********************************/




#ifndef HLCD_CONFIG_H	
#define HLCD_CONFIG_H	


/*Choose Mode of Operation*/
/*
 * HLCD_4_BIT_MODE
 * HLCD_8_BIT_MODE
*/

#define HLCD_BIT_MODE HLCD_8_BIT_MODE

/*Choose Ports and pins */

/*
 *  HLCD_PORTA
 *  HLCD_PORTB
 *  HLCD_PORTC
 *  HLCD_PORTD
 *  HLCD_PIN0 
 *  HLCD_PIN1 
 *  HLCD_PIN2
 *  HLCD_PIN3
 *  HLCD_PIN4
 *  HLCD_PIN5
 *  HLCD_PIN6
 *  HLCD_PIN7
*/


#define HLCD_DATA_PORT    HLCD_PORTC
#define HLCD_CTRL_PORT    HLCD_PORTA
#define HLCD_RS_PIN		  HLCD_CTRL_PORT,HLCD_PIN0
#define HLCD_RW_PIN		  HLCD_CTRL_PORT,HLCD_PIN1
#define HLCD_E_PIN		  HLCD_CTRL_PORT,HLCD_PIN2
#define HLCD_D0_PIN			HLCD_PIN0
#define HLCD_D1_PIN			HLCD_PIN1
#define HLCD_D2_PIN			HLCD_PIN2
#define HLCD_D3_PIN			HLCD_PIN3
#define HLCD_D4_PIN			4
#define HLCD_D5_PIN			5
#define HLCD_D6_PIN			6
#define HLCD_D7_PIN			7





#endif 
