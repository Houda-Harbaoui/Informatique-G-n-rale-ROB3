/*=====================================
*
*        oO  Black-Jack   Oo
*
*=====================================
*
* File : partie.h
* Date : 17 octobre 10
* Author : Hilaire Thibault
*
*=====================================
*
* Fonctions de partie
*/


#ifndef __PARTIE_H__
#define __PARTIE_H__


#include "cartes.h"


/******** Types **********/

/* type pour une main */
typedef struct
{
	t_jeu jeu;
	int nbCartes;
	char nom[20];
} t_main;


/* type pour la partie */
typedef struct
{
	t_jeu pioche;
	int posPioche;
	t_main ordi;
	t_main humain;
} t_partie;



/******** Prototypes *********/


/* procédure qui initialise une partie
Paramètres d'entrée/sortie:
- partie : la partie à initialiser
- nom0 : le nom du joueur 0
- nom1 : le nom du joueur 1 */
void initPartie( t_partie* pPartie, char nomOrdi[20], char nomHumain[20]);


/* procédure qui distribue la 1ère carte de la pioche
dans le jeu d'un joueur
Paramètres d'entrée/sortie:
- partie : une partie
- nJoueur : n° du joueur : 0->joueur, 1->ordi */
void distribue( t_partie* pPartie, int nJoueur);


/* procédure qui affiche une main
Paramètres d'entrée:
- main : main à afficher */
void afficheMain( t_main main);


/* procédure qui détermine la meilleure valeur d'une main
Paramètres d'entrée:
- main : main à évaluer */
int evaluerMain( t_main main);



#endif