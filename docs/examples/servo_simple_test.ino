/*
  Johnny552 Simple Servo Test
  This sketch provides a simple test for servo control using both
  the Servo library and direct PWM control.
  
  - LED on pin 7 (P1.1) provides visual feedback
  - Servo signal on pin 5 (P1.5) - PWM1
*/

#include <Servo.h>

// Pin definitions
#define SERVO_PIN 5  // P1.5 (PWM1)
#define LED_PIN 7    // P1.1 (D0)

// Test mode: 0 = Servo library, 1 = Direct PWM
#define TEST_MODE 1  // Changed to direct PWM mode since Servo library isn't working

// Servo parameters for direct PWM (only used in direct PWM mode)
#define SERVO_MIN_PULSE 500     // Minimum pulse width in microseconds (0°)
#define SERVO_MAX_PULSE 2500    // Maximum pulse width in microseconds (180°)
#define SERVO_REFRESH 20000     // PWM period in microseconds (50Hz)

// Function to generate servo pulse using direct PWM
void servoPulse(int pin, int angle) {
  // Convert angle to pulse width
  long pulseWidth = map(angle, 0, 180, SERVO_MIN_PULSE, SERVO_MAX_PULSE);
  
  // Generate pulse
  digitalWrite(pin, HIGH);
  delayMicroseconds(pulseWidth);
  digitalWrite(pin, LOW);
  delayMicroseconds(SERVO_REFRESH - pulseWidth);
}

void setup() {
  // Set up LED for visual feedback
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);  // Turn on LED to indicate startup
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
  
  // Configure servo pin
  pinMode(SERVO_PIN, OUTPUT);
  
  if (TEST_MODE == 0) {
    // Servo library mode
    Servo_init();
    if (Servo_attach(SERVO_PIN)) {
      // Success - two slow blinks
      digitalWrite(LED_PIN, HIGH);
      delay(300);
      digitalWrite(LED_PIN, LOW);
      delay(300);
      digitalWrite(LED_PIN, HIGH);
      delay(300);
      digitalWrite(LED_PIN, LOW);
      delay(300);
    } else {
      // Error - rapid blinking
      for (int i = 0; i < 10; i++) {
        digitalWrite(LED_PIN, HIGH);
        delay(100);
        digitalWrite(LED_PIN, LOW);
        delay(100);
      }
    }
  }
}

void loop() {
  if (TEST_MODE == 0) {
    // Servo library mode
    
    // Move to 0 degrees
    digitalWrite(LED_PIN, HIGH);
    Servo_write(SERVO_PIN, 0);
    delay(2000);
    
    // Move to 90 degrees
    digitalWrite(LED_PIN, LOW);
    Servo_write(SERVO_PIN, 90);
    delay(2000);
    
    // Move to 180 degrees
    digitalWrite(LED_PIN, HIGH);
    Servo_write(SERVO_PIN, 180);
    delay(2000);
    
  } else {
    // Direct PWM mode
    
    // Move to 0 degrees
    digitalWrite(LED_PIN, HIGH);
    for (int i = 0; i < 100; i++) {  // Generate more pulses (2 seconds worth)
      servoPulse(SERVO_PIN, 0);
    }
    delay(500);  // Short pause between positions
    
    // Move to 90 degrees
    digitalWrite(LED_PIN, LOW);
    for (int i = 0; i < 100; i++) {  // Generate more pulses (2 seconds worth)
      servoPulse(SERVO_PIN, 90);
    }
    delay(500);  // Short pause between positions
    
    // Move to 180 degrees
    digitalWrite(LED_PIN, HIGH);
    for (int i = 0; i < 100; i++) {  // Generate more pulses (2 seconds worth)
      servoPulse(SERVO_PIN, 180);
    }
    delay(500);  // Short pause between positions
  }
}
