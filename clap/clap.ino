int soundSensor=2;
int LED=4;
boolean LEDStatus=false;




void setup() {
 pinMode(soundSensor,INPUT);
 pinMode(LED,OUTPUT);

}

void loop() {

  int SensorData=digitalRead(soundSensor); 
  if(SensorData==1){

    if(LEDStatus==false){
        LEDStatus=true;
        digitalWrite(LED,LOW);
        delay(10000);
    }
    else{
        LEDStatus=false;
        digitalWrite(LED,HIGH);
        delay(1000);
    }
  }
 } 
