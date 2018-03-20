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
#include <EEPROM.h>

int ledPin = 9;    // LED connected to digital pin 9
int sensorPin = A0;
int startPin = A1;
int sensorValue = 0; 
int setTime=0;
int countdown=0;
int startButton=0;
int maxAccel=0;
int accelRead=0;
int addr = 0; 
int address = 0;
byte value;

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

  lcd.setCursor(0,0);
  lcd.print("3");
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("2");
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("1");
  delay(1000);

  lcd.setCursor(0,0);
  lcd.print("Launch Rocket!!!");
    delay(2000);
    
  lcd.setCursor(0,0);
  lcd.print("Touch Sensor for Max Accel and Alt");
  lcd.setCursor(0,1);
  lcd.print("Max Acel and Alt");delay(1000);
  delay(1000);
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


  accelRead = event.acceleration.y;
  EEPROM.write(addr, accelRead);
  
//  if(accelRead>maxAccel)
//    {
//      maxAccel=accelRead;
//    }
  
    startButton = analogRead(startPin);


  if (startButton>20) {
      
//    Serial.println("Max Acceleration: X m/s^2");
//    Serial.println("Max Altitude: X meters");
//    delay(5000);

    lcd.print("Accel Playback");
    delay(2000);
    lcd.clear();
     
        while(address<addr)
        {
          value = EEPROM.read(address);
      
          if(value>maxAccel)
          {
            maxAccel=value;
          }
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Time: ");
          lcd.print(address);
          lcd.print(" 1/10 sec");

          lcd.setCursor(0,1);
          lcd.print("Accel: ");
          lcd.print(value);
          lcd.print(" m/s^2");
          

          address = address + 1;
          delay(100);
        }


    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Mx Acel: "); lcd.print(maxAccel); lcd.print(" m/s^2"); delay(1000);
    delay(2000);

  
  addr = addr + 1;
  if (addr == EEPROM.length()) {
    addr = 0;
  }
  
  delay(100);
  
  

}
