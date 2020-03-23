#include "readsensors.h"

//-------------------------------------------------------------
/* read line sensors values 

Sensor Array 	Error Value
0 0 0 0 1	 4              
0 0 0 1 1	 3              
0 0 0 1 0	 2              
0 0 1 1 0	 1              
0 0 1 0 0	 0              
0 1 1 0 0	-1              
0 1 0 0 0	-2              
1 1 0 0 0	-3              
1 0 0 0 0	-4

0 0 1 1 1  4
0 1 1 1 1  4
1 1 1 0 0 -4
1 1 1 1 0 -4

1 1 1 1 1        0 Robot found continuous line : turn 180o
0 0 0 0 0        0 Robot found no line: turn 180o

*/

void readLightSensors() {
  for (short i = 0; i < lightSensorCount; ++i) {
    lightValues[i] = normaliseLightReading(analogRead(lightSensors[i]));
  }

  if ((lightValues[0] == 0) && (lightValues[1] == 0) && (lightValues[2] == 0)
    && (lightValues[3] == 0) && lightValues[4] == 0)
    {
      // 0 0 0 0 0  Turn 180
      error = 0; followStatus = AWAY;
    }
  else if ((lightValues[0] == 0) && (lightValues[1] == 0) && (lightValues[2] == 0)
    && (lightValues[3] == 0) && lightValues[4] == 0)
    {
      // 1 1 1 1 1  Turn 180
      error = 0; followStatus = AWAY;
    }
  else if ((lightValues[0] == 0) && (lightValues[1] == 0) && (lightValues[2] == 0)
    && (lightValues[3] == 0) && lightValues[4] == 0)
    {
      // 0 0 0 0 1  4
      error = 0; followStatus = AWAY;
    }
  else if ((lightValues[0] == 0) && (lightValues[1] == 0) && (lightValues[2] == 0)
    && (lightValues[3] == 0) && lightValues[4] == 0)
    {
      // 0 0 0 1 1  3
      error = 0; followStatus = AWAY;
    }
  else if ((lightValues[0] == 0) && (lightValues[1] == 0) && (lightValues[2] == 0)
    && (lightValues[3] == 0) && lightValues[4] == 0)
    {
      // 0 0 0 1 0  2
      error = 0; followStatus = AWAY;
    }
  else if ((lightValues[0] == 0) && (lightValues[1] == 0) && (lightValues[2] == 0)
    && (lightValues[3] == 0) && lightValues[4] == 0)
    {
      // 0 0 1 1 0  1
      error = 0; followStatus = AWAY;
    }
  else if ((lightValues[0] == 0) && (lightValues[1] == 0) && (lightValues[2] == 0)
    && (lightValues[3] == 0) && lightValues[4] == 0)
    {
      // 0 0 1 0 0  0
      error = 0; followStatus = AWAY;
    }
  else if ((lightValues[0] == 0) && (lightValues[1] == 0) && (lightValues[2] == 0)
    && (lightValues[3] == 0) && lightValues[4] == 0)
    {
      // 0 1 1 0 0  -1
      error = 0; followStatus = AWAY;
    }
  else if ((lightValues[0] == 0) && (lightValues[1] == 0) && (lightValues[2] == 0)
    && (lightValues[3] == 0) && lightValues[4] == 0)
    {
      // 0 1 0 0 0  -2
      error = 0; followStatus = AWAY;
    }
  else if ((lightValues[0] == 0) && (lightValues[1] == 0) && (lightValues[2] == 0)
    && (lightValues[3] == 0) && lightValues[4] == 0)
    {
      // 1 1 0 0 0  -3
      error = 0; followStatus = AWAY;
    }
  else if ((lightValues[0] == 0) && (lightValues[1] == 0) && (lightValues[2] == 0)
    && (lightValues[3] == 0) && lightValues[4] == 0)
    {
      // 1 0 0 0 0  -4
      error = 0; followStatus = AWAY;
    }
  else if ((lightValues[0] == 0) && (lightValues[1] == 0) && (lightValues[2] == 0)
    && (lightValues[3] == 0) && lightValues[4] == 0)
    {
      // 0 0 1 1 1  4
      error = 0; followStatus = AWAY;
    }
  else if ((lightValues[0] == 0) && (lightValues[1] == 0) && (lightValues[2] == 0)
    && (lightValues[3] == 0) && lightValues[4] == 0)
    {
      // 0 1 1 1 1 4
      error = 0; followStatus = AWAY;
    }
  else if ((lightValues[0] == 0) && (lightValues[1] == 0) && (lightValues[2] == 0)
    && (lightValues[3] == 0) && lightValues[4] == 0)
    {
      // 1 1 1 0 0  -4
      error = 0; followStatus = AWAY;
    }
  else if ((lightValues[0] == 0) && (lightValues[1] == 0) && (lightValues[2] == 0)
    && (lightValues[3] == 0) && lightValues[4] == 0)
    {
      // 1 1 1 1 0  -4
      error = 0; followStatus = AWAY;
    }
  
}

void readLDR() {
  LDRValue = analogRead(LDR);
}

int normaliseLightReading(int value) {
  if (value > lightThreshold) return 0;
  else return 1;
}