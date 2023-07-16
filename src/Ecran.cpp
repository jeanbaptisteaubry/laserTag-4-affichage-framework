#include <Arduino.h>
#include <TFT_eSPI.h>
#include <SPI.h>

#include "enum.h"
#include "InputText.h"
#include "Ecran.h"
// #include <Fonts/GFXFF/FreeSans9pt7b.h>

Ecran::Ecran() : ecran(),
                spr_test1Ligne(&ecran),
                 spr_test2Lignes(&ecran),
                 spr_test3Lignes(&ecran),
                 spr_tdm(&ecran),
                 spr_shd(&ecran),
                 spr_balleX1(&ecran),
                 spr_balleX3(&ecran),
                 spr_balleXAuto(&ecran),
                 spr_reload(&ecran),
                 spr_cible(&ecran)
                 
{
    spr_test1Ligne.init();
    spr_test2Lignes.init();
    spr_test3Lignes.init();
    spr_tdm.init();
    spr_shd.init();
    spr_balleX1.init();
    spr_balleX3.init();
    spr_balleXAuto.init();
    spr_reload.init();
    spr_cible.init();
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
    if (ROTATION)
    { // réglage de l'écran en mode paysage (0 pour mode portrait)
        ecran.setFreeFont(&FreeSans9pt7b);
        ecran.setRotation(1);
        width = TFT_HEIGHT;
        height = TFT_WIDTH;
    }
    else
    {
        ecran.setRotation(0);
        width = TFT_WIDTH;
        height = TFT_HEIGHT;
    }

    ecran.fillScreen(TFT_BLACK);
    ecran.setTextColor(TFT_WHITE);
    // Charge depuis un fichier
    if (!SPIFFS.begin(true))
    {
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
    }


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
/*void Ecran::afficherCentrerNormal(char *str)
{
    ecran.setTextColor(TFT_WHITE);
    ecran.drawCentreString(str, width / 2,  height / 2, 2);
    setChange();
}*/

void Ecran::afficherCentrerNormal(char *str, int taille = 1)
{
    ecran.setTextSize(taille);

    ecran.setTextColor(TFT_WHITE);

    /* ecran.setCursor(width / 2 - ecran.textsize * strlen(str) / 2, height / 2 - ecran.fontHeight() / 2);
     ecran.print(str);*/
    ecran.drawCentreString(str, width / 2, height / 2 - ecran.fontHeight() / 3, 2);
    setChange();
}

/**
 * @brief affiche une valeur sur l'écran, centrée aux coordonnées indiquées
 */
void Ecran::drawValue(int value, int x, int y, int size, uint16_t color)
{

    char str[3];
    if (value <= 9)
        sprintf(str, "0%d", value);
    else if (value <= 99)
        sprintf(str, "%d", value);
    else
        sprintf(str, "++");
    ecran.setTextSize(size);
    ecran.setTextColor(color);
    ecran.drawCentreString(str, x, y - ecran.fontHeight() / 3, 2);

    ecran.setTextColor(TFT_WHITE);
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
    ecran.drawCentreString(str, width / 2, height / 2, 2);
    ecran.setTextColor(TFT_WHITE);
    setChange();
}

/**
 * @brief une action de type Arme à mettre en avant, 1 icone, 1 texte
 *
 * @param mode
 * @param etat
 * @param tempsRestantReload
 */
void Ecran::afficherEcranJeuArme(int munition, modeTire mode, etatArme etat, int tempsRestantReload)
{
    Serial.printf("afficherEcranJeuArme 2s\n");
    effacerEcran();
    setChange();
    int deltaX = 0;
    int deltaY = 0;
    float coeff = 1.5f;
    if (etat != rechargeChargeur)
    {
        switch (mode)
        {
        case simple:
            deltaX = (width / 2 - spr_balleX1.width() * coeff) / 2;
            deltaY = (height / 2 - spr_balleX1.height() * coeff) / 2;
            DrawSprite(deltaX, deltaY + (height - spr_balleX1.height() * coeff) / 2, &spr_balleX1, TFT_WHITE, coeff);

            Serial.println("Simple");
            break;
        case rafale:
            deltaX = (width / 2 - spr_balleX3.width() * coeff) / 2;
            deltaY = (height / 2 - spr_balleX3.height() * coeff) / 2;
            DrawSprite(deltaX, deltaY + (height - spr_balleX3.height() * coeff) / 2, &spr_balleX3, TFT_WHITE, coeff);

            Serial.println("Rafale");
            break;
        case automatique:
            deltaX = (width / 2 - spr_balleXAuto.width() * coeff) / 2;
            deltaY = (height / 2 - spr_balleXAuto.height() * coeff) / 2;
            DrawSprite(deltaX, deltaY + (height - spr_balleXAuto.height() * coeff) / 2, &spr_balleXAuto, TFT_WHITE, coeff);

            Serial.println("Automatique");
            break;
        }
        drawValue(munition, (3 * width) / 4, height / 2, 5, TFT_WHITE);
    }
    else
    {
        // Changement de temps
        deltaX = (width / 2 - spr_reload.width() * coeff) / 2;
        deltaY = (height / 2 - spr_reload.height() * coeff) / 2;
        DrawSprite(deltaX, deltaY + (height - spr_reload.height() * coeff) / 2, &spr_reload, TFT_WHITE, coeff);

        drawValue(tempsRestantReload, (3 * width) / 4, height / 2, 5, TFT_RED);
        Serial.printf("Reload %d\n", tempsRestantReload);
    }
}

void Ecran::DrawSprite(int xDest, int yDest, TFT_eSprite *sprite, uint16_t color, float scale)
{

    if (scale != 1.0f)
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
    else
    {
        sprite->pushSprite(xDest, yDest);
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
    float coeff = 1.5f;
    Serial.printf("afficherEcranJeuArmureVie 2s %d %d \n", armure, vie);
    effacerEcran();
    setChange();

    int deltaX = (width / 2 - spr_shd.width() * coeff) / 2;
    int deltaY = (height / 2 - spr_shd.height() * coeff) / 2;
    int deltaY2 = (height / 2 - spr_tdm.height() * coeff) / 2;
    DrawSprite(deltaX, deltaY, &spr_shd, TFT_WHITE, coeff);
    DrawSprite(deltaX, height / 2 + deltaY2, &spr_tdm, TFT_WHITE, coeff);

    drawValue(armure, width * 3 / 4, spr_shd.height() * coeff / 2 + deltaY, 4, TFT_WHITE);
    drawValue(vie, width * 3 / 4, spr_tdm.height() * coeff / 2 + height / 2 + deltaY2, 4, TFT_WHITE);
    // drawValue(armure, spr_shd.width()*1.5f + (width / 2 -  spr_shd.width()*1.5f )/2, height / 2, 5, TFT_WHITE);
    //  drawValue(vie,spr_tdm.width()*1.5f + width / 2 + (width / 2 -  spr_tdm.width()*1.5f )/2, height / 2, 5, TFT_WHITE);
}


void Ecran::AfficherImageTest(int nbLigne)
{
    effacerEcran();
    setChange();
    //DrawSprite (0,0, &spr_test1Ligne, TFT_WHITE, 1.0f);
    spr_tdm.pushSprite(0,0);
    spr_shd.pushSprite(32,0);
    spr_balleX1.pushSprite(64,0);

    spr_balleX3.pushSprite(0,32);
    spr_balleXAuto.pushSprite(32,32);
    spr_reload.pushSprite(64,32);

    spr_test1Ligne.pushSprite(0,64);
    spr_test2Lignes.pushSprite(32,64);
    spr_test3Lignes.pushSprite(64,64);
/*
    spr_balleX1.pushSprite(0,128);
    spr_balleX3.pushSprite(32,128);
    spr_balleXAuto.pushSprite(64,128);*/
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
    int deltaY = (height - spr_tdm.height() - spr_shd.height()) / 3;

    spr_tdm.pushSprite(0, deltaY);
    drawValue(armure, width / 4 + spr_tdm.width() / 2, spr_tdm.height() / 2 + deltaY, 2, TFT_WHITE);

    spr_shd.pushSprite(0, height / 2 + deltaY / 2);
    drawValue(vie, width / 4 + spr_shd.width() / 2, spr_shd.height() / 2 + height / 2 + deltaY / 2, 2, TFT_WHITE);

    if (etat != rechargeChargeur)
    {
        Serial.printf("afficherEcranJeu 5s changement mode arme\n");
        switch (mode)
        {
        case simple:
            spr_balleX1.pushSprite(width / 2, +deltaY);
            Serial.println("Simple");
            break;
        case rafale:
            spr_balleX3.pushSprite(width / 2, +deltaY);
            Serial.println("Rafale");
            break;
        case automatique:
            spr_balleXAuto.pushSprite(width / 2, +deltaY);
            Serial.println("Automatique");
            break;
        }

        if (munition < 10)
            drawValue(munition, 3 * width / 4 + spr_balleXAuto.width() / 2, spr_balleXAuto.height() / 2 + deltaY, 2, TFT_RED);
        else
            drawValue(munition, 3 * width / 4 + spr_balleXAuto.width() / 2, spr_balleXAuto.height() / 2 + deltaY, 2, TFT_WHITE);
    }
    else
    {
        spr_reload.pushSprite(width / 2, +deltaY);

        drawValue(tempsRestantReload, 3 * width / 4 + spr_balleXAuto.width() / 2, spr_balleXAuto.height() / 2 + deltaY, 2, TFT_RED);
        Serial.printf("afficherEcranJeu 5s Reload %d\n", tempsRestantReload);
        setChange();
    }

    // Il faut afficher le score en bas à droite
    // TODO : Manque le sprite
    spr_cible.pushSprite(width / 2, height / 2  +deltaY);
    drawValue(score, 3 * width / 4 + spr_balleXAuto.width() / 2, spr_balleXAuto.height() / 2 + height / 2 + deltaY / 2, 2, TFT_WHITE);
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
    Serial.printf("afficherEcranJeuScore 2s\n");
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
        Serial.printf("SetChangeToEcranInGame 2s\n");
        // Calcul du nombre de changements
        int nbChgt = 0;
        if (armure != memoArmure || vie != memoVie)
            nbChgt++;

        if (munition != memoMunition || etatArme != memoEtatArme || tempsRestantReload != memoRestant || modeTir != memoModeTir)
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
