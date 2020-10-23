#define MAX_CARD 52
#define MAX_SUIT_CARD 13
#define SUIT_NUMBER 4

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <memory.h>

#include "printutils.h"


static int rand_int(int n) {
    int limit = RAND_MAX - RAND_MAX % n;
    int rnd;

    do {
        rnd = rand();
    } while (rnd >= limit);
    return rnd % n;
}

void shuffle(s_card *array, int n);
void createInitialDeck(s_stack* initialDeck);
s_card* createCard(int value, int color, int suit);
void initializeStack(s_stack* initialDeck, s_stack* deckToInitialize, int maxCard);
void createOsmosisGame(s_osmosis* game);


void createOsmosisGame(s_osmosis* game) {   /*
     * Creato il mazzo iniziale di 52 carte
     * e mescolato mediante l'algoritmo di Fisher–Yates
     */
    s_stack* initialDeck = calloc(1, sizeof(s_stack));
    createInitialDeck(initialDeck);
    shuffle(initialDeck->cards, MAX_CARD);

    initializeStack(initialDeck, game->fStack, 4);
    initializeStack(initialDeck, game->fFlippedStack, 1);
    initializeStack(initialDeck, game->sStack, 4);
    initializeStack(initialDeck, game->tStack, 4);
    initializeStack(initialDeck, game->fourthStack, 4);
    initializeStack(initialDeck, game->deck, 35);

}

void initializeStack(s_stack* initialDeck, s_stack* deckToInitialize, int maxCard) {
    int j = initialDeck->maxCards - 1;
    for (int i = maxCard - 1; i >= 0; i--) {
        deckToInitialize->cards[i] = initialDeck->cards[j];
        j--;
    }
    initialDeck->maxCards -= maxCard;
}


void createInitialDeck(s_stack* initialDeck) {
    initialDeck->cards = calloc(MAX_CARD, sizeof(s_card));
    int k = 0;
    for (int i = 1; i <= SUIT_NUMBER; i++) {
        for (int j = 1; j <= MAX_SUIT_CARD; j++) {
            s_card* card = calloc(1, sizeof(s_card));
            card = createCard(j, i, i);
            initialDeck->cards[k].value = card->value;
            initialDeck->cards[k].suit = card->suit;
            initialDeck->cards[k].color = card->color;
            free(card);
            k++;
        }
    }
    initialDeck->maxCards = MAX_CARD;
    initialDeck->firstCard = initialDeck->cards[0];
    initialDeck->currentElement = MAX_CARD - 1;
}

s_card* createCard(int value, int color, int suit) {
    s_card* card = calloc(1, sizeof(s_card));
    card->value = value;
    card->color = color;
    card->suit = suit;

    return card;
}

void shuffle(s_card *array, int n) {
    int i, j;
    s_card tmp;

    for (i = n - 1; i > 0; i--) {
        j = rand_int(i + 1);
        tmp = array[j];
        array[j] = array[i];
        array[i] = tmp;
    }
}
