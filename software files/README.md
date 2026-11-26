# Boardoza DRV8834 Library

## Description

This library provides an easy-to-use API for interfacing with the DRV8834 stepper motor driver. It supports configuration, control, and monitoring of stepper motors. Designed for Arduino and PlatformIO projects, it includes example sketches and minimal dependencies.

## Features

- Clean Arduino-compatible C++ API through the `DRV8834` class
- ESP32 (Arduino / PlatformIO) support
- 2 example sketch(es) under `examples/`

## Installation

**Arduino Library Manager:** Search for `Boardoza DRV8834 Stepper Driver` and click Install.

**Manual ZIP:** Download ZIP from GitHub → Arduino IDE → Sketch → Include Library → Add .ZIP Library.

## Wiring

| DRV8834 Pin | ESP32 Pin | Notes |
|---|---|---|
| VCC | 3.3V |
| GND | GND |
| Signal | See examples | Pin assignments are defined in the example sketches |

## Usage

```cpp
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
  motor.begin();
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
```

## API Reference

| Method | Parameters | Returns |
|---|---|---|
| `DRV8834` | `uint8_t M0, uint8_t DIR, uint8_t M1, uint8_t AENBL, uint8_t BENBL, uint8_t DECAY_A, uint8_t DECAY_B` | `-` |
| `begin` | `-` | `void` |
| `bridgeEnables` | `uint8_t A, uint8_t B` | `void` |
| `motorFloat` | `uint8_t A, uint8_t B` | `void` |
| `brake` | `uint8_t A, uint8_t B` | `void` |
| `turnForward` | `uint8_t A, uint8_t B` | `void` |
| `turnReverse` | `uint8_t A, uint8_t B` | `void` |

## License

MIT License — Copyright (c) 2026 Boardoza
