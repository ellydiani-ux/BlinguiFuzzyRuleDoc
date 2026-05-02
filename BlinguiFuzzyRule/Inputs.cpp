#include "Inputs.h"
#include "Arduino.h"

  Inputs::Inputs (){
      lastTime=0;
      currentTime=0;
      speeds=0;
      }
      
      
    void Inputs::pinSonar(){
        Serial.begin(9600); 
        pinMode(trigPin1, OUTPUT);
        pinMode(echoPin1, INPUT);
        pinMode(trigPin2, OUTPUT);
        pinMode(echoPin2, INPUT);
        pinMode(trigPin3, OUTPUT);
        pinMode(echoPin3, INPUT);
        pinMode(trigPin4, OUTPUT);
        pinMode(echoPin4, INPUT);

        }
        
     double Inputs::sonarCalcDistance(int trigPin,int echoPin){
          digitalWrite(trigPin, LOW);
          delayMicroseconds(1);
          digitalWrite(trigPin, HIGH);
          delayMicroseconds(1);
          digitalWrite(trigPin, LOW);
          duration = pulseIn(echoPin, HIGH);
          distance = duration /29.4 / 2 ; 
          return distance;
     }
     
     
  double Inputs:: sonarDistancesObstacles() {    
    frontSensor = sonarCalcDistance(trigPin1, echoPin1);
    dowSensor = sonarCalcDistance(trigPin2, echoPin2);
    upSensor = sonarCalcDistance(trigPin3, echoPin3);
    upAux = sonarCalcDistance(trigPin4, echoPin4);

    distMin>=0;
    distMin = frontSensor;

   // Serial.print("DistMinima");
    //Serial.println(distMin);
    //Serial.print("font testando");
    //Serial.println(frontSensor);


   if (distMin > dowSensor)
    distMin = dowSensor;
   if (distMin > upSensor)
    distMin = upSensor;
   if (distMin > upAux)
    distMin = upAux;

 /* Serial.println("\tDISTANCES:");

  Serial.print("DistFront: ");
  Serial.println(frontSensor);

  Serial.print("DistUpAux: ");
  Serial.println(upAux);

  Serial.print("DistDow: ");
  Serial.println(dowSensor);

  Serial.print("DistUp: ");
  Serial.println(upSensor);
  
   Serial.print("DIST MENOR: ");
  Serial.println(distMin);
*/

  return distMin;
          
}


  double Inputs::sonarSpeed(){
    
  //  Serial.println("lastDist");
    lastDist = sonarDistancesObstacles();
    //Serial.println(lastDist);

    //Serial.print("Tempo1: ");
    lastTime = millis();
    //Serial.println(lastTime);
    
    //Serial.print("distanceCURRENT:"); 
    currentDist = sonarDistancesObstacles();
    //Serial.println(currentDist);
    
    //Serial.print("TempoCURRENT:");  
    currentTime = millis();
    //Serial.println(currentTime);

    //Serial.print("Deslocamento:");
    variatDist = abs(lastDist - currentDist); 
    //Serial.println(variatDist);
    
    //Serial.print("Tempo variacao::");
    variatTime = abs(currentTime-lastTime)/1000;
    //Serial.println(variatTime);
     
   //Serial.println("Velocidade::");
    speeds = (variatDist)/ (variatTime);
    //Serial.println(speeds);
    
    return speeds;
   
  }



double Inputs::sonarAcceleration(){
    
    lastSpeed = sonarSpeed();
    //Serial.println("Velocidade 1: ");        
    //Serial.print(lastSpeed);        
    
    //Serial.print("Tempo1: ");
    lastTime = millis();
    //Serial.println(lastTime);
    
    //Serial.print("Velocidade 2:"); 
    currentSpeed = sonarSpeed();
    //Serial.println(currentSpeed);
    
    //Serial.print("Tempo2:");  
    currentTime = millis();//milisegundos
    //Serial.println(currentTime);

    variatSpeed = abs(lastSpeed - currentSpeed); 
    //Serial.print("velocidade variacao:");
    //Serial.println(variatSpeed);
    
    variatTime = abs(currentTime-lastTime)/1000; //transforma milisegundos em segundos
   // Serial.print("Tempo variacao::");
    //Serial.println(variatTime);
     
  //  Serial.print("aceleração::");
    acell = (variatSpeed / variatTime);
    //Serial.println(acell);
  
    return acell;
   
  }

