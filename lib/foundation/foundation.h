#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include "../card/card.h"

#ifndef SOLITAIR_FOUNDATION_H
#define SOLITAIR_FOUNDATION_H

#endif //SOLITAIR_FOUNDATION_H

typedef struct Foundation {
    int top_card;
    size_t capacity;
    Card* foundation_cards;
    int seed;
} Foundation;

Foundation* foundation_constructor(unsigned capacity);

bool foundation_is_full(Foundation* foundation);

bool foundation_is_empty(Foundation* foundation);

bool foundation_check_if_value_exists(Foundation* foundation, Card* card);

bool foundation_can_push_card(Foundation* foundation, Card* card);

bool foundation_push(Foundation* foundation, Card* card);

Card* foundation_pop(Foundation* foundation);

Card* foundation_peek(Foundation* foundation);


