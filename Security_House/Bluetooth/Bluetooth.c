#include <pic18f4550.h>
#include "clases.h"
#define LED LATD0             
void main()
{
    OSCCON=0x72;  /* use internal oscillator frequency
                                 which is set to 8 MHz */
    char data_in;
    TRISD = 0;  /* set PORT as output port */
    USART_Init(9600);  /* initialize USART operation with 9600 baud rate */ 
    MSdelay(50);
    while(1)
    {
        data_in=USART_ReceiveChar();
        if(data_in=='1')
        {   
            LED = 0;  /* turn ON LED */
            USART_SendString("LED_ON");  /* send LED ON status to terminal */
        }
        else if(data_in=='2')
                
        {
            LED = 1;  /* turn OFF LED */
            USART_SendString("LED_OFF");  /* send LED OFF status to terminal */
        }
        else
        {
            USART_SendString(" select 1 or 2");  /* send msg to select proper option */
        }
        MSdelay(100);
    
    }
    
}