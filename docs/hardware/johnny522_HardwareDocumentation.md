# Johnny552 Hardware Documentation

## Overview

The Johnny552 is a development board based on the CH552 microcontroller, which is part of the CH55x family of USB-capable 8051-core MCUs.

## Hardware Specifications

### CH552 Microcontroller Features
- 12-bit ADC
- 16KB Flash
- USB Device functionality
- Enhanced peripherals

### Development Board Layout

Front View | Back View
:-------------------------:|:-------------------------:
![Johnny552 Development Board Front](johnny552-0.1.0_front.png) | ![Johnny552 Development Board Back](johnny552-0.1.0_back.png)

## Pin Configuration

The Johnny552 development board exposes the CH552's GPIO pins in an Arduino-compatible layout. The board includes:
- Digital I/O pins
- Analog input pins
- USB connectivity
- Power regulation

## Getting Started with the Hardware

### Power Supply
The board can be powered through:
- USB connection
- External power supply

### Programming Mode
To upload code to the board:
1. Hold the BOOT button
2. Press RESET
3. Release BOOT
4. Upload your code using the Arduino IDE

## Hardware Interfaces

### USB Interface
- USB Type-C connector
- Supports USB Device mode
- Used for programming and serial communication

### GPIO Pins
- Digital I/O capabilities
- PWM support on selected pins
- Analog input support
- I2C and SPI support

## Additional Resources

- [Schematic Diagrams](schematics/)
- [PCB Layout Files](pcb/)
- [Component Datasheets](datasheets/)

## Troubleshooting

### Common Hardware Issues
1. USB Connection Problems
   - Check USB cable connection
   - Verify USB driver installation
   - Ensure proper bootloader mode entry

2. Power Issues
   - Check USB power supply
   - Verify voltage regulator output
   - Check for short circuits

## Safety Considerations

- Do not exceed maximum voltage ratings
- Observe proper polarity when connecting power
- Handle the board with ESD protection
- Keep the board away from moisture and conductive materials