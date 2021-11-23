/*=====================================
*
*        oO  Black-Jack   Oo
*
*=====================================
*
* File : cartes.h
* Date : 17 octobre 10
* Author : Hilaire Thibault
*
*=====================================
*
* Définitions de types (t_carte, etc.)
* et prototypes
*/

#ifndef __CARTES_H__
#define __CARTES_H__


/******** Types **********/

/* énumération des couleurs */
typedef enum
{
	coeur, pique, carreau, trefle
} t_couleur;


/* carte à jouer*/
typedef struct
{
	int valeur;
	t_couleur couleur;
} t_carte;

/* jeu de 52 cartes */
typedef t_carte t_jeu[52];



/******** Prototypes *********/


/* Fonction qui affiche une carte 
Paramètres d'entrée : 
 - carte : carte à afficher */
void afficheCarte( t_carte carte);


/* fonction qui remplit un jeu de carte 
Paramètre d'entrée/sortie:
- jeu : tableau de cartes à remplir */
void remplitJeu( t_jeu jeu);


/* fonction qui affiche un jeu de carte
Paramètre d'entrée:
- jeu : jeu de carte à afficher */
void afficheJeu( t_jeu jeu);


/* fonction qui mélange un jeu de carte
Paramètres d'entrée:
- jeu : jeu de carte à mélanger
- nb : nombre d'itération pour le mélange */
void melangeJeu( t_jeu jeu, int nb);

#endif
