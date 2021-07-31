#include "bits.h"
#include "io.h"
#include <pic18f4520.h>

void digitalWrite(int pin, int value) {
    //porta
    if (pin < 8) {
        if (value) {
            bitSet(PORTA, pin);
        } else {
            bitClr(PORTA, pin);
        }
    } else if (pin < 11) {

        if (value) {
            bitSet(PORTE, pin - 8);
        } else {
            bitClr(PORTE, pin - 8);
        }
    } else if (pin >= 15 && pin < 19) {

        if (value) {
            bitSet(PORTC, pin - 15);
        } else {
            bitClr(PORTC, pin - 15);
        }
    } else if (pin >= 23 && pin < 27) {

        if (value) {
            bitSet(PORTC, pin - 23 + 4);
        } else {
            bitClr(PORTC, pin - 23 + 4);
        }
    } else if (pin >= 19 && pin < 23) {

        if (value) {
            bitSet(PORTD, pin - 19);
        } else {
            bitClr(PORTD, pin - 19);
        }
    } else if (pin >= 27 && pin < 31) {

        if (value) {
            bitSet(PORTD, pin - 27 + 4);
        } else {
            bitClr(PORTD, pin - 27 + 4);
        }
    } else if (pin >= 33 && pin < 40) {

        if (value) {
            bitSet(PORTB, pin - 33);
        } else {
            bitClr(PORTB, pin - 33);
        }
    }


}

int digitalRead(int pin) {
    if (pin < 8) {
        return bitTst(PORTA, pin);
    } else if (pin < 11) {
        return bitTst(PORTE, pin - 8);
    } else if (pin >= 15 && pin < 19) {
        return bitTst(PORTC, pin - 15);
    } else if (pin >= 23 && pin < 27) {
        return bitTst(PORTC, pin - 23 + 4);
    } else if (pin >= 19 && pin < 23) {
        return bitTst(PORTD, pin - 19);
    } else if (pin >= 27 && pin < 31) {
        return bitTst(PORTD, pin - 27 + 4);
    } else if (pin >= 33 && pin < 40) {
        return bitTst(PORTB, pin - 33);
    }
    return -1;
}

void pinMode(int pin, int type) {

    if (pin < 8) {
        if (type) {
            bitSet(TRISA, pin);
        } else {
            bitClr(TRISA, pin);
        }
    } else if (pin < 11) {
        if (type) {
            bitSet(TRISE, pin - 8);
        } else {
            bitClr(TRISE, pin - 8);
        }
    } else if (pin >= 15 && pin < 19) {
        if (type) {
            bitSet(TRISC, pin - 15);
        } else {
            bitClr(TRISC, pin - 15);
        }
    } else if (pin >= 23 && pin < 27) {
        if (type) {
            bitSet(TRISC, pin - 23 + 4);
        } else {
            bitClr(TRISC, pin - 23 + 4);
        }
    } else if (pin >= 19 && pin < 23) {
        if (type) {
            bitSet(TRISD, pin - 19);
        } else {
            bitClr(TRISD, pin - 19);
        }
    } else if (pin >= 27 && pin < 31) {
        if (type) {
            bitSet(TRISD, pin - 27 + 4);
        } else {
            bitClr(TRISD, pin - 27 + 4);
        }
    } else if (pin >= 33 && pin < 40) {
        if (type) {
            bitSet(TRISB, pin - 33);
        } else {
            bitClr(TRISB, pin - 33);
        }
    }
}



