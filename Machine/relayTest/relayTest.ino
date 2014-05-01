int valvePin = 5;                 // LED connected to digital pin 13
int heaterPin = 6;                 // LED connected to digital pin 13
int shredderPin = 7;                 // LED connected to digital pin 13
int blenderPin = 12;                 // LED connected to digital pin 13

void setup()
{
  pinMode(valvePin, OUTPUT);      // sets the digital pin as output
  pinMode(heaterPin, OUTPUT);      // sets the digital pin as output
  pinMode(shredderPin, OUTPUT);      // sets the digital pin as output
  pinMode(blenderPin, OUTPUT);      // sets the digital pin as output

}

void loop()
{
  digitalWrite(valvePin, HIGH);   // sets the LED on
    digitalWrite(heaterPin, HIGH);   // sets the LED on
  digitalWrite(shredderPin, HIGH);   // sets the LED on
    digitalWrite(blenderPin, HIGH);   // sets the LED on

}
