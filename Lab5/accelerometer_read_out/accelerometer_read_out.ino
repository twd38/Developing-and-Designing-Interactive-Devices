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
#include <Adafruit_LSM303_U.h>
#include <Adafruit_LSM303.h>

#include <Wire.h>
#include <Adafruit_Sensor.h>

int ledPin = 9;    // LED connected to digital pin 9
int sensorPin = A0;
int startPin = A1;
int sensorValue = 0; 
int setTime=0;
int countdown=0;
int startButton=0;
int maxAccel=0;
int accelRead=0;
int accelY = 0;
int accelX = 0;
int accelZ = 0;

Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(54321);


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void displayIntro(void)
{
  sensor_t sensor;
  accel.getSensor(&sensor);


  Serial.println("------------------------------------");
  Serial.print  ("Launch Rocket!!!");
  Serial.print  ("Touch Pressure Sensor for Max Acceleration and Altitude"); Serial.println(sensor.version);
  Serial.println("------------------------------------");
  Serial.println("");

}

void setup(void) {
  #ifndef ESP8266
  while (!Serial);     // will pause Zero, Leonardo, etc until serial console opens
#endif
  Serial.begin(9600);
  Serial.println("Accelerometer Test"); Serial.println("");

  /* Initialise the sensor */
  if(!accel.begin())
  {
    /* There was a problem detecting the ADXL345 ... check your connections */
    Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
    while(1);
  }

  /* Display some basic information on this sensor */
  
  pinMode(9, OUTPUT);
  lcd.begin(16, 2);
  // Print a message to the LCD.

  displayIntro();
}

void loop(void) {
  /* Get a new sensor event */
  sensors_event_t event;
  accel.getEvent(&event);

   /* Display the results (acceleration is measured in m/s^2) */
//  Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("  ");
//  Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print("  ");
//  Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.print("  ");Serial.println("m/s^2 ");

  accelY = event.acceleration.y;
  accelX = event.acceleration.x;
  accelZ = event.acceleration.z;
  
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("X: "); lcd.print(accelX); lcd.print(" Y: "); lcd.print(accelY); lcd.print(" Z: "); lcd.print(accelZ);delay(1000);

    
//     for (setTime; setTime >= 0; setTime--) {
//      lcd.setCursor(0,0);
//      lcd.print(setTime);
//      delay(1000);
//      lcd.clear();
//      }
//      lcd.setCursor(0,1);
//      lcd.print("Time's Up!");
//      digitalWrite(9, HIGH); 
//      delay(2000); 
//      lcd.clear(); 


  delay(100);
  
  

}
