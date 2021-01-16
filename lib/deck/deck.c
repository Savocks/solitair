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
    for (int suit_number = 1; suit_number <= SUIT_NUMBER; suit_number++) {
        for (int card_value = 1; card_value <= MAX_SUIT_CARD; card_value++) {
            Card* current_card = card_constructor();
            card_initialize_card_values(current_card, card_value, suit_number, suit_number);
            deck_push(deck, current_card);
        }
    }
}


Deck* deck_constructor(void) {
    Deck* deck = calloc(1, sizeof(deck));
    if(deck == NULL) { exit(1); };

    deck->deck_cards = calloc(MAX_DECK_CARD, sizeof(deck->deck_cards) * MAX_DECK_CARD);
    if(deck->deck_cards == NULL) { exit(1); };

    deck->capacity = MAX_DECK_CARD;
    fill_deck(deck);
    shuffle(deck->deck_cards, MAX_DECK_CARD);

    return deck;
}


// Stack is full when top_card is equal to the last index
bool deck_is_full(Deck* deck)
{
    return deck->top_card == deck->capacity - 1;
}

// Stack is empty when top_card is equal to -1
bool deck_is_empty(Deck* deck)
{
    return deck->top_card == -1;
}


void deck_push(Deck* deck, Card* card) {
    if (deck_is_full(deck))
        return;
    deck->top_card++;
    deck->deck_cards[deck->top_card].color = card->color;
    deck->deck_cards[deck->top_card].value = card->value;
    deck->deck_cards[deck->top_card].seed = card->seed;
}

Card* deck_pop(Deck* deck) {
    if (!deck_is_empty(deck)) {
        return &deck->deck_cards[deck->top_card--];
    }
    return NULL;
}


// Function to return the top_card from stack without removing it
Card* deck_peek(Deck* deck)
{
    if (!deck_is_empty(deck))
        return &deck->deck_cards[deck->top_card];
    return NULL;
}

Card* deck_get_deck_cards(Deck* this) {
    return this->deck_cards;
}

