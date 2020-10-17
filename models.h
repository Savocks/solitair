#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Definizione delle strutture che servono al gioco.
 */
typedef struct Card{
	int value;
	int suit;
	int color;
}Card;

typedef struct CardStack{
	struct Card* cards;
	struct Card firstCard;
	int maxCards;
	int currentElement;
}CardStack;

typedef struct Osmosis {
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
}Osmosis;


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





