 
#include <Arduino.h>
#include "Ecran.h"
#include "enum.h"

Ecran ecran;

void setup() {
   Serial.begin(115200);

  Serial.printf("***** Démarrage *****\n");
  
  ecran.init();
  ecran.effacerEcran();
  
}

void loop() {
  ecran.effacerEcran();
  ecran.afficherCentrerNormal("Hello World");
  delay(2500);
  ecran.effacerEcran();
  ecran.afficherCentrerAlerte("Alerte");
  delay(2500);
  ecran.effacerEcran();
  ecran.afficherGaucheL1("GaucheL1");
  delay(2500);
  ecran.effacerEcran();
  ecran.afficherEcranJeu(50,50,50,modeTire::simple,etatArme::attente,0);
delay(2500);
  ecran.effacerEcran();
  ecran.afficherEcranJeu(50,50,50,modeTire::rafale,etatArme::attente,0);
delay(2500);
  ecran.effacerEcran();
  ecran.afficherEcranJeu(50,50,50,modeTire::automatique,etatArme::attente,0);
delay(2500);
  ecran.effacerEcran();
  ecran.afficherEcranJeu(50,50,50,modeTire::rafale,etatArme::chargement,0);
delay(2500);
  ecran.effacerEcran();
  ecran.afficherEcranJeu(50,50,50,modeTire::rafale,etatArme::rechargeChargeur,0);
  delay(2500);
   ecran.effacerEcran();
  ecran.afficherEcranJeu(50,50,50,modeTire::rafale,etatArme::rechargeChargeur,1000);
  delay(2500);
  ecran.effacerEcran();
  ecran.afficherEcranJeu(50,50,50,modeTire::rafale,etatArme::rechargeChargeur,500);
  delay(2500);
  ecran.effacerEcran();
  ecran.afficherEcranJeu(50,50,50,modeTire::rafale,etatArme::rechargeChargeur,50);
  delay(2500);
  ecran.effacerEcran();
  ecran.afficherEcranJeu(50,50,50,modeTire::rafale,etatArme::refroidissement,0);
  delay(2500);
  ecran.effacerEcran();
  ecran.afficherEcranJeu(50,50,50,modeTire::rafale,etatArme::shoot,0);
}