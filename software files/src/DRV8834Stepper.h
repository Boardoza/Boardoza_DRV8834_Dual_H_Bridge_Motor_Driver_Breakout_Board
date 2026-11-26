#ifndef DRV8834Stepper_h
#define DRV8834Stepper_h

#include "Arduino.h"

class DRV8834Stepper {
  public:

    // Enum for microstepping modes
    enum MicrostepMode {
      FULL_STEP = 0,        // M1 = LOW, M0 = LOW
      HALF_STEP,            // M1 = LOW, M0 = HIGH
      EIGHTH_STEP,          // M1 = HIGH, M0 = LOW
      SIXTEENTH_STEP,       // M1 = HIGH, M0 = HIGH
      THIRTY_TWO_STEP    // M1 = HIGH, M0 = tri-state (INPUT)
    };

    // Constructor: STEP, DIR, EN (shared enable; e.g., if AENBL and BENBL are combined), M0 and M1 pins
    DRV8834Stepper(uint8_t stepPin, uint8_t dirPin, uint8_t enPin, uint8_t m0Pin, uint8_t m1Pin);

    // Initialization and configuration function
    bool begin();

    // Sets the microstepping mode
    void setMicrostepMode(MicrostepMode mode, uint16_t step_delay_us);

    // Sets direction: true = forward (e.g., CLOCKWISE), false = backward (COUNTERCLOCKWISE)
    void setDirection(bool forward);

    // Enables or disables driver outputs
    void enableOutputs(bool enable);

    // Generates a single step pulse
    void step();

    // Takes the specified number of steps; waits delayMs milliseconds between each step
    void stepSteps(uint16_t steps);

  private:
    uint8_t _stepPin;
    uint8_t _dirPin;
  uint8_t _enPin;   // Shared enable signal (e.g., if AENBL and BENBL are tied together)
    uint8_t _m0Pin;
    uint8_t _m1Pin;
};

#endif
