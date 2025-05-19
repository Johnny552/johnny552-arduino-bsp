/*
  Johnny552 Servo Control - Direct PWM Implementation
  This sketch controls a standard hobby servo using direct PWM generation.
  - Servo signal: pin 5 (PWM1)
  - Servo power: 5V (external power recommended)
  - Servo ground: GND
  - LED indicator: pin 7 (P1.1)
  
  This implementation bypasses the Servo library and directly generates
  the required PWM signals for servo control.
*/

// Pin assignments
#define servoPin 5    // PWM1 on Johnny552 (P1.5)
#define ledPin 7      // P1.1 (D0)

// Servo parameters
#define MIN_PULSE_WIDTH 500    // Minimum pulse width in microseconds (0°)
#define MAX_PULSE_WIDTH 2500    // Maximum pulse width in microseconds (180°)
#define DEFAULT_PULSE_WIDTH 1500 // Default pulse width (90°)
#define REFRESH_INTERVAL 20000  // PWM period in microseconds (50Hz)

// Helper function to write a specific angle to the servo
void servoWriteAngle(int pin, int angle) {
  // Constrain angle to 0-180 range
  if (angle < 0) angle = 0;
  if (angle > 180) angle = 180;
  
  // Convert angle to pulse width (mapping 0-180 to MIN_PULSE_WIDTH-MAX_PULSE_WIDTH)
  long pulseWidth = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  
  // Generate 10 pulses (about 200ms) at the specified width
  for (int i = 0; i < 10; i++) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(pulseWidth);
    digitalWrite(pin, LOW);
    delayMicroseconds(REFRESH_INTERVAL - pulseWidth);
  }
}

// Sweep parameters
const int minAngle = 0;
const int maxAngle = 180;
const int step = 5;
const int pauseStep = 50;      // ms at each step

void setup() {
  // Set up LED for visual feedback
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);  // Turn on LED to indicate startup
  
  // Configure servo pin as output
  pinMode(servoPin, OUTPUT);
  
  // Move to center position (90°)
  servoWriteAngle(servoPin, 90);
  
  // Indicate setup complete
  digitalWrite(ledPin, LOW);
  delay(1000);
}

void loop() {
  // Visual indicator for sweep start
  digitalWrite(ledPin, HIGH);
  
  // Sweep from 0° to 180°
  for (int angle = minAngle; angle <= maxAngle; angle += step) {
    servoWriteAngle(servoPin, angle);
    delay(pauseStep);
  }
  
  // Visual indicator for direction change
  digitalWrite(ledPin, LOW);
  delay(100);
  digitalWrite(ledPin, HIGH);
  
  // Sweep from 180° back to 0°
  for (int angle = maxAngle; angle >= minAngle; angle -= step) {
    servoWriteAngle(servoPin, angle);
    delay(pauseStep);
  }
  
  // Pause at center before next cycle
  servoWriteAngle(servoPin, 90);
  digitalWrite(ledPin, LOW);
  delay(1000);
}
