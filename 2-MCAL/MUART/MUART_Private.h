













#ifndef _MUART_PRIVATE_H_
#define _MUART_PRIVATE_H_

#define UBBRH *((u8 volatile*)0x40)

#define UBRR	11
#define UBRR	10
#define UBRR	9
#define UBRR	8






#define UCSRC *((u8 volatile*)0x40)
#define URSEL		7
#define UMSEL		6
#define UPM1		5
#define UPM0		4
#define USBS		3
#define USZ1		2
#define USZ0		1
#define UCPOL		0



#define UCSRA *((u8 volatile*)0x2B)

#define RXC			7
#define TXC			6
#define UDRE		5
#define FE			4
#define DOR			3
#define PE			2
#define U2X			1
#define MPCM		0


#define UCSRB *((u8 volatile*)0x2A)
#define RXCIE		7
#define TXCIE		6
#define UDREIE		5
#define RXEN		4
#define TXEN		3
#define UCSZ2		2
#define RXB8		1
#define TXB8		0

#define UBRRL *((u8 volatile*)0x29)
#define UDR   *((u8 volatile*)0x2C)


#endif
