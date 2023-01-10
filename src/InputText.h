#include <pgmspace.h>
#include <Arduino.h>

#ifndef InputText_H
#define InputText_H


/**
 * @brief Classe permettant de gérer la construction d'une chaine de saisie avec un curseur qui se déplace
 *
 */
class InputText
{
private:
    String possible = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890 <";
    String chaine = "                                                                                     ";
    int positionAct = 0;
    int length = 0;
    int positionPossible = 0;

    int DonnePositionPossible(char charCherche);

public:
    InputText(String texteBase);

    String donneTexte();
    void setTexteBase(String texteBase);

    void CaracterePossibleSuivant();

    void CaracterePossiblePrecedent();

    void CaractereSelectionPrecedent();

     void SupprimerCharAct();

    void CaractereSelectionSuivant();

    String DonneChaineAvantAct();

    char DonneCharAct();

    String DonneChaineApres();
};

#endif