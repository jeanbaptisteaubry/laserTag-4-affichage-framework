#include <Arduino.h>
#include <TFT_eSPI.h>
#include <SPI.h>

#include "eSprite_TDM.h"
#include "eSprite_SHD.h"
#include "eSprite_balleX1.h"
#include "eSprite_balleX3.h"
#include "eSprite_balleX5.h"
#include "eSprite_balleXAuto.h"
#include "eSprite_reload.h" 
#include "enum.h"
#include "InputText.h"

#define _RGB16BIT565(r, g, b) ((b % 32) + ((g % 64) << 6) + ((r % 32) << 11))

class Ecran
{
private:
    eSprite_TDM spr_tdm;
    eSprite_SHD spr_shd;
    eSprite_balleX1 spr_balleX1;
    eSprite_balleX3 spr_balleX3;
    eSprite_balleX5 spr_balleX5;
    eSprite_balleXAuto spr_balleXAuto;
    eSprite_Reload spr_reload;

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
    /**
     * @brief Affichage au centre
     *
     * @param str
     */
    void afficherCentrerNormal(char *str);

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

    /**
     * @brief Une action fait évoluer l'armure et/ou la vie du joueur mais pas l'arme
     *
     * @param armure
     * @param vie
     */
    void afficherEcranJeuArmure(int armure, int vie);

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
    void afficherEcranJeu(int armure, int vie, int munition, modeTire mode, etatArme etat, int tempsRestantReload);

    /**
     * @brief Affichage de la zone Input pour la sélection du SSID
     *
     * @param inpTxt
     */
    void EcranAfficherChoixMdPSSID(InputText inpTxt);
}; 