#include <Arduino.h>

const int segmentA = 2;
const int segmentB = 3;
const int segmentC = 4;
const int segmentDP = 5;
const int segmentE = 6;
const int segmentF = 7;
const int segmentG = 8;
const int segmentD = 9;

const int led1 = 10;
const int led2 = 11;
const int wait = 1000;
int a = 1;

void setup() {
  // Set all segment pins as output
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentDP, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
  pinMode(segmentD, OUTPUT);

  // Set LED pins as output
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  // Start serial communication
  Serial.begin(9600);
  Serial.println("Enter a number: ");
}

void loop() {
  if (Serial.available() > 0) {
    int number = Serial.parseInt();
    Serial.print("You entered: ");
    Serial.println(number);
    
    // Display the digit
    displayDigit(number % 10);

    // Blink the appropriate LED
    if (number % 2 == 0) {
      blinkLED(led2);
    } else {
      blinkLED(led1);
    }

    // Prompt for another number
    Serial.println("Enter a number: ");
  }
}

void displayDigit(int digit) {
  // Turn off all segments
  digitalWrite(segmentA, HIGH);
  digitalWrite(segmentB, HIGH);
  digitalWrite(segmentC, HIGH);
  digitalWrite(segmentD, HIGH);
  digitalWrite(segmentE, HIGH);
  digitalWrite(segmentF, HIGH);
  digitalWrite(segmentG, HIGH);
  digitalWrite(segmentDP, HIGH);  // Turn off the decimal point

  // Turn on the segments for the given digit
  switch (digit) {
    case 0:
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentC, LOW);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      break;
    case 1:
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentC, LOW);
      break;
    case 2:
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentG, LOW);
      break;
    case 3:
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentC, LOW);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentG, LOW);
      break;
    case 4:
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentC, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, LOW);
      break;
    case 5:
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentC, LOW);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, LOW);
      break;
    case 6:
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentC, LOW);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, LOW);
      break;
    case 7:
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentC, LOW);
      break;
    case 8:
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentC, LOW);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, LOW);
      break;
    case 9:
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentC, LOW);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, LOW);
      break;
  }
}

void blinkLED(int ledPin) {
  digitalWrite(ledPin, HIGH);
  delay(wait);
  digitalWrite(ledPin, LOW);
  delay(wait);
}
