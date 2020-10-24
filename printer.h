//
// Created by giuli on 23/10/2020.
//

#ifndef SOLITAIR_PRINTER_H
#define SOLITAIR_PRINTER_H

#endif //SOLITAIR_PRINTER_H

#include <stdlib.h>
#include <stdio.h>
#include "models.h"
#include "mapperutils.h"

void printRules() ;
void printGameCommands();
void printBoard(s_osmosis*);
void printBoardRow(s_card* , int, s_card* , bool isDeck);


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
    printBoardRow(game->fStack->cards, game->fStack->currentElement, game->fFlippedStack->cards, false);
    printBoardRow(game->sStack->cards, game->sStack->currentElement, game->sFlippedStack->cards, false);
    printBoardRow(game->tStack->cards, game->tStack->currentElement, game->tFlippedStack->cards, false);
    printBoardRow(game->fourthStack->cards, game->fourthStack->currentElement, game->fourthFlippedStack->cards, false);
    printBoardRow(game->deck->cards, game->deck->currentElement, game->deck->cards, true);
    printf("***************************************************\n");


}

void printBoardRow(s_card *stack, int currentElement, s_card *flippedStack, bool isDeck) {
    if (!isDeck) {
        printf("**\t%s\t\t%s %s %s %s %s %s %s %s %s %s %s %s %s**\n",
               getCardValueAndSuit(stack[currentElement].value, stack[currentElement].suit),
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
               getCardValueAndSuit(stack[currentElement].value, stack[currentElement].suit));
        printf("\n");
    }
}
