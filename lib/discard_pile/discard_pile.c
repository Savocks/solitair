#define MAX_DISCARD_PILE 35
#include "discard_pile.h"

DiscardPile* discard_pile_constructor(unsigned capacity)
{
    DiscardPile* discard_pile = calloc(1, sizeof(DiscardPile));
    if(discard_pile == NULL) { exit(1); };

    discard_pile->discard_pile_cards = calloc(MAX_DISCARD_PILE, sizeof(Card));
    if(discard_pile->discard_pile_cards == NULL) { exit(1); };

    discard_pile->capacity = capacity;
    discard_pile->top_card = -1;
    return discard_pile;
}

// Stack is full when top_card is equal to the last index
bool discard_pile_is_full(DiscardPile* discard_pile)
{
    return discard_pile->top_card == discard_pile->capacity - 1;
}

// Stack is empty when top_card is equal to -1
bool discard_pile_is_empty(DiscardPile* discard_pile)
{
    return discard_pile->top_card == -1;
}


void discard_pile_push(DiscardPile* discard_pile, Card* card) {
    if (discard_pile_is_full(discard_pile))
        return;
    discard_pile->top_card++;
    discard_pile->discard_pile_cards[discard_pile->top_card].color = card->color;
    discard_pile->discard_pile_cards[discard_pile->top_card].value = card->value;
    discard_pile->discard_pile_cards[discard_pile->top_card].seed = card->seed;
}

Card* discard_pile_pop(DiscardPile* discard_pile) {
    if (!discard_pile_is_empty(discard_pile)) {
        return &discard_pile->discard_pile_cards[discard_pile->top_card--];
    }
    return NULL;
}


// Function to return the top_card from stack without removing it
Card* discard_pile_peek(DiscardPile* discard_pile)
{
    if (!discard_pile_is_empty(discard_pile))
        return &discard_pile->discard_pile_cards[discard_pile->top_card];
    return NULL;
}