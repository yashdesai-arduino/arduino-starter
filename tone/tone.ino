/*
  Pitch follower

  Plays a pitch that changes based on a changing
  analog input

  circuit:
  * 8-ohm speaker on digital pin 9
  * photoresistor on analog 0 to 5V
  * 4.7K resistor on analog 0 to ground

  created 21 Jan 2010
  modified 31 May 2012  by Tom Igoe, with
  suggestion from Michael Flynn

  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/Tone2
*/

int sensorReading = 0;

void setup()
{
  pinMode(9, OUTPUT);
}

void loop()
{
 /* tone(9, 1700, 200);
  delay(1000); // Delay a little bit to improve simulation performance
  noTone(9);*/

  for(int i=0;i<10;i++)
  {
    int r = random(15, 30);
    tone(9, r*100, 200);
    delay(600); // Delay a little bit to improve simulation performance
    noTone(9);
  }
}
