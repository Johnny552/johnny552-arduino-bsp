#ifndef _PINS_ARDUINO_H_
#define _PINS_ARDUINO_H_

// Pin aliases for Johnny552 (based on CH552P)

#define LED_BUILTIN    4     // P1.4 (connected to SK6812)
#define PIN_BUTTON     10    // P3.3 (INT1) - user button
#define PIN_BOOT       6     // P3.2 (INT0) - boot button

// Digital pins
#define D0  7   // P1.1
#define D1  8   // P3.1
#define D2  9   // P3.0
#define D3  10  // P3.3
#define D4  11  // P3.4
#define D5  2   // P1.4
#define D6  3   // P1.6
#define D7  4   // P1.7
#define D8  5   // P1.5

// Analog pins (AINx)
#define A0  7   // P1.1
#define A1  2   // P1.4
#define A2  5   // P1.5

// I2C (for AHT21)
#define SDA D6  // P1.6
#define SCL D7  // P1.7

// SPI
#define PIN_SPI_SS    D5   // P1.4
#define PIN_SPI_MOSI  D6   // P1.6
#define PIN_SPI_MISO  D8   // P1.5
#define PIN_SPI_SCK   D7   // P1.7

#endif
