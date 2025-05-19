/*
  Johnny552Servo.cpp - Servo library for Johnny552 board
  
  This library provides servo control for the Johnny552 board
  using direct PWM generation. It's designed as a replacement for
  the standard Servo library which doesn't work with the Johnny552's
  pin mapping.
  
  Created by Zwammaker, May 19, 2025
*/

#include "Johnny552Servo.h"

// Maximum number of servos
#define MAX_SERVOS 8

// Servo data structure
typedef struct {
  uint8_t pin;          // Pin connected to servo
  uint16_t pulseWidth;  // Current pulse width
  bool attached;        // True if servo is attached
} servo_t;

// Array of servo data
static servo_t servos[MAX_SERVOS];

// Generate a servo pulse
static void generatePulse(uint8_t pin, uint16_t pulseWidth) {
  // Generate multiple pulses to ensure servo has time to respond
  for (int i = 0; i < JOHNNY552_SERVO_NUM_PULSES; i++) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(pulseWidth);
    digitalWrite(pin, LOW);
    delayMicroseconds(JOHNNY552_SERVO_REFRESH_INTERVAL - pulseWidth);
  }
}

// Initialize the servo library
void Johnny552Servo_init(void) {
  // Initialize all servos as detached
  for (int i = 0; i < MAX_SERVOS; i++) {
    servos[i].attached = false;
    servos[i].pulseWidth = JOHNNY552_SERVO_DEFAULT_PULSE_WIDTH;
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
bool Johnny552Servo_attach(uint8_t pin) {
  int servoIndex = findFreeServo();
  if (servoIndex < 0) {
    return false; // No free slots
  }
  
  // Configure pin
  pinMode(pin, OUTPUT);
  
  // Store servo data
  servos[servoIndex].pin = pin;
  servos[servoIndex].pulseWidth = JOHNNY552_SERVO_DEFAULT_PULSE_WIDTH;
  servos[servoIndex].attached = true;
  
  // Move to default position (90 degrees)
  generatePulse(pin, JOHNNY552_SERVO_DEFAULT_PULSE_WIDTH);
  
  return true;
}

// Detach servo
void Johnny552Servo_detach(uint8_t pin) {
  int servoIndex = findServoByPin(pin);
  if (servoIndex >= 0) {
    servos[servoIndex].attached = false;
  }
}

// Write angle (0-180 degrees)
void Johnny552Servo_write(uint8_t pin, int angle) {
  int servoIndex = findServoByPin(pin);
  if (servoIndex < 0) return;
  
  // Constrain angle to valid range
  if (angle < 0) angle = 0;
  if (angle > 180) angle = 180;
  
  // Convert angle to pulse width
  uint16_t pulseWidth = map(angle, 0, 180, JOHNNY552_SERVO_MIN_PULSE_WIDTH, JOHNNY552_SERVO_MAX_PULSE_WIDTH);
  
  // Store pulse width
  servos[servoIndex].pulseWidth = pulseWidth;
  
  // Generate pulses
  generatePulse(pin, pulseWidth);
}

// Write pulse width in microseconds
void Johnny552Servo_writeMicroseconds(uint8_t pin, uint16_t pulseWidth) {
  int servoIndex = findServoByPin(pin);
  if (servoIndex < 0) return;
  
  // Constrain pulse width to valid range
  if (pulseWidth < JOHNNY552_SERVO_MIN_PULSE_WIDTH) pulseWidth = JOHNNY552_SERVO_MIN_PULSE_WIDTH;
  if (pulseWidth > JOHNNY552_SERVO_MAX_PULSE_WIDTH) pulseWidth = JOHNNY552_SERVO_MAX_PULSE_WIDTH;
  
  // Store pulse width
  servos[servoIndex].pulseWidth = pulseWidth;
  
  // Generate pulses
  generatePulse(pin, pulseWidth);
}

// Check if servo is attached
bool Johnny552Servo_attached(uint8_t pin) {
  return (findServoByPin(pin) >= 0);
}
