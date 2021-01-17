#define PILE_SIZE 4
#define DISCARD_PILE_SIZE 35
#define FOUNDATION_SIZE 13

#include "osmosis.h"
#include "../utils/printer.h"

Osmosis* osmosis_constructor() {
    Osmosis* osmosis = calloc(1, sizeof(Osmosis));
    init_game_elements(osmosis);
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
    game->first_foundation->seed = first_card_on_field->seed;
    foundation_push(game->first_foundation, first_card_on_field);
}

void prepare_game(Osmosis* game) {
    init_game_elements(game);
    deal_cards(game);
}

bool move_card(Osmosis* game, Card* card_to_move) {
    if (foundation_push(game->first_foundation, card_to_move)) {
        return true;
    }
    if (foundation_check_if_value_exists(game->first_foundation, card_to_move)) {
        if (foundation_is_empty(game->second_foundation)) {
            game->second_foundation->seed = card_to_move->seed;
        }
        if (foundation_push(game->second_foundation, card_to_move)) {
            return true;
        }
    }
    if (foundation_check_if_value_exists(game->second_foundation, card_to_move)) {
        if (foundation_is_empty(game->third_foundation)) {
            game->third_foundation->seed = card_to_move->seed;
        }
        if (foundation_push(game->third_foundation, card_to_move)) {
            return true;
        }
    }
    if (foundation_check_if_value_exists(game->third_foundation, card_to_move)) {
        if (foundation_is_empty(game->forth_foundation)) {
            game->forth_foundation->seed = card_to_move->seed;
        }
        if (foundation_push(game->forth_foundation, card_to_move)) {
            return true;
        }
    }
    return false;
}


void move_card_from_pile(Osmosis* game, Pile* pile) {
    Card* card_to_move = pile_peek(pile);
    if (move_card(game, card_to_move))
        if (pile->top_card > 0)
            pile_pop(pile);
}

void move_card_from_discard_pile(Osmosis* game, DiscardPile* discard_pile) {
    Card* card_to_move = discard_pile_peek(discard_pile);
    if (discard_pile->top_card == -1) {
        return;
    } else if (move_card(game, card_to_move))
        discard_pile_pop(discard_pile);
}

void flip_card(Osmosis* game) {
    Card* card = deck_peek(game->deck);
    if (game->deck->top_card == 0) {
        reset_deck(game);
    }
    discard_pile_push(game->discard_pile, deck_pop(game->deck));
}

void reset_deck(Osmosis* game) {
    Card* card = discard_pile_peek(game->discard_pile);
    while (game->discard_pile->top_card >= 0) {
        if (card_is_valid(card)) {
            deck_push(game->deck, discard_pile_pop(game->discard_pile));
        }
    }
}

void start_game(void) {
    Osmosis* game = osmosis_constructor();
    prepare_game(game);
    int command_choice = 0;
    do {
        system("clear");
        print_game_board(game);
        print_game_commands();
        scanf("%d", &command_choice);
        switch (command_choice) {
            case 1:
                move_card_from_pile(game, game->first_pile);
                break;
            case 2:
                move_card_from_pile(game, game->second_pile);
                print_game_board(game);
                break;
            case 3:
                move_card_from_pile(game, game->third_pile);
                print_game_board(game);
                break;
            case 4:
                move_card_from_pile(game, game->fourth_pile);
                print_game_board(game);
                break;
            case 5:
                flip_card(game);
                break;
            case 6:
                move_card_from_discard_pile(game, game->discard_pile);
                break;
            case 0:
                return;
        }
    }
    while (command_choice != 0 || !game->isFinish);
    if (game->isWin) {
        printf("Hai vinto!");
    }
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
                print_rules();
                break;
        }
    } while (choice != 3);
}

void check_remaining_moves(Osmosis* game) {
    if (game->first_foundation->top_card == 12 &&
        game->second_foundation->top_card == 12 &&
        game->third_foundation->top_card == 12 &&
        game->forth_foundation->top_card == 12) {
        game->isFinish = true;
        game->isWin = true;
    }

}