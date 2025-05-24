/*
  Servo.h - Servo library for Johnny552 board
  
  This library provides servo control for the Johnny552 board
  using direct PWM generation. It's a replacement for the standard
  Servo library that works with the Johnny552's pin mapping.
  
  Created by Zwammaker, May 19, 2025
*/

#ifndef SERVO_H
#define SERVO_H

#include <Arduino.h>

// Constants
#define MIN_PULSE_WIDTH 544    // Minimum pulse width (0 degrees)
#define MAX_PULSE_WIDTH 2400   // Maximum pulse width (180 degrees)
#define DEFAULT_PULSE_WIDTH 1500 // Default pulse width (90 degrees)
#define REFRESH_INTERVAL 20000  // 20ms refresh interval (50Hz)
#define NUM_PULSES 10           // Number of pulses to generate per call

// Initialize the servo library
void Servo_init(void);

// Attach servo to pin with default pulse width range (500-2500)
bool Servo_attach(uint8_t pin);

// Attach servo to pin with custom min/max pulse width values
bool Servo_attachMinMax(uint8_t pin, uint16_t minPulse, uint16_t maxPulse);

// Detach servo
void Servo_detach(uint8_t pin);

// Write angle (0-180 degrees)
void Servo_write(uint8_t pin, int angle);

// Write pulse width in microseconds
void Servo_writeMicroseconds(uint8_t pin, uint16_t pulseWidth);

// Check if servo is attached
bool Servo_attached(uint8_t pin);

#endif // SERVO_H
