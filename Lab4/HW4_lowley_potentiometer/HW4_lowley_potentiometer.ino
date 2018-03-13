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
#include <LiquidCrystal.h>
int ledPin = 9;    // LED connected to digital pin 9
int sensorPin = A0;
int sensorValue = 0; 

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  
}

void loop() {
  sensorValue = analogRead(sensorPin);
  analogWrite(ledPin, sensorValue);
  
//  Serial.println(sensorValue);
  lcd.setCursor(0,0);
  lcd.print(millis() / 1000);
  
  lcd.setCursor(0,1);
  lcd.print(sensorValue);
 
  lcd.display();
  delay(100);
  

}
