//
// Created by giuli on 10/01/2021.
//

#include <stdlib.h>
#include <stdio.h>
#include "deck.h"

#define MAX_DECK_CARD 52
#define MAX_SUIT_CARD 13
#define SUIT_NUMBER 4


static int rand_int(int n) {
    int limit = RAND_MAX - RAND_MAX % n;
    int rnd;

    do {
        rnd = rand();
    } while (rnd >= limit);
    return rnd % n;
}

static void shuffle(Card* cards, int card_to_shuffle) {
    srand(time(NULL));
    int i, j;
    Card tmp;

    for (i = card_to_shuffle - 1; i > 0; i--) {
        j = rand_int(i + 1);
        tmp = cards[j];
        cards[j] = cards[i];
        cards[i] = tmp;
    }
}

static void fill_deck(Deck* deck) {
    int current_card = 0;
    for (int suit_number = 1; suit_number <= SUIT_NUMBER; suit_number++) {
        for (int card_value = 1; card_value <= MAX_SUIT_CARD; card_value++) {
            card_initialize_card_values(&deck_get_deck_cards(deck)[current_card], card_value, suit_number, suit_number);
            current_card++;
        }
    }
}


Deck* deck_constructor(void) {
    Deck* deck = calloc(1, sizeof(deck));
    if(deck == NULL) { exit(1); };

    deck->deck_cards = calloc(MAX_DECK_CARD, sizeof(deck->deck_cards) * MAX_DECK_CARD);
    if(deck->deck_cards == NULL) { exit(1); };

    fill_deck(deck);
    shuffle(deck->deck_cards, MAX_DECK_CARD);

    return deck;
}

Card* deck_get_deck_cards(Deck* this) {
    return this->deck_cards;
}

