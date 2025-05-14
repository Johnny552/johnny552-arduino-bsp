// Blink LED example for Johnny552 board
// LED connected to pin 7 (P1.1)

const int ledPin = 7;  // Define LED pin (P1.1)

void setup() {
  // Configure P1.1 as push-pull output
  P1_MOD_OC &= ~(1 << 1);  // Clear bit 1 in P1_MOD_OC (non-open-collector)
  P1_DIR_PU |= (1 << 1);   // Set bit 1 in P1_DIR_PU (output mode)
  
  // Set initial state to LOW
  P1 &= ~(1 << 1);         // Clear bit 1 in P1 (LOW)
  delay(100);              // Short delay to ensure the pin is set
}

void loop() {
  P1 |= (1 << 1);         // Set bit 1 in P1 (HIGH)
  delay(1000);            // Wait for 1 second
  P1 &= ~(1 << 1);        // Clear bit 1 in P1 (LOW)
  delay(1000);            // Wait for 1 second
}
