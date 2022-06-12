#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define VT_PIN A0 // connect VT
#define AT_PIN A1 // connect AT

#define ARDUINO_WORK_VOLTAGE 5.0

LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004

void setup()
{
  Serial.begin(9600);
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");

  delay(1000);

  lcd.clear();
}

void loop()
{ 
  lcd.setCursor(0,0);
  lcd.print("B145:MAX471");

  int vt_temp = analogRead(VT_PIN);
  int at_temp = analogRead(AT_PIN);

  double voltage = vt_temp * (ARDUINO_WORK_VOLTAGE / 1023.0) * 5;
  double current = at_temp * (ARDUINO_WORK_VOLTAGE / 1023.0);
  
  lcd.setCursor(0,1);
  lcd.print("Voltage= " + (String)voltage + "V  ");
  Serial.println("Voltage=" + (String)(voltage)+ "V ");
  lcd.setCursor(0,2);
  lcd.print("Current= " + (String)current + "A  ");
  Serial.println("Current= " + (String)current + "A  ");
  delay(500);
}
