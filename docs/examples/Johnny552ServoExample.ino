/*
  Johnny552 Servo Example
  
  This example demonstrates how to use the Johnny552Servo library
  to control a standard hobby servo with the Johnny552 board.
  
  The servo will sweep from 0 to 180 degrees and back.
  
  Connections:
  - Servo signal wire to pin 5 (P1.5)
  - Servo power wire to 5V (external power recommended)
  - Servo ground wire to GND
  - LED on pin 7 (P1.1) for visual feedback
*/

#include <Johnny552Servo.h>

// Pin definitions
#define SERVO_PIN 5  // P1.5 (PWM1)
#define LED_PIN 7    // P1.1 (D0)

// Sweep parameters
const int minAngle = 0;
const int maxAngle = 180;
const int step = 5;
const int pauseStep = 50;      // ms at each step

void setup() {
  // Initialize servo library
  Johnny552Servo_init();
  
  // Set up LED for visual feedback
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);  // Turn on LED to indicate startup
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
  
  // Attach servo to pin
  Johnny552Servo_attach(SERVO_PIN);
  
  // Move to center position (90 degrees)
  Johnny552Servo_write(SERVO_PIN, 90);
  delay(1000);
}

void loop() {
  // Visual indicator for sweep start
  digitalWrite(LED_PIN, HIGH);
  
  // Sweep from 0 to 180 degrees
  for (int angle = minAngle; angle <= maxAngle; angle += step) {
    Johnny552Servo_write(SERVO_PIN, angle);
    delay(pauseStep);
  }
  
  // Visual indicator for direction change
  digitalWrite(LED_PIN, LOW);
  delay(100);
  digitalWrite(LED_PIN, HIGH);
  
  // Sweep from 180 back to 0 degrees
  for (int angle = maxAngle; angle >= minAngle; angle -= step) {
    Johnny552Servo_write(SERVO_PIN, angle);
    delay(pauseStep);
  }
  
  // Pause at center before next cycle
  Johnny552Servo_write(SERVO_PIN, 90);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}
