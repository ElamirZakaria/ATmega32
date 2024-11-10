/**********************************/
/* Author    : Elamir Galal       */
/* SWC       : EXTI		          */
/* Layer     : MCAL	 		      */
/* Version   : 1.0                */
/* Date      : December 6,2023    */
/* Last Edit : December 6,2023    */
/**********************************/



#ifndef MEXTI_PRIVATE_H	
#define MEXTI_PRIVATE_H



/****************EXTI Registers****************/
#define GICR		*((volatile u8*)0x5B)
#define GIFR		*((volatile u8*)0x5A)
#define MCUCR		*((volatile u8*)0x55)
#define MCUCSR		*((volatile u8*)0x54)

/****************GICR Bits****************/

#define  INT1		7
#define  INT0		6
#define  INT2		5
/****************GIFR Bits****************/
#define  INTF1		7
#define  INTF0		6
#define  INTF2		5
/****************MCUCR Bits****************/
#define  ISC11		3
#define  ISC10		2
#define  ISC01		1
#define  ISC00		0

/****************MCUCSR Bits****************/
#define  ISC2		6




#endif	
