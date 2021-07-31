#include "lcd.h"
#include <pic18f4520.h>
#include "bits.h"
#include "io.h"
#include "keypad.h"



void liga_sistema(void) {
    lcdInit(); // rotinas de inicializa��o do display LCD 2x16 HD44780
    static unsigned char k;
    static unsigned char msg[] = "SISTEMA SEGURO";
    //escrevendo o simbolo do cadeado na mem�ria CGRAM
    lcdCommand(0b01000000); //acesso � memoria CGRAM

    lcdData(0b00001110);
    lcdData(0b00001010);
    lcdData(0b00001010);
    lcdData(0b00011111); //linhas entre acesso e sa�da s�o o bitmap para o cadeado
    lcdData(0b00011111);
    lcdData(0b00011111);
    lcdData(0b00011111);
    lcdData(0b00000000);

    lcdCommand(0x80); //sa�da da mem�ria CGRAM

    lcdData(0x00); //posi��o da mem�ria CGRAM na qual est� o desenho do cadeado
    mensagemLCD(msg);
    lcdData(0x00); //posi��o da mem�ria CGRAM na qual est� o desenho do cadeado
}

unsigned char inicializacao(void) {
    static unsigned char senha[] = "123456"; //senha do sistema
    static unsigned char msg[] = "tente novamente"; //mensagem de erro de digita��o
    static unsigned char msg_2[] = "digite a senha"; //mensagem inicial
    static unsigned char digito, j, i, cont = 0;
    static unsigned char entrada[6]; //entrada inserida pelo usu�rio
    static unsigned int temp;
    //inicializa teclado matricial e display de cristal l�quido
    kpInit();
    mensagemLCD(msg_2);
    i = 0;
    lcdCommand(0xC0);
    while (i < 6) {
        if (kpRead() != temp && kpRead() != 0) {
            temp = kpRead();
            digito = teclas();
            lcdData(digito);
            entrada[i] = digito;
            i++;
        }
        kpDebounce();
    }
    for (i = 0; i < 6; i++) {
        if (senha[i] == entrada[i]) {
            cont++;
        } else {
            cont = cont;
        }
    }
    if (cont != 6) {
        cont = 0;
        lcdCommand(0x01);
        mensagemLCD(msg);
    }

    for (i = 0; i < 255; i++) {
        for (j = 0; j < 255; j++);
        for (j = 0; j < 255; j++);
    }
    for (i = 0; i < 255; i++) {
        for (j = 0; j < 255; j++);
        for (j = 0; j < 255; j++);
    }
    return cont;
}




