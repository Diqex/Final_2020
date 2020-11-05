
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <pic18f4550.h>
void MSdelay(unsigned int);  
void USART_Init (long);
void SART_ReceiveChar(unsigned char);
void USART_SendString(const char *);
