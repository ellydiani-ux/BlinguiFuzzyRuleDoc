#include "Alerts.h"
#include "CollisionRisks.h"
#include "Arduino.h"



  CollisionRisks::collisionRisks() {

  }
  
  
  void CollisionRisks::alertsRisks(float risk) {
                Serial.println("\nALERTAS: ");

     if(risk < 2){// SE o RIsco de colisão for menor que 2 (risco baixo)
       // a->pisca(); 
            
            a->vibra();
            a->beeps(); 

            Serial.print("\tVIBRANDO~~~~~~ ");

        }
    
      else

     if((risk >=2) & (risk < 3) ){// Se o risco de colisão estiver entre 1 e 3 risco medio
            a->beeps(); 
            a->beeps(); 
            //a->vibra();



                        Serial.print("\tBEEPS.........");

   }
      else

    if((risk >=3 ) & (risk < 4 ) ){// Se o risco de colisão estiver entre 2 e 4 será risco alto
            a->voice();
           // a->vibra();
            a->pisca();
            a->beeps();
              Serial.print("\tVOZZZ >>>>>>");

  
        }
}

