#include <Keypad.h>
#include <Wire.h>
#include <Pitches.h>
#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x27);
const byte ROWS = 4; //four rows
const byte COLS = 4; //fours columns
char keys[ROWS][COLS] = {
  {'1','2','3','4'},
  {'5','6','7','8'},
  {'9','0','/','-'},
  {'*','+','=','.'}
};

/*
BC+F+E+
BC+E+D+
BC+F+….E+D+E+*/



int a[]={};
int b[]={};

byte rowPins[ROWS] = {6, 7, 8, 9}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {2, 3, 4, 5}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);

  Wire.begin();
  Wire.beginTransmission(0x27); //Your LCD Address
  lcd.begin(16, 2);
  pinMode(10, OUTPUT);
}
  
void loop(){
  lcd.setBacklight(255);
  char key = keypad.getKey();
  switch(key){
    case '1': lcd.print(key);tone(10, NOTE_B5, 200);break;
    case '2': lcd.print(key);tone(10, NOTE_C5, 200);break;
    case '3': lcd.print(key);tone(10, NOTE_F5, 200);break;
    case '4': lcd.print(key);tone(10, NOTE_E5, 200);break;
    case '5': lcd.print(key);tone(10, NOTE_D5, 200);break;
    case '6': lcd.print(key);tone(10, NOTE_F5, 200);break;
    case '7': lcd.print(key);tone(10, NOTE_FS5, 200);break;
    case '8': lcd.print(key);tone(10, NOTE_G5, 200);break;
    case '9': lcd.print(key);tone(10, NOTE_D6, 200);break;
    case '0': lcd.print(key);tone(10, NOTE_E5, 200);break;
    case '/': lcd.print(key);tone(10, NOTE_AS6, 200);break;
    case '*': lcd.print(key);tone(10, NOTE_B6, 200);break;
    case '-': lcd.print(key);tone(10, NOTE_C6, 200);break;
    case '+': lcd.print(key);tone(10, NOTE_CS6, 200);break;
    case 'C': lcd.clear();break;
  }
}
