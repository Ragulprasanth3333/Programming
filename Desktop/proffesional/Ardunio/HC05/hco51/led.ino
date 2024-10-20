#include <Arduino.h>

int led = 13 ,data;
void setup()
{
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  while (Serial.available()>0)
  {
    data = Serial.read();
    Serial.println(data);
    if(data == 'A')
    {
      digitalWrite(led,HIGH);
    }
    if(data == 'B')
    {
      digitalWrite(led,LOW);
    }
  }
  
}