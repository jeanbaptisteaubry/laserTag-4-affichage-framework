
#include <pgmspace.h>
#include <Arduino.h>
#include "InputText.h"
/**
 * @brief Classe permettant de gérer la construction d'une chaine de saisie avec un curseur qui se déplace
 *
 */
 

    int InputText::DonnePositionPossible(char charCherche)
    {
        for (int i = 0; i < possible.length(); i++)
        {
            if (possible[i] == charCherche)
                return i;
        }
        return -1;
    }

 
    InputText::InputText(String texteBase) : chaine(texteBase)
    {

        positionAct = 0;
        length = chaine.length();
        Serial.printf("texteBase : %s \n", texteBase);
    }

    String InputText::donneTexte()
    {
        return chaine;
    }
    void InputText::setTexteBase(String texteBase)
    {
        Serial.printf("setTexteBase texteBase %s\n", texteBase.c_str());
        if (texteBase.compareTo("") == 0)
        {
            chaine = String("A");
            positionPossible = 0;
        }
        else
        {

            chaine = String(texteBase);
        }
        positionAct = 0;
        positionPossible = DonnePositionPossible(chaine[0]);

        length = chaine.length();

        Serial.printf("setTexteBase chaine %s\n", chaine.c_str());
    }

    void InputText::CaracterePossibleSuivant()
    {
        if (positionPossible < possible.length() - 1)
            positionPossible++;
        else
            positionPossible = 0;

        chaine[positionAct] = possible[positionPossible];
    }

    void InputText::CaracterePossiblePrecedent()
    {
        if (positionPossible > 0)
            positionPossible--;
        else
            positionPossible = possible.length() - 1;

        chaine[positionAct] = possible[positionPossible];
    }

    void InputText::CaractereSelectionPrecedent()
    {
        if (positionAct > 0)
            positionAct--;
        else
            positionAct = chaine.length() - 1;
        positionPossible = DonnePositionPossible(chaine[positionAct]);
    }

     void InputText::SupprimerCharAct()
    {
        char strTmp[500];
        sprintf(strTmp,"%s%s", DonneChaineAvantAct().c_str(),DonneChaineApres().c_str());
        chaine = String(strTmp);
         
    
        if (positionAct >= chaine.length())
            positionAct=chaine.length()-1;
    }

    void InputText::CaractereSelectionSuivant()
    {

        if (positionAct < chaine.length() - 1)
        {
            positionAct++;
            positionPossible = DonnePositionPossible(chaine[positionAct]);
        }
        if (positionAct == chaine.length() - 1)
        {
            // on est en bout de chaine...
            Serial.printf("avant add : %s\n", chaine);
            chaine = String (chaine + possible[positionPossible]);
            Serial.printf("après add : %s\n", chaine);
            positionAct++;
        }
    }

    String InputText::DonneChaineAvantAct()
    {
        return chaine.substring(0, positionAct);
    }

    char InputText::DonneCharAct()
    {
        return chaine[positionAct];
    }

    String InputText::DonneChaineApres()
    {
        if (chaine.length() - positionAct <= 1)
            return "";
        return chaine.substring(positionAct + 1, chaine.length() );
    }
 
 