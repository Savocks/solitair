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

void printRules() ;
void printGameCommands();
void print_board_row(Pile* pile, Foundation* foundation);


void print_rules() {
    printf("SCOPO DEL GIOCO");
    printf("\n");
    printf("Spostare tutte le carte nelle pile di base.\n");
    printf("REGOLE:\n");
    printf("4 PILE DI BASE (al centro):\n");
    printf("-Costruire file di carte per seme senza tener conto del valore.\n");
    printf("-Nella pila di base superiore � possibile mettere qualsiasi carta dello stesso seme della prima carta distribuita dal mazzo.\n");

}

void print_game_commands() {
    printf("1 - Primo mazzo scoperto \t 2 - Secondo mazzo scoperto \t 3 - Terzo mazzo scoperto \t 4 - Quarto mazzo scoperto \t 5 - Gira carta \t 6 - Muovi carta scoperta\n");
}

void print_board_row(Pile* pile, Foundation* foundation) {

}
