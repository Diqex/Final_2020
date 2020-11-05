
// CONFIG1L
#pragma config PLLDIV = 1       // PLL Prescaler Selection bits (No prescale (4 MHz oscillator input drives PLL directly))
#pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])
#pragma config USBDIV = 1       // USB Clock Selection bit (used in Full-Speed USB mode only; UCFG:FSEN = 1) (USB clock source comes directly from the primary oscillator block with no postscale)

// CONFIG1H
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator (HS))
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = ON         // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 3         // Brown-out Reset Voltage bits (Minimum setting 2.05V)
#pragma config VREGEN = OFF     // USB Voltage Regulator Enable bit (USB voltage regulator disabled)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = ON      // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer 1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config ICPRT = OFF      // Dedicated In-Circuit Debug/Programming Port (ICPORT) Enable bit (ICPORT disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) is not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) is not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) is not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) is not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) is not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM is not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) is not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) is not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) is not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) is not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) are not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) is not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM is not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) is not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      

#define _XTAL_FREQ 4000000
#include <xc.h>
#include "lcd.h"
#include "teclado.h"
#include "eeprom.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "USART_Header_File.h"


/*void main(void) {
 INICIO:  
    TRISC = 0;
    TRISD = 0;
    
    char tecla = 0; //  GUARDAR LA TECLA PRESIONADA
    char inclave[5] = {0}; //  GUARDAR LOS DATOS INGRESADOS EN UN ARREGLO
    int countinclave = 0; //  CONTADOR PARA LA POSICION EN EL ARREGLO
    int clave1check = 0; //  VERIFICACION DE LA CLAVE DIGITO1
    int clave2check = 0; //  VERIFICACION DE LA CLAVE DIGITO2
    int clave3check = 0; //  VERIFICACION DE LA CLAVE DIGITO3
    int clave4check = 0; //  VERIFICACION DE LA CLAVE DIGITO4
    int clavechecktotal = 0; //  VERIFICACION DE LA CLAVE TOTAL
    char clave1 = '2'; //  CLAVE POR DEFECTO DIGITO1
    char clave2 = '2'; //  CLAVE POR DEFECTO DIGITO2
    char clave3 = '2'; //  CLAVE POR DEFECTO DIGITO3
    char clave4 = '2'; //  CLAVE POR DEFECTO DIGITO4
    char direccion1 = 0b0011; //  DIRECCION DE LA MEMORIA EEPROM
    char direccion2 = 0b0101; //  DIRECCION DE LA MEMORIA EEPROM
    char direccion3 = 0b1000; //  DIRECCION DE LA MEMORIA EEPROM
    char direccion4 = 0b1001; //  DIRECCION DE LA MEMORIA EEPROM

    int DERE[4] = {0b1100, 0b0110, 0b0011, 0b1001};
    int IZQ[4] = {0b1001, 0b0011, 0b0110, 0b1100};
    //  INICIALMENTE LOS DATOS EN LA MEMORIA ESTA CON 0xFF(255))
    if (eeprom_readx(direccion1) == 0xff) { // si la memoria esta vacia
        eeprom_writex(direccion1, clave1); // escribir clave1    
    }
    if (eeprom_readx(direccion2) ==0xff ) { // si la memoria esta vacia
        eeprom_writex(direccion2, clave2); // escribir clave2    
    }
    if (eeprom_readx(direccion3) == 0xff) { // si la memoria esta vacia
        eeprom_writex(direccion3, clave3); // escribir clave3    
    }
    if (eeprom_readx(direccion4) == 255) { // si la memoria esta vacia
        eeprom_writex(direccion4, clave4); // escribir clave3    
    }


    LCD_init(); //  inicia la configuracion del LCD
    teclado_init(); //  inicial la configuracion del TECLADO MATRICIAL

    LCD_gotoxy(2, 1);
    LCD_puts("INGRESAR CLAVE", 14);

    while (1) {
        tecla = teclado_getc(); //  RETORNA LA TECLA PRESIONADA
        if (tecla != 0) {

            //  SOLO LOS NUMEROS 
            if (tecla != 'A' && tecla != 'B' && tecla != 'C' && tecla != 'D' && tecla != '#' && tecla != '*') {

                LCD_gotoxy(2, 1);
                LCD_puts("INGRESAR CLAVE", 14);
                inclave[countinclave] = tecla; //  LA TECLA PRESIONADA SE ALMACENA EN EL ARREGLO
                countinclave++; //  INCREMENTA LA POSICION EN EL ARREGLO
                LCD_gotoxy(countinclave + 5, 2); //columna,fila
                //LCD_putc(tecla);
                LCD_puts("*",2);
                
                //LCD_putc(tecla);
                
            }
            

            //  SOLO LAS LETRAS
            if (tecla == '#') //  ENTER
            {
                if (eeprom_readx(direccion1) == inclave[0]) clave1check = 1;
                else clave1check = 0;
                if (eeprom_readx(direccion2) == inclave[1]) clave2check = 1;
                else clave2check = 0;
                if (eeprom_readx(direccion3) == inclave[2]) clave3check = 1;
                else clave3check = 0;
                if (eeprom_readx(direccion4) == inclave[3]) clave4check = 1;
                else clave4check = 0;

                clavechecktotal = clave1check + clave2check + clave3check+clave4check;

                if (clavechecktotal == 4) {
                    LCD_gotoxy(1, 1);
                    LCD_puts(" CLAVE CORRECTA ",16);
                    __delay_ms(1000);
                    LCD_clear();
                    LCD_gotoxy(2, 1);
                    LCD_puts(" *BIENVENIDO* ", 16);
                    __delay_ms(1000);
                    
                    PORTC =IZQ;
                    __delay_ms(1000);
                    PORTC = 0B00000001;
                    __delay_ms(1000);
                    PORTC = 0;
                    goto INICIO;
 

                } else {
                    
                    
                    LCD_gotoxy(1, 1);
                    LCD_puts("CLAVE INCORRECTA",16);
                    __delay_ms(10);
                    PORTDbits.RD3=1;
                    __delay_ms(2000);
                    PORTDbits.RD3=0;
                    __delay_ms(1000);
                    LCD_clear();
                    LCD_gotoxy(3, 1);
                    LCD_puts("**BLOQUEO**", 16);
                    __delay_ms(4000);
                    PORTC = 0B00000001;
                    __delay_ms(500);
                    PORTC = 0B0000001;
                    __delay_ms(500);
                    PORTC = 0B00000011;
                    __delay_ms(1000);
                    PORTC = 0;
                    LCD_clear();
                    LCD_gotoxy(2, 1);
                    LCD_puts("INGRESAR CLAVE",16);
                    
                    //  REINICIO DE TODAS LAS VARIABLES
                    goto INICIO;
                    /*clave1check = 0;
                     
                    clave2check = 0;
                    clave3check = 0;
                    clavechecktotal = 0;
                    countinclave = 0;*/

               /* }

            }
        }
    }

    return;
}*/

char K = 0;
char MIL, CEN, DEC, UNI, VAL; //int8==unsigned
long contra = 2020; //Variable entera para almacenar la contraseña //int16==long
char sinal; //Variable para saber si tengo contraseña
long intentos;

void TECLADO() {
    K = teclado_getc(); //Llamar la función del teclado y almacenar
    //el valor digitado en una variable tipo
    //carácter. Si no se oprime ninguna tecla el
    //teclado retornara el carácter nulo.*/
    while (K == '\0') //si no se oprime ninguna tecla sigue llamando al teclado.
    {
        K = teclado_getc();
    }
    if ((K != '\0')) {
        if (K == '0')//Si K es igual a cero
            VAL = 0; //Val es igual a cero
        if (K == '1')
            VAL = 1;
        if (K == '2')
            VAL = 2;
        if (K == '3')
            VAL = 3;
        if (K == '4')
            VAL = 4;
        if (K == '5')
            VAL = 5;
        if (K == '6')
            VAL = 6;
        if (K == '7')
            VAL = 7;
        if (K == '8')
            VAL = 8;
        if (K == '9')
            VAL = 9;
    }
}


//Rutina para pedir la clave

void pedir_clave(void) {
    TECLADO();

    if ((K != '#')&&(K != '*')) {
        LCD_putc('*');
        MIL = VAL;
    }
    if (K == '*' || K == '#')
        return;
    TECLADO();
    if ((K != '#')&&(K != '*')) {
        LCD_putc('*');
        CEN = VAL;
    }
    if (K == '*' || K == '#')
        return;
    TECLADO();
    if ((K != '#')&&(K != '*')) {
        LCD_putc('*');
        DEC = VAL;
    }
    if (K == '*' || K == '#')
        return;
    TECLADO();
    if ((K != '#')&&(K != '*')) {
        LCD_putc('*');
        UNI = VAL;
    }
    if (K == '*' || K == '#')
        return;
}

int validar_clave(void) {
    if (intentos <= 2) {
        //Variables locales
        long clave = 0, m, c, d, u;

        /* Para realizar la multiplicación cuando se tienen numeros del tipo int8, 
           como por ejemplo 100 con otro tipo int8 como por ejemplo CEN, el programa
           hará un producto int8, sin embargo se desea un resultado int16, por lo 
           tanto debe informarce al compilador por medio de un 'cast' (c=(int16)CEN*100)
           o utilizando la función de multiplicación de tipos del compilador (_mul)*/

        m = MIL * 1000; //Convierto miles a numero
        //c=_mul(CEN,100); //Otra alternativa para multiplicar int8*int8=int16
        c = (long) CEN * 100; //Convierto centemas, haciendo un CAST para obtener un int16
        d = DEC * 10; //Convierto decenas a numero 
        u = UNI; //Convierto unidades a numero 

        clave = m + c + d + u;
        //Borra lo último que fue digitado en el teclado
        MIL = 0;
        CEN = 0;
        DEC = 0;
        UNI = 0;
        if (clave == contra) //Si la clave es igual a la contraseña
            return (1);
        else
            return (0);
    } else {
        LCD_clear();
        LCD_gotoxy(3, 1);
        LCD_puts("  ERROR  ", 8);
        LCD_gotoxy(3, 2);
        LCD_puts("SOLO 3 INTENOS", 15);
        __delay_ms(9000);
       /* CEN=0;
          DEC=0;
          MIL=0;
          UNI=0;
          VAL=0;+*/
          
       
       return 0; 
        //goto INICIO;
    }
    
}

void cambio_clave(void) {
    // int bandera = 0;
    long clave = 0, m, c, d, u;
    LCD_clear();
    LCD_gotoxy(2, 1);
    LCD_puts(" CLAVE ACTUAL ", 15);
    __delay_ms(500);
    LCD_gotoxy(1, 2);
    pedir_clave(); //Llama la funcion de pedir la clave
    //bandera=validar_clave(); //Compruebo si la clave actual es correcta
    if (validar_clave()) {
        LCD_clear();
        __delay_ms(500);
        LCD_gotoxy(2, 1);
        LCD_puts(" CLAVE NUEVA ", 14);
        LCD_gotoxy(1, 2);
        __delay_ms(1000);
        TECLADO();
        validar_clave();
         
        if ((K != '#')&&(K != '*')) {
            LCD_putc('*');
            __delay_ms(100);
            MIL = VAL;
        }

        TECLADO();
        if ((K != '#')&&(K != '*')) {
            LCD_putc('*');
            __delay_ms(100);
            CEN = VAL;
        }

        TECLADO();
        if ((K != '#')&&(K != '*')) {
            LCD_putc('*');
            __delay_ms(100);
            DEC = VAL;
        }

        TECLADO();
        if ((K != '#')&&(K != '*')) {
            LCD_putc('*');
            __delay_ms(100);
            UNI = VAL;
        }

        m = MIL * 1000; //Convierto miles a numero
        c = CEN * 10; //Convierto centemas a numero y lo sumo al anterior
        c = c * 10;
        d = DEC * 10; //Convierto decenas a numero y lo sumo al anterior
        u = UNI; //Convierto unidades a numero y lo sumo al anterior

        clave = m + c + d + u;
         
       
        contra = clave;
        eeprom_writex(0, MIL); //Guarda en la eemprom posicion cero la nueva contraseña
        eeprom_writex(1, CEN);
        eeprom_writex(2, DEC);
        eeprom_writex(3, UNI);
        eeprom_writex(4, 12); //Guardo un # en la posicion 1 de la EEPROM, para decir que tengo
        __delay_ms(900);
        //una contraseña guardada
         LCD_gotoxy(3, 1);
        LCD_puts("   CORRECTO   ", 16);
        __delay_ms(900);

    } else {
        LCD_clear();
        LCD_gotoxy(2, 1); //COLUMNA-FILA
        LCD_puts("**1_BLOQUEO**", 16);
        __delay_ms(60);
        LCD_gotoxy(1, 2);
        LCD_puts("CLAVE INVALIDA ", 16);
        __delay_ms(10);
        PORTDbits.RD3 = 1;
        __delay_ms(2000);
        PORTD = 0;
        LCD_clear();
        

    }
}

void main() {
  INICIO: 
        intentos = 0;
        //Variables Locales
        long m, c, d, u;
        char m1, c1, d1, u1;

        //Puerto C como Salida
        TRISC = 0;
        TRISD = 0;
        PORTC = 0; //Limpia Puerto C

        LCD_init(); //Inicializa el LCD

        teclado_init();

        //port_b_pullups(0xFF); //PIC16F887
        //port_b_pullups(TRUE); //PIC16F877A

        sinal = eeprom_readx(4); //Averiguo si tengo una contraseña guardada o no
        if (sinal != 1)
            contra = 2020;
        else {
            //Lee los datos del EEPROM
            m1 = eeprom_readx(0);
            c1 = eeprom_readx(1);
            d1 = eeprom_readx(2);
            u1 = eeprom_readx(3);

            /* Para realizar la multiplicación cuando se tienen numeros del tipo int8, 
               como por ejemplo 100 con otro tipo int8 como por ejemplo CEN, el programa
               hará un producto int8, sin embargo se desea un resultado int16, por lo 
               tanto debe informarce al compilador por medio de un 'cast' (c=(int16)CEN*100)
               o utilizando la función de multiplicación de tipos del compilador (_mul)*/

            m = m1 * 1000; //Convierto miles a numero
            //c=_mul(c1,100); //Otra alternativa para multiplicar int8*int8=int16
            c = (long) c1 * 100; //Convierto centemas, haciendo un CAST para obtener un int16
            d = d1 * 10; //Convierto decenas a numero 
            u = u1; //Convierto unidades a numero 

            contra = m + c + d + u;
        }

        while (1) {
            LCD_clear();
            LCD_gotoxy(2, 1);
            LCD_puts(" DIGITE CLAVE ", 14);
            LCD_gotoxy(1, 2);
            __delay_ms(1000);
          
            pedir_clave(); //Llama la funcion de pedir la clave
            if (K == '*')
                cambio_clave();
            else {
                while ((K != '#')) {
                    TECLADO();
                    if (K == '*')
                        cambio_clave();
                }
                if (validar_clave()) //Aquí se compara si
                    //los números digitados
                    //están correctos.*/
                {
                    LCD_clear();
                    LCD_gotoxy(2, 1); //Se ubica en la posición 2,1
                    LCD_puts("CLAVE CORRECTA", 16);
                    __delay_ms(40);
                    LCD_gotoxy(2, 2);
                    LCD_puts("  BIENVENIDO  ", 16);
                    __delay_ms(4000);
                    PORTC = 0B00000001;
                    __delay_ms(2000);
                    PORTC = 0B00000010;
                    __delay_ms(4000);

                    PORTC = 0;

                } else {
                    LCD_clear();
                    LCD_gotoxy(3, 1); //COLUMNA-FILA
                    LCD_puts(" **BLOQUEO** ", 16);
                    __delay_ms(80);
                      intentos++;
                    LCD_gotoxy(2, 2);
                    LCD_puts("CLAVE INVALIDA ", 16);
                    __delay_ms(500);
                    PORTDbits.RD3 = 1;
                    __delay_ms(1000);
                    PORTD = 0;
            }
        }
    }

} 

