/**********************************/
/* Author    : Elamir Galal       */
/* SWC       : Bit Maths          */
/* Layer     : Lib	 		      */
/* Version   : 1.0                */
/* Date      : November 25,2023   */
/* Last Edit : November 25,2023   */
/**********************************/



#ifndef _LBIT_MATH_H_	
#define _LBIT_MATH_H_	

#define SET_BIT(Reg,bit)	(Reg|=(1<<bit))		
#define CLEAR_BIT(Reg,bit)	(Reg&=~(1<<bit))
#define TOGGLE_BIT(Reg,bit)	(Reg^=(1<<bit))
#define GET_BIT(Reg,bit)	((Reg>>bit)&1) 






#endif 