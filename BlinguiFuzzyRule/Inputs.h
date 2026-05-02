#ifndef Inputs_h
#define Inputs_h
#include "Arduino.h"

#define trigPin1 3 //front /righ
#define echoPin1 2 //front /righ
#define trigPin2 6 //dow / left
#define echoPin2 5 //dow /left
#define trigPin3 7 //up / frontu
#define echoPin3 8 //up / front
#define trigPin4 36 //upaux /righ
#define echoPin4 38 //upaux /righ


class Inputs {
  
    public: 
    Inputs();
    void pinSonar();
    double sonarCalcDistance(int trigPin,int echoPin);
    
    double sonarDistancesObstacles();
    double sonarSpeed();
    double sonarAcceleration();

    
    public:
    double duration, distance, frontSensor, dowSensor, upSensor,upAux, distMin, lastDist, lastTime,
    currentDist, currentTime,speeds,variatDist, variatTime, lastSpeed, currentSpeed, variatSpeed, acell;
   
  
};

#endif 
