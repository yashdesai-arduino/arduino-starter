#include <virtuabotixRTC.h> //Library used
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>
LiquidCrystal_PCF8574 lcd(0x27); 


//Wiring SCLK -> 6, I/O -> 7, CE -> 8
//Or CLK -> 6 , DAT -> 7, Reset -> 8

virtuabotixRTC myRTC(7, 6, 5); //If you change the wiring change the pins here also

void setup() {
 Serial.begin(9600);

 Wire.begin();
  Wire.beginTransmission(0x27); //Your LCD Address
  lcd.begin(16, 2); // initialize the lcd

// Set the current date, and time in the following format:
 // seconds, minutes, hours, day of the week, day of the month, month, year
 //myRTC.setDS1302Time(0, 46, 17, 7, 4, 8, 2019); //Here you write your actual time/date as shown above 
 //but remember to "comment/remove" this function once you're done
 //The setup is done only one time and the module will continue counting it automatically
}

void loop() {
  lcd.clear(); 
 // This allows for the update of variables for time or accessing the individual elements.
 myRTC.updateTime();
lcd.setBacklight(255);
// Start printing elements as individuals
 //lcd.print("Current Date / Time: ");
 lcd.setCursor(0,0);
 lcd.print(myRTC.month); //You can switch between day and month if you're using American system
 lcd.print("/");
 lcd.print(myRTC.dayofmonth);
 lcd.print("/");
 lcd.print(myRTC.year);
 lcd.print(" ");
 lcd.setCursor(0,1);
 lcd.print(myRTC.hours);
 lcd.print(":");
 lcd.print(myRTC.minutes);
 lcd.print(":");
 lcd.println(myRTC.seconds);

// Delay so the program doesn't print non-stop
 delay(1000);
}
