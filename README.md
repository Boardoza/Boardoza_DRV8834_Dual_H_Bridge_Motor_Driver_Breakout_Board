
# Boardoza DRV8834 Dual H-Bridge Motor Driver Breakout Board

The **Boardoza DRV8834 Breakout Board** is a dual H-bridge motor driver board based on the **Texas Instruments DRV8834RGER** integrated circuit. It is designed to control **one bipolar stepper motor or two brushed DC motors**, providing PWM current regulation for precise and smooth motor operation.

Each H-bridge can deliver up to **1.5A continuous current and 2.2A peak current** under specified conditions. Integrated protection features include overcurrent, overtemperature, and undervoltage protection, making the board suitable for **robotics, battery-powered devices, printers, camera mechanisms, and other motion control applications**.

## Product Images

| Front Side | Back Side |
|:---:|:---:|
| ![Front](./assets/DRV8834%20Front.png) | ![Back](./assets/DRV8834%20Back.png) |

---

## Key Features

- **Dual H-Bridge Motor Control:** Drives one bipolar stepper motor or two brushed DC motors independently.
- **Flexible Control Modes:** Supports Step/Direction control with an integrated indexer and Phase/Enable control for direct H-bridge operation.
- **Precision Microstepping:** Provides full-step, half-step, and microstepping resolutions up to 1/32-step for smoother stepper motor operation.
- **Adjustable Decay Modes:** Supports slow, fast, and mixed decay modes to optimize winding current regulation.
- **Integrated Current Regulation:** Uses PWM winding current regulation and current limiting for controlled motor operation.
- **Built-In Protection:** Includes overcurrent, overtemperature, and undervoltage protection with a fault indication output.

---

## Technical Specifications

**Model:** DRV8834RGER   
**Manufacturer:** Boardoza  
**Manufacturer IC:** Texas Instruments     
**Input Voltage:** 2.5V - 10.8V (Motor Supply)  
**Logic Supply Connection:** 3.3V  
**Functions:** Bipolar Stepper Motor or Dual Brushed DC Motor Driver  
**Output Current:** 1.5A Continuous, 2.2A Peak per H-Bridge (@VM = 5V, TA = 25°C)  
**Control Modes:** Indexer Mode and Phase/Enable Mode  
**Decay Modes:** Slow, Fast, Mixed Decay  
**Protection Features:** Overcurrent, Overtemperature, Undervoltage  
**Operating Temperature:** -40°C to +85°C  
**Board Dimensions:** 40mm x 40mm

---

## Board Pinout

### ( J1 ) Sleep Mode Control Pins

| Pin Number | Pin Name | Description |
| :---: | :---: | --- |
| 1 | +3V3 | External 3.3V Supply Connection |
| 2 | nSLEEP | Sleep Mode Input. Logic high enables the device; logic low enters low-power sleep mode and resets internal logic. |
| 3 | GND | Ground |

### ( J2 ) Operating Mode Configuration Pins

| Pin Number | Pin Name | Description |
| :---: | :---: | --- |
| 1 | +3V3 | External 3.3V Supply Connection |
| 2 | CONFIG | Operating Mode Selection. Logic high selects Indexer Mode; logic low selects Phase/Enable Mode. The state is latched at power-up and sleep exit. |
| 3 | GND | Ground |

### ( J3 ) Motor Power Supply Pins

| Pin Number | Pin Name | Description |
| :---: | :---: | --- |
| 1 | VM | Motor Power Supply Input (2.5V - 10.8V) |
| 2 | GND | Ground |

### ( J4 ) H-Bridge B Motor Output Pins

| Pin Number | Pin Name | Description |
| :---: | :---: | --- |
| 1 | B_OUT1 | H-Bridge B Output 1. |
| 2 | B_OUT2 | H-Bridge B Output 2. |

### ( J5 ) H-Bridge A Motor Output Pins

| Pin Number | Pin Name | Description |
| :---: | :---: | --- |
| 1 | A_OUT2 | H-Bridge A Output 2. |
| 2 | A_OUT1 | H-Bridge A Output 1. |

### ( J6 ) Motor Control and Status Pins

| Pin Number | Pin Name | Description |
| :---: | :---: | --- |
| 1 | +3V3 | External 3.3V Supply Connection |
| 2 | nFAULT | Active-Low Fault Output. Indicates overcurrent, overtemperature, or undervoltage conditions. |
| 3 | nENBL | Indexer Mode: Logic low enables all motor outputs. Phase/Enable Mode: Logic high enables H-Bridge A outputs. |
| 4 | STEP | Indexer Mode: A rising edge advances the motor by one selected step increment. Phase/Enable Mode: Logic high enables H-Bridge B outputs. |
| 5 | DIR/BP | Indexer Mode: Sets the motor rotation direction. Phase/Enable Mode: Controls the polarity of H-Bridge B outputs. |
| 6 | M0/AP | Indexer Mode: Selects microstepping resolution together with M1. Phase/Enable Mode: Controls the polarity of H-Bridge A outputs. |
| 7 | M1 | Indexer Mode: Selects microstepping resolution together with M0. Phase/Enable Mode: Determines the output state when a bridge is disabled. |
| 8 | B_DECAY | Selects how quickly the current decreases in motor winding B (Slow, Fast, or Mixed Decay). |
| 9 | A_DECAY | Selects how quickly the current decreases in motor winding A (Slow, Fast, or Mixed Decay). In Indexer Mode, controls both windings. |
| 10 | GND | Ground |

---

## Board Dimensions

<img src="./assets/DRV8834 Dimensions.png" alt="DRV8834 Dimension" width="450"/>

---

## Step Files

[Boardoza DRV8834.step](./assets/DRV8834%20Step.step)

---

## Sensor Datasheet

[DRV8834 Datasheet](./assets/DRV8834%20Datasheet.pdf)

---

## Version History

- V1.0.0 - Initial Release

---

## Support

- If you have any questions or need support, please contact <support@boardoza.com>

---

## **License**

This repository contains both hardware and software components:

### **Hardware Design**

[![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

All hardware design files are licensed under [Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg

### **Software/Firmware**

[![BSD-3-Clause][bsd-shield]][bsd]

All software and firmware are licensed under [BSD 3-Clause License][bsd].

[bsd]: https://opensource.org/licenses/BSD-3-Clause
[bsd-shield]: https://img.shields.io/badge/License-BSD%203--Clause-blue.svg
