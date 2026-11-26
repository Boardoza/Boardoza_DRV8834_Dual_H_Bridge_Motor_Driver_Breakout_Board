#include "DRV8834.h"

#define DECAY_A 5
#define DECAY_B 18
#define AENBL 22
#define BENBL 21
#define M1 19
#define M0 23
#define DIR 25

DRV8834 motor(M0, DIR, M1, AENBL, BENBL, DECAY_A, DECAY_B);

void setup() {
  Serial.begin(115200);
  while(!Serial){

  }
  if (!motor.begin()) { Serial.println("DRV8834 not found."); while (1); }
  motor.bridgeEnables(1, 0);
}

void loop() {
  motor.turnForward(1, 0);
  delay(5000);
  motor.motorFloat(1, 0);
  delay(2000);
  motor.turnReverse(1, 0);
  delay(4000);
  motor.brake(1, 0);
  delay(2000);
}