#include <stdio.h>

void supprime_espaces(char chaine[], int *nb_espaces){
	int src = 0;
	int dst = 0;
	*nb_espaces=0;
	while(chaine[src] != '\0') {
		if (chaine[src] == ' ') {
			*nb_espaces = *nb_espaces+1;
		}
		else{
			chaine[dst] = chaine[src];
			dst = dst + 1;
		}
		src = src + 1;
	}
	chaine[dst]='\0';
}

int main () {
	char phrase[] = "Bonjour tout le monde.";
	int i, nb;
	supprime_espaces(phrase,&nb);
	printf("Nombre d’espaces supprimes : %d\n", nb);
	printf("Phrase modifiee : \n");
	i = 0;
	while (phrase[i] != '\0') {
		printf("%c", phrase[i]);
		i++;
	}
	printf("\n");
	//Ou simplement
	//printf("%s\n",phrase);
	
	return 0;
}
