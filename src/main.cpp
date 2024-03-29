
#include <Arduino.h>
#include "Ecran.h"
#include "enum.h"
#include "InputText.h"
#define STATE_INIT 10
Ecran ecran;
InputText inputText("TexteBase");
char ActionInputTexte[] = "NNNNSUUUUUUUUUUNDDDDDN";
int etape = 0;
int memoEtape = -1;
int lastTime = 0;

void setup()
{
  Serial.begin(115200);
  Serial.printf("STATE_INIT : %d\n", STATE_INIT);
  ecran.init();
  ecran.effacerEcran();

  switch (STATE_INIT)
  {
  case 0: // Pour tester les écrans dans le temps (on passe à l'étape suivante toutes les 5 secondes)
    // Chaque étape doit être composée de 2 écrans : un sur l'action en cours et un global
    Serial.printf("***** Démarrage *****\n");
    Serial.printf("Etape : %d\n", etape);

    break;
  case 2:
    ecran.afficherEcranJeuArmureVie(50, 50);
    break;
  case 3:
    ecran.afficherEcranJeuArme(50, modeTire::simple, etatArme::attente, 0);

    break;
  case 4:
    ecran.afficherEcranJeuArme(50, modeTire::rafale, etatArme::attente, 0);

    break;
  case 5:
    ecran.afficherEcranJeuArme(50, modeTire::automatique, etatArme::attente, 0);

    break;

  case 6:
    ecran.afficherEcranJeuArme(50, modeTire::automatique, etatArme::rechargeChargeur, 10);

    break;
  case 7:
    ecran.afficherEcranJeu(50, 50, 50, modeTire::automatique, etatArme::rechargeChargeur, 10, 1);

    break;
  case 8:
    ecran.afficherEcranJeu(40, 50, 60, modeTire::automatique, etatArme::attente, 10, 1);

    break;
  case 9: // Pour tester l'affichage des sprites, il est arrivé que l'affichage était douteux, juste à cause du sprite...
    ecran.AfficherImageTest(1);
    Serial.printf("***** Démarrage 9 *****\n");
    break;
  case 10: // On va tester les inputs
    break;
  }
}
bool ecranAfficherEtape = false;
int size = 1;
void loop()
{

  switch (STATE_INIT)
  {
  case 10:
    if (millis() - lastTime > 6000)
    {
      lastTime = millis();
      etape++;
      if (etape > strlen(ActionInputTexte) - 1)
        etape = 0;
      Serial.printf("Etape : %d\n Lettre %c\n", etape, ActionInputTexte[etape]);
      ecranAfficherEtape = false;
    }
    // On fait une animation de test
    if (millis() - lastTime < 1000)
    {
      if (ecranAfficherEtape == false)
      {
        ecranAfficherEtape = true;
        ecran.effacerEcran();
        char str[25];
        sprintf(str, "Etape : %d\n Lettre %c\n", etape, ActionInputTexte[etape]);
        ecran.afficherCentrerNormal(str, 1);
      }
    }
    else
    {
      if (memoEtape != etape)
      {

        switch (ActionInputTexte[etape])
        {
        case 'U':
          inputText.CaracterePossibleSuivant();
          break;
        case 'D':
          inputText.CaracterePossiblePrecedent();
          break;
        case 'P':
          inputText.CaractereSelectionPrecedent();
          break;
        case 'S':
          inputText.SupprimerCharAct();
          break;
        case 'N':
          inputText.CaractereSelectionSuivant();
          break;
        }
        ecran.EcranAfficherChoixMdPSSID(inputText);
      }
       memoEtape = etape;
    }
   
    break;

  case 1:
    if (millis() - lastTime > 1000)
    {
      lastTime = millis();
      ecran.effacerEcran();
      // ecran.afficherEcranJeuArmureVie(50, 50);
      if (size < 6)
        size++;
      else
        size = 1;
      ecran.afficherCentrerNormal("Test", size);
    }
    break;

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
        ecran.afficherCentrerNormal(str, 2);
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
        ecran.SetChangeToEcranInGame(50, 50, 30, modeTire::rafale, etatArme::attente, 0, 1);
        break;

      case 3:
        // On change le mode de tir en automatique
        ecran.SetChangeToEcranInGame(50, 50, 20, modeTire::automatique, etatArme::attente, 0, 1);
        break;

      case 4:
        // On recharge le chargeur
        ecran.SetChangeToEcranInGame(50, 50, 20, modeTire::automatique, etatArme::rechargeChargeur, 0, 1);
        break;

      case 5:
        // On se fait toucher dans l'armure
        ecran.SetChangeToEcranInGame(20, 50, 20, modeTire::automatique, etatArme::rechargeChargeur, 0, 1);
        break;

      case 6:
        // On se fait toucher dans la vie
        ecran.SetChangeToEcranInGame(20, 20, 20, modeTire::automatique, etatArme::rechargeChargeur, 0, 1);
        break;
      }
    memoEtape = etape;
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
}