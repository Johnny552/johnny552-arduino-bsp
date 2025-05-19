/*
  Johnny552 Servo Test
  
  This is a simple test for the Johnny552Servo library
  which uses C-style functions for servo control.
  
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
  
  // Move to center position
  Johnny552Servo_write(SERVO_PIN, 90);
  digitalWrite(LED_PIN, HIGH);
  delay(2000);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  // Test three positions: 0°, 90°, and 180°
  
  // Position 1: 0°
  digitalWrite(LED_PIN, HIGH);
  Johnny552Servo_write(SERVO_PIN, 0);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
  
  // Position 2: 90°
  digitalWrite(LED_PIN, HIGH);
  Johnny552Servo_write(SERVO_PIN, 90);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
  
  // Position 3: 180°
  digitalWrite(LED_PIN, HIGH);
  Johnny552Servo_write(SERVO_PIN, 180);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}
