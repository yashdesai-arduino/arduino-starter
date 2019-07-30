#include <IRremote.h>

int RECV_PIN = 11; // the pin where you connect the output pin of sensor
int led1 = 2;
int led2 = 4;
int led3 = 7;
int itsONled[] = {0,0,0,0};
/* the initial state of LEDs is OFF (zero)
the first zero must remain zero but you can
change the others to 1's if you want a certain
led to light when the board is powered */
#define code1 3249196338 // code received from button no. 1
#define code2 3249147378 // code received from button no. 2
#define code3 3249180018 // code received from button no. 3

#define pat1 3249208323
#define pat2 2811816732
#define pat3 0

int patOn = 0;
int p = 0;
IRrecv irrecv(RECV_PIN);

decode_results results;


void setup()
{
  Serial.begin(9600); // you can ommit this line
  irrecv.enableIRIn(); // Start the receiver
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop()
{
  if (irrecv.decode(&results)) {
    p++;
  unsigned int value = results.value;
  if(p==1)
  {
    if(p==1)
  {
 digitalWrite(led1,1); 
 digitalWrite(led2,0); 
 digitalWrite(led3,0);   //1
  delay(de);  
  
 digitalWrite(led1,0); 
 digitalWrite(led2,1); 
 digitalWrite(led3,0);   //2
  delay(de); 
  
 digitalWrite(led1,0); 
 digitalWrite(led2,0); 
 digitalWrite(led3,1);  //3
  delay(de); 
  
  }
  
  }
  switch(value) {
    case code1:
      if(itsONled[1] == 1) { // if first led is on then
        digitalWrite(led1, LOW); // turn it off when button is pressed
        itsONled[1] = 0; // and set its state as off
      }
      else { // else if first led is off
        digitalWrite(led1, HIGH); // turn it on when the button is pressed
        itsONled[1] = 1; // and set its state as on
      }
      break;
    case code2:
      if(itsONled[2] == 1) {
        digitalWrite(led2, LOW);
        itsONled[2] = 0;
      }
      else{
        digitalWrite(led2, HIGH);
        itsONled[2] = 1;
      }
      break;
    case code3:
      if(itsONled[3] == 1) {
        digitalWrite(led3, LOW);
        itsONled[3] = 0;
      }
      else {
        digitalWrite(led3, HIGH);
        itsONled[3] = 1;
      }
      break;
    }
    Serial.println(value); // you can ommit this line
    irrecv.resume(); // Receive the next value
  }
}
