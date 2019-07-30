void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop()
{
  /*digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    delay(500);
    digitalWrite(13,LOW);
    digitalWrite(12,HIGH);
    delay(500);*/

 for (int i = 0; i < 10; i++)
  {
    int r = random(0, 2);
    int s = random(0, 2);
    if (r == 0)
    {
      if (s == 1)
      {
        digitalWrite(13, HIGH);
        delay(200);
      }
      else if (s == 0)
      {
        digitalWrite(13, LOW);
        delay(200);
      }
    }
    else if (r == 1)
    {
      if (s == 1)
      {
        digitalWrite(12, HIGH);
        delay(200);
      }
      else if (s == 0)
      {
        digitalWrite(12, LOW);
        delay(200);
      }
    }
  }
}
