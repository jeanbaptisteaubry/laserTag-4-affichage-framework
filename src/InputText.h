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

    void CaracterePossibleSuivant(); // U On propose le caractère suivant

    void CaracterePossiblePrecedent(); // D On propose le caractère précédent

    void CaractereSelectionPrecedent(); // P On recule le curseur

     void SupprimerCharAct(); // S On supprime la position de curseur, et on se met sur le suivant s'il y a des caractères après ou sur le précédent si on est à la fin.

    void CaractereSelectionSuivant(); // N (suivaNt)On avance le curseur

    String DonneChaineAvantAct();

    char DonneCharAct();

    String DonneChaineApres();
};

#endif