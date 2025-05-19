#include <Servo.h>

/*
  Johnny552 Servo Test using CH55x Servo Library
  This sketch tests servo control using the CH55x Servo library.
  It cycles through multiple pins to find which ones work with the servo.
  
  Pins to test (in sequence):
  - Pin 2 (P1.4)
  - Pin 3 (P1.6)
  - Pin 4 (P1.7)
  - Pin 5 (P1.5) - PWM1
  - Pin 11 (P3.4) - PWM2
  
  LED on pin 7 (P1.1) provides visual feedback about which pin is being tested.
*/

// Pin definitions
#define LED_PIN 7  // P1.1 (D0) - LED for visual feedback

// Array of pins to test (avoid pins ending with 8 or 9 as they're rejected by the library)
const int servoPinsToTest[] = {2, 3, 4, 5, 11, 12, 13};
const int numPins = 7;
int currentPinIndex = 0;
int currentPin = 0;

// Function prototypes (declarations)
void setupServoPin(int pin);
void moveToNextPin();

// Function to set up a servo pin
void setupServoPin(int pin) {
  // Configure pin as output
  pinMode(pin, OUTPUT);
  
  // Try to attach servo to the pin
  if (Servo_attach(pin)) {
    // Success - blink the number of times corresponding to the pin index + 1
    for (int i = 0; i < currentPinIndex + 1; i++) {
      digitalWrite(LED_PIN, HIGH);
      delay(200);
      digitalWrite(LED_PIN, LOW);
      delay(200);
    }
  } else {
    // Error - rapid blinking
    for (int i = 0; i < 5; i++) {
      digitalWrite(LED_PIN, HIGH);
      delay(100);
      digitalWrite(LED_PIN, LOW);
      delay(100);
    }
    
    // Move to next pin
    moveToNextPin();
    return;
  }
  
  // Pause before starting tests
  delay(1000);
}

// Function to move to the next pin
void moveToNextPin() {
  // Detach current servo if it was attached
  Servo_detach(currentPin);
  
  // Move to next pin
  currentPinIndex = (currentPinIndex + 1) % numPins;
  currentPin = servoPinsToTest[currentPinIndex];
  
  // Set up the new pin
  setupServoPin(currentPin);
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
  
  // Start with the first pin
  currentPinIndex = 0;
  currentPin = servoPinsToTest[currentPinIndex];
  
  // Configure and attach the first servo pin
  setupServoPin(currentPin);
}



void loop() {
  // Indicate which pin we're testing with LED pattern
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
  
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
  
  // Move to next pin after testing current one
  moveToNextPin();
}
