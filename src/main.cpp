
#include <Arduino.h>
#include "Ecran.h"
#include "enum.h"

Ecran ecran;

void setup()
{
  Serial.begin(115200);

  Serial.printf("***** Démarrage *****\n");

  ecran.init();
  ecran.effacerEcran();

  ecran.afficherEcranJeuArmureVie(50, 50);
}

int etape = 0;
int lastTime = 0;
void loop()
{
  //On fait une animation de test
  if (millis() - lastTime > 5000)
  {
    lastTime = millis();
    etape++;
    if (etape > 6)
      etape = 0;
  }
  switch (etape)
  {
    case 0:
      //Base
      ecran.SetChangeToEcranInGame(50,50,50,modeTire::simple,etatArme::attente,0,1);
    break;
      
    case 1:
      //On tire avec une arme simple 20 shoots
      ecran.SetChangeToEcranInGame(50,50,30,modeTire::simple,etatArme::attente,0,1);

    break;
      
    case 2:
      //On change le mode de tir en rafale
      ecran.SetChangeToEcranInGame(50,50,30,modeTire::rafale,etatArme::attente,0,1);
    break;

    case 3:
      //On change le mode de tir en automatique
      ecran.SetChangeToEcranInGame(50,50,20,modeTire::automatique,etatArme::attente,0,1);
    break;

    case 4:
      //On recharge le chargeur
      ecran.SetChangeToEcranInGame(50,50,20,modeTire::automatique,etatArme::rechargeChargeur,0,1);
    case 5:
      //On se fait toucher dans l'armure
      ecran.SetChangeToEcranInGame(20,50,20,modeTire::automatique,etatArme::rechargeChargeur,0,1);
    case 6:
      //On se fait toucher dans la vie
      ecran.SetChangeToEcranInGame(20,20,20,modeTire::automatique,etatArme::rechargeChargeur,0,1);
  }
  ecran.afficherEcranJeuMAJ();

  // ecran.effacerEcran();
  /*ecran.afficherCentrerNormal("Hello World");
  delay(2500);
  ecran.effacerEcran();
  ecran.afficherCentrerAlerte("Alerte");
  delay(2500);
  ecran.effacerEcran();
  ecran.afficherGaucheL1("GaucheL1");
  delay(2500);
  ecran.effacerEcran();
  */
  /*ecran.afficherEcranJeu(50, 50, 50, modeTire::simple, etatArme::attente, 0);
  delay(2500);
  ecran.effacerEcran();
  ecran.afficherEcranJeu(50, 50, 50, modeTire::rafale, etatArme::attente, 0);
  delay(2500);
  ecran.effacerEcran();
  ecran.afficherEcranJeu(50, 50, 50, modeTire::automatique, etatArme::attente, 0);
  delay(2500);
  ecran.effacerEcran();
  ecran.afficherEcranJeu(50, 50, 50, modeTire::rafale, etatArme::chargement, 0);*/

  /*
   delay(2500);
   ecran.effacerEcran();
   ecran.afficherEcranJeu(50, 50, 50, modeTire::rafale, etatArme::rechargeChargeur, 1000);
   delay(2500);
   ecran.effacerEcran();
   ecran.afficherEcranJeu(50, 50, 50, modeTire::rafale, etatArme::rechargeChargeur, 500);
    delay(2500);
   ecran.effacerEcran();
   ecran.afficherEcranJeu(50, 50, 50, modeTire::rafale, etatArme::rechargeChargeur, 99);

   delay(2500);
   ecran.effacerEcran();
   ecran.afficherEcranJeu(50, 50, 50, modeTire::rafale, etatArme::rechargeChargeur, 50);
    delay(2500);
   ecran.effacerEcran();
   ecran.afficherEcranJeu(50, 50, 50, modeTire::rafale, etatArme::rechargeChargeur, 0);

   delay(2500);
   ecran.effacerEcran();
   ecran.afficherEcranJeu(50, 50, 50, modeTire::rafale, etatArme::refroidissement, 0);
   delay(2500);
   ecran.effacerEcran();
   ecran.afficherEcranJeu(50, 50, 50, modeTire::rafale, etatArme::shoot, 0);
   */
}