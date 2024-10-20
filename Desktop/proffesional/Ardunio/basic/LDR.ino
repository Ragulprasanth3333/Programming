#include <Arduino.h>
int lightval,wait=1000;
int lightpin = A0;
int led1 = 7,led2=8;
void setup()
{
  pinMode(lightpin,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);

  Serial.begin(9600);
}
void loop()
{
  lightval = analogRead(lightpin);
  if(lightval > 750)
  {
    digitalWrite(led2,LOW);
    digitalWrite(led1,HIGH);
    
  }
  else if(lightval < 750 )
  {
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    
  }
  
}