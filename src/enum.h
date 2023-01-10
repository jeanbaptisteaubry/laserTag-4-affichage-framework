#ifndef enum_H
#define enum_H

enum etatArme
{
	attente,
	rechargeChargeur,
	chargement,
	shoot,
	refroidissement
};

enum modeTire
{
	simple,
	rafale,
	automatique
};

enum etatEcran{
	affichageFull, //Affichage de l'écran de jeu avec vie, armure, munitions, mode de tir, etat de l'arme et score
	affichageReload, //Affichage de l'écran de jeu avec la progression du rechargement en cours
	affichageArmure, //Affichage de l'écran de jeu avec l'armure
	affichageVie, //Affichage de l'écran de jeu avec la vie
	affichageScore, //Affichage de l'écran de jeu avec le score
	affichageArme, //Affichage de l'écran de jeu avec le mode de tir et les munitions restantes
};
#endif
