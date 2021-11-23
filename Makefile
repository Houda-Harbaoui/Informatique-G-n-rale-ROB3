# options de compilation
CC = gcc
CCFLAGS = -Wall 
LIBS = 
LIBSDIR = 

# 1ère règle
all: blackjack.out

# règles de compilation
cartes.o: cartes.h
partie.o: partie.h cartes.h
blackjack.o: cartes.h partie.h
%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<
	
# règles d'édition de liens
blackjack.out: cartes.o blackjack.o partie.o
	$(CC) $(CCFLAGS) -o $@ $^ 


# règles supplémentaires
clean:
	rm -f *.o
mproper:
	rm -f blackjack.out *.o