//
// Created by giuli on 23/10/2020.
//
#pragma once

#define SPADE "♠"
#define CLUB "♣"
#define HEART "♥"
#define DIAMOND "♦"

#include <stdlib.h>
#include "string.h"

#ifndef SOLITAIR_MAPPERUTILS_H
#define SOLITAIR_MAPPERUTILS_H

#endif //SOLITAIR_MAPPERUTILS_H


char * transformValueCard(int value) {

    switch (value) {
        case 0:
            return "X";
        case 1:
            return "A";
        case 2:
            return "2";
        case 3:
            return "3";
        case 4:
            return "4";
        case 5:
            return "5";
        case 6:
            return "6";
        case 7:
            return "7";
        case 8:
            return "8";
        case 9:
            return "9";
        case 10:
            return "10";
        case 11:
            return "J";
        case 12:
            return "Q";
        case 13:
            return "K";
    }
}

char* transformSuitCard(int suit) {
    switch(suit){
        case 1:return SPADE;
        case 2:return CLUB;
        case 3:return HEART;
        case 4:return DIAMOND;
        default:return "?";
    }
}

char* concat(char *s1, char *s2)
{
    char *result = 
	result = (char*)calloc(1, strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

char* getCardValueAndSuit(Card* card) {
    return concat(transformValueCard(card->value), transformSuitCard(card->seed));
}
