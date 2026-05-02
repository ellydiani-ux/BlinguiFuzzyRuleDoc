#ifndef Rulles_h
#define Rulles_h
#include "Arduino.h"
#include <Fuzzy.h>
#include "Inputs.h"
#include "Alerts.h"




class Rulles {
  
    public: 
    Rulles();
    void fuzzySet();
    void rulleFuzzy();
    void fuzzificaDefuzzifica(double input1, double input2, double input3);

    void alertsRisks(float risks);

    public:

// Instantiating a Fuzzy object


Inputs *i = new Inputs();
Alerts *a = new Alerts();
Fuzzy *fuzzy = new Fuzzy();


FuzzySet *verysmall = new FuzzySet(0, 0, 0, 150);
FuzzySet *small = new FuzzySet(0, 150, 150, 300);
FuzzySet *medium = new FuzzySet(150, 300, 300, 450);
FuzzySet *large = new FuzzySet(300, 450, 450, 600);
FuzzySet *verylarge = new FuzzySet(450, 600, 600, 600);

FuzzySet *verysmallv = new FuzzySet(0, 0, 0, 100);
FuzzySet *smallv = new FuzzySet(0, 100, 100, 200);
FuzzySet *mediumv = new FuzzySet(100, 200, 200, 300);
FuzzySet *largev = new FuzzySet(200, 300, 300, 400);
FuzzySet *verylargev = new FuzzySet(300, 400, 400, 400);

FuzzySet *verysmallac = new FuzzySet(0, 0, 0, 100);
FuzzySet *smallac = new FuzzySet(0, 100, 100, 200);
FuzzySet *mediumac = new FuzzySet(100, 200, 200, 300);
FuzzySet *largeac = new FuzzySet(200, 300, 300, 400);
FuzzySet *verylargeac = new FuzzySet(300, 400, 400, 400);


FuzzySet *minimum = new FuzzySet(0, 1, 1, 2);  //risco baixo 1
FuzzySet *average = new FuzzySet(1, 2, 2, 3); // risco medio 2
FuzzySet *maximum = new FuzzySet(2, 3, 3, 3); // risco alto 3

};

#endif 








