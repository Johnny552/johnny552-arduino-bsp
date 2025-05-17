# Johnny552 Documentation

Johnny552 is an Arduino-compatible board support package (BSP) based on the WCH CH552P microcontroller. This documentation provides comprehensive information about setting up and using the Johnny552 development board.

## Table of Contents
1. [Introduction](#introduction)
2. [Supported Hardware](#supported-hardware)
3. [Getting Started](#getting-started)
4. [Programming Reference](#programming-reference)
5. [Tools and Utilities](#tools-and-utilities)

## Introduction

Johnny552 enables Arduino-style programming for the CH552P microcontroller, which is an 8051-core USB-capable MCU. The project provides:
- Arduino-compatible development environment
- USB bootloader support
- Core libraries for CH552P peripherals
- Examples and documentation


## Supported Hardware

The Johnny552 BSP is specifically designed for the Johnny552 development board, which features the CH552P microcontroller:

- **Johnny552 Development Board**:
  - CH552P microcontroller
  - 12-bit ADC
  - 16KB Flash
  - USB Device capabilities
  - Onboard SK6812 RGB LED
  - AHT21 sensor
  - Boot/user buttons
  - Exposed GPIO, UART, PWM, ADC, and interrupt pins

For detailed hardware documentation of the Johnny552 development board, please see [Johnny552 Hardware Documentation](johnny522_HardwareDocumentation.md).

## Getting Started

### Finding Examples

The Johnny552 package comes with several example sketches to help you get started. You can find them in the Arduino IDE:

![Example Location in Arduino IDE](exampleLocation.png)

Check out our detailed example guides:
- [Blink LED Example](../examples/Blink_LED_Example.md) - The classic LED blink example with demonstration

### Setting Up Your First Project

1. **Select Your Board**
   - Tools → Board → Johnny552

2. **Configure Settings**
   - USB Settings (if applicable)
   - Clock Speed
   - Upload Method

3. **Basic Example**
   ```cpp
   const int ledPin = D0;  // Use D0 constant for clarity

   void setup() {
   // Configure pin as output and ensure it starts LOW
   pinMode(ledPin, OUTPUT);
   digitalWrite(ledPin, LOW);
   delay(100);  // Short delay to ensure the pin is set
   }

   void loop() {
   digitalWrite(ledPin, HIGH);  // Turn LED on
   delay(1000);                 // Wait for 1 second
   digitalWrite(ledPin, LOW);   // Turn LED off
   delay(1000);                 // Wait for 1 second
   }
   ```

### Uploading Code

1. **Enter Bootloader Mode**
   - Hold the **BOOT** button
   - Connect the board to USB
   - Release the **BOOT** button

2. **Upload from Arduino IDE**
   - Click Upload button or press Ctrl+U/Cmd+U

## Programming Reference

### Core Functions

- **Digital I/O**
  - `pinMode(pin, mode)`
  - `digitalWrite(pin, value)`
  - `digitalRead(pin)`

- **Analog I/O**
  - `analogRead(pin)`
  - `analogWrite(pin, value)`

- **USB Functions**
  - `USBInit()`
  - `CDC_print()`
  - `USB_Suspend()`

### Interrupts and Timers

- Timer0/Timer1/Timer2 support
- External interrupts
- USB interrupts

## Tools and Utilities

### Johnny552 Specific Tools


### Development Tips


## Additional Resources

- [Official Repository](https://github.com/Johnny552/johnny552-arduino-bsp)
- [Johnny552 Project on Hackaday](https://hackaday.io/project/202773-johnny552-iot-development-board)

## Troubleshooting

### Common Issues

1. **Upload Problems**
   - Verify bootloader mode
   - Check USB connection
   - Verify driver installation

2. **Compilation Errors**
   - Check SDCC version compatibility
   - Verify memory usage
   - Check syntax for 8051 specifics

### Getting Help

- Open issues on GitHub
- [Reddit](https://www.reddit.com/r/Johnny552)

## License

This project is licensed under open-source terms. See LICENSE file for details.
