/*=====================================
*
*        oO  Black-Jack   Oo
*
*=====================================
*
* File : blackjack.c
* Date : 17 octobre 10
* Author : Hilaire Thibault
*
*=====================================
*
* Jeu du Black-Jack, TP n°5
*/


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "partie.h"


int main()
{
 

	/***********
	   Q1 à Q3
	t_carte c;
	
	c.valeur=2;
	c.couleur=pique;
	afficheCarte(c);
	
	c.valeur=1;
	c.couleur=coeur;
	afficheCarte(c);
	
	c.valeur=10;
	c.couleur=carreau;
	afficheCarte(c);
	
	c.valeur=13;
	c.couleur=trefle;
	afficheCarte(c);
	*/
	
	
	/**********
	   Q4 à Q6
	t_jeu jeu;
	srand(time(NULL));
	remplitJeu( jeu );
	afficheJeu( jeu );
	melangeJeu( jeu , 1000);
	afficheJeu( jeu );
	*/
	
	/**************
	   Q7 à Q10 */
	t_partie partie;			/* partie en cours */
	char rep[5];				/* réponse */
	int sc_ordi, sc_joueur; 	/* scores */
	
	/* initialise la partie */
	srand(time(NULL));
	initPartie( &partie, "Ordi", "Titi");
	

	while (partie.posPioche<=42)
	{
		/* remise à zéro des mains */
		partie.ordi.nbCartes = partie.humain.nbCartes = 0;
		
		/* distribue deux cartes à chacun */
		distribue( &partie, 0);
		distribue( &partie, 1);
		distribue( &partie, 0);
		distribue( &partie, 1);

		/* affichage des deux mains */
		printf ("\n\nC'est parti!\n");
		afficheMain( partie.ordi );
		afficheMain( partie.humain );

		/* demander si nouvelle carte */
		printf( "\n Voulez-vous une nouvelle carte ? (o/n)");
		scanf( "%s", rep);
	
		/* jeu du joueur humain */
		while (rep[0]=='o' && evaluerMain( partie.humain)<=21 )
		{
			distribue( &partie, 1);
			afficheMain( partie.humain );
			if ( evaluerMain( partie.humain ) <= 21 )
			{
				printf( "\n Voulez-vous une nouvelle carte ? (o/n)");
				scanf( "%s", rep);
			}
		}	
	
		/* jeu de l'ordi */
		/* stratégie de l'ordinateur */
		while ( evaluerMain( partie.ordi)<17 && evaluerMain( partie.humain)<=21 )
		{
			distribue( &partie, 0);		
		}
			
		/* affichage de la main de l'ordi*/
		afficheMain( partie.ordi );
	
		/* afficher le vainqueur */
		sc_ordi = evaluerMain( partie.ordi );
		sc_joueur = evaluerMain( partie.humain );		
		if (sc_ordi>21)
		{
			if (sc_joueur>21)
				printf("\nLe deux joueurs perdent!\n");
			else
				printf("\nVous gagnez !\n");
		}
		else
		{
			if ( (sc_joueur>21) || (sc_ordi>sc_joueur) )
				printf("\nL'ordinateur gagne!\n");
			else if (sc_joueur>sc_ordi)
					printf("\nVous gagnez!\n");
				else
					printf("\nÉgalité !\n");
		}
			
	}

	return EXIT_SUCCESS;
}

