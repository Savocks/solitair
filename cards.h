//
// Created by giuli on 23/10/2020.
//

#ifndef SOLITAIR_CARDS_H
#define SOLITAIR_CARDS_H

#endif //SOLITAIR_CARDS_H

#define MAX_CARD 52
#define MAX_SUIT_CARD 13
#define SUIT_NUMBER 4

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <memory.h>

#include "printer.h"
#include "utils.h"

s_osmosis* createOsmosisGame();
s_stack* initializeStack(int maxCards, bool isFlipped);
s_osmosis* initializeOsmosisGame();
s_stack* initializeDeckOfCards();
void initializeCard(s_card* card, int value, int color, int suit);
void fillDeck(s_stack* deck);
void giveCards(s_stack** deck, s_stack** stack, int cardToGive);
void distributeCards(s_stack*, s_osmosis*);
void flipDeckCard(s_osmosis*);
bool isEmptyStack(s_stack*);
bool isSuitPresentInStack(int, s_stack*);
bool isValuePresentInStack(int, s_stack*);
bool canAddCardToStack(s_card , s_stack*, s_stack*);
bool addCard(s_stack*, s_stack*, s_stack*);
bool moveCard(s_stack*, s_osmosis*);

s_osmosis* createOsmosisGame() {
    s_osmosis* game = initializeOsmosisGame();
    game->fDeck = initializeStack(35, true);
    game->deck = initializeStack(35, false);
    game->fStack = initializeStack(4, false);
    game->sStack = initializeStack(4, false);
    game->tStack = initializeStack(4, false);
    game->fourthStack = initializeStack(4, true);
    game->fFlippedStack = initializeStack(12, true);
    game->sFlippedStack = initializeStack(12, true);
    game->tFlippedStack = initializeStack(12, true);
    game->fourthFlippedStack = initializeStack(12, true);
    return game;
}

s_stack* initializeStack(int maxCards, bool isFlipped) {
    s_stack* stack = calloc(1, sizeof(*stack));
    stack->cards = calloc(maxCards, sizeof(s_card));
    if (!stack->cards) {
        perror("Stack Cards Calloc failed");
        exit(1);
    }
    stack->firstCard = calloc(1, sizeof(s_card));
    if (!stack->firstCard) {
        perror("Stack first Card Calloc failed");
        exit(1);
    }
    stack->maxCards = maxCards;
    if (isFlipped) {
        stack->currentElement = 0;
    } else {
        stack->currentElement = maxCards - 1;
    }
    return stack;
}

s_osmosis* initializeOsmosisGame() {
    s_osmosis* osmosis = calloc(1, sizeof(*osmosis));
    if (!osmosis) {
        perror("Osmosis Malloc Failed");
        exit(1);
    }
    return osmosis;
}

s_stack* initializeDeckOfCards() {
    s_stack* deck = initializeStack(52, false);
    fillDeck(deck);
    shuffle(deck->cards, MAX_CARD);
    return deck;
}

void initializeCard(s_card* card, int value, int color, int suit) {
    card->value = value;
    card->color = color;
    card->suit = suit;
}

void fillDeck(s_stack* deck) {
    int k = 0;
    for (int i = 1; i <= SUIT_NUMBER; i++) {
        for (int j = 1; j <= MAX_SUIT_CARD; j++) {
            initializeCard(&deck->cards[k], j, i, i);
            k++;
        }
    }
    deck->maxCards = MAX_CARD;
    deck->firstCard->suit = deck->cards[0].suit;
    deck->firstCard->value = deck->cards[0].value;
    deck->firstCard->color = deck->cards[0].color;
    deck->currentElement = MAX_CARD - 1;
}

void distributeCards(s_stack* deck, s_osmosis* game) {
    giveCards(&deck, &game->fStack, 4);
    giveCards(&deck, &game->sStack, 4);
    giveCards(&deck, &game->tStack, 4);
    giveCards(&deck, &game->fourthStack, 4);
    giveCards(&deck, &game->fFlippedStack, 1);
    giveCards(&deck, &game->fDeck, 1);
    giveCards(&deck, &game->deck, 34);
}

void giveCards(s_stack** deck, s_stack** stack, int cardToGive) {
    int j = (*deck)->maxCards - 1;
    for (int i = cardToGive - 1; i >= 0; i--) {
        (*stack)->cards[i] = (*deck)->cards[j];
        j--;
    }
    (*deck)->maxCards -= cardToGive;
}

void flipDeckCard(s_osmosis* game) {
    if (game->deck->currentElement == 0 && game->fDeck->currentElement == 34) {
        game->deck->currentElement = game->deck->maxCards;
        game->fDeck->currentElement = 0;
        return;
    } else {
        game->fDeck->currentElement++;
        game->deck->currentElement--;
        int currentDeckElement = game->deck->currentElement;
        int currentFlippedDeckElement = game->fDeck->currentElement;
        game->fDeck->cards[currentFlippedDeckElement] = game->deck->cards[currentDeckElement];
    }
}

bool moveCard(s_stack* stack, s_osmosis* game) {
    bool cardAdded = false;
    if (stack->currentElement < 0) {
        return cardAdded;
    } else {
        cardAdded = addCard(stack, game->fFlippedStack, NULL);
        if (!cardAdded) {
            cardAdded = addCard(stack, game->sFlippedStack, game->fFlippedStack);
            if (!cardAdded) {
                cardAdded = addCard(stack, game->tFlippedStack, game->sFlippedStack);
            }
            if (!cardAdded) {
                cardAdded = addCard(stack, game->fourthFlippedStack, game->tFlippedStack);
            }
            if (!cardAdded) {
                return false;
            } else {
                return true;
            }
        }
    }
    return cardAdded;
}

bool isEmptyStack(s_stack* stack) {
    if (stack->currentElement == 0) {
        return true;
    }
    return false;
}

bool isSuitPresentInStack(int suit, s_stack* stack) {
    if (stack->cards[0].suit == suit) {
        return true;
    }
    return false;
}

bool isValuePresentInStack(int cardValue, s_stack* stack) {
    for (int i = 0; i < stack->currentElement; ++i) {
        if (stack->cards[i].value == cardValue) {
            return true;
        }
    }
    return false;
}

bool canAddCardToStack(s_card cardToAdd, s_stack* stack, s_stack* stackToCheck) {
    int suit = cardToAdd.suit;
    int value = cardToAdd.value;
    if (stackToCheck == NULL) {
        if (isSuitPresentInStack(suit, stack)) return true;
    }
    else if (isEmptyStack(stack) && isValuePresentInStack(value, stackToCheck)) return true;
    else if (isSuitPresentInStack(suit, stack) && isValuePresentInStack(value, stackToCheck)) return true;
    return false;
}

bool addCard(s_stack* stackFrom, s_stack* stackTo, s_stack* stackToCheck) {
    s_card cardToAdd = stackFrom->cards[stackFrom->currentElement];
    if (canAddCardToStack(cardToAdd, stackTo, stackToCheck) && !stackToCheck) {
        stackTo->currentElement++;
        stackTo->cards[stackTo->currentElement] = cardToAdd;
        if (stackFrom->currentElement > 0) {
            stackFrom->currentElement--;
        }
        return true;
    } else if (canAddCardToStack(cardToAdd, stackTo, stackToCheck) && stackToCheck){
        stackTo->cards[stackTo->currentElement] = cardToAdd;
        stackTo->currentElement++;
        if (stackFrom->currentElement > 0) {
            stackFrom->currentElement--;
        }
    }
    return false;
}