/**********************************/
/* Author    : Elamir Galal       */
/* SWC       : 7 Segment Dispaly  */
/* Layer     : HAL	 		      */
/* Version   : 1.0                */
/* Date      : Dec 3,2023 		  */
/* Last Edit : Dec 3,2023 		  */
/**********************************/



#ifndef SEVEN_SEGMENT_INTERFACE_H
#define SEVEN_SEGMENT_INTERFACE_H


#define HSEVEN_SEGMENT_PORTA	0
#define HSEVEN_SEGMENT_PORTB	1
#define HSEVEN_SEGMENT_PORTC	2
#define HSEVEN_SEGMENT_PORTD	3

							 
#define HSEVEN_SEGMENT_PIN0	 		 0
#define HSEVEN_SEGMENT_PIN1	 		 1
#define HSEVEN_SEGMENT_PIN2	 		 2
#define HSEVEN_SEGMENT_PIN3	 		 3
#define HSEVEN_SEGMENT_PIN4	 		 4
#define HSEVEN_SEGMENT_PIN5	 		 5
#define HSEVEN_SEGMENT_PIN6	 		 6
#define HSEVEN_SEGMENT_PIN7	 		 7

#define HSEVEN_SEGMENT_NUM0	 		 0
#define HSEVEN_SEGMENT_NUM1	 		 1
#define HSEVEN_SEGMENT_NUM2	 		 2
#define HSEVEN_SEGMENT_NUM3	 		 3
#define HSEVEN_SEGMENT_NUM4	 		 4
#define HSEVEN_SEGMENT_NUM5	 		 5
#define HSEVEN_SEGMENT_NUM6	 		 6
#define HSEVEN_SEGMENT_NUM7	 		 7
#define HSEVEN_SEGMENT_NUM8	 		 8
#define HSEVEN_SEGMENT_NUM9	 		 9




STD_error_t HSevenSegment_stderrInit(u8 ARG_u8Port);
STD_error_t HSevenSegment_stderrDisplayWithDelay(u8 ARG_u8Port, u16 ARG_u16RequiredDelayBetweenElements);
void HSevenSegment_stderrDisable(u8 ARG_u8Port);
STD_error_t HSevenSegment_stderrDisplayNumber(u8 ARG_u8Port, u8 ARG_u8Number);

#endif
