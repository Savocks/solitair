//
// Created by giuli on 23/10/2020.
//

#pragma once

#ifndef SOLITAIR_PRINTER_H
#define SOLITAIR_PRINTER_H

#endif //SOLITAIR_PRINTER_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../osmosis/osmosis.h"
#include "../card/card.h"
#include "mapperutils.h"

void print_rules(void) ;
void print_game_commands(void);
void print_board_row(Pile* pile, Foundation* foundation);


void print_rules(void) {
    printf("Spostare tutte le carte nelle pile di base.\n");
    printf("\n");
    printf("Regole\n");
    printf("\n");
    printf("4 pile di base (al centro)\n");
    printf("\n");
    printf("Costruire file di carte per seme senza tener conto del valore.\n");
    printf("Nella pila di base superiore è possibile mettere qualsiasi carta dello stesso seme della prima carta distribuita dal mazzo.\n");
    printf("Nelle pile di base inferiori, si mette dapprima una carta dello stesso valore della prima carta della pila di base superiore, e poi su di essa qualsiasi carta dello stesso seme ma solo se nella pila di sopra è presente già una carta dello stesso valore.\n");
    printf("4 pile di riserva (a sinistra dalle pile di base)\n");
    printf("\n");
    printf("La carta superiore può essere messa nella pila di base.\n");
    printf("Tallone (in basso a destra)\n");
    printf("\n");
    printf("Le carte dal tallone vanno al pozzo una alla volta.\n");
    printf("Ridistribuzioni illimitate.\n");
    printf("Pozzo (accanto al tallone)\n");
    printf("\n");
    printf("La carta superiore può essere messa nella pila di base.\n");
    printf("Spostare tutte le carte nelle pile di base.\n");
    printf("\n");
    printf("Regole\n");
    printf("\n");
    printf("•4 pile di base (al centro)\n");
    printf("\n");
    printf("-Costruire file di carte per seme senza tener conto del valore.\n");
    printf("-Nella pila di base superiore è possibile mettere qualsiasi carta dello stesso seme della prima carta distribuita dal mazzo.\n");
    printf("-Nelle pile di base inferiori, si mette dapprima una carta dello stesso valore della prima carta della pila di base superiore, e poi su di essa qualsiasi carta dello stesso \n");
    printf("  seme ma solo se nella pila di sopra è presente già una carta dello stesso valore.\n");
    printf("•4 pile di riserva (a sinistra dalle pile di base)\n");
    printf("\n");
    printf("La carta superiore può essere messa nella pila di base.\n");
    printf("Tallone (in basso a destra)\n");
    printf("\n");
    printf("Le carte dal tallone vanno al pozzo una alla volta.\n");
    printf("Ridistribuzioni illimitate.\n");
    printf("Pozzo (accanto al tallone)\n");
    printf("\n");
    printf("La carta superiore può essere messa nella pila di base.");
}

void print_game_commands(void) {
    printf("1 - Primo mazzo scoperto \t"
           "2 - Secondo mazzo scoperto \t"
           "3 - Terzo mazzo scoperto \t"
           "4 - Quarto mazzo scoperto \t"
           "5 - Gira carta \t"
           "6 - Muovi carta scoperta\n"
           "0 - Esci dal gioco");
}

void print_board_row(Pile* pile, Foundation* foundation) {
    printf("(%d)%s\t %s %s %s %s %s %s %s %s %s %s %s %s %s\n",
           pile->top_card + 1, getCardValueAndSuit(&pile->pile_cards[pile->top_card]),
           getCardValueAndSuit(&foundation->foundation_cards[0]),
           getCardValueAndSuit(&foundation->foundation_cards[1]),
           getCardValueAndSuit(&foundation->foundation_cards[2]),
           getCardValueAndSuit(&foundation->foundation_cards[3]),
           getCardValueAndSuit(&foundation->foundation_cards[4]),
           getCardValueAndSuit(&foundation->foundation_cards[5]),
           getCardValueAndSuit(&foundation->foundation_cards[6]),
           getCardValueAndSuit(&foundation->foundation_cards[7]),
           getCardValueAndSuit(&foundation->foundation_cards[8]),
           getCardValueAndSuit(&foundation->foundation_cards[9]),
           getCardValueAndSuit(&foundation->foundation_cards[10]),
           getCardValueAndSuit(&foundation->foundation_cards[11]),
           getCardValueAndSuit(&foundation->foundation_cards[12])
           );
}

void print_deck_row(DiscardPile* discard_pile, Deck* deck) {

    if (discard_pile_is_empty(discard_pile)) {
        printf("X?\t%s\n",
               getCardValueAndSuit(deck_peek(deck))
        );
    } else {
        printf("\t\t\t\t%s\t(%d)%s\n",
               getCardValueAndSuit(discard_pile_peek(discard_pile)),
               deck->top_card + 1,
               getCardValueAndSuit(deck_peek(deck))
        );
    }
}

void print_game_board(Osmosis* game) {
    print_board_row(game->first_pile, game->first_foundation);
    print_board_row(game->second_pile, game->second_foundation);
    print_board_row(game->third_pile, game->third_foundation);
    print_board_row(game->fourth_pile, game->forth_foundation);
    print_deck_row(game->discard_pile, game->deck);
}
