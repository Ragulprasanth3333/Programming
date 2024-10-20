# Arduino Bluetooth LED Control with HC-05 and Arduino Uno

This project demonstrates how to control a red LED using an Arduino Uno through Bluetooth communication with the HC-05 Bluetooth module. The LED can be controlled by sending commands from a Bluetooth-enabled device, such as a smartphone.

## Components
- **Arduino Uno**
- **HC-05 Bluetooth Module**
- **1 Red LED**
- **1 Resistor (220Ω recommended)**
- **Jumper Wires**
- **Breadboard**

## Circuit Diagram
- **HC-05 Connections**:
  - VCC → Arduino 5V
  - GND → Arduino GND
  - TX → Arduino RX (Pin 0)
  - RX → Arduino TX (Pin 1)
- **LED Connections**:
  - Positive leg (long leg) → Arduino Pin 13
  - Negative leg (short leg) → Resistor → Arduino GND

## Features
- Control the LED via Bluetooth communication by sending simple commands.
- Turn the LED on/off from a mobile app or Bluetooth terminal.

## How It Works

1. **Setup Phase**:
   - The Arduino sets Pin 13 as output to control the LED.
   - Serial communication is initialized at a baud rate of `9600` to communicate with the HC-05 Bluetooth module.

2. **Loop Phase**:
   - The Arduino constantly checks for incoming data via Bluetooth.
   - When a command is received (e.g., `'1'` to turn the LED on and `'0'` to turn it off), the LED responds accordingly.

## Code

```cpp
#include <Arduino.h>

int led = 13;
char data;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600); // Initialize Bluetooth serial communication
}

void loop() {
  if (Serial.available() > 0) {
    data = Serial.read(); // Read the incoming data
    if (data == '1') {
      digitalWrite(led, HIGH); // Turn the LED on
    } else if (data == '0') {
      digitalWrite(led, LOW);  // Turn the LED off
    }
    Serial.println(data); // Echo the received data for debugging
  }
}
