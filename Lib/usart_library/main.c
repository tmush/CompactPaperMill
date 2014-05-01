#include "m_general.h"
#define F_CPU 16000000UL
#define BAUD 9600
#include "m_usb.h"
#include <util/setbaud.h>
void USART_Transmit(unsigned char);
void USART_Init(unsigned int);
unsigned char USART_Receive(void);
int main(void){
USART_Init(BAUD);
USART_Transmit(0xAA);
m_usb_init();
while(1){
USART_Transmit(0x8D);
USART_Transmit(0x7F);
unsigned char value;
m_green(ON);
value = USART_Receive();
while(!m_usb_isconnected());
//m_usb_tx_int(500);
m_usb_tx_char(value);
m_wait(250);
m_green(OFF);
m_wait(250);
}
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
unsigned char USART_Receive( void )
{
/* Wait for data to be received */
while ( !(UCSR1A & (1<<RXC1)) )
;
/* Get and return received data from buffer */
return UDR1;
}
