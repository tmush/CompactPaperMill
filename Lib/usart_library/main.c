#include "m_general.h"
#define F_CPU 16000000UL
#define BAUD 9600

#include <util/setbaud.h>
void USART_Transmit(unsigned char);
void USART_Init(unsigned int);

int main(void){
// do stuff here
}

void USART_Transmit( unsigned char data )
{
/* Wait for empty transmit buffer */
while ( !( UCSR1A & (1<<UDRE1)) )
;
/* Put data into buffer, sends the data */
UDR1 = data;
}
//------------------------------------------------------------
void USART_Init( unsigned int baud )
{
/* Set baud rate */
UBRR1H = (unsigned char)(baud>>8);
UBRR1L = (unsigned char)baud;
/* Enable receiver and transmitter */
UCSR1B = (1<<RXEN1)|(1<<TXEN1);
/* Set frame format: 8data, 2stop bit */
UCSR1C = (1<<USBS1)|(3<<UCSZ10);
}
