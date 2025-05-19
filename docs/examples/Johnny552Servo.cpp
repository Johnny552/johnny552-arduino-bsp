/*
  Johnny552Servo.cpp - Servo library for Johnny552 board
  
  This library provides servo control for the Johnny552 board
  using direct PWM generation. It's designed as a replacement for
  the standard Servo library which doesn't work with the Johnny552's
  pin mapping.
  
  Created by Zwammaker, May 19, 2025
*/

#include "Johnny552Servo.h"

// Constructor
Johnny552Servo::Johnny552Servo() {
  _attached = false;
  _pulseWidth = DEFAULT_PULSE_WIDTH;
}

// Attach servo to pin
void Johnny552Servo::attach(uint8_t pin) {
  _pin = pin;
  pinMode(_pin, OUTPUT);
  _attached = true;
  
  // Move to default position (90 degrees)
  _pulseWidth = DEFAULT_PULSE_WIDTH;
  _generatePulse(_pulseWidth);
}

// Detach servo
void Johnny552Servo::detach() {
  _attached = false;
}

// Write angle (0-180 degrees)
void Johnny552Servo::write(int angle) {
  if (!_attached) return;
  
  // Constrain angle to valid range
  if (angle < 0) angle = 0;
  if (angle > 180) angle = 180;
  
  // Convert angle to pulse width
  _pulseWidth = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  
  // Generate pulses
  _generatePulse(_pulseWidth);
}

// Write pulse width in microseconds
void Johnny552Servo::writeMicroseconds(int pulseWidth) {
  if (!_attached) return;
  
  // Constrain pulse width to valid range
  if (pulseWidth < MIN_PULSE_WIDTH) pulseWidth = MIN_PULSE_WIDTH;
  if (pulseWidth > MAX_PULSE_WIDTH) pulseWidth = MAX_PULSE_WIDTH;
  
  _pulseWidth = pulseWidth;
  
  // Generate pulses
  _generatePulse(_pulseWidth);
}

// Check if servo is attached
bool Johnny552Servo::attached() {
  return _attached;
}

// Private method to generate servo pulses
void Johnny552Servo::_generatePulse(int pulseWidth) {
  // Generate multiple pulses to ensure servo has time to respond
  for (int i = 0; i < NUM_PULSES; i++) {
    digitalWrite(_pin, HIGH);
    delayMicroseconds(pulseWidth);
    digitalWrite(_pin, LOW);
    delayMicroseconds(REFRESH_INTERVAL - pulseWidth);
  }
}
