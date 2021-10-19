#include <stdio.h>
#define CHAINE "bonjour"

int main() {
	char chaine[] = CHAINE;
	char tmp;
	int i = 0;
	int longueur = 0;
	/* calcul de la longueur de la chaine */
	while(chaine[i] != '\0'){
		i++;
	}
	longueur=i;
	/* inversion du tableau */
	for(i = 0; i < longueur/2; i++) {
		tmp=chaine[i];
		chaine[i] = chaine[longueur - 1 - i];
		chaine[longueur - 1 - i] = tmp;
	}
	printf("La chaine miroir est : %s\n",chaine);
	return 0;
}
