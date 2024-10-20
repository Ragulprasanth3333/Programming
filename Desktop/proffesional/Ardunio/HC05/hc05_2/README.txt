# Arduino Bluetooth Control for Motor and LED using HC-05 and L293D Motor Driver

This project demonstrates how to control a 12V fan (motor) and an LED using an Arduino Uno through Bluetooth communication with the HC-05 Bluetooth module. A mobile device or Bluetooth terminal can be used to send commands that control the motor speed and LED state.

## Components
- **Arduino Uno**
- **HC-05 Bluetooth Module**
- **L293D Motor Driver**
- **12V Fan (Motor)**
- **1 Red LED**
- **1 Resistor (220Ω)**
- **12V Battery**
- **Jumper Wires**
- **Breadboard**

## Circuit Diagram
- **HC-05 Bluetooth Module**:
  - VCC → Arduino 5V
  - GND → Arduino GND
  - TX → Arduino RX (Pin 0)
  - RX → Arduino TX (Pin 1)
- **L293D Motor Driver**:
  - EN1 → Arduino Pin 6 (PWM control)
  - IN1 → Arduino Pin 2 (Direction control)
  - IN2 → Arduino Pin 3 (Direction control)
  - VCC → 12V Battery (to power the motor)
  - GND → Arduino GND and 12V Battery GND
  - OUT1 and OUT2 → Fan motor terminals
- **LED**:
  - Positive leg (long leg) → Arduino Pin 13
  - Negative leg (short leg) → Resistor → Arduino GND

## Features
- **Bluetooth control** for a fan motor's speed and an LED state.
- Commands are sent from a mobile app or Bluetooth terminal to control:
  - LED (on/off)
  - Motor (start/stop, change speed)

## How It Works

1. **Setup Phase**:
   - The Arduino sets Pin 13 as an output to control the LED.
   - Pins 2, 3, and 6 are used to control the L293D motor driver.
   - Serial communication is initialized at a baud rate of `9600` to communicate with the HC-05 Bluetooth module.

2. **Loop Phase**:
   - The Arduino constantly checks for incoming Bluetooth data.
   - Commands:
     - **'A'**: Turns the LED ON.
     - **'B'**: Turns the LED OFF.
     - **'C'**: Stops the motor (Fan OFF).
     - **'D'**: Starts the motor at low speed (PWM value = 100).
     - **'E'**: Runs the motor at full speed (PWM value = 255).

## Code

```cpp
#include <Arduino.h>

int led = 13, data, en1 = 6;
int in1 = 2;
int in2 = 3;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(en1, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while (Serial.available() > 0) {
    data = Serial.read();
    Serial.println(data);
    
    if (data == 'A') {
      digitalWrite(led, HIGH); // Turn LED on
    }
    
    if (data == 'B') {
      digitalWrite(led, LOW);  // Turn LED off
    }
    
    if (data == 'C') {
      digitalWrite(in1, LOW);  // Stop motor
      digitalWrite(in2, LOW);
      analogWrite(en1, 0);     // Set motor speed to 0
    }
    
    if (data == 'D') {
      digitalWrite(in1, HIGH); // Set motor direction
      digitalWrite(in2, HIGH);
      analogWrite(en1, 100);   // Set motor to low speed
    }
    
    if (data == 'E') {
      digitalWrite(in1, HIGH); // Set motor direction
      digitalWrite(in2, HIGH);
      analogWrite(en1, 255);   // Set motor to full speed
    }
  }
}
