// Blink LED example for Johnny552 board
// LED connected to D0 (Arduino pin 7, maps to P1.1)

const int ledPin = D0;  // Use D0 constant for clarity

void setup() {
  // Configure pin as output and ensure it starts LOW
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  delay(100);  // Short delay to ensure the pin is set
}

void loop() {
  digitalWrite(ledPin, HIGH);  // Turn LED on
  delay(1000);                 // Wait for 1 second
  digitalWrite(ledPin, LOW);   // Turn LED off
  delay(1000);                 // Wait for 1 second
}
