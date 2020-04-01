#include "Sensors.h" //download from: github.com/hshshv/Sensors
#include "Led.h" //download from:  github.com/hshshv/Led

#define trig 4
#define acho 5
#define ledpin 6
#define LDR A0
#define poten A1
#define TurnedOnTime 10000

UltrasonicSensor sens(trig, acho); //creat an object of 'ultrasonicSensor' class namd 'sens'
Led lamp(ledpin); //creat an object of 'Led' class named 'lamp'

void setup()
{
  sens.StoppingDistance = 40;//the sensor will be considered 'activated' if the distance it gets is less then 40 sm.
}

unsigned int StopAt;

void loop()
{
  if (sens.Activated() && analogRead(LDR) < analogRead(poten)) //if the voltage from the LDR is lower then the voltage from the potentiometer it means thet ther is not enought light in the room
  {
    lamp.TurnOn();
    StopAt = 0;
    while (StopAt < TurnedOnTime / 6)
    {
      delay(6);
      if (sens.Activated())
      {
        StopAt = 0;
      }
      StopAt++;
    }
    lamp.TurnOff();
  }
}
