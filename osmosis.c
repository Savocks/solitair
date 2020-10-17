#define MAX_CARD 52
#define MAX_SUIT_CARD 13
#define SUIT_NUMBER 4

#include <stdio.h>
#include <stdlib.h>

typedef int bool;
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
	struct CardStack firstStack[4];
	struct CardStack secondStack[4];
	struct CardStack thirdStack[4];
	struct CardStack forthStack[4];
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
void shuffle(struct Card *array, int n);
void printBoard(
	struct Card *firstStack,
 	struct Card *secondStack,
	struct Card *thirdStack,
	struct Card *fourthStack,
	struct Card *firstOpenStack,
	struct Card *secondOpenStack,
	struct Card *thirdOpenStack,
	struct Card *fourthOpenStack,
	struct Card *deck,
	struct Card *openDeck
	);
	
char* transformvaluecard(int value);

/*
char[] transformSuiteCard(int suite);
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
		switch(choice) {
			case 1: 
				startGame();
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
	struct Card cardStack[MAX_CARD];
	k = 0;
	for (i = 1; i <= SUIT_NUMBER; i++) {
		for(j = 1; j <= MAX_SUIT_CARD; j++) {
			struct Card card;
			card.color = i;
			card.suit = 1;
			card.value = j;
			cardStack[k] = card;
			k++;
		}
	}
	
	shuffle(cardStack, MAX_CARD);

	struct Card firstStack[4];
	struct Card secondStack[4];
	struct Card thirdStack[4];
	struct Card fourthStack[4];
	struct Card firstOpenStack[13];
	struct Card secondOpenStack[13];
	struct Card thirdOpenStack[13];
	struct Card fourthOpenStack[13];
	struct Card deck[35];
	struct Card openDeck[35];
	
	
	for (i = 0; i < 13; i++) {
		firstOpenStack[i].value = 0;
		secondOpenStack[i].value = 0;
		thirdOpenStack[i].value = 0;
		fourthOpenStack[i].value = 0;
	}
	
	for(i = 0; i < 36; i++) {
		openDeck[i].value = 0;
	}

	
	j = 0;
	for (i = 0; i < 4; i++) {
		firstStack[i].value = cardStack[j].value;
		firstStack[i].suit = cardStack[j].suit;
		firstStack[i].color = cardStack[j].color;
		j++;
	}
	
	for (i = 0; i < 4; i++) {
		secondStack[i].value = cardStack[j].value;
		secondStack[i].suit = cardStack[j].suit;
		secondStack[i].color = cardStack[j].color;
		j++;
	}
	
	
	for (i = 0; i < 4; i++) {
		thirdStack[i].value = cardStack[j].value;
		thirdStack[i].suit = cardStack[j].suit;
		thirdStack[i].color = cardStack[j].color;
		j++;
	}
	
	for (i = 0; i < 4; i++) {
		fourthStack[i].value = cardStack[j].value;
		fourthStack[i].suit = cardStack[j].suit;
		fourthStack[i].color = cardStack[j].color;
		j++;
	}
	
	firstOpenStack[0].value = cardStack[j].value;
	firstOpenStack[0].color = cardStack[j].color;
	firstOpenStack[0].suit = cardStack[j].suit;
	j++;
	
	for (i = 0; i < 35; i++) {
		deck[i].value = cardStack[j].value;
		j++;
	}
		
	printBoard(
	firstStack,
 	secondStack,
	thirdStack,
	fourthStack,
	firstOpenStack,
	secondOpenStack,
	thirdOpenStack,
	fourthOpenStack,
	deck,
	openDeck
	);
	
	
	
}
static int rand_int(int n) {
	int limit = RAND_MAX - RAND_MAX % n;
	int rnd;

	do {
		rnd = rand();
	} while (rnd >= limit);
	return rnd % n;
}

void shuffle(struct Card *array, int n) {
	int i, j;
	struct Card tmp;
	
  	for (i = n - 1; i > 0; i--) {
		j = rand_int(i + 1);
	    tmp = array[j];
	    array[j] = array[i];
	    array[i] = tmp;
	}
}

char* transformvaluecard(int value){ 

	switch(value) {
	case 0:
		return "X";
    case 1:
        return "A";
    case 2:
        return "2";
    case 3:
        return "3";
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
    case 10:
        return "10";
    case 11:
        return "J";
    case 12:
        return "Q";
    case 13:
        return "K"; 
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




int main() {
	displayMenu();
}

void printBoard(
	struct Card *firstStack,
 	struct Card *secondStack,
	struct Card *thirdStack,
	struct Card *fourthStack,
	struct Card *firstOpenStack,
	struct Card *secondOpenStack,
	struct Card *thirdOpenStack,
	struct Card *fourthOpenStack,
	struct Card *deck,
	struct Card *openDeck) {
		system("cls");
		printf("\n***************************************************\n");
		printf("***************************************************\n");
		printBoardRow(firstStack, firstOpenStack, false);
		printBoardRow(secondStack, secondOpenStack, false);
		printBoardRow(thirdStack, thirdOpenStack, false);
		printBoardRow(fourthStack, fourthOpenStack, false);
		printBoardRow(deck, openDeck, true);
		printf("***************************************************\n");


		

}

/*for(i = 0; i < 52; i++) {
		printf("\nIl valore della carta: %d", cardStack[i].value);
	}
	*/
void printBoardRow(struct Card *stack, struct Card *flippedStack, bool isDeck) {
	if (!isDeck) {
		printf("**\t%s\t\t%s %s %s %s %s %s %s %s %s %s %s %s %s**\n",
		transformvaluecard(stack[0].value),
		transformvaluecard(flippedStack[0].value),
		transformvaluecard(flippedStack[1].value),
		transformvaluecard(flippedStack[2].value),
		transformvaluecard(flippedStack[3].value),
		transformvaluecard(flippedStack[4].value),
		transformvaluecard(flippedStack[5].value),
		transformvaluecard(flippedStack[6].value),
		transformvaluecard(flippedStack[7].value),
		transformvaluecard(flippedStack[8].value),
		transformvaluecard(flippedStack[9].value),
		transformvaluecard(flippedStack[10].value),
		transformvaluecard(flippedStack[11].value),
		transformvaluecard(flippedStack[12].value)
		);
		printf("\n");
	} else {
		printf("**\t\t\t\t\t      %s %s**\n", transformvaluecard(flippedStack[0].value), transformvaluecard(stack[0].value));
		printf("\n");
	}
}
