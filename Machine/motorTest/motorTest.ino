/*
Required connections between Arduino and qik 2s12v10:

      Arduino   qik 2s12v10
---------------------------
          GND - GND
Digital Pin 2 - TX
Digital Pin 3 - RX
Digital Pin 4 - RESET

DO NOT connect the 5V output on the Arduino to the 5V output on the qik 2s12v10!
*/

#include <SoftwareSerial.h>
#include <PololuQik.h>

PololuQik2s12v10 qik(2, 3, 4);

void setup()
{
  Serial.begin(115200);
  Serial.println("qik 2s12v10 dual serial motor controller");
  qik.init();
}

void loop()
{
    qik.setM1Speed(120);
    delay(2000);
    qik.setM1Speed(-120);
    Serial.println("run");
    delay(2000);
}
