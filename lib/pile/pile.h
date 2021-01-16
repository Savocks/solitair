//
// Created by giuli on 16/01/2021.
//
#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include "../card/card.h"

#ifndef SOLITAIR_PILE_H
#define SOLITAIR_PILE_H

#endif //SOLITAIR_PILE_H

typedef struct Pile {
    int top_card;
    size_t capacity;
    Card* pile_cards;
} Pile;

Pile* pile_constructor(unsigned capacity);

bool pile_is_full(Pile* pile);

bool pile_is_empty(Pile* pile);

void pile_push(Pile* pile, Card* card);

Card* pile_pop(Pile* pile);

Card* pile_peek(Pile* pile);

void test_function();


