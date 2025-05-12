/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include "pins_arduino_include.h"

#ifndef _BV
#define _BV(X) (1 << (X))
#endif

__code uint8_t digital_pin_to_pwm_PGM[] = {
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

__code uint8_t PROGMEM digital_pin_to_port_PGM[] = {
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

__code uint8_t digital_pin_to_bit_mask_PGM[] = {
    0, // PIN00
    0, _BV(4), _BV(6), _BV(7),         // PIN02->P1.4, PIN03->P1.6, PIN04->P1.7
    _BV(5), _BV(1), 0,                  // PIN05->P1.5, PIN07->P1.1
    _BV(1), _BV(0),                     // PIN08->P3.1, PIN09->P3.0

    _BV(3), _BV(4),                     // PIN10->P3.3, PIN11->P3.4
    0, 0, 0,
    0, 0, 0,
    0, 0,

    0, // PIN20
    0, 0, 0, 0,
    0, 0, 0,
    0, 0,

    0, // PIN30
    0, 0, 0, 0,
    0, 0, 0,
    0, 0
};

__code uint8_t digital_pin_to_channel_PGM[] = {
    NOT_ANALOG, // PIN00
    NOT_ANALOG, 1, NOT_ANALOG, NOT_ANALOG,          // PIN02->P1.4 (AIN1), PIN03->P1.6, PIN04->P1.7
    2,          NOT_ANALOG, 0,                      // PIN05->P1.5 (AIN2), PIN07->P1.1 (AIN0)
    NOT_ANALOG, NOT_ANALOG,                          // PIN08->P3.1, PIN09->P3.0

    NOT_ANALOG, NOT_ANALOG,                          // PIN10->P3.3, PIN11->P3.4
    NOT_ANALOG, NOT_ANALOG, NOT_ANALOG,
    NOT_ANALOG, NOT_ANALOG, NOT_ANALOG,
    NOT_ANALOG, NOT_ANALOG

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

#endif
