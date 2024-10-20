#include <Arduino.h>

int valpin = A0;          // Analog input pin for the sensor or button
int value;                // Variable to store the analog value
int led = 8;              // Digital output pin for LED
int buzz = 7;             // Digital output pin for Buzzer
bool isOn = false;        // Variable to track if LED and Buzzer are on or off
bool lastState = LOW;     // Variable to store the last button state

void setup() {
  pinMode(valpin, INPUT);  // Set valpin as input for the button
  pinMode(led, OUTPUT);    // Set LED pin as output
  pinMode(buzz, OUTPUT);   // Set Buzzer pin as output
  Serial.begin(9600);      // Initialize serial communication
}

void loop() {
  value = analogRead(valpin);  // Read the analog value from the pin

  // Check if the button is pressed (analog value threshold)
  bool buttonPressed = (value > 1000);

  // Toggle the LED and Buzzer state only on button press
  if (buttonPressed && !lastState) {
    isOn = !isOn;                // Toggle the state
    if (isOn) {
      digitalWrite(led, HIGH);   // Turn on LED
      digitalWrite(buzz, HIGH);  // Turn on Buzzer
    } else {
      digitalWrite(led, LOW);    // Turn off LED
      digitalWrite(buzz, LOW);   // Turn off Buzzer
    }
    delay(200);  // Debounce delay
  }

  lastState = buttonPressed;  // Update the last button state
}
