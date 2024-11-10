







#ifndef _MUART_INTERFACE_H_
#define _MUART_INTERFACE_H_




#define MUART_RX_INTERRUPT					0
#define MUART_TX_INTERRUPT				    1	
#define MUART_REGISTER_EMPTY INTERRUPT      2




STD_error_t MUART_stderrInit();
STD_error_t MUART_stderrSendData(u8 ARG_u8Data);
STD_error_t MUART_stderrRecieveData(u8 *ARG_pu8Data);
STD_error_t MUART_stderrInterruptEnable(u8 ARG_u8Interrupt);
STD_error_t MUART_stderrInterruptDisable(u8 ARG_u8Interrupt);











#endif










