# Johnny552 Arduino BSP

This repository provides an Arduino-compatible board support package (BSP) for the [Johnny552](https://github.com/Johnny552) development board, which uses the WCH CH552P microcontroller. It is based on [ch55xduino](https://github.com/DeqingSun/ch55xduino) but specifically configured for the Johnny552 pinout and hardware layout.

## About Johnny552

Johnny552 is a compact, USB-powered development board featuring:
- CH552P (8051-core USB microcontroller)
- Boot/user buttons
- Exposed GPIO, UART, PWM, ADC, and interrupt pins
- Onboard SK6812 RGB LED
- AHT21 sensor
- USB HID/MIDI/CDC capable

## Installation

This BSP is not yet available via Boards Manager. To install manually:

### Arduino CLI or Manual Install

1. Clone this repository into your Arduino hardware directory:

mkdir -p ~/Arduino/hardware/johnny552 cd ~/Arduino/hardware/johnny552 git clone https://github.com/Johnny552/johnny552-arduino-bsp.git ch55xduino

2. Restart the Arduino IDE.

3. Under **Tools > Board**, select **Johnny552**.

## Flashing Firmware

The Johnny552 comes with a USB bootloader pre-installed. To enter bootloader mode:

1. Hold the **BOOT** button
2. Tap the **RESET** button
3. Release **BOOT**

Then upload your sketch from the Arduino IDE.

## Pinout

Refer to the [pinout diagram](docs/johnny552-pinout.png) and [CH552 datasheet](docs/CH552DS1.pdf) for GPIO and peripheral mapping.

## Documentation

Comprehensive documentation is available in the [docs](docs/index.md) directory, including:
- Complete CH55xduino Guide
- Hardware Documentation
- Example Projects
- Tools and Resources
- Programming Reference

## Credits

- Based on [ch55xduino](https://github.com/DeqingSun/ch55xduino) by Deqing Sun
- Hardware design: [Johnny552 Project](https://github.com/Johnny552)

## License

The Johnny552 Arduino BSP software is licensed under the GNU Lesser General Public License v2.1.

Hardware designs are licensed under the GNU Lesser General Public License v2.1.

Documentation is licensed under the GNU Lesser General Public License v2.1.

This project is based on the CH55xduino project.
