//
// Created by giuli on 10/01/2021.
//

#ifndef SOLITAIR_CARD_H
#define SOLITAIR_CARD_H

#endif //SOLITAIR_CARD_H


typedef struct Card {
    int color;
    int value;
    int seed;
} Card;

Card* card_constructor(void);

int card_get_color(Card* this);

int card_get_value(Card* this);

int card_get_seed(Card* this);

void card_initialize_card_values(Card* this, int color, int value, int seed);

void card_print_card_values(Card* this);

