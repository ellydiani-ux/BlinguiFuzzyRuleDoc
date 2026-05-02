#include <Fuzzy.h>

#include "Inputs.h"
#include "Rulles.h"
#include "CollisionRisks.h"
#include "Alerts.h"

double lastDist=0;
double currentDist=0;
double variatDist=0;
double variatTime=0;
double lastTime=0;
double currentTime=0;
double speeds=0;
double variatVelocity=0;
double accel=0;



Inputs i;
Rulles r;
CollisionRisks c;
Alerts a;

void setup() {

  Serial.begin(9600);
  i.pinSonar();
  r.fuzzySet();
  r.rulleFuzzy();
  a.pinAlerts();

}


void loop()
{

  //Serial.println("DISTANCIA::");
  double input1 = i.sonarDistancesObstacles();

  //Serial.println("VELOCIDADE::");
  double input2 = i.sonarSpeed();

  //Serial.println("ACELERAÇÃO::");
  double input3 = i.sonarAcceleration();

  r.fuzzificaDefuzzifica(input1, input2, input3);

 
}