#include <DRV8834.h>

DRV8834::DRV8834(uint8_t M0, uint8_t DIR, uint8_t M1, uint8_t AENBL, uint8_t BENBL, uint8_t DECAY_A, uint8_t DECAY_B) {
    _M0 = M0;
    _DIR = DIR;
    _M1 = M1;
    _AENBL = AENBL;
    _BENBL = BENBL;
    _DECAY_A = DECAY_A;
    _DECAY_B = DECAY_B;
}

bool DRV8834::begin() {
    pinMode(_M0, OUTPUT);
    pinMode(_M1, OUTPUT);
    pinMode(_AENBL, OUTPUT);
    pinMode(_BENBL, OUTPUT);
    pinMode(_DECAY_A, OUTPUT);
    pinMode(_DECAY_B, OUTPUT);
    digitalWrite(_DECAY_A, LOW);
    digitalWrite(_DECAY_B, LOW);
    return true;
}

void DRV8834::bridgeEnables(uint8_t A, uint8_t B) {
    if(A) {
        digitalWrite(_AENBL, HIGH);
    } else {
        digitalWrite(_AENBL, LOW);
    }
    if(B) {
        digitalWrite(_BENBL, HIGH);
    } else {
        digitalWrite(_BENBL, LOW);
    }
}

void DRV8834::motorFloat(uint8_t A, uint8_t B) {
    digitalWrite(_M1, HIGH); 
    if (A)
        {
        digitalWrite(_AENBL, LOW);  
        }
    if (B)
        {
        digitalWrite(_BENBL, LOW);  
        }
}

void DRV8834::brake(uint8_t A, uint8_t B) {
    digitalWrite(_M1, LOW);
    if (A)
        {
        digitalWrite(_AENBL, LOW);  
        }
    if (B)
        {
        digitalWrite(_BENBL, LOW);  
        }
}

void DRV8834::turnForward(uint8_t A, uint8_t B) {
    if (A)
        {
        digitalWrite(_AENBL, HIGH);  
        digitalWrite(_M0, LOW);
        }
    if (B)
        {
        digitalWrite(_BENBL, HIGH);  
        digitalWrite(_DIR, LOW);
        }
}

void DRV8834::turnReverse(uint8_t A, uint8_t B) {
    if (A)
        {
        digitalWrite(_AENBL, HIGH);  
        digitalWrite(_M0, HIGH);
        }
    if (B)
        {
        digitalWrite(_BENBL, HIGH);  
        digitalWrite(_DIR, HIGH);
        }
}