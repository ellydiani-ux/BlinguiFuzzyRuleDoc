#ifndef Alerts_h
#define Alerts_h
#include "Arduino.h"


class Alerts{

   public: 

    Alerts();
    void pinAlerts();
    void vibra();
    void voice();
    void voiceOff(); 
    void beeps();
    void pisca();
    
    public:

    int vib1;
    int vib2;
    int pino_playe;
    int buzzer;
    int led;

};





#endif 





