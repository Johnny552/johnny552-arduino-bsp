# Johnny552Servo Library

A custom servo library for the Johnny552 board based on the CH55x microcontroller architecture.

## Overview

This library provides servo control for the Johnny552 board using direct PWM generation. It's designed as a replacement for the standard Servo library which doesn't work with the Johnny552's pin mapping.

## Features

- Arduino-like interface with familiar methods: `attach()`, `write()`, and `writeMicroseconds()`
- Compatible with Johnny552 board's pin mapping
- Configurable pulse width parameters
- Support for multiple servo objects

## Installation

The library is already included in the Johnny552 Arduino BSP. No additional installation is required.

## Usage

```cpp
#include <Johnny552Servo.h>

// Create servo object
Johnny552Servo myservo;

void setup() {
  // Attach servo to pin
  myservo.attach(5);  // Use pin 5 (P1.5)
  
  // Move to position
  myservo.write(90);  // Move to 90 degrees
}
```

## Hardware Connections

- Connect the servo signal wire to a digital pin (pin 5 recommended)
- Connect the servo power wire to 5V (external power supply recommended)
- Connect the servo ground wire to GND

## API Reference

### Constructor

```cpp
Johnny552Servo myservo;
```

### Methods

- `attach(uint8_t pin)`: Attaches the servo to a pin
- `detach()`: Detaches the servo
- `write(int angle)`: Writes an angle to the servo (0-180 degrees)
- `writeMicroseconds(int pulseWidth)`: Writes a pulse width in microseconds
- `attached()`: Returns true if the servo is attached

## Examples

- **ServoSweep**: Demonstrates sweeping a servo from 0 to 180 degrees and back

## Troubleshooting

If your servo is not responding:

1. Check your power supply - servos require more current than the USB connection can provide
2. Verify your wiring connections
3. Try different pulse width values by modifying the MIN_PULSE_WIDTH and MAX_PULSE_WIDTH constants

## License

This library is released under the MIT License.
