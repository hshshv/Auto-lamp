/*
   מנורה אוטומטית
   עם חיישן אולטראסוני \ נפח
*/

#include "Sensors.h" //download from: github.com/hshshv/Sensors
#include "Led.h" //download from:  github.com/hshshv/Led

#define trig 4
#define acho 5
#define ledpin 6
#define LDR A0
#define poten A1
#define TurnedOnTime 10000

UltrasonicSensor sens(trig, acho);
Led led(ledpin);

void setup()
{
  sens.StoppingDistance = 40;
  digitalWrite(13, LOW);
  Serial.begin(9600);
}

unsigned int StopAt;

void loop()
{
  if (sens.Activated() && analogRead(LDR) < analogRead(poten))
  {
    led.TurnOn();
    StopAt = 0;
    while (StopAt < TurnedOnTime / 6)
    {
      delay(6);
      if (sens.Activated())
      {
        StopAt = 0;
        Serial.println("sensor active");
      }
      StopAt++;
      Serial.print(StopAt); Serial.print(" < "); Serial.println(TurnedOnTime / 6);  
    }
    led.TurnOff();
  }
}
