#include "Rulles.h"
#include <Fuzzy.h>
#include "Inputs.h"
#include "Alerts.h"
#include "Arduino.h"

Rulles::Rulles (){
  
 
 }



// Instantiating a Fuzzy object


void Rulles::fuzzySet() {

  FuzzyInput *distance = new FuzzyInput(1);

  distance->addFuzzySet(verysmall);
  distance->addFuzzySet(small);
  distance->addFuzzySet(medium);
  distance->addFuzzySet(verylarge);
  distance->addFuzzySet(large);
  fuzzy->addFuzzyInput(distance);

  FuzzyInput *speed = new FuzzyInput(2);

  speed->addFuzzySet(verysmallv);
  speed->addFuzzySet(smallv);
  speed->addFuzzySet(mediumv);
  speed->addFuzzySet(largev);
  speed->addFuzzySet(verylargev);
  fuzzy->addFuzzyInput(speed);

  FuzzyInput *accel = new FuzzyInput(3);

  accel->addFuzzySet(verysmallac);
  accel->addFuzzySet(smallac);
  accel->addFuzzySet(mediumac);
  accel->addFuzzySet(largeac);
  accel->addFuzzySet(verylargeac);
  fuzzy->addFuzzyInput(accel);

  //FuzzyOutput
  FuzzyOutput *risk = new FuzzyOutput(1);
  risk->addFuzzySet(minimum);
  risk->addFuzzySet(average);
  risk->addFuzzySet(maximum);
  fuzzy->addFuzzyOutput(risk);

}



void Rulles::rulleFuzzy() {

  //IF distance = medium and velocity = small THEN risk is 1 (Baixo)

  FuzzyRuleAntecedent *distanceMediumAndSpeedSmall = new FuzzyRuleAntecedent();
  distanceMediumAndSpeedSmall->joinWithAND(medium, smallv);

  FuzzyRuleConsequent *thenRiskMinimum = new FuzzyRuleConsequent();
  thenRiskMinimum->addOutput(minimum);
  FuzzyRule *fuzzyRule01 = new FuzzyRule(1, distanceMediumAndSpeedSmall, thenRiskMinimum);
  fuzzy->addFuzzyRule(fuzzyRule01);


  //IF distance = very.large and velocity = small THEN risk  is   1 (baixo)

  FuzzyRuleAntecedent *distanceVeryLargeAndSpeedSmall = new FuzzyRuleAntecedent();
  distanceVeryLargeAndSpeedSmall->joinWithAND(verylarge, smallv);
  FuzzyRuleConsequent *thenRiskMinimum2 = new FuzzyRuleConsequent();
  thenRiskMinimum2->addOutput(minimum);
  FuzzyRule *fuzzyRule02 = new FuzzyRule(2, distanceVeryLargeAndSpeedSmall, thenRiskMinimum2);
  fuzzy->addFuzzyRule(fuzzyRule02);

  //IF distance =small and velocity =small THEN risk  is   2 (medio)

  FuzzyRuleAntecedent *distanceSmallAndSpeedSmall = new FuzzyRuleAntecedent();
  distanceSmallAndSpeedSmall->joinWithAND(small, smallv);
  FuzzyRuleConsequent *thenRiskMedium = new FuzzyRuleConsequent();
  thenRiskMedium->addOutput(average);
  FuzzyRule *fuzzyRule03 = new FuzzyRule(3, distanceSmallAndSpeedSmall, thenRiskMedium);
  fuzzy->addFuzzyRule(fuzzyRule03);


  //IF distance = medium THEN risk  is   1 (baixo)

  FuzzyRuleAntecedent *ifDistanceMedium = new FuzzyRuleAntecedent();
  ifDistanceMedium->joinSingle(medium);
  FuzzyRuleConsequent *thenRiskMinimum3 = new FuzzyRuleConsequent();
  thenRiskMinimum3->addOutput(minimum);
  FuzzyRule *fuzzyRule04 = new FuzzyRule(4, ifDistanceMedium, thenRiskMinimum3);
  fuzzy->addFuzzyRule(fuzzyRule04);



  //IF distance = very.small and velocity = small THEN risk is   3 (alto)

  FuzzyRuleAntecedent *distanceVerySmallAndSpeedSmall = new FuzzyRuleAntecedent();
  distanceVerySmallAndSpeedSmall->joinWithAND(verysmall, smallv);
  FuzzyRuleConsequent *thenRiskMaximum = new FuzzyRuleConsequent();
  thenRiskMaximum->addOutput(maximum);
  FuzzyRule *fuzzyRule05 = new FuzzyRule(5, distanceVerySmallAndSpeedSmall, thenRiskMaximum);
  fuzzy->addFuzzyRule(fuzzyRule05);

  //IF distance = large and acceleration  = large THEN risk   is   1 (baixo)

  FuzzyRuleAntecedent *distanceLargeAccelLarge = new FuzzyRuleAntecedent();
  distanceLargeAccelLarge->joinWithAND(large, largeac);
  FuzzyRuleConsequent *thenRiskMinimum4 = new FuzzyRuleConsequent();
  thenRiskMinimum4->addOutput(minimum);
  FuzzyRule *fuzzyRule06 = new FuzzyRule(6, distanceLargeAccelLarge, thenRiskMinimum4);
  fuzzy->addFuzzyRule(fuzzyRule06);

/*
//IF distance = small and acceleration  = very.small THEN risk   is   1 (baixo)

  FuzzyRuleAntecedent *distanceSmallAccelVerySmall = new FuzzyRuleAntecedent();
  distanceSmallAccelVerySmall->joinWithAND(verysmall, verysmallac);
  FuzzyRuleConsequent *thenRiskMinimum5 = new FuzzyRuleConsequent();
  thenRiskMinimum5->addOutput(minimum);
  FuzzyRule *fuzzyRule07 = new FuzzyRule(7, distanceSmallAccelVerySmall, thenRiskMinimum5);
  fuzzy->addFuzzyRule(fuzzyRule07);
*/


}


void Rulles::fuzzificaDefuzzifica(double input1, double input2, double input3)
{

   Serial.println("\nEntrance: ");
   Serial.print("\tDistance: ");
   Serial.println(input1);
   Serial.print("\tVelocity: ");
   Serial.println(input2);
   Serial.print("\tAcceleration: ");
   Serial.println(input3);


  fuzzy->setInput(1, input1);
  fuzzy->setInput(2, input2);
  fuzzy->setInput(3, input3);

  // Running the Fuzzification
  fuzzy->fuzzify();
  
  
    // Running the Fuzzification
  fuzzy->fuzzify();
  bool rule1 = fuzzy->isFiredRule(1);
  bool rule2 = fuzzy->isFiredRule(2);
  bool rule3 = fuzzy->isFiredRule(3);
  bool rule4 = fuzzy->isFiredRule(4);
  bool rule5 = fuzzy->isFiredRule(5);
  bool rule6 = fuzzy->isFiredRule(6);

  //regras usadas em cada momento
  Serial.print("REGRA 1-> ");
  Serial.println(rule1);

  Serial.print("REGRA 2-> ");
  Serial.println(rule2);

  Serial.print("REGRA 3-> ");
  Serial.println(rule3);

  Serial.print("REGRA 4-> ");
  Serial.println(rule4);

  Serial.print("REGRA 5-> ");
  Serial.println(rule5);

  Serial.print("REGRA 6-> ");
  Serial.println(rule6);

  float output = fuzzy->defuzzify(1);

  Serial.print("\nOutput: ");
  Serial.println(output);

  // se o risk estives entre 1 e 2
  
   Serial.print("\nDISTANCE: ");
  Serial.print("Small-> ");
   Serial.print(small->getPertinence());
  Serial.print(", very small-> ");
  Serial.print(verysmall->getPertinence());
  Serial.print(", medium-> ");
 Serial.print(medium->getPertinence());
   Serial.print(", Large-> ");
 Serial.print(large->getPertinence());
 Serial.print(", Very Large-> ");
 Serial.print(verylarge->getPertinence());
 
 Serial.print("\n\nVELOCITY: ");
  Serial.print("Small-> ");
   Serial.print(smallv->getPertinence());
  Serial.print(", very small-> ");
  Serial.print(verysmallv->getPertinence());
  Serial.print(", medium-> ");
 Serial.print(mediumv->getPertinence());
   Serial.print(", Large-> ");
 Serial.print(largev->getPertinence());
 Serial.print(", Very Large-> ");
 Serial.print(verylargev->getPertinence());
 
  
 Serial.print("\n\nACCELERATION: ");
 Serial.print("Small-> ");
 Serial.print(smallac->getPertinence());
 Serial.print(", very small-> ");
 Serial.print(verysmallac->getPertinence());
 Serial.print(", medium-> ");
 Serial.print(mediumac->getPertinence());
 Serial.print(", Large-> ");
 Serial.print(largeac->getPertinence());
 Serial.print(", Very Large-> ");
 Serial.print(verylargeac->getPertinence());
 
 
  Serial.println("Result: ");
  Serial.print("\t\t\tRisk: ");
  Serial.println(output);
  Serial.print("\tRisk: Minimum-> ");
  Serial.print(minimum->getPertinence());
  Serial.print(", Average-> ");
  Serial.print(average->getPertinence());
  Serial.print(", Maximum-> ");
  Serial.println(maximum->getPertinence());
     //Serial.print("\nOutput: ");
     //Serial.println(output);

  // Alerta se estiver dentro da zona de perigo
  // Dispara os alertas
  
   if(output >0 & output <2){// SE o RIsco de colisão for menor que 2 (risco baixo)
       // a->pisca(); 
            
            a->vibra();
           // a->beeps(); 

            Serial.print("\tVIBRANDO~~~~~~ ");

        }
    
      else

     if((output >=2) & (output < 3) ){// Se o risco de colisão estiver entre 1 e 3 risco medio
            a->beeps(); 
            a->beeps(); 
          //  a->beeps(); 
            //a->vibra();
        Serial.print("\tBEEPS leves.........");
   }
      else
    if((output >=3 ) & (output < 4 ) ){// Se o risco de colisão estiver entre 2 e 4 será risco alto
          //  a->voice();
           // a->vibra();
          ///  a->pisca();
            
            a->beeps();
            a->beeps();
            a->beeps();
            
              Serial.print("\tBEEPS  FORTE >>>>>>");
        }

}



