//
// Created by giuli on 10/01/2021.
//

#include <time.h>
#include <stdbool.h>
#include "../card/card.h"

#ifndef SOLITAIR_DECK_H
#define SOLITAIR_DECK_H

#endif //SOLITAIR_DECK_H

typedef struct Deck {
    int top_card;
    size_t capacity;
    Card* deck_cards;
} Deck;

Deck* deck_constructor(void);

bool deck_is_full(Deck* deck);

bool deck_is_empty(Deck* deck);

void deck_push(Deck* deck, Card* card);

Card* deck_pop(Deck* deck);

Card* deck_peek(Deck* deck);

Card* deck_get_deck_cards(Deck*);





