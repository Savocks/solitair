#include <stdlib.h>
#include <stdio.h>
#include "card.h"

static void card_set_seed(Card* this, int seed) {
    this->seed = seed;
}

static void card_set_value(Card* this, int value) {
    this->value = value;
}

static void card_set_color(Card* this, int color) {
    this->color = color;
}

Card* card_constructor(void) {
    Card* card = malloc(sizeof(Card));
    if(card == NULL) { exit(1); };
    card->value = 0;
    card->color = 0;
    card->seed = 0;
    return card;
}

int card_get_color(Card* this) {
    return this->color;
}

int card_get_value(Card* this) {
    return this->value;
}

int card_get_seed(Card* this) {
    return this->seed;
}

void card_initialize_card_values(Card* this, int value, int color, int seed) {
    card_set_value(this, value);
    card_set_color(this, color);
    card_set_seed(this, seed);
}

void card_print_card_values(Card* this) {
    printf("Value: %d\tColor: %d\tSeed: %d\n", card_get_value(this), card_get_color(this), card_get_seed(this));
}

bool card_is_valid(Card* this) {
    if (this->seed > 0 && this->seed < 5 &&
        this->value > 0 && this->value < 14 &&
        this->color > 0 && this->color < 5)
        return true;
}