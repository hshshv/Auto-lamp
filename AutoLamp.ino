/*
   מנורה אוטומטית
   עם חיישן אולטראסוני \ נפח
*/

#include "Sensors.h"
#include "Led.h"

#define trig 4
#define acho 5
#define ledpin 6
#define LDR A0
#define poten A1
#define TurnedOnTime 10000
#define LightSensitivity 20 //רגישות גבוהה יותר - נדלק גם באור גדול יותר

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
  if (sens.Activated() && analogRead(LDR) < LightSensitivity)//analogRead(poten) / 20
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
/*
Serial.print("LDR: "); Serial.print(analogRead(LDR));
Serial.print("    poten: "); Serial.println(analogRead(poten) / 20);
*/
}
