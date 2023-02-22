#include <Arduino.h>
#include <TFT_eSPI.h>
#include <SPI.h>

#include "sprite.h"
//#include "eSprite_TDM.h"
//#include "eSprite_SHD.h"
//#include "eSprite_balleX1.h"
//#include "eSprite_balleX3.h"
//#include "eSprite_balleX5.h"
//#include "eSprite_balleXAuto.h"
#include "eSprite_reload.h" 
#include "enum.h"
#include "InputText.h"

#define ROTATION 1
#define _RGB16BIT565(r, g, b) ((b % 32) + ((g % 64) << 6) + ((r % 32) << 11))

class Ecran
{
private:
    Sprite_TeteDeMort spr_tdm; //Sprite Tête de mort
    Sprite_Bouclier spr_shd; //Sprite shield => bouclié ou armure
    Sprite_Balle_Par_1 spr_balleX1; //Sprite de balle 1 coup
    Sprite_Balle_Rafale_Par_3 spr_balleX3; //Sprite de balle 3 coups
  //  eSprite_balleX5 spr_balleX5; //Sprite de balle 5 coups
    Sprite_Balle_Vollee spr_balleXAuto; //Sprite de balle automatique
    eSprite_Reload spr_reload; //Sprite de rechargement

    int memoMunition = -1; // Nombre de munition dans le chargeur
    int memoArmure = -1; // Nombre de point d'armure
    int memoVie = -1; // Nombre de point de vie
    modeTire memoModeTir = modeTire::automatique; // Mode de tir
    etatArme memoEtatArme = etatArme::attente; // Etat de l'arme
    int memoScore = -1; // Score du joueur

    void drawValue(int x, int y, int value, int size, uint16_t color);

    int timeLastChgt = -1;
    bool boolTimerChgtEnCours = false;
    etatEcran etatEcranActuel = etatEcran::affichageFull;
    int width =-1;
    int height = -1;
public:
    int lastChange;
    TFT_eSPI ecran;
    int memoRestant = -1; // Temps restant dans le compte à rebour
    int positionScanVeille;
    bool veilleEnCours = false;
    int dureeAvantVeille = 15000; // 5s
    Ecran();
 
    void setChange();

    int lastDrawVeille = 0;
    int dureeDrawVeille = 100;
    void checkVeille();

    uint8_t veilleR;
    uint8_t veilleG;
    uint8_t veilleB;
    uint16_t colorVeilleN;
    uint16_t colorVeilleNm1;
    uint16_t colorVeilleNm2;
    void veille_initColor();

    void drawVeille();

    void init();
    
    void effacerEcran();
    

    void afficherCentrerNormal(char *str, int size);
    /**
     * @brief Affiche la chaine Titre à gauche en première ligne
     *
     * @param str
     */
    void afficherGaucheL1(char *str);

    /**
     * @brief Affichage au centre d'un message d'alerte
     *
     * @param str
     */
    void afficherCentrerAlerte(char *str);

    /**
     * @brief une action de type Arme à mettre en avant
     *
     * @param mode
     * @param etat
     * @param tempsRestantReload
     */
    void afficherEcranJeuArme(int munition, modeTire mode, etatArme etat, int tempsRestantReload);

    void afficherEcranJeuScore(int score);

    /**
     * @brief On vérifie si l'écran doit revenir à l'affichage normal
     *
     * @param munition
     * @param mode
     * @param etat
     * @param tempsRestantReload
     */
    void afficherEcranJeuMAJ();

    /**
     * @brief Une action fait évoluer l'armure et/ou la vie du joueur mais pas l'arme
     *
     * @param armure
     * @param vie
     */
    void afficherEcranJeuArmureVie(int armure, int vie);

    /**
     * @brief Affiche l'écran  de jeu sans activité mise en avant
     *
     * @param armure
     * @param vie
     * @param munition
     * @param mode
     * @param etat
     * @param tempsRestantReload
     */
    void afficherEcranJeu(int armure, int vie, int munition, modeTire mode, etatArme etat, int tempsRestantReload, int score);

    /**
     * @brief Affichage de la zone Input pour la sélection du SSID
     *
     * @param inpTxt
     */
    void EcranAfficherChoixMdPSSID(InputText inpTxt);

    void DrawSprite(int xDest, int yDest,  TFT_eSprite *sprite, uint16_t color, float scale);

    void SetChangeToEcranInGame(int armure, int vie, int munition, modeTire mode, etatArme etat, int tempsRestantReload, int score);
}; 