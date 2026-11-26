#include "DRV8834Stepper.h"

#define STEP_PIN  25
#define DIR_PIN   26
#define EN_PIN    27    // Assuming you have combined AENBL and BENBL pins
#define M0_PIN    14
#define M1_PIN    12

DRV8834Stepper stepper(STEP_PIN, DIR_PIN, EN_PIN, M0_PIN, M1_PIN);

/*
  FULL STEP -> 720 us
  HALF STEP -> 300 us
  EIGHTH STEP -> 84 us
  SIXTEENTH STEP -> 42 us
  THIRTY_TWO_STEP -> 24 us

  These are the safe microsecond delays between steps for each microstepping mode.
*/

void setup() {
  if (!stepper.begin()) { Serial.println("DRV8834 not found."); while (1); }
  stepper.setMicrostepMode(DRV8834Stepper::THIRTY_TWO_STEP, 75);
  stepper.setDirection(true);   // Forward direction
  stepper.enableOutputs(false);  // Enable outputs
}

void loop() {
  // Take 2000 steps, 10ms delay between each step
  stepper.setDirection(true);
  stepper.stepSteps(2000);
  delay(100);
  // Change direction
  stepper.setDirection(false);
  stepper.stepSteps(2000);
  delay(100);
}
