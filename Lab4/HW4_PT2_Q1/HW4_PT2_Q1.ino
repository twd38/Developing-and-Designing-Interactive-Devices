/*
  Fading

  This example shows how to fade an LED using the analogWrite() function.

  The circuit:
  - LED attached from digital pin 9 to ground.

  created 1 Nov 2008
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Fading
*/

int ledPin = 9;    // LED connected to digital pin 9
int sensorPin = A0;
int sensorValue = 0; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  analogWrite(ledPin, sensorValue);
  
  Serial.println(sensorValue);
  delay(100);  
  

}
