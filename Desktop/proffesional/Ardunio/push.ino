//push button to control led and buzz by sensing analog signal with 1k resistance
#include<Arduino.h>
int valpin = A0,value,led=8,buzz=7;
void setup()
{
  pinMode(valpin,INPUT);
  pinMode(led,OUTPUT);
  pinMode(buzz,OUTPUT);
  Serial.begin(9600);

}
void loop()
{
  value = analogRead(valpin);
  Serial.println(value);
  delay(200);
  if (value >1000)
  {
    digitalWrite(led,HIGH);
    digitalWrite(buzz,HIGH);
  }
  else{
    digitalWrite(led,LOW);
    digitalWrite(buzz,LOW);
  }

}