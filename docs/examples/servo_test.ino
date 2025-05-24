#include <Servo.h>

/*
  Johnny552 Servo Test using CH55x Servo Library
  This sketch tests servo control using the CH55x Servo library.
  It cycles through multiple pins to find which ones work with the servo.
  
  Pins to test (in sequence):
  - Pin 5 (P1.5) - PWM1
  - Pin 11 (P3.4) - PWM2
  
  LED on pin 7 (P1.1) provides visual feedback about which pin is being tested.
*/

// Pin definitions
#define LED_PIN 7  // P1.1 (D0) - LED for visual feedback

// Servo pins to test
const int servoPin1 = 5;  // P1.5 - PWM1
const int servoPin2 = 11; // P3.4 - PWM2
int activeServo = 1;      // Which servo is currently being tested (1 or 2)
int minPulseWidth = 544;  // SG90 optimal minimum pulse width
int maxPulseWidth = 2400; // SG90 optimal maximum pulse width

// Function prototypes (declarations)
void setupServos();
void switchActiveServo();

// Function to set up both servos
void setupServos() {
  // Configure pins as output
  pinMode(servoPin1, OUTPUT);
  pinMode(servoPin2, OUTPUT);
  
  // Try to attach both servos with custom pulse width range
  bool servo1Success = Servo_attachMinMax(servoPin1, minPulseWidth, maxPulseWidth);
  bool servo2Success = Servo_attachMinMax(servoPin2, minPulseWidth, maxPulseWidth);
  
  // Indicate success/failure with LED patterns
  if (servo1Success) {
    // Servo 1 success - one blink
    digitalWrite(LED_PIN, HIGH);
    delay(300);
    digitalWrite(LED_PIN, LOW);
    delay(300);
  } else {
    // Servo 1 error - two rapid blinks
    for (int i = 0; i < 2; i++) {
      digitalWrite(LED_PIN, HIGH);
      delay(100);
      digitalWrite(LED_PIN, LOW);
      delay(100);
    }
  }
  
  if (servo2Success) {
    // Servo 2 success - one blink
    digitalWrite(LED_PIN, HIGH);
    delay(300);
    digitalWrite(LED_PIN, LOW);
    delay(300);
  } else {
    // Servo 2 error - two rapid blinks
    for (int i = 0; i < 2; i++) {
      digitalWrite(LED_PIN, HIGH);
      delay(100);
      digitalWrite(LED_PIN, LOW);
      delay(100);
    }
  }
  
  // Pause before starting tests
  delay(1000);
}

// Function to switch which servo is being tested
void switchActiveServo() {
  // Toggle between servo 1 and 2
  activeServo = (activeServo == 1) ? 2 : 1;
  
  // Visual feedback for which servo is active
  for (int i = 0; i < activeServo; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(200);
    digitalWrite(LED_PIN, LOW);
    delay(200);
  }
}

void setup() {
  // Initialize the servo library
  Servo_init();
  
  // Set up LED for visual feedback
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);  // Turn on LED to indicate startup
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
  
  // Configure and attach both servo pins
  setupServos();
}



void loop() {
  // Indicate which servo we're testing with LED pattern
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
  
  // Get the current active pin
  int currentPin = (activeServo == 1) ? servoPin1 : servoPin2;
  
  // Test angle control
  
  // Move to 0 degrees
  digitalWrite(LED_PIN, HIGH);
  Servo_write(currentPin, 0);
  delay(2000);
  
  // Move to 90 degrees
  digitalWrite(LED_PIN, LOW);
  Servo_write(currentPin, 90);
  delay(2000);
  
  // Move to 180 degrees
  digitalWrite(LED_PIN, HIGH);
  Servo_write(currentPin, 180);
  delay(2000);
  
  // Center position
  digitalWrite(LED_PIN, LOW);
  Servo_write(currentPin, 90);
  delay(2000);
  
  // Switch to the other servo
  switchActiveServo();
}
