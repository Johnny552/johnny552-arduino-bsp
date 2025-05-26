# Johnny552 Analog Input Test Example

This example demonstrates how to use the analog input pins on the Johnny552 board to read values from potentiometers and control the blinking speed of LEDs. This test verifies the functionality of the analog-to-digital converter (ADC) and shows how to implement basic input-controlled outputs.

![Analog Input Test in Action](analog_input_test.gif)

## Hardware Requirements

- 1× Johnny552 development board
- 3× Potentiometers (10kΩ recommended)
- 3× LEDs (different colors recommended for visual distinction)
- 3× 220Ω resistors (for the LEDs)
- Breadboard
- Jumper wires

## Circuit Diagram

The circuit consists of:

- **Potentiometer 1** connected to analog pin 7 (P1.1 - AIN0)
  - Center pin to pin 7
  - Outside pins to 5V and GND
- **Potentiometer 2** connected to analog pin 2 (P1.4 - AIN1)
  - Center pin to pin 2
  - Outside pins to 5V and GND
- **Potentiometer 3** connected to analog pin 5 (P1.5 - AIN2)
  - Center pin to pin 5
  - Outside pins to 5V and GND
- **LED 1** connected to digital pin 8 (P3.1)
  - Anode (longer leg) through a 220Ω resistor to pin 8
  - Cathode (shorter leg) to GND
- **LED 2** connected to digital pin 9 (P3.0)
  - Anode through a 220Ω resistor to pin 9
  - Cathode to GND
- **LED 3** connected to digital pin 10 (P3.3)
  - Anode through a 220Ω resistor to pin 10
  - Cathode to GND

![Analog Input Test Circuit Diagram](analog_input_test_bb.png)

> **Note:** The Johnny552 has an 8-bit ADC, so analog readings will range from 0 to 255, not 0 to 1023 as on standard Arduino boards.

## How It Works

The example program reads values from three potentiometers connected to the analog inputs and uses these values to control the blinking speed of three corresponding LEDs:

1. **Potentiometer 1** controls the blink rate of **LED 1**
2. **Potentiometer 2** controls the blink rate of **LED 2**
3. **Potentiometer 3** controls the blink rate of **LED 3**

As you turn each potentiometer, the corresponding LED's blink rate changes - turning clockwise makes the LED blink faster, while turning counter-clockwise makes it blink slower.

## Code Explanation

```cpp
// Analog Input Test for Johnny552 board
// Tests reading from 3 potentiometers to control 3 LED blink rates

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
  // Initialize serial communication for debugging
  USBSerial_begin(9600);
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
  USBSerial_print("Pot1: ");
  USBSerial_print(potValue1);
  USBSerial_print(" Delay1: ");
  USBSerial_println(blinkDelay1);
  
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
```

## Key Concepts

1. **Analog Input Reading**: The `analogRead()` function reads values from the potentiometers connected to analog pins.

2. **Non-blocking Timing**: The example uses the `millis()` function for non-blocking timing control, allowing multiple LEDs to blink at different rates simultaneously.

3. **Value Mapping**: The `map()` function converts the analog reading range (0-255) to a useful delay time range (50-1000ms).

4. **Pull-up Resistor Disabling**: Setting analog pins to `INPUT` mode explicitly disables the internal pull-up resistors to get the full input range.

5. **Serial Debugging**: The code includes serial output to help debug and visualize the analog readings and calculated delay times.

## How the ADC Works on Johnny552

The Johnny552 board features an 8-bit analog-to-digital converter (ADC) with the following characteristics:

- **Resolution**: 8 bits (values from 0 to 255)
- **Reference Voltage**: Fixed to VCC (typically 5V when USB-powered)
- **Available Analog Pins**:
  - AIN0 (P1.1) - pin 7
  - AIN1 (P1.4) - pin 2
  - AIN2 (P1.5) - pin 5

When you call `analogRead()`, the ADC converts the analog voltage on the pin (between 0V and VCC) to a digital value between 0 and 255.

## Troubleshooting

If the example doesn't work as expected:

1. **Check Connections**: Verify all wiring connections, especially the potentiometer center pins to the correct analog pins.

2. **Potentiometer Orientation**: Make sure the outside pins of the potentiometers are connected to 5V and GND (order matters).

3. **LED Polarity**: Verify that the LEDs are connected with the correct polarity (anode/longer leg to the resistor, cathode/shorter leg to GND).

4. **Serial Monitor**: Open the serial monitor to see the analog readings and calculated delay times for debugging.

5. **Pull-up Resistors**: If you're getting inconsistent readings, ensure the pull-up resistors are properly disabled by setting the pin mode to `INPUT`.

## Extending the Example

Here are some ways to modify this example:

1. **PWM Control**: Instead of controlling blink rate, use the potentiometer values to control LED brightness using `analogWrite()`.

2. **Threshold Triggers**: Add code to trigger events when potentiometer values cross certain thresholds.

3. **Averaging Readings**: Implement a simple moving average to smooth out noisy potentiometer readings.

4. **Combined Control**: Use multiple potentiometers together to control more complex behaviors.

5. **Additional Sensors**: Replace potentiometers with other analog sensors like photoresistors, thermistors, or force-sensitive resistors.

## Related Examples

- [PWM LED Example](../pwm_led/pwm_led_example.md) - Control LED brightness using PWM
- [Button Input Example](../button_input/button_input_example.md) - Reading digital inputs

## Notes on Analog Input Accuracy

For more accurate analog readings:

1. Use a stable power supply for your potentiometers
2. Add a small capacitor (0.1μF) between the analog pin and ground to reduce noise
3. Take multiple readings and average them for more stable values
4. Allow a small delay between consecutive analog readings
5. Keep analog signal wires short and away from digital signal wires to minimize interference