#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "models.h"

#define SPADE "♠"
#define CLUB "♣"
#define HEART "♥"
#define DIAMOND "♦"

void printRules() ;
void printGameCommands();
void printBoard(s_osmosis*);
void printBoardRow(s_card* , s_card* , bool isDeck);
char* concat(char*, char*);
char* transformValueCard(int value);
char* transformSuitCard(int suit);
char* getCardValueAndSuit(int value, int suit);



void printRules() {
    printf("SCOPO DEL GIOCO");
    printf("\n");
    printf("Spostare tutte le carte nelle pile di base.\n");
    printf("REGOLE:\n");
    printf("4 PILE DI BASE (al centro):\n");
    printf("-Costruire file di carte per seme senza tener conto del valore.\n");
    printf("-Nella pila di base superiore � possibile mettere qualsiasi carta dello stesso seme della prima carta distribuita dal mazzo.\n");

}

void printGameCommands() {
    printf("1 - Primo mazzo scoperto \t 2 - Secondo mazzo scoperto \t 3 - Terzo mazzo scoperto \t 4 - Quarto mazzo scoperto \t 5 - Gira carta \t 6 - Muovi carta scoperta\n");
}

void printBoard(s_osmosis* game) {
    system("clear");
    printf("\n***************************************************\n");
    printf("***************************************************\n");
    printBoardRow(game->fStack->cards, game->fFlippedStack->cards, false);
    printBoardRow(game->sStack->cards, game->sFlippedStack->cards, false);
    printBoardRow(game->tStack->cards, game->tFlippedStack->cards, false);
    printBoardRow(game->fourthStack->cards, game->fourthFlippedStack->cards, false);
    printBoardRow(game->fDeck->cards, game->deck->cards, true);
    printf("***************************************************\n");


}

void printBoardRow(s_card *stack, s_card *flippedStack, bool isDeck) {
    if (!isDeck) {
        printf("**\t%s\t\t%s %s %s %s %s %s %s %s %s %s %s %s %s**\n",
               getCardValueAndSuit(stack[0].value, stack[0].suit),
               getCardValueAndSuit(flippedStack[0].value, flippedStack[0].suit),
               getCardValueAndSuit(flippedStack[1].value, flippedStack[1].suit),
               getCardValueAndSuit(flippedStack[2].value, flippedStack[2].suit),
               getCardValueAndSuit(flippedStack[3].value, flippedStack[3].suit),
               getCardValueAndSuit(flippedStack[4].value, flippedStack[4].suit),
               getCardValueAndSuit(flippedStack[5].value, flippedStack[5].suit),
               getCardValueAndSuit(flippedStack[6].value, flippedStack[6].suit),
               getCardValueAndSuit(flippedStack[7].value, flippedStack[7].suit),
               getCardValueAndSuit(flippedStack[8].value, flippedStack[8].suit),
               getCardValueAndSuit(flippedStack[9].value, flippedStack[9].suit),
               getCardValueAndSuit(flippedStack[10].value, flippedStack[10].suit),
               getCardValueAndSuit(flippedStack[11].value, flippedStack[11].suit),
               getCardValueAndSuit(flippedStack[12].value, flippedStack[12].suit)
        );
        printf("\n");
    } else {
        printf("**\t\t\t\t\t      %s %s**\n", getCardValueAndSuit(flippedStack[0].value, flippedStack[0].suit),
               getCardValueAndSuit(stack[0].value, stack[0].suit));
        printf("\n");
    }
}

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
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

char* getCardValueAndSuit(int value, int suit) {
    return concat(transformValueCard(value), transformSuitCard(suit));
}

