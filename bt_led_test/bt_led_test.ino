#define led 13

int data;
int blink_=LOW;
unsigned long previousMillis = 0;
const long interval = 1000;
void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
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
    if (data==49)
    {
      digitalWrite(led, HIGH);
    }
    else if (data == 48)
    {
      digitalWrite(led, LOW);
    }
    else if (data == 50)
    {
      /*if (currentMillis - previousMillis >= interval)
      {
         previousMillis = currentMillis;
         if (blink_ == LOW)
         {
            blink_ = HIGH;
         }
         else
         {
            blink_ = LOW;
         }*/
    digitalWrite(led,millis()>>9 &1);
    //}
  }
}
}
