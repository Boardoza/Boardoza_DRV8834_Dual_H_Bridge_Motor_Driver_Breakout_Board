/**
 * @file DRV8834Stepper.cpp
 * @brief Implementation of the DRV8834Stepper class for controlling a DRV8834 stepper motor driver.
 *
 * This file provides the function definitions for initializing, configuring, and controlling
 * a stepper motor using the DRV8834 driver. It supports various microstepping modes, direction control,
 * output enable/disable, and step pulse generation.
 */

#include "DRV8834Stepper.h"
#include "DRV8834Stepper.h"

/**
 * @brief Constructor for DRV8834Stepper.
 *
 * Initializes the stepper driver object with the specified pin assignments.
 *
 * @param stepPin Pin connected to the STEP input of the driver.
 * @param dirPin Pin connected to the DIR (direction) input.
 * @param enPin Pin connected to the enable input (shared if AENBL and BENBL are combined).
 * @param m0Pin Pin connected to the M0 microstepping mode input.
 * @param m1Pin Pin connected to the M1 microstepping mode input.
 */
DRV8834Stepper::DRV8834Stepper(uint8_t stepPin, uint8_t dirPin, uint8_t enPin, uint8_t m0Pin, uint8_t m1Pin) {
  _stepPin = stepPin;
  _dirPin  = dirPin;
  _enPin   = enPin;
  _m0Pin   = m0Pin;
  _m1Pin   = m1Pin;
}

/**
 * @brief Initialize the stepper driver and configure pins.
 *
 * Sets all control pins as outputs, sets the default microstepping mode to FULL_STEP,
 * and enables the driver outputs by default (active low enable).
 */
bool DRV8834Stepper::begin() {
  pinMode(_stepPin, OUTPUT);
  pinMode(_dirPin, OUTPUT);
  pinMode(_enPin, OUTPUT);
  // M0 and M1 are initially set as OUTPUT
  pinMode(_m0Pin, OUTPUT);
  pinMode(_m1Pin, OUTPUT);

  // Default microstepping mode: FULL_STEP
  setMicrostepMode(FULL_STEP, 675);

  // Enable outputs (driver is active when nENBL is HIGH)
  digitalWrite(_enPin, LOW);
    return true;
}


uint16_t _step_delay;

/**
 * @brief Set the microstepping mode and step pulse delay.
 *
 * Configures the M0 and M1 pins to select the desired microstepping mode (full, half, 1/8, 1/16, 1/32 step).
 * Also sets the delay (in microseconds) between step pulses for timing control.
 *
 * @param mode Microstepping mode (enum value).
 * @param step_delay_us Delay in microseconds for each step pulse.
 */
void DRV8834Stepper::setMicrostepMode(MicrostepMode mode, uint16_t step_delay_us) {
  switch(mode) {
    case FULL_STEP:
      // Full step: M1 = LOW, M0 = LOW
      pinMode(_m0Pin, OUTPUT);
      digitalWrite(_m0Pin, LOW);
      digitalWrite(_m1Pin, LOW);
      _step_delay = step_delay_us;
      break;
    case HALF_STEP:
      // Half step: M1 = LOW, M0 = HIGH
      pinMode(_m0Pin, OUTPUT);
      digitalWrite(_m0Pin, HIGH);
      digitalWrite(_m1Pin, LOW);
      _step_delay = step_delay_us;
      break;
    case EIGHTH_STEP:
      // 8 microsteps: M1 = HIGH, M0 = LOW
      pinMode(_m0Pin, OUTPUT);
      digitalWrite(_m0Pin, LOW);
      digitalWrite(_m1Pin, HIGH);
      _step_delay = step_delay_us;
      break;
    case SIXTEENTH_STEP:
      // 16 microsteps: M1 = HIGH, M0 = HIGH
      pinMode(_m0Pin, OUTPUT);
      digitalWrite(_m0Pin, HIGH);
      digitalWrite(_m1Pin, HIGH);
      _step_delay = step_delay_us;
      break;
    case THIRTY_TWO_STEP:
      // 32 microsteps: M1 = HIGH, M0 = tri-state (INPUT)
      digitalWrite(_m1Pin, HIGH);
      pinMode(_m0Pin, INPUT); // Switch to tri-state mode, releasing the M0 pin.
      _step_delay = step_delay_us;
      break;
    default:
      // If undefined, revert to full step
      pinMode(_m0Pin, OUTPUT);
      digitalWrite(_m0Pin, LOW);
      digitalWrite(_m1Pin, LOW);
      _step_delay = step_delay_us;
      break;
  }
}


/**
 * @brief Set the rotation direction of the stepper motor.
 *
 * Sets the DIR pin to control the direction: HIGH for forward (clockwise), LOW for backward (counterclockwise).
 *
 * @param forward true for forward (clockwise), false for backward (counterclockwise).
 */
void DRV8834Stepper::setDirection(bool forward) {
  digitalWrite(_dirPin, forward ? HIGH : LOW);
}


/**
 * @brief Enable or disable the stepper driver outputs.
 *
 * Controls the enable pin to activate or deactivate the driver outputs.
 *
 * @param enable true to enable outputs, false to disable.
 */
void DRV8834Stepper::enableOutputs(bool enable) {
  digitalWrite(_enPin, enable ? HIGH : LOW);
}


/**
 * @brief Generate a single step pulse on the STEP pin.
 *
 * Sends a HIGH-LOW pulse to the STEP pin, with timing determined by the configured step delay.
 * This advances the stepper motor by one microstep or full step, depending on the mode.
 */
void DRV8834Stepper::step() {
  // Send a pulse to the STEP pin.
  digitalWrite(_stepPin, HIGH);
  delayMicroseconds(_step_delay);  // According to the datasheet, tWH(STEP) minimum is 1.9µs; using a safe value here.
  digitalWrite(_stepPin, LOW);
  delayMicroseconds(_step_delay);  // Similarly for tWL(STEP).
}


/**
 * @brief Take a specified number of steps.
 *
 * Calls the step() function repeatedly to move the stepper motor by the given number of steps.
 *
 * @param steps Number of steps to take.
 */
void DRV8834Stepper::stepSteps(uint16_t steps) {
  for (uint16_t i = 0; i < steps; i++) {
    step();
  }
}
