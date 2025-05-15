#ifndef _PINS_ARDUINO_H_
#define _PINS_ARDUINO_H_

#include "pins_arduino_include.h"


#ifndef __code
#define __code
#endif

#ifndef PROGMEM
#define PROGMEM
#endif

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

#ifndef _BV
#define _BV(X) (1 << (X))
#endif

uint8_t digital_pin_to_pwm_PGM[] = {
    NOT_ON_PWM, // PIN00
    NOT_ON_PWM, NOT_ON_PWM, NOT_ON_PWM, NOT_ON_PWM,  // PIN02->P1.4, PIN03->P1.6, PIN04->P1.7
    PIN_PWM1, NOT_ON_PWM, NOT_ON_PWM,               // PIN05->P1.5 (PWM1), PIN07->P1.1
    PIN_PWM2, PIN_PWM1,                            // PIN08->P3.1 (PWM2), PIN09->P3.0 (PWM1)

    NOT_ON_PWM, PIN_PWM2,                          // PIN10->P3.3, PIN11->P3.4 (PWM2)
    NOT_ON_PWM, NOT_ON_PWM, NOT_ON_PWM,
    NOT_ON_PWM, NOT_ON_PWM, NOT_ON_PWM,
    NOT_ON_PWM, NOT_ON_PWM,

    NOT_ON_PWM, // PIN20
    NOT_ON_PWM, NOT_ON_PWM, NOT_ON_PWM, NOT_ON_PWM,
    NOT_ON_PWM, NOT_ON_PWM, NOT_ON_PWM,
    NOT_ON_PWM, NOT_ON_PWM,

    NOT_ON_PWM, // PIN30
    NOT_ON_PWM, NOT_ON_PWM, NOT_ON_PWM, NOT_ON_PWM,
    NOT_ON_PWM, NOT_ON_PWM, NOT_ON_PWM,
    NOT_ON_PWM, NOT_ON_PWM
};

uint8_t digital_pin_to_port_PGM[] = {
    NOT_A_PORT, // PIN00
    NOT_A_PORT, P1PORT, P1PORT, P1PORT,  // PIN02->P1.4, PIN03->P1.6, PIN04->P1.7
    P1PORT, P1PORT, P1PORT,              // PIN05->P1.5, PIN07->P1.1
    P3PORT, P3PORT,                      // PIN08->P3.1, PIN09->P3.0

    P3PORT, P3PORT,                      // PIN10->P3.3, PIN11->P3.4
    NOT_A_PORT, NOT_A_PORT, NOT_A_PORT,
    NOT_A_PORT, NOT_A_PORT, NOT_A_PORT,
    NOT_A_PORT, NOT_A_PORT,

    NOT_A_PORT, // PIN20
    NOT_A_PORT, NOT_A_PORT, NOT_A_PORT, NOT_A_PORT,
    NOT_A_PORT, NOT_A_PORT, NOT_A_PORT,
    NOT_A_PORT, NOT_A_PORT,

    P3PORT, // PIN30 (P3.0)
    P3PORT, P3PORT, P3PORT, P3PORT,     // P3.1-P3.4
    NOT_A_PORT, NOT_A_PORT, NOT_A_PORT,
    NOT_A_PORT, // not exist
    NOT_A_PORT  // not exist
};

// Bit mask mapping for each Arduino digital pin
uint8_t digital_pin_to_bit_mask_PGM[] = {
    0,      // 0: NOT_A_PORT
    0,      // 1: NOT_A_PORT
    _BV(4), // 2: P1.4 (D5)
    _BV(6), // 3: P1.6 (D6)
    _BV(7), // 4: P1.7 (D7)
    _BV(5), // 5: P1.5 (D8)
    0,      // 6: Not mapped
    _BV(1), // 7: P1.1 (D0)
    _BV(1), // 8: P3.1 (D1)
    _BV(0), // 9: P3.0 (D2)
    _BV(3), // 10: P3.3 (D3)
    _BV(4), // 11: P3.4 (D4)
    0, 0, 0, 0, 0, 0, 0, 0, // 12-19: Not mapped
    0,      // 20: NOT_A_PORT
    0, 0, 0, 0, 0, 0, 0, 0, 0, // 21-29: Not mapped
    _BV(0), // 30: P3.0
    _BV(1), // 31: P3.1
    _BV(2), // 32: P3.2
    _BV(3), // 33: P3.3
    _BV(4), // 34: P3.4
    0, 0, 0, 0, // 35-38: Not mapped
    0        // 39: Not mapped
};

uint8_t digital_pin_to_channel_PGM[] = {
    NOT_ANALOG, // PIN00
    NOT_ANALOG, 1, NOT_ANALOG, NOT_ANALOG,          // PIN02->P1.4 (AIN1), PIN03->P1.6, PIN04->P1.7
    2,          NOT_ANALOG, 0,                      // PIN05->P1.5 (AIN2), PIN07->P1.1 (AIN0)
    NOT_ANALOG, NOT_ANALOG,                          // PIN08->P3.1, PIN09->P3.0

    NOT_ANALOG, NOT_ANALOG,                          // PIN10->P3.3, PIN11->P3.4
    NOT_ANALOG, NOT_ANALOG, NOT_ANALOG,
    NOT_ANALOG, NOT_ANALOG, NOT_ANALOG,
    NOT_ANALOG, NOT_ANALOG,

    NOT_ANALOG, // PIN20
    NOT_ANALOG, NOT_ANALOG, NOT_ANALOG, NOT_ANALOG,
    NOT_ANALOG, NOT_ANALOG, NOT_ANALOG,
    NOT_ANALOG, // not exist
    NOT_ANALOG, // not exist

    NOT_ANALOG, // PIN30
    NOT_ANALOG, NOT_ANALOG, NOT_ANALOG, NOT_ANALOG,  // PIN32 is onboard tactile switch
    NOT_ANALOG, NOT_ANALOG, NOT_ANALOG,
    NOT_ANALOG, NOT_ANALOG
};

// End of include guard
#endif