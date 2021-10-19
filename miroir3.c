#include <stdio.h>

void affiche_miroir(char chaine[]) {
	if (chaine[0] != '\0' ) {
		affiche_miroir(chaine+1);
		printf("%c", chaine[0]);
	}
}

int main(){
	int i = 0;
	char mot[]="bonjour";
	printf("L'inverse du mot %s est : ", mot);
	affiche_miroir(mot);
	printf("\n");	
	return 0;
}
