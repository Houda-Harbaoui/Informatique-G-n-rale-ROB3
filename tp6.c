#include <stdlib.h>
#include <stdio.h>
#include <math.h>


struct list {
  int n;
  double c;
  struct list * next;
};

struct list * ajout (int n, double c, struct list * l);
void print_list(struct list *l) ;
struct list * supprime (struct list *l) ;
double eval(struct list *l, double x);
void supprimeTout(struct list **l);
struct list* somme(struct list* l1, struct list* l2);
void multipleV(struct list*l,double v);
void multipleMonome(struct list*l,double c,double n);


int main() {
  struct list * l = NULL;
  l = ajout(10,1,l);
  l = ajout(7,1,l);
  l = ajout(12,1,l);
  l = ajout(9,1,l);
  print_list(l);
  l=supprime(l);
  print_list(l);
  l = ajout(9,2,l);
  print_list(l);
  printf("val=%f\n",eval(l,1));

  struct list * l2 = NULL;

	l2 = ajout(10,2,l2);
	l2 = ajout(7,5,l2);	

	print_list(l2);

	struct list* l3 = somme(l,l2);

	print_list(l3);	

	multipleV(l,5.0);
	print_list(l);

	multipleMonome(l,3.0,7);

	print_list(l);

	supprimeTout(&l);
	supprimeTout(&l2);
	supprimeTout(&l3);
}

void multipleMonome(struct list*l,double c,double n){
	multipleV(l,c);
	struct list* courant=l;
 	while (courant!=NULL){
		courant->n=courant->n+n;
		courant=courant->next;
	}
}



void multipleV(struct list*l,double v){
	struct list* courant=l;
 	while (courant!=NULL) {
		courant->c=courant->c*v;
		courant=courant->next;
	}
}


void supprimeTout(struct list **l){
	while (*l!=NULL){
		*l=supprime(*l);
	}

}

struct list * supprime (struct list *l) {
  struct list *mail = l;
	if ((mail)!=NULL){
  	l = l->next;
  	free(mail);
	}
  return(l);
}

struct list * ajout (int n, double c, struct list * l) {
  struct list * crt = l;
  struct list * prec= NULL;
  while (crt != NULL && crt->n > n) {
    prec = crt ;
    crt = crt -> next ;
  }

  if (crt!=NULL && crt->n==n) {
    crt->c += c;
    return(l);
  }

  struct list *elem ;
  elem =(struct list*) malloc(sizeof(struct list));
  elem->n = n;
  elem->c = c;

  if (prec == NULL)
    l = elem ;
  else
    prec -> next= elem;
  
  elem -> next=crt ;
  return(l);
  
}

struct list* somme(struct list* l1, struct list* l2){
	struct list * l = NULL;
	struct list* courant=l1;
 	while (courant!=NULL) {
		l=ajout(courant->n,courant->c,l);
		courant=courant->next;
	}

	courant=l2;
	while (courant!=NULL) {
		l=ajout(courant->n,courant->c,l);
		courant=courant->next;
	}
	return l;	
}

void print_list(struct list *l) {
  while (l!=NULL) {
    printf("%3.2fx^%d +",l->c,l->n);
    l=l->next;
  }
  printf("\n");
}

double eval(struct list *l, double x) {
  double val;
  while (l!=NULL) {
    val += l->c*pow(x,l->n);
    l=l->next;
  }
  return(val);
}
