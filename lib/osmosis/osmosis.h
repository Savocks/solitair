//
// Created by giuli on 16/01/2021.
//

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../pile/pile.h"
#include "../foundation/foundation.h"
#include "../deck/deck.h"
#include "../discard_pile/discard_pile.h"

#ifndef SOLITAIR_OSMOSIS_H
#define SOLITAIR_OSMOSIS_H

#endif //SOLITAIR_OSMOSIS_H

typedef struct Osmosis {
    Pile* first_pile;
    Pile* second_pile;
    Pile* third_pile;
    Pile* fourth_pile;
    Foundation* first_foundation;
    Foundation* second_foundation;
    Foundation* third_foundation;
    Foundation* forth_foundation;
    Deck* deck;
    DiscardPile* discard_pile;
    bool isWin;
    bool isFinish;
} Osmosis;

Osmosis* osmosis_constructor();

void init_game_elements(Osmosis* game);

void deal_cards(Osmosis* game);

void prepare_game(Osmosis* game);

void check_remaining_moves(Osmosis* game);

bool move_card(Osmosis* game, Card* card_to_move);

void move_card_from_pile(Osmosis* game, Pile* pile);

void move_card_from_discard_pile(Osmosis* game, DiscardPile* discard_pile);

void flip_card(Osmosis* game);

void reset_deck(Osmosis* game);

void start_game(void);

void display_menu();
