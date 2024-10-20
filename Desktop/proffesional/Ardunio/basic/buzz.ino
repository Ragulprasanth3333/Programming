#include <Arduino.h>

int buzzPin = 8;
String prompt = "Enter a number (1-5) to buzz, 0 to stop: ";
int inputNum;

void setup() {
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
  Serial.println(prompt);
}

void loop() {
  if (Serial.available() > 0) {
    inputNum = Serial.parseInt();
    
    if (inputNum >= 1 && inputNum <= 5) {
      for (int i = 0; i < inputNum; i++) {
        digitalWrite(buzzPin, HIGH);
        delay(500);
        digitalWrite(buzzPin, LOW);
        delay(500);
      }
    } 
    else if (inputNum == 0) {
      digitalWrite(buzzPin, LOW);
    } 
    else {
      Serial.println("Invalid input. Enter a number between 1 and 5.");
    }
    
    Serial.println(prompt);
  }
}
