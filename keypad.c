// -----------------------------------------------------------------------
//   Copyright (C) Rodrigo Almeida 2014
// -----------------------------------------------------------------------
//   Arquivo: keypad.c
//            Biblioteca de operação de um teclado matricial
//   Autor:   Rodrigo Maximiano Antunes de Almeida
//            rodrigomax at unifei.edu.br
//   Licença: GNU GPL 2
// -----------------------------------------------------------------------
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; version 2 of the License.
//
//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
// -----------------------------------------------------------------------

#include "keypad.h"
#include <pic18f4520.h>
#include "io.h"
#include "bits.h"

static unsigned int valor = 0x0000;

unsigned int kpRead(void) {
    return valor;
}

void kpDebounce(void) {
    unsigned char i, j;
    static unsigned char tempo;
    static unsigned int valorNovo = 0x00;
    static unsigned int valorAntigo = 0x00;

    //store D to avoid mess with other periphels
    unsigned char old_D;
    old_D = PORTD;

    //PORTD é compartilhado, então tem
    //que garantir que é entrada
    TRISD |= 0x0f;

    for (i = 0; i < 4; i++) {
        //desabilita todas as colunas
        TRISB &= 0x08;
        //Habilita apenas a coluna desejada
        bitClr(TRISB, i);
        //coloca nivel alto só na coluna desejada
        PORTB |= 0x07;
        bitClr(PORTB, i);

        //delay pra estabilizar os sinais
        for (int k = 0; k < 10; k++);

        //realiza o teste para cada bit e atualiza a variável
        for (j = 1; j < 4; j++) {
            if (!bitTst(PORTD, j)) {
                bitSet(valorNovo, 3 * i + j);
            } else {
                bitClr(valorNovo, 3 * i + j);
            }
        }
    }
    if (valorAntigo == valorNovo) {
        tempo--;
    } else {
        tempo = 10;
        valorAntigo = valorNovo;
    }
    if (tempo == 0) {
        valor = valorAntigo;
    }
    PORTD = old_D;
    TRISD = 0x00;
}

void kpInit(void) {
    //coloca 0-2 como saída
    TRISB &= 0x08;
    //coloca 0-3 como entrada
    TRISD |= 0x0f;
    ADCON0 = 0x31;
    ADCON1 = 0x0F;
    ADCON2 = 0b10101010;
}

unsigned char teclas() {

    switch (kpRead()) {
        case 8:
            return '1';
        case 64:
            return '2';
        case 512:
            return '3';
        case 4:
            return '4';
        case 32:
            return '5';
        case 256:
            return '6';
        case 2:
            return '7';
        case 16:
            return '8';
        case 128:
            return '9';

    }
}