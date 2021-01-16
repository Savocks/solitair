//
// Created by giuli on 16/01/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "pile.h"



Pile* pile_constructor(unsigned capacity)
{
    Pile* pile = calloc(1, sizeof(Pile));
    pile->capacity = capacity;
    pile->top_card = -1;
    pile->pile_cards = calloc(pile->capacity, sizeof(Card));
    return pile;
}

// Stack is full when top_card is equal to the last index
bool pile_is_full(Pile* pile)
{
    return pile->top_card == pile->capacity - 1;
}

// Stack is empty when top_card is equal to -1
bool pile_is_empty(Pile* pile)
{
    return pile->top_card == -1;
}


void pile_push(Pile* pile, Card* card) {
    if (pile_is_full(pile))
        return;
    pile->top_card++;
    pile->pile_cards[pile->top_card].color = card->color;
    pile->pile_cards[pile->top_card].value = card->value;
    pile->pile_cards[pile->top_card].seed = card->seed;
}

Card* pile_pop(Pile* pile) {
    if (!pile_is_empty(pile)) {
        return &pile->pile_cards[pile->top_card--];
    }
}


// Function to return the top_card from stack without removing it
Card* pile_peek(Pile* pile)
{
    if (!pile_is_empty(pile))
        return &pile->pile_cards[pile->top_card];
}

void test_function() {
    Pile* pile = pile_constructor(5);
    for (size_t i = 0; i < 5; i++) {
        Card* card = card_constructor();
        card_initialize_card_values(card, i, i, i);
        pile_push(pile, card);
    }

    card_print_card_values(pile_peek(pile));

    for (size_t i = 0; i < 5; i++) {
        Card* popped_card = pile_pop(pile);
        card_print_card_values(popped_card);
    }

    exit(0);
}