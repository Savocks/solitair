#include "foundation.h"


Foundation* foundation_constructor(unsigned capacity)
{
    Foundation* foundation = calloc(1, sizeof(Foundation));
    foundation->capacity = capacity;
    foundation->top_card = -1;
    foundation->seed = 0;
    foundation->foundation_cards = calloc(foundation->capacity, sizeof(Card));
    return foundation;
}

// Stack is full when top_card is equal to the last index
bool foundation_is_full(Foundation* foundation)
{
    return foundation->top_card == foundation->capacity - 1;
}

// Stack is empty when top_card is equal to -1
bool foundation_is_empty(Foundation* foundation)
{
    return foundation->top_card == -1;
}

bool foundation_check_if_value_exists(Foundation* foundation, Card* card) {
    for (int i = 0; i < foundation->capacity; i++) {
        if (foundation->foundation_cards[i].value == card->value) return true;
    }
    return false;
}

bool foundation_can_push_card(Foundation* foundation, Card* card) {
    if (foundation->seed == card->seed)
        return true;
    return false;
}

bool foundation_push(Foundation* foundation, Card* card) {
    if (foundation_is_full(foundation))
        return false;
    if (foundation_can_push_card(foundation, card)) {
        foundation->top_card++;
        foundation->foundation_cards[foundation->top_card].color = card->color;
        foundation->foundation_cards[foundation->top_card].value = card->value;
        foundation->foundation_cards[foundation->top_card].seed = card->seed;
        return true;
    }
    return false;
}

Card* foundation_pop(Foundation* foundation) {
    if (!foundation_is_empty(foundation)) {
        return &foundation->foundation_cards[foundation->top_card--];
    }
    return NULL;
}


// Function to return the top_card from stack without removing it
Card* foundation_peek(Foundation* foundation)
{
    if (!foundation_is_empty(foundation))
        return &foundation->foundation_cards[foundation->top_card];
    return NULL;
}