/**********************************/
/* Author    : Elamir Galal       */
/* SWC       : STD Types          */
/* Layer     : Lib	 		      */
/* Version   : 1.0                */
/* Date      : November 25,2023   */
/* Last Edit : November 25,2023   */
/**********************************/



#ifndef LSTD_TYPES_H_	
#define LSTD_TYPES_H_	

typedef unsigned char	 	u8 ;
typedef signed char 	 	s8 ; 
typedef unsigned short int  u16;
typedef signed short int 	s16; 
typedef unsigned long int   u32;
typedef signed short int 	s32;
typedef float 				f32;
typedef double 				f64;
typedef enum 
{
	E_OK,
	E_NOK,
	E_NULL_POINTER
	
}STD_error_t;


#define NULL_POINTER ((void*)0x00)

#endif 
