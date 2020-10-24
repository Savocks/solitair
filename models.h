//
// Created by giuli on 23/10/2020.
//

#ifndef SOLITAIR_MODELS_H
#define SOLITAIR_MODELS_H

#endif //SOLITAIR_MODELS_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
 * Definizione delle strutture che servono al gioco.
 */
typedef struct Card {
    int value;
    int suit;
    int color;
} s_card;

typedef struct CardStack {
    s_card* cards;
    s_card* firstCard;
    int maxCards;
    int currentElement;
} s_stack;

typedef struct Osmosis {
    bool isStarded;
    bool isFinished;
    s_stack* fStack;
    s_stack* sStack;
    s_stack* tStack;
    s_stack* fourthStack;
    s_stack* fFlippedStack;
    s_stack* sFlippedStack;
    s_stack* tFlippedStack;
    s_stack* fourthFlippedStack;
    s_stack* deck;
    s_stack* fDeck;
} s_osmosis;



