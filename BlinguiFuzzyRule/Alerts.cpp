#include "Alerts.h"
#include "Arduino.h"

  Alerts::Alerts (){

     vib1 = 48;
     vib2 = 49;
      // Pino ligado ao P-E (PLAYE) do modulo (5v)
     pino_playe = 9;  
     buzzer = 46;
     led = 52;

          }
    

    void Alerts::pinAlerts(){
      
       //Definindo o pino buzzer como de saída.
       pinMode(buzzer, OUTPUT);
       pinMode(pino_playe, OUTPUT);
       pinMode(vib1, OUTPUT);  
       pinMode(vib2, OUTPUT);  

        }
        

    void Alerts::vibra(){
     digitalWrite(vib1, HIGH);   // turn the vibra on (HIGH is the voltage level)
     digitalWrite(vib2, HIGH);   // turn the vibra on (HIGH is the voltage level)
     delay(100); 
     digitalWrite(vib1, LOW);    // turn the vibra off by making the voltage LOW
     digitalWrite(vib2, LOW);
     
   }

   void Alerts::voice (){
    digitalWrite(pino_playe, HIGH);
    delay(3000);
    digitalWrite(pino_playe, LOW);
 
}

void Alerts::voiceOff (){
  digitalWrite(pino_playe, LOW);
  }



void Alerts::beeps(){
    tone(buzzer,2500);//ACIONA O BUZZER
    delay(50);
    noTone(buzzer);//desliga O BUZZER
   }


void Alerts::pisca(){
  
digitalWrite(led, HIGH);
delay(3000);
digitalWrite(led, LOW);

 
}



