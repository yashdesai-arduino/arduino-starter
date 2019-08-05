#include<SoftwareSerial.h>

#define led1 2
#define led2 3
#define led3 4
#define led4 5

int data;
int on1 = 0, on2 = 0, on3 = 0, on4 = 0, onAll = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}
void loop()
{
  if (Serial.available() > 0)
  {
    data = Serial.read();
    Serial.print(" OK, from Yash...");  Serial.print("\n");  Serial.print(data);  Serial.print("\n");

    switch(data){
      case 48:  if(on1==0) {digitalWrite(led1, HIGH); on1 = 1;} else {digitalWrite(led1, LOW); on1=0;} break;
   
      case 49:  if(on2==0) {digitalWrite(led2, HIGH); on2 = 1;} else {digitalWrite(led2, LOW); on2=0;} break;
   
      case 50:  if(on3==0) {digitalWrite(led3, HIGH); on3 = 1;} else {digitalWrite(led3, LOW); on3=0;} break;
     
      case 51:  if(on4==0) {digitalWrite(led4, HIGH); on4 = 1;} else {digitalWrite(led4, LOW); on4=0;} break;
     
      case 52:  if(onAll==0) {
                   digitalWrite(led1, HIGH); onAll = 1; on1 = 1;
                   digitalWrite(led2, HIGH); onAll = 1; on2 = 1;
                   digitalWrite(led3, HIGH); onAll = 1; on3 = 1;
                   digitalWrite(led4, HIGH); onAll = 1; on4 = 1;
                } 
                else {
                   digitalWrite(led1, LOW); onAll = 0; on1 = 0;
                   digitalWrite(led2, LOW); onAll = 0; on2 = 0;
                   digitalWrite(led3, LOW); onAll = 0; on3 = 0;
                   digitalWrite(led4, LOW); onAll = 0; on4 = 0;
                } break;
    }
  }
}
