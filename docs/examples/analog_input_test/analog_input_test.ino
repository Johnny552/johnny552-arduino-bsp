// Analog Input Test for Johnny552 board
// Tests reading from 3 potentiometers to control 3 LED blink rates

#include <Serial.h>

// Define analog input pins (potentiometers)
const int potPin1 = 7;  // P1.1 (AIN0)
const int potPin2 = 2;  // P1.4 (AIN1)
const int potPin3 = 5;  // P1.5 (AIN2)

// Define digital output pins (LEDs)
const int ledPin1 = 8;  // P3.1
const int ledPin2 = 9;  // P3.0
const int ledPin3 = 10; // P3.3

// Variables to store potentiometer readings
int potValue1 = 0;
int potValue2 = 0;
int potValue3 = 0;

// Variables to track LED states and timing
bool ledState1 = false;
bool ledState2 = false;
bool ledState3 = false;

unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;

// Minimum and maximum delay values (in milliseconds)
const int minDelay = 50;   // Fastest blink (50ms)
const int maxDelay = 1000; // Slowest blink (1 second)

void setup() {
  // No need to initialize USBSerial on Johnny552
  // Just use USBSerial_println directly
  USBSerial_println("Johnny552 Analog Input Test");
  
  // Set LED pins as outputs
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  
  // Set analog pins as inputs (explicitly disable pull-up resistors)
  pinMode(potPin1, INPUT);
  pinMode(potPin2, INPUT);
  pinMode(potPin3, INPUT);
}

void loop() {
  // Get current time
  unsigned long currentMillis = millis();
  
  // Read values from potentiometers
  potValue1 = analogRead(potPin1);
  potValue2 = analogRead(potPin2);
  potValue3 = analogRead(potPin3);
  
  // Map potentiometer values (0-255) to delay times (50-1000ms)
  int blinkDelay1 = map(potValue1, 0, 255, maxDelay, minDelay);
  int blinkDelay2 = map(potValue2, 0, 255, maxDelay, minDelay);
  int blinkDelay3 = map(potValue3, 0, 255, maxDelay, minDelay);
  
  // Print values to serial monitor (for debugging)
  // Only print occasionally to avoid flooding the serial monitor
  if (currentMillis % 500 == 0) {
    USBSerial_print("Pot1: ");
    USBSerial_print(potValue1);
    USBSerial_print(" Delay1: ");
    USBSerial_println(blinkDelay1);
  }
  
  // Control LED 1 blinking based on potentiometer 1
  if (currentMillis - previousMillis1 >= blinkDelay1) {
    previousMillis1 = currentMillis;
    ledState1 = !ledState1;  // Toggle LED state
    digitalWrite(ledPin1, ledState1);
  }
  
  // Control LED 2 blinking based on potentiometer 2
  if (currentMillis - previousMillis2 >= blinkDelay2) {
    previousMillis2 = currentMillis;
    ledState2 = !ledState2;  // Toggle LED state
    digitalWrite(ledPin2, ledState2);
  }
  
  // Control LED 3 blinking based on potentiometer 3
  if (currentMillis - previousMillis3 >= blinkDelay3) {
    previousMillis3 = currentMillis;
    ledState3 = !ledState3;  // Toggle LED state
    digitalWrite(ledPin3, ledState3);
  }
  
  // Small delay to stabilize ADC readings
  delay(10);
}