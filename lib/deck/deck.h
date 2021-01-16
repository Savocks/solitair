//
// Created by giuli on 10/01/2021.
//

#include <time.h>
#include "../card/card.h"

#ifndef SOLITAIR_DECK_H
#define SOLITAIR_DECK_H

#endif //SOLITAIR_DECK_H

typedef struct Deck {
    Card* deck_cards;
} Deck;

Deck* deck_constructor(void);

Card* deck_get_deck_cards(Deck*);


