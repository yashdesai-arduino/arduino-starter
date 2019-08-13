#include<SoftwareSerial.h>

#define led1 2
#define led2 3
#define led3 4
#define led4 5

int data;
String cmd;
int on1 = 1, on2 = 1, on3 = 1, on4 = 1, onAll = 1;
void setup()
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}
void loop()
{
  if (Serial.available() > 0)
  {
    data = Serial.read();
    if(cmd=="LED on"){data=48;}
    if(cmd=="LED off"){data=49;}
    Serial.print(" OK, from Yash...");  Serial.print("\n");  Serial.print(data);  Serial.print("\n");

    switch(data){
      case 48:  if(on1==0) {digitalWrite(led1, HIGH); Serial.print("LED 1 is ON\n"); on1 = 1;} else if(on1==1) {digitalWrite(led1, LOW); Serial.print("LED 1 is OFF\n"); on1=0;} break;
   
      case 49:  if(on2==0) {analogWrite(led2, 255); on2 = 1;Serial.print("LED 2 is ON\n");} else {analogWrite(led2, 0); on2=0;Serial.print("LED 2 is OFF\n");} break;
   
      case 50:  if(on3==0) {digitalWrite(led3, LOW); on3 = 1;Serial.print(" CFL is ON\n");} else {digitalWrite(led3, HIGH); on3=0;Serial.print("CFL is OFF\n");} break;
     
      case 51:  if(on4==0) {digitalWrite(led4, LOW); on4 = 1;Serial.print("FAN is ON\n");} else {digitalWrite(led4, HIGH); on4=0;Serial.print("FAN is OFF\n");} break;
     
      case 52:  if(onAll==0) {
                   digitalWrite(led1, HIGH); onAll = 1; on1 = 1;
                   analogWrite(led2, 255); onAll = 1; on2 = 1;
                   digitalWrite(led3, LOW); onAll = 1; on3 = 1;
                   digitalWrite(led4, LOW); onAll = 1; on4 = 1;
                } 
                else {
                   digitalWrite(led1, LOW); onAll = 0; on1 = 0;
                   analogWrite(led2, 0); onAll = 0; on2 = 0;
                   digitalWrite(led3, HIGH); onAll = 0; on3 = 0;
                   digitalWrite(led4, HIGH); onAll = 0; on4 = 0;
                } break;
    }
  }
}
