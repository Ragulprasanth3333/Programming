#include <Arduino.h>

int buzzPin = 8;
String prompt = "Enter 1 to buzz, 0 to stop: ";
int inputNum;

void setup() {
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
  Serial.println(prompt);
}

void loop() {
  if (Serial.available() > 0) {
    inputNum = Serial.parseInt();
    
    if (inputNum == 1) {
      digitalWrite(buzzPin, HIGH);
      delay(2000);
      digitalWrite(buzzPin, LOW);
    } 
    else if (inputNum == 0) {
      digitalWrite(buzzPin, LOW);
    } 
    else {
      Serial.println("Invalid input. Try again.");
    }
    
    Serial.println(prompt);
  }
}
