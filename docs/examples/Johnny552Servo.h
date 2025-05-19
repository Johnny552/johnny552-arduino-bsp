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

class Johnny552Servo {
  public:
    // Constructor
    Johnny552Servo();
    
    // Attach the servo to a pin
    void attach(uint8_t pin);
    
    // Detach the servo
    void detach();
    
    // Write angle (0-180 degrees)
    void write(int angle);
    
    // Write pulse width in microseconds
    void writeMicroseconds(int pulseWidth);
    
    // Returns true if servo is attached
    bool attached();
    
  private:
    uint8_t _pin;           // Pin connected to servo
    int _pulseWidth;        // Current pulse width
    bool _attached;         // True if servo is attached
    
    // Generate a servo pulse
    void _generatePulse(int pulseWidth);
    
    // Constants
    static const int MIN_PULSE_WIDTH = 500;   // Minimum pulse width (0 degrees)
    static const int MAX_PULSE_WIDTH = 2500;  // Maximum pulse width (180 degrees)
    static const int DEFAULT_PULSE_WIDTH = 1500; // Default pulse width (90 degrees)
    static const int REFRESH_INTERVAL = 20000; // 20ms refresh interval (50Hz)
    static const int NUM_PULSES = 10;  // Number of pulses to generate per call
};

#endif // JOHNNY552_SERVO_H
