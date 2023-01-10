#include <Arduino.h>
#include <TFT_eSPI.h>
#include <SPI.h>

#include "enum.h"
#include "InputText.h"
#include "Ecran.h"

Ecran::Ecran() : ecran(),
                 spr_tdm(&ecran),
                 spr_shd(&ecran),
                 spr_balleX1(&ecran),
                 spr_balleX3(&ecran),
                 spr_balleX5(&ecran),
                 spr_balleXAuto(&ecran),
                 spr_reload(&ecran)
{
}

/**
 * @brief Récommence le compteur pour l'écran de veille
 *
 */
void Ecran::setChange()
{
    lastChange = millis();
    veilleEnCours = false;
}

void Ecran::checkVeille()
{
    if (veilleEnCours == false)
        if (millis() - lastChange >= dureeAvantVeille)
        {
            veilleEnCours = true;
            positionScanVeille = 0;
            lastDrawVeille = millis();
            Serial.println("Veille en cours");
        }
}

void Ecran::veille_initColor()
{
    veilleR = random(2, 255);
    veilleG = random(2, 255);
    veilleB = random(2, 255);
    colorVeilleN = ecran.color565(veilleR, veilleG, veilleB);
    colorVeilleNm1 = ecran.color565(veilleR - 1, veilleG - 1, veilleB - 1);
    colorVeilleNm2 = ecran.color565(veilleR - 2, veilleG - 2, veilleB - 2);
    Serial.printf("%d %d %d \n", colorVeilleN, colorVeilleNm1, colorVeilleNm2);
}

void Ecran::drawVeille()
{
    if (veilleEnCours && millis() - lastDrawVeille >= dureeDrawVeille)
    {
        lastDrawVeille = millis();
        // Serial.printf("Position %d\n", positionScanVeille);
        switch (positionScanVeille)
        {

        case 0:
            veille_initColor();
            effacerEcran();
            ecran.drawLine(0, 0, 0, 80, colorVeilleN);
            positionScanVeille++;
            break;
        case 1:
            ecran.drawLine(0, 0, 80, 0, colorVeilleNm1);
            ecran.drawLine(1, 0, 1, 80, colorVeilleN);
            positionScanVeille++;
            break;
        case 182:
            veille_initColor();
            ecran.drawLine(0, 0, 0, 80, colorVeilleN);
            positionScanVeille = 1;
            break;
        default:
            ecran.drawLine(positionScanVeille - 2, 0, positionScanVeille - 2, 80, colorVeilleNm2);
            ecran.drawLine(positionScanVeille - 1, 0, positionScanVeille - 1, 80, colorVeilleNm1);
            ecran.drawLine(positionScanVeille, 0, positionScanVeille, 80, colorVeilleN);
            positionScanVeille++;
            break;
        }
    }
}

void Ecran::init()
{
    ecran.init();
    ecran.setRotation(1); // réglage de l'écran en mode paysage (0 pour mode portrait)
    ecran.fillScreen(TFT_BLACK);
    ecran.setTextColor(TFT_WHITE);
    // Charge depuis un fichier
    if (!SPIFFS.begin(true))
    {
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
    }

    spr_tdm.init();
    spr_shd.init();
    spr_balleX1.init();
    spr_balleX3.init();
    spr_balleX5.init();
    spr_balleXAuto.init();
    spr_reload.init();
}

void Ecran::effacerEcran()
{
    ecran.fillScreen(TFT_BLACK);
    // setChange();
}
/**
 * @brief Affichage au centre
 *
 * @param str
 */
void Ecran::afficherCentrerNormal(char *str)
{
    ecran.setTextColor(TFT_WHITE);
    ecran.drawCentreString(str, 80, 40, 2);
    setChange();
}

/**
 * @brief Affiche la chaine Titre à gauche en première ligne
 *
 * @param str
 */
void Ecran::afficherGaucheL1(char *str)
{
    ecran.setTextColor(TFT_WHITE);
    ecran.drawString(str, 0, 10, 2);
    setChange();
}

/**
 * @brief Affichage au centre d'un message d'alerte
 *
 * @param str
 */
void Ecran::afficherCentrerAlerte(char *str)
{
    ecran.setTextColor(TFT_RED);
    ecran.drawCentreString(str, 80, 40, 2);
    setChange();
}

/**
 * @brief une action de type Arme à mettre en avant
 *
 * @param mode
 * @param etat
 * @param tempsRestantReload
 */
void Ecran::afficherEcranJeuArme(int munition, modeTire mode, etatArme etat, int tempsRestantReload)
{
    if (etat != rechargeChargeur)
    {
        effacerEcran();
        setChange();

        switch (mode)
        {
        case simple:
            spr_balleX1.pushSprite(0, 20);
            Serial.println("Simple");
            break;
        case rafale:
            spr_balleX3.pushSprite(0, 20);
            Serial.println("Rafale");
            break;
        case automatique:
            spr_balleXAuto.pushSprite(0, 20);
            Serial.println("Automatique");
            break;
        }

        char str[4];
        if (munition <= 9)
            sprintf(str, "0%d\n", munition);
        else if (munition <= 99)
            sprintf(str, "%d\n", munition);
        else
            sprintf(str, "++\n");
        // Sprite spr = new Sprite
        // ecran.pushImage

        ecran.drawCentreString(str, 120, 20, 6);
    }
    else
    {

        // Changement de temps
        effacerEcran();
        setChange();

        memoRestant = tempsRestantReload;
        spr_reload.pushSprite(0, 20);
        char str[4];
        sprintf(str, "%d\n", tempsRestantReload);
        // Sprite spr = new Sprite
        // ecran.pushImage
        ecran.setTextColor(TFT_RED);
        ecran.drawCentreString(str, 120, 20, 6);
        ecran.setTextColor(TFT_WHITE);
        Serial.printf("Reload %d\n", tempsRestantReload);
    }
}

void Ecran::DrawSprite(int xDest, int yDest, TFT_eSprite *sprite, uint16_t color, float scale)
{
    int width = sprite->width();
    int height = sprite->height();

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            uint16_t pixel = sprite->readPixel(x, y);
            if (pixel != TFT_TRANSPARENT)
            {
                for (int xScale = (int)(x * scale); xScale < (int)((x + 1) * scale); xScale++)
                {
                    for (int yScale = (int)(y * scale); yScale < (int)((y + 1) * scale); yScale++)
                    {
                        ecran.drawPixel(xDest + xScale, yDest + yScale, pixel);
                    }
                }
            }
        }
    }
}

/**
 * @brief Une action fait évoluer l'armure et/ou la vie du joueur mais pas l'arme
 *
 * @param armure
 * @param vie
 */
void Ecran::afficherEcranJeuArmureVie(int armure, int vie)
{

    memoArmure = armure;
    memoVie = vie;
    effacerEcran();
    setChange();

    DrawSprite(20, 0, &spr_shd, TFT_WHITE, 1.5f);
    DrawSprite(100, 0, &spr_tdm, TFT_WHITE, 1.5f);
    drawValue(armure, 50, 70, 5, TFT_WHITE);
    drawValue(vie, 130, 70, 5, TFT_WHITE);
}

void Ecran::drawValue(int value, int x, int y, int size, uint16_t color)
{
    ecran.setTextColor(color);
    char str[6];
    if (value <= 9)
        sprintf(str, "0%d\n", value);
    else if (value <= 99)
        sprintf(str, "%d\n", value);
    else
        sprintf(str, "++\n");

    ecran.drawCentreString(str, x, y, size);
    ecran.setTextColor(TFT_WHITE);
}

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
void Ecran::afficherEcranJeu(int armure, int vie, int munition, modeTire mode, etatArme etat, int tempsRestantReload, int score)
{

    effacerEcran();
    setChange();
    spr_tdm.pushSprite(0, 0);
    drawValue(armure, 52, 10, 4, TFT_WHITE);

    spr_shd.pushSprite(0, 40);
    drawValue(vie, 52, 50, 4, TFT_WHITE);

    if (etat != rechargeChargeur)
    {

        switch (mode)
        {
        case simple:
            spr_balleX1.pushSprite(80, 0);
            Serial.println("Simple");
            break;
        case rafale:
            spr_balleX3.pushSprite(80, 0);
            Serial.println("Rafale");
            break;
        case automatique:
            spr_balleXAuto.pushSprite(80, 0);
            Serial.println("Automatique");
            break;
        }

        drawValue(munition, 135, 10, 4, TFT_WHITE);
    }
    else
    {
        spr_reload.pushSprite(80, 0);

        drawValue(tempsRestantReload, 135, 10, 4, TFT_RED);

        Serial.printf("Reload %d\n", tempsRestantReload);
        setChange();
    }

    // Il faut afficher le score en bas à droite
    // TODO : Manque le sprite
    drawValue(score, 135, 40, 4, TFT_WHITE);
}

/**
 * @brief Affichage de la zone Input pour la sélection du SSID
 *
 * @param inpTxt
 */
void Ecran::EcranAfficherChoixMdPSSID(InputText inpTxt)
{
    effacerEcran();
    setChange();
    afficherGaucheL1("Mot de passe");

    // Affichage en rouge du caractère en cours :
    ecran.setTextColor(TFT_RED);
    char strTmp[5];
    sprintf(strTmp, "%c\n", inpTxt.DonneCharAct());
    ecran.drawCentreString(strTmp, 80, 40, 2);
    ecran.setTextColor(TFT_WHITE);
    ecran.drawRightString(String(inpTxt.DonneChaineAvantAct().c_str()), 70, 40, 2);
    ecran.drawString(String(inpTxt.DonneChaineApres().c_str()), 85, 40, 2);
    Serial.printf("EcranAfficherChoixMdPSSID : %s %c %s \n %s\n", inpTxt.DonneChaineAvantAct().c_str(), inpTxt.DonneCharAct(), inpTxt.DonneChaineApres().c_str(), inpTxt.donneTexte().c_str());
}

void Ecran::afficherEcranJeuScore(int score)
{
    memoScore = score;
    effacerEcran();
    setChange();
    spr_tdm.pushSprite(0, 0);
    drawValue(score, 135, 40, 4, TFT_WHITE);
}

void Ecran::SetChangeToEcranInGame(int armure, int vie, int munition, modeTire modeTir, etatArme etatArme, int tempsRestantReload, int score)
{
    if (armure != memoArmure || vie != memoVie || munition != memoMunition || modeTir != memoModeTir || etatArme != memoEtatArme || tempsRestantReload != memoRestant || score != memoScore)
    {
        // Calcul du nombre de changements
        int nbChgt = 0;
        if (armure != memoArmure)
            nbChgt++;
        if (vie != memoVie)
            nbChgt++;
        if (munition != memoMunition)
            nbChgt++;
        if (modeTir != memoModeTir)
            nbChgt++;
        if (etatArme != memoEtatArme)
            nbChgt++;
        if (tempsRestantReload != memoRestant)
            nbChgt++;
        if (score != memoScore)
            nbChgt++;

        if (nbChgt > 1 || millis() - timeLastChgt < 2000)
        {
            // On a plusieurs changements en même temps ou on a changé il y a moins de 2 secondes
            // On va donc tout afficher pour que l'utilisateur puisse voir les changements
            afficherEcranJeu(armure, vie, munition, modeTir, etatArme, tempsRestantReload, score);
            etatEcranActuel = etatEcran::affichageFull;
            boolTimerChgtEnCours = false;
        }
        else
        {
            // On a un seul changement, on va donc afficher uniquement ce qui a changé
            if (armure != memoArmure || vie != memoVie)
            {
                afficherEcranJeuArmureVie(armure, vie);
                etatEcranActuel = etatEcran::affichageArmure;
            }
            else if (munition != memoMunition || modeTir != memoModeTir || etatArme != memoEtatArme || tempsRestantReload != memoRestant)
            {
                afficherEcranJeuArme(munition, modeTir, etatArme, tempsRestantReload);
                etatEcranActuel = etatEcran::affichageArme;
            }
            else
            {
                // Il ne reste que le score qui peut avoir changé
                afficherEcranJeuScore(score);
                etatEcranActuel = etatEcran::affichageScore;
            }
            boolTimerChgtEnCours = true;
        }

        setChange();

        timeLastChgt = millis();

        // Il faut détecter ce qui a changé pour propose un affichage adapté
        // On peut avoir plusieurs changements en même temps

        memoArmure = armure;
        memoVie = vie;
        memoMunition = munition;
        memoModeTir = modeTir;
        memoEtatArme = etatArme;
        memoRestant = tempsRestantReload;
        memoScore = score;
        }
}

void Ecran::afficherEcranJeuMAJ()
{
    if (boolTimerChgtEnCours)
    {
        if (timeLastChgt + 2000 < millis())
        {
            // On a plus de 2 secondes sans changement, on affiche l'écran de jeu
            afficherEcranJeu(memoArmure, memoVie, memoMunition, memoModeTir, memoEtatArme, memoRestant, memoScore);
            etatEcranActuel = etatEcran::affichageFull;
            boolTimerChgtEnCours = false;
        }
    }
}
