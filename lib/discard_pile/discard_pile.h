//
// Created by giuli on 10/01/2021.
//
#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include "../card/card.h"

#ifndef SOLITAIR_DISCARD_PILE_H
#define SOLITAIR_DISCARD_PILE_H

#endif //SOLITAIR_DISCARD_PILE_H


typedef struct DiscardPile {
    int top_card;
    size_t capacity;
    Card* discard_pile_cards;
} DiscardPile;

DiscardPile* discard_pile_constructor(unsigned capacity);

bool discard_pile_is_full(DiscardPile* discard_pile);

bool discard_pile_is_empty(DiscardPile* discard_pile);

void discard_pile_push(DiscardPile* discard_pile, Card* card);

Card* discard_pile_pop(DiscardPile* discard_pile);

Card* discard_pile_peek(DiscardPile* discard_pile);

