enum FollowStatus { FOLLOWING, AWAY };
FollowStatus followStatus;

const int E1 = 5;     //M1 Speed Control
const int E2 = 6;     //M2 Speed Control
const int M1 = 4;    //M1 Direction Control
const int M2 = 7;    //M1 Direction Control

// Sensors
const int LDR = 0;    // LDR Pin
int LDRValue;         // LDR Value

const int lightSensorCount = 5;
const int lightSensors[] = { 1, 2, 3, 4, 5 };
int lightValues[lightSensorCount];
const int lightThreshold = 500;

// PID Controller
float Kp = 25;
float Ki = 0.15;
float Kd = 1200;

float error=0, P=0, I=0, D=0, PIDvalue=0;
float previousError=0, previousI=0;
