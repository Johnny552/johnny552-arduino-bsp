// LED test program for Johnny552 board
// Tests 5 green LEDs (pins 7-11) and 4 red LEDs (pins 2-5)

// Define pins for green LEDs (going "up")
const int greenLED_pins[] = {7, 8, 9, 10, 11};  // 5 green LEDs
const int greenLED_count = 5;

// Define pins for red LEDs (going "down")
const int redLED_pins[] = {2, 3, 4, 5};  // 4 red LEDs
const int redLED_count = 4;

void setup() {
  // Set all LED pins as outputs and start LOW
  
  // Initialize green LEDs
  for (int i = 0; i < greenLED_count; i++) {
    pinMode(greenLED_pins[i], OUTPUT);
    digitalWrite(greenLED_pins[i], LOW);
  }
  
  // Initialize red LEDs
  for (int i = 0; i < redLED_count; i++) {
    pinMode(redLED_pins[i], OUTPUT);
    digitalWrite(redLED_pins[i], LOW);
  }
  
  delay(100);  // Short delay to ensure pins are set
}

void loop() {
  // Green LEDs go "up" (pins 7 to 11)
  for (int i = 0; i < greenLED_count; i++) {
    // Turn on current green LED
    digitalWrite(greenLED_pins[i], HIGH);
    delay(200);  // Wait 0.2 seconds between each LED
    digitalWrite(greenLED_pins[i], LOW);  // Turn off current LED before moving to next
  }
  
  delay(1000);  // Wait 1 second after all green LEDs
  
  // Red LEDs go "down" (pins 5 to 2)
  for (int i = redLED_count - 1; i >= 0; i--) {
    // Turn on current red LED
    digitalWrite(redLED_pins[i], HIGH);
    delay(200);  // Wait 0.2 seconds between each LED
    digitalWrite(redLED_pins[i], LOW);  // Turn off current LED before moving to next
  }
  
  delay(200);  // Small delay before starting the sequence again
}

