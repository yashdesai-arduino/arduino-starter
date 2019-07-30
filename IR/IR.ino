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
#define code1 3249208323 // code received from button no. 1
#define code2 3249177213 // code received from button no. 2
#define code3 3249174918 // code received from button no. 3

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

void loop() {
if (irrecv.decode(&results)) {
unsigned int value = results.value;
switch(value) {
case code1:
if(itsONled[1] == 1) { // if first led is on then
Serial.write("From 1");
digitalWrite(led1, LOW); // turn it off when button is pressed
delay(1000);
itsONled[1] = 0; // and set its state as off
} else { // else if first led is off
  Serial.write("From 1");
digitalWrite(led1, HIGH); // turn it on when the button is pressed
itsONled[1] = 1; // and set its state as on
}
break;
case code2:
if(itsONled[2] == 1) {
  Serial.write("From 1");
digitalWrite(led2, LOW);

itsONled[2] = 0;
} else {
  Serial.write("From 1");
digitalWrite(led2, HIGH);
itsONled[2] = 1;
}
break;
case code3:
if(itsONled[3] == 1) {
  Serial.write("From 1");
digitalWrite(led3, LOW);
itsONled[3] = 0;
} else {
digitalWrite(led3, HIGH);
itsONled[3] = 1;
}
break;
}
Serial.println(value); // you can ommit this line
irrecv.resume(); // Receive the next value
}
}
