#include <Arduino.h>
#include <RobotDefines.h>
#include "motorfunc.h"
#include "readsensors.h"

//Standard PWM DC control
void calculatePID()
{
  P = error;
  I = I + error;
  D = error-previousError;
  PIDvalue = (Kp*P) + (Ki*I) + (Kd*D);
  previousError = error;
}

void setup() {
  // put your setup code here, to run once:

  // Setup LDR Pin
  pinMode(LDR, INPUT);

  // Setup input pins for light sensors
  for (short i = 0; i < lightSensorCount; ++i) {
    pinMode(lightSensors[i], INPUT);
  }

}

void loop() {
  while(readLDR() < 400);
  // put your main code here, to run repeatedly:
  readLightSensors();
}