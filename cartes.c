/*=====================================
*
*        oO  Black-Jack   Oo
*
*=====================================
*
* File : cartes.c
* Date : 17 octobre 10
* Author : Hilaire Thibault
*
*=====================================
*
* Fonctions de manipulation de jeu de cartes
*/

#include <stdio.h>
#include "cartes.h"
#include <stdlib.h>



/* Fonction qui affiche une carte 
Paramètres d'entrée : 
 - carte : carte à afficher
*/
void afficheCarte( t_carte carte)
{
	/* affichage de la valeur */
	printf(" ");
	switch (carte.valeur)
	{
		case 1 :
			printf( " A"); break;
		case 11 :
			printf( " V"); break;
		case 12 :
			printf( " D"); break;
		case 13 :
			printf( " R"); break;
		default:
			printf( "%2d",carte.valeur);
	}
	
	/* affichage de la couleur */
	switch (carte.couleur)
	{
		case pique : 
			printf( "\xE2\x99\xA0"); break;
		case coeur : 
			printf( "\xE2\x99\xA1"); break;
		case carreau :
			printf( "\xE2\x99\xA2"); break;
		case trefle :
			printf("\xE2\x99\xA3"); break;
		default:
			printf("titi");
	}
	printf(" ");
}


/* fonction qui remplit un jeu de carte 
Paramètre d'entrée/sortie:
- jeu : tableau de cartes à remplir */
void remplitJeu( t_jeu jeu)
{
	int v,c,n;
	n=0;
	/* itération sur la valeur et la couleur */
	for( v=1; v<=13; v++)
		for( c=coeur; c<=trefle; c++)
		{
			jeu[n].couleur = c;
			jeu[n].valeur = v;
			n++;
		}
}

/* fonction qui affiche un jeu de carte
Paramètre d'entrée:
- jeu : jeu de carte à afficher */
void afficheJeu( t_jeu jeu)
{
	int n;
	printf ("\n");
	
	/* affichage des 52 cartes */
	for( n=0; n<52; n++)
		afficheCarte( jeu[n] );
		
	printf("\n");
}


/* fonction qui mélange un jeu de carte
Paramètres d'entrée:
- jeu : jeu de carte à mélanger
- nb : nombre d'itération pour le mélange */
void melangeJeu( t_jeu jeu, int nb)
{
	int i;
	int n1,n2;
	t_carte temp;
	
	/* on répète nb permutation */
	for( i=0; i<nb; i++)
	{
		/* tirage au sort des 2 indices de cartes à permuter */
		n1 = (int) ( (rand() * 52.0) / RAND_MAX );
		n2 = (int) ( (rand() * 52.0) / RAND_MAX );
		
		/* permutation des 2 cartes */
		temp = jeu[n1];
		jeu[n1] = jeu[n2];
		jeu[n2] = temp;
	}
}
