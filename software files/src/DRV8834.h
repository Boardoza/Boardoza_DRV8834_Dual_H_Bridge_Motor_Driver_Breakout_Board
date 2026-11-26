#ifndef DRV8834_h
#define DRV8834_h

#include "Arduino.h"

class DRV8834 {
 public:
    DRV8834(uint8_t M0, uint8_t DIR, uint8_t M1, uint8_t AENBL, uint8_t BENBL, uint8_t DECAY_A, uint8_t DECAY_B);
    bool begin();
    void bridgeEnables(uint8_t A, uint8_t B);
    void motorFloat(uint8_t A, uint8_t B);
    void brake(uint8_t A, uint8_t B);
    void turnForward(uint8_t A, uint8_t B);
    void turnReverse(uint8_t A, uint8_t B);

 private:
    uint8_t _M0;
    uint8_t _DIR;
    uint8_t _M1;
    uint8_t _AENBL;
    uint8_t _BENBL;
    uint8_t _DECAY_A;
    uint8_t _DECAY_B;
};

#endif