#include <stdio.h>
#define CHAINE "bonjour"

int main() {
	char chaine[] = CHAINE;
	char miroir[] = CHAINE;
	int i = 0;
	int longueur = 0;
	/* calcul de la longueur de la chaine */
	while(chaine[i] != '\0'){
		i++;
	}
	longueur=i;
	/* inversion du mot */
	for(i = 0; i < longueur; i++) {
		miroir[i] = chaine[longueur - 1 - i];
	}
	printf("La chaine miroir est : %s\n",miroir);
	return 0;
}
