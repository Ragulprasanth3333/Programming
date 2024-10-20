#include <Arduino.h>

int led = 13 ,data,en1=6;
int in1 = 2;
int in2 = 3;
void setup()
{
  pinMode(led,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(en1,OUTPUT);
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
    if(data == 'C')
    {
      digitalWrite(in1,LOW);
      digitalWrite(in2,LOW);
      analogWrite(en1,0);
    }
    if(data == 'D')
    {
      digitalWrite(in1,HIGH);
      digitalWrite(in2,HIGH);
      analogWrite(en1,100);
    }
    if(data == 'E')
    {
      digitalWrite(in1,HIGH);
      digitalWrite(in2,HIGH);
      analogWrite(en1,255);
    }
  }
  
}