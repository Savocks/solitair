#define MAX_CARD 52
#define MAX_SUIT_CARD 13

#include <stdio.h>
#include <stdlib.h>

/*
 * Definizione delle strutture che servono al gioco.
 */
struct Card{
	int value;
	int suit;
	int color;
};

struct CardStack{
	struct Card* cards;
	struct Card firstCard;
	int maxCards;
	int currentElement;
};

struct Osmosis {
	bool isStarded;
	bool isFinished;
	struct CardStack firstStack;
	struct CardStack secondStack;
	struct CardStack thirdStack;
	struct CardStack forthStack;
	struct CardStack firstOpenStack;
	struct CardStack secondOpenStack;
	struct CardStack thirdOpenStack;
	struct CardStack forthOpenStack;
	struct CardStack deck;
	struct CardStack openDeck;
};


/*
 * Definizione delle funzioni
 */

int displayMenu();
int printRules();
int startGame();
void shuffle(int [], int n);
/*
char[] transformSuiteCard(int suite);
char transformvaluecard(int value);
void removecard(stack *s, card *c);
void addCards(stack *A, card *B);
void givesCards (stack *s, stack *c, int maxcards);
struct Card * createInitialCardStack();
*/


int displayMenu() {
	int choice = 0;
	printf("Ciao, benvenuto in Osmosi Solitaire\n");
	do {
		printf("Fai la tua scelta!\n");
		printf("1 - Nuova Partita");
		printf("\n");
		printf("2 - Regole del gioco");
		printf("\n");
		printf("3 - Esci dal gioco");
		printf("\n");
		scanf("%d", &choice);
		switch(choice){
			case 1: 
				startGame();
				break;
			break;
			case 2:
				printRules();
				break;
		}
	}
	while(choice != 3);
}
int printRules(){
	printf("SCOPO DEL GIOCO");
	printf("\n");
	printf("Spostare tutte le carte nelle pile di base.\n");
	printf("REGOLE:\n");
	printf("4 PILE DI BASE (al centro):\n");
	printf("-Costruire file di carte per seme senza tener conto del valore.\n");
	printf("-Nella pila di base superiore � possibile mettere qualsiasi carta dello stesso seme della prima carta distribuita dal mazzo.\n");
	
}
int startGame() {
	int i, j, k;
	printf("Buona fortuna");
	printf("\n");
	struct Card card;
	struct Card cardStack[MAX_CARD];
	for (i = 0; i < MAX_CARD; i++) {
		for(j=1; j<=4; j++) {
			for(k=1; k<=MAX_SUIT_CARD; k++) {
				card.value = k;
				card.suit = j;
				card.color = j;
			}
		}
		cardStack[i] = card;
	}
	for(i = 0; i<MAX_CARD; i++) {
		printf("Valore della carta %d\n", cardStack[i].value);
	}
}

static int rand_int(int n) {
	int limit = RAND_MAX - RAND_MAX % n;
	int rnd;

	do {
		rnd = rand();
	} while (rnd >= limit);
	return rnd % n;
}

void shuffle(int arra[], int n) {
	int array[5] = {11, 22, 33, 44, 55};
	int i, j, tmp;
	
  	for (i = n - 1; i > 0; i--) {
		j = rand_int(i + 1);
	    tmp = array[j];
	    array[j] = array[i];
	    array[i] = tmp;
	}
}

/*
char[] transformSuiteCard(int suite){
    switch (suite)
	case 1:
		return "U+2660" ;
	case 2:
		return "U+2663" ;
	case 3:
		return "U+2665" ;
	case 4:
    	return "U+2666" ;
}


char transformvaluecard(int value){ 
	switch(value);    
      case 1:
        return "A";
    case 2:
        return "2";
    case 3:
        return"3";
    case 4:
        return "4";
    case 5:
        return "5";
    case 6:
        return "6";
    case 7:
        return "7";
    case 8:
        return "8";
    case 9:
        return "9";
    case 10;
        return "10";
    case 11:
        return "J";
    case 12:
        return "Q";
    case 13:
        return "K"; 
}


void removecard(CardStack *s, Card *c) {
	s.card[s.elementocorrente -1]=c;
	s.elementocorrente--;
}

void addCards(stack *A, card *B) {
    A.card[A.elemento_corrente + 1] = B;
    A.elemento_corrente ++;
}

void givesCards(stack *s, stack *c, int maxcards){
    int i;
    for(i=0;i < maxcards;i++){
        s.cards[i]=c.cards[c.elementocorrente];
        c.elementocorrente--;
    }
}

struct Card * createInitialCardStack() {
	int i, j, k;
	struct Card card;
	struct Card cardStack[MAX_CARD];
	for (i = 0; i < MAX_CARD; i++) {
		for(j=1; j<=4; j++) {
			for(k=1; k<=MAX_SUIT_CARD; k++) {
				card.value = k;
				card.suit = j;
				card.color = j;
			}
		}
		cardStack[i] = card;
	}
	for(i = 0; i<MAX_CARD; i++) {
		printf("Valore della carta %d\n", cardStack[i].value);
	}
	return cardStack;
}*/
