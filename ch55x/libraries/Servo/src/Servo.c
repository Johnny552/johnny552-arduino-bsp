/*
  Servo.cpp - Servo library for Johnny552 board
  
  This library provides servo control for the Johnny552 board
  using direct PWM generation. It's a replacement for the standard
  Servo library that works with the Johnny552's pin mapping.
  
  Created by Zwammaker, May 19, 2025
*/

#include "Servo.h"

// Maximum number of servos
#define MAX_SERVOS 8

// Servo data structure
typedef struct {
  uint8_t pin;          // Pin connected to servo
  uint16_t pulseWidth;  // Current pulse width
  uint16_t minPulse;    // Minimum pulse width for this servo
  uint16_t maxPulse;    // Maximum pulse width for this servo
  bool attached;        // True if servo is attached
} servo_t;

// Array of servo data
static servo_t servos[MAX_SERVOS];

// Generate a servo pulse
static void generatePulse(uint8_t pin, uint16_t pulseWidth) {
  // Generate multiple pulses to ensure servo has time to respond
  for (int i = 0; i < NUM_PULSES; i++) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(pulseWidth);
    digitalWrite(pin, LOW);
    delayMicroseconds(REFRESH_INTERVAL - pulseWidth);
  }
}

// Initialize the servo library
void Servo_init(void) {
  // Initialize all servos as detached
  for (int i = 0; i < MAX_SERVOS; i++) {
    servos[i].attached = false;
    servos[i].pulseWidth = DEFAULT_PULSE_WIDTH;
    servos[i].minPulse = MIN_PULSE_WIDTH;
    servos[i].maxPulse = MAX_PULSE_WIDTH;
  }
}

// Find an available servo slot
static int findFreeServo(void) {
  for (int i = 0; i < MAX_SERVOS; i++) {
    if (!servos[i].attached) {
      return i;
    }
  }
  return -1; // No free slots
}

// Find a servo by pin
static int findServoByPin(uint8_t pin) {
  for (int i = 0; i < MAX_SERVOS; i++) {
    if (servos[i].attached && servos[i].pin == pin) {
      return i;
    }
  }
  return -1; // Not found
}

// Attach servo to pin
bool Servo_attach(uint8_t pin) {
  int servoIndex = findFreeServo();
  if (servoIndex < 0) {
    return false; // No free slots
  }
  
  // Configure pin
  pinMode(pin, OUTPUT);
  
  // Store servo data
  servos[servoIndex].pin = pin;
  servos[servoIndex].pulseWidth = DEFAULT_PULSE_WIDTH;
  servos[servoIndex].minPulse = MIN_PULSE_WIDTH;
  servos[servoIndex].maxPulse = MAX_PULSE_WIDTH;
  servos[servoIndex].attached = true;
  
  // Move to default position (90 degrees)
  generatePulse(pin, DEFAULT_PULSE_WIDTH);
  
  return true;
}

// Attach servo to pin with custom min/max pulse width values
bool Servo_attachMinMax(uint8_t pin, uint16_t minPulse, uint16_t maxPulse) {
  int servoIndex = findFreeServo();
  if (servoIndex < 0) {
    return false; // No free slots
  }
  
  // Configure pin
  pinMode(pin, OUTPUT);
  
  // Store servo data
  servos[servoIndex].pin = pin;
  servos[servoIndex].pulseWidth = DEFAULT_PULSE_WIDTH;
  servos[servoIndex].minPulse = minPulse;
  servos[servoIndex].maxPulse = maxPulse;
  servos[servoIndex].attached = true;
  
  // Move to default position (90 degrees)
  generatePulse(pin, DEFAULT_PULSE_WIDTH);
  
  return true;
}

// Detach servo
void Servo_detach(uint8_t pin) {
  int servoIndex = findServoByPin(pin);
  if (servoIndex >= 0) {
    servos[servoIndex].attached = false;
  }
}

// Write angle (0-180 degrees)
void Servo_write(uint8_t pin, int angle) {
  int servoIndex = findServoByPin(pin);
  if (servoIndex < 0) return;
  
  // Constrain angle to valid range
  if (angle < 0) angle = 0;
  if (angle > 180) angle = 180;
  
  // Convert angle to pulse width using this servo's custom range
  uint16_t pulseWidth = map(angle, 0, 180, servos[servoIndex].minPulse, servos[servoIndex].maxPulse);
  
  // Store pulse width
  servos[servoIndex].pulseWidth = pulseWidth;
  
  // Generate pulses
  generatePulse(pin, pulseWidth);
}

// Write pulse width in microseconds
void Servo_writeMicroseconds(uint8_t pin, uint16_t pulseWidth) {
  int servoIndex = findServoByPin(pin);
  if (servoIndex < 0) return;
  
  // Constrain pulse width to this servo's valid range
  if (pulseWidth < servos[servoIndex].minPulse) pulseWidth = servos[servoIndex].minPulse;
  if (pulseWidth > servos[servoIndex].maxPulse) pulseWidth = servos[servoIndex].maxPulse;
  
  // Store pulse width
  servos[servoIndex].pulseWidth = pulseWidth;
  
  // Generate pulses
  generatePulse(pin, pulseWidth);
}

// Check if servo is attached
bool Servo_attached(uint8_t pin) {
  return (findServoByPin(pin) >= 0);
}
