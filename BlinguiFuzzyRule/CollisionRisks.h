#ifndef CollisionRisks_h
#define CollisionRisks_h
#include "Arduino.h"
#include "Alerts.h"


class CollisionRisks{

   public: 

    collisionRisks();
    void alerts();
    void alertsRisks(float risk);
    
    public:
    
    Alerts *a = new Alerts();

  
};





#endif 





