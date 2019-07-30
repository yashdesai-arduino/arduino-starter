int lightCal=0;
void setup() {
  pinMode(9, OUTPUT);
  lightCal = analogRead(A0);
}

void loop() {
int  lightVal = analogRead(A0);

  if(lightVal<lightCal-50)
  {
    digitalWrite(9, LOW);
  }
  else
  {
    digitalWrite(9, HIGH);
  }
}
