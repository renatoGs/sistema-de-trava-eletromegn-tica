#include <pic18f4520.h>
#include "config.h"
#include "bits.h"
#include "io.h"
#include "lcd.h"
#include "estado_sistema.h"
#include "keypad.h"

void main(void) {
    unsigned char a;
    bitClr(TRISC, 0);
    lcdInit(); //inicializa  display HD44780 
    unsigned char i;
    unsigned char estado; //recebe 1 para senha correta e 0 para senha incorreta
    estado = inicializacao();


    while (estado == 0) { //loop até o usuário inserir a senha correta
        estado = inicializacao();
    }

    liga_sistema();
    bitSet(PORTC,0);
    while (1){
        
    }
}
