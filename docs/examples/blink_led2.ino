// Alternate two LEDs on Johnny552 board
// LED1 connected to pin 0, LED2 connected to pin 8

const int led1_pin = 7;  // P1.1
const int led2_pin = 5;  // P1.5

void setup() {
  // Set both pins as outputs and start LOW
  pinMode(led1_pin, OUTPUT);
  pinMode(led2_pin, OUTPUT);
  digitalWrite(led1_pin, LOW);
  digitalWrite(led2_pin, LOW);
  delay(100);  // Short delay to ensure pins are set
}

void loop() {
  // Turn LED1 ON, LED2 OFF
  digitalWrite(led1_pin, HIGH);
  digitalWrite(led2_pin, LOW);
  delay(1000);  // Wait 1 second

  // Turn LED1 OFF, LED2 ON
  digitalWrite(led1_pin, LOW);
  digitalWrite(led2_pin, HIGH);
  delay(1000);  // Wait 1 second
}

