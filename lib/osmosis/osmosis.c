//
// Created by giuli on 16/01/2021.
//

#define PILE_SIZE 4
#define DISCARD_PILE_SIZE 35
#define FOUNDATION_SIZE 13

#include "osmosis.h"

Osmosis* osmosis_constructor() {
    Osmosis* osmosis = calloc(1, sizeof(Osmosis));
    return osmosis;
}

void init_game_elements(Osmosis* game) {
    game->deck = deck_constructor();
    game->discard_pile = discard_pile_constructor(DISCARD_PILE_SIZE);
    game->first_pile = pile_constructor(PILE_SIZE);
    game->second_pile = pile_constructor(PILE_SIZE);
    game->third_pile = pile_constructor(PILE_SIZE);
    game->fourth_pile = pile_constructor(PILE_SIZE);
    game->first_foundation = foundation_constructor(FOUNDATION_SIZE);
    game->second_foundation = foundation_constructor(FOUNDATION_SIZE);
    game->third_foundation = foundation_constructor(FOUNDATION_SIZE);
    game->forth_foundation = foundation_constructor(FOUNDATION_SIZE);
}

void deal_cards(Osmosis* game) {
    for (size_t i = 0; i < PILE_SIZE; i++) {
        Card* popped_card = deck_pop(game->deck);
        pile_push(game->first_pile, popped_card);
    }
    for (size_t i = 0; i < PILE_SIZE; i++) {
        Card* popped_card = deck_pop(game->deck);
        pile_push(game->second_pile, popped_card);
    }
    for (size_t i = 0; i < PILE_SIZE; i++) {
        Card* popped_card = deck_pop(game->deck);
        pile_push(game->third_pile, popped_card);
    }
    for (size_t i = 0; i < PILE_SIZE; i++) {
        Card* popped_card = deck_pop(game->deck);
        pile_push(game->fourth_pile, popped_card);
    }

    Card* first_card_on_field = deck_pop(game->deck);
    foundation_push(game->first_foundation, first_card_on_field);
}

void prepare_game(Osmosis* game) {
    init_game_elements(game);
    deal_cards(game);
}

void start_game(void) {
    Osmosis* game = osmosis_constructor();
    prepare_game(game);
}

void display_menu() {
    int choice = 0;
    printf("Ciao, benvenuto in Osmosi Solitaire\n");
    do {
        printf("Fai la tua scelta!\n");
        printf("1 - Nuova Partita");
        printf("\n");
        printf("2 - Regole del gioco");
        printf("\n");
        printf("3 - Esci dal gioco");
        printf("\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                start_game();
                break;
            case 2:
                break;
        }
    } while (choice != 3);
}