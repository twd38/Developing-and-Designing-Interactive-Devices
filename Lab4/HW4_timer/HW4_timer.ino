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
int startPin = A1;
int sensorValue = 0; 
int setTime=0;
int countdown=0;
int startButton=0;


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  
}

void loop() {
  digitalWrite(9, LOW);
  sensorValue = analogRead(sensorPin);
  startButton = analogRead(startPin);
  setTime=map(sensorValue, 100, 1023, 0, 60);
  analogWrite(ledPin, setTime);
  
  Serial.println(startButton);
  
  lcd.display();
  lcd.setCursor(0,0);
  lcd.print(setTime);
  
//  Serial.println(sensorValue);

  
  
  
  if (startButton>5) {
     for (setTime; setTime >= 0; setTime--) {
      lcd.setCursor(0,0);
      lcd.print(setTime);
      delay(1000);
      lcd.clear();
      }
      lcd.setCursor(0,1);
      lcd.print("Time's Up!");
      digitalWrite(9, HIGH); 
      delay(2000); 
      lcd.clear(); 
  }
  
  

}
