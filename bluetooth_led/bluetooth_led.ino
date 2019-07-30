#include <SoftwareSerial.h>
int bluetoothTx = 2; // D2 to TXD

int bluetoothRx = 3; // D3 to RXD  (Warning! See Text)

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()

{

Serial.begin(9600);

bluetooth.begin(115200);

delay(100);

bluetooth.println("U,9600,N");

bluetooth.begin(9600);

}

void loop()

{

if (bluetooth.available())

{

Serial.print((char)bluetooth.read());

}

if (Serial.available())

{

bluetooth.print((char)Serial.read());

}



}
