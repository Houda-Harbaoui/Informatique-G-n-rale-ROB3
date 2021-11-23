/*=====================================
*
*        oO  Black-Jack   Oo
*
*=====================================
*
* File : partie.c
* Date : 17 octobre 10
* Author : Hilaire Thibault
*
*=====================================
*
* Fonctions de partie
*/

#include <stdio.h>
#include <string.h>
#include "partie.h"


/* procédure qui initialise une partie
Paramètres d'entrée/sortie:
- partie : la partie à initialiser
- nomOrdi : le nom de l'ordi
- nomHumain : le nom du joueur humain */
void initPartie( t_partie* pPartie, char nomOrdi[20], char nomHumain[20])
{
	/* gère la pioche */
	remplitJeu( pPartie->pioche );
	melangeJeu( pPartie->pioche, 1000 );
	pPartie->posPioche = 0;
	
	/* l'ordi */
	pPartie->ordi.nbCartes = 0;
	strcpy( pPartie->ordi.nom, nomOrdi);
	
	/* le joueur 1 */
	pPartie->humain.nbCartes = 0;
	strcpy( pPartie->humain.nom, nomHumain);
}


/* procédure qui distribue la 1ère carte de la pioche
dans le jeu d'un joueur
Paramètres d'entrée/sortie:
- partie : une partie
- nJoueur : n° du joueur : 1->joueur, 0->ordi */
void distribue( t_partie* pPartie, int nJoueur)
{
	/* on copie la 1ère carte de la pioche dans le jeu */
	if (nJoueur)
	{
		pPartie->humain.jeu[ pPartie->humain.nbCartes] = pPartie->pioche[ pPartie->posPioche ];
		pPartie->humain.nbCartes++;
	}
	else
	{
		pPartie->ordi.jeu[ pPartie->ordi.nbCartes] = pPartie->pioche[ pPartie->posPioche ];
		pPartie->ordi.nbCartes++;
	}
	
	/* on incrémente la position de la pioche */
	pPartie->posPioche ++;
}


/* procédure qui affiche une main
Paramètres d'entrée:
- main : main à afficher */
void afficheMain( t_main main)
{
	int i;
	/* affichage du nom */
	printf( "%s :", main.nom);
	/* affichage de la main */
	for( i=0; i<main.nbCartes; i++)
		afficheCarte( main.jeu[i] );
	printf( "\n");
}


/* procédure qui détermine la meilleure valeur d'une main
Paramètres d'entrée:
- main : main à évaluer */
int evaluerMain( t_main main)
{
	int i, nbAs = 0;
	int valeur = 0;
	
	/* calcul de la valeur minimum */
	for( i=0; i<main.nbCartes; i++)
	{
		/* valeur +=  main.jeu[i].valeur>10 ? 10 : main.jeu[i].valeur;
		   nbAs += main.jeu[i].valeur==1; */
		if (main.jeu[i].valeur>10)
			valeur = valeur + 10;
		else
			valeur = valeur + main.jeu[i].valeur;
		if (main.jeu[i].valeur==1)
			nbAs = nbAs + 1;
	}

	/* si on a au moins un as, et qu'on a moins de 11 points, 
	alors il faut compter l'as comme valant 11 points et non 1*/
	if (nbAs>0 && valeur<=11)
		valeur = valeur + 10;	
	
	return valeur;
}