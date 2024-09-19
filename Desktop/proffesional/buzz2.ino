#include <Arduino.h>

int buzzPin = 8;
int dt1 = 1,dt2 =2,dt3=3,i;
String prompt = "Enter a number (1-5) to buzz, 0 to stop: ";
int inputNum;

void setup() {
   pinMode(buzzPin, OUTPUT);
}

void loop() {
  for(i=1;i<100;i+=1)
  {
    digitalWrite(buzzPin,HIGH);
    delay(dt1);
    digitalWrite(buzzPin,LOW);
    delay(dt1);
  }
  for(i=1;i<100;i+=1)
  {
    digitalWrite(buzzPin,HIGH);
    delay(dt2);
    digitalWrite(buzzPin,LOW);
    delay(dt2);
  }
  for(i=1;i<100;i+=1)
  {
    digitalWrite(buzzPin,HIGH);
    delay(dt3);
    digitalWrite(buzzPin,LOW);
    delay(dt3);
  }
    for(i=1;i<100;i+=1)
  {
    digitalWrite(buzzPin,HIGH);
    delay(dt2);
    digitalWrite(buzzPin,LOW);
    delay(dt2);
  }
  for(i=1;i<100;i+=1)
  {
    digitalWrite(buzzPin,HIGH);
    delay(dt1);
    digitalWrite(buzzPin,LOW);
    delay(dt1);
  }
  
}
