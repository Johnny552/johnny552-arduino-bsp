/*
  Johnny552Servo.h - Servo library for Johnny552 board
  
  This library provides servo control for the Johnny552 board
  using direct PWM generation. It's designed as a replacement for
  the standard Servo library which doesn't work with the Johnny552's
  pin mapping.
  
  Created by Zwammaker, May 19, 2025
*/

#ifndef JOHNNY552_SERVO_H
#define JOHNNY552_SERVO_H

#include <Arduino.h>

// Constants
#define JOHNNY552_SERVO_MIN_PULSE_WIDTH 500    // Minimum pulse width (0 degrees)
#define JOHNNY552_SERVO_MAX_PULSE_WIDTH 2500   // Maximum pulse width (180 degrees)
#define JOHNNY552_SERVO_DEFAULT_PULSE_WIDTH 1500 // Default pulse width (90 degrees)
#define JOHNNY552_SERVO_REFRESH_INTERVAL 20000  // 20ms refresh interval (50Hz)
#define JOHNNY552_SERVO_NUM_PULSES 10           // Number of pulses to generate per call

// Initialize the servo library
void Johnny552Servo_init(void);

// Attach servo to pin
bool Johnny552Servo_attach(uint8_t pin);

// Detach servo
void Johnny552Servo_detach(uint8_t pin);

// Write angle (0-180 degrees)
void Johnny552Servo_write(uint8_t pin, int angle);

// Write pulse width in microseconds
void Johnny552Servo_writeMicroseconds(uint8_t pin, uint16_t pulseWidth);

// Check if servo is attached
bool Johnny552Servo_attached(uint8_t pin);

#endif // JOHNNY552_SERVO_H
