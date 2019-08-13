#include<SoftwareSerial.h>
#define led1 2
#define led2 3
#define led3 4


int data;
int blink_=LOW;
unsigned long previousMillis = 0;
const long interval = 1000;
void setup()
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}
void loop()
{
  unsigned long currentMillis = millis();
  if (Serial.available() > 0)
  {
    data = Serial.read();
    //data = Serial.read();
    Serial.print("Hello from Yash...");
    Serial.print("\n");
    Serial.print(data);
      if (data==48)
      {
        digitalWrite(led1, HIGH);
      }
      else if (data == 49)
      {
        digitalWrite(led1, LOW);
      }
      else if (data == 0)
      {
        if (currentMillis - previousMillis >= interval)
        {
           previousMillis = currentMillis;
           if (blink_ == LOW)
           {
              blink_ = HIGH;
           }
           else
           {
              blink_ = LOW;
           }
      digitalWrite(led1, blink_);
     }
      }
      
     if (data==50)
    {
      digitalWrite(led2, HIGH);
    }
    else if (data == 51)
    {
      digitalWrite(led2, LOW);
    }
    else if (data == 0)
    {
      if (currentMillis - previousMillis >= interval)
      {
         previousMillis = currentMillis;
         if (blink_ == LOW)
         {
            blink_ = HIGH;
         }
         else
         {
            blink_ = LOW;
         }
      
    digitalWrite(led2, blink_);
      }
    }
     if (data==52)
    {
      digitalWrite(led3, HIGH);
    }
    else if (data == 53)
    {
      digitalWrite(led3, LOW);
    }
    else if (data == 0)
    {
      if (currentMillis - previousMillis >= interval)
      {
         previousMillis = currentMillis;
         if (blink_ == LOW)
         {
            blink_ = HIGH;
         }
         else
         {
            blink_ = LOW;
         }
      
    digitalWrite(led3, blink_);
      }
    }
    if (data==54)
      {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
      }
      else if (data == 55)
      {
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
      }
      else if (data == 0)
      {
        if (currentMillis - previousMillis >= interval)
        {
           previousMillis = currentMillis;
           if (blink_ == LOW)
           {
              blink_ = HIGH;
           }
           else
           {
              blink_ = LOW;
           }
      digitalWrite(led1, blink_);
       digitalWrite(led2, blink_);
        digitalWrite(led3, blink_);
     }
      }
      
  
}
}
