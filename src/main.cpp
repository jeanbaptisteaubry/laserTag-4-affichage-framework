
#include <Arduino.h>
#include "Ecran.h"
#include "enum.h"
#define STATE_INIT 1
Ecran ecran;
int etape = 0;
int memoEtape = -1;
int lastTime = 0;

void setup()
{
  Serial.begin(115200);
  ecran.init();
  ecran.effacerEcran();
  switch (STATE_INIT)
  {
  case 0:
    Serial.printf("***** Démarrage *****\n");
    Serial.printf("Etape : %d\n", etape);

   
    break;
  case 1:
    ecran.afficherEcranJeuArmureVie(50, 50);
    break;
  }
}
bool ecranAfficherEtape = false;
void loop()
{

  switch (STATE_INIT)
  {
  case 0:

    if (millis() - lastTime > 6000)
    {
      lastTime = millis();
      etape++;
      if (etape > 6)
        etape = 0;
      Serial.printf("Etape : %d\n", etape);
      ecranAfficherEtape = false;
    }

    // On fait une animation de test
    if (millis() - lastTime < 1000)
    {
      if (ecranAfficherEtape == false)
      {
        ecranAfficherEtape = true;
        ecran.effacerEcran();
        char str[20];
        sprintf(str, "Etape : %d", etape);
        ecran.afficherCentrerNormal(str);
      }
    }
    else
      switch (etape)
      {
      case 0:
        // Base
        if (memoEtape != etape)
          Serial.println("Attendu : intialisation");

        ecran.SetChangeToEcranInGame(50, 50, 50, modeTire::simple, etatArme::attente, 0, 1);
        break;

      case 1:
        // On tire avec une arme simple 20 shoots
        if (memoEtape != etape)
          Serial.println("Attendu changement munition donc, 5s et 2s");
        ecran.SetChangeToEcranInGame(50, 50, 30, modeTire::simple, etatArme::attente, 0, 1);

        break;

      case 2:
        // On change le mode de tir en rafale
        if (memoEtape != etape)
          Serial.println("Attendu changement mode de tir : rafale, 5s et 2s");
        ecran.SetChangeToEcranInGame(50, 50, 30, modeTire::rafale, etatArme::attente, 0, 1);
        break;

      case 3:
        // On change le mode de tir en automatique
        if (memoEtape != etape)
          Serial.println("Attendu changement mode de tir : automatique, 5s et 2s");
        ecran.SetChangeToEcranInGame(50, 50, 30, modeTire::automatique, etatArme::attente, 0, 1);
        break;

      case 4:
        // On recharge le chargeur
        if (memoEtape != etape)
          Serial.println("Attendu changement rechargement : automatique, 5s et 2s");
        ecran.SetChangeToEcranInGame(50, 50, 20, modeTire::automatique, etatArme::rechargeChargeur, 20, 1);
        break;
      case 5:
        // On se fait toucher dans l'armure
        if (memoEtape != etape)
          Serial.println("Attendu touché dans l'armure, 50 au lieu de 20 : 5s et 2s");
        ecran.SetChangeToEcranInGame(20, 50, 20, modeTire::automatique, etatArme::rechargeChargeur, 0, 1);
        break;
      case 6:
        // On se fait toucher dans la vie
        if (memoEtape != etape)
          Serial.println("Attendu touché dans la vie, 50 au lieu de 20 : 5s et 2s");
        ecran.SetChangeToEcranInGame(20, 20, 20, modeTire::automatique, etatArme::rechargeChargeur, 0, 1);
        break;
      }
    ecran.afficherEcranJeuMAJ();
    memoEtape = etape;
    break;
  }

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