#include "cardutils.h"


void displayMenu();

void startGame();

void shuffle(s_card *array, int n);

void displayMenu() {
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
                startGame();
                break;
            case 2:
                printRules();
                break;
        }
    } while (choice != 3);
}



void moveCard(s_card *pCard, s_card *fFlip, s_card *sFlip, s_card *tFlip, s_card *fourthFlip) {
    s_card card = pCard[0];
    bool moved = false;
    while (!moved) {
        if (card.suit == fFlip[0].suit) {
            size_t n = sizeof(fFlip);
            fFlip[n+1] = card;
            moved = true;
        }
        if (card.suit == sFlip[0].suit) {
            size_t n = sizeof(sFlip);
            sFlip[n+1] = card;
            moved = true;
        }
        if (card.suit == tFlip[0].suit) {
            size_t n = sizeof(tFlip);
            tFlip[n+1] = card;
            moved = true;
        }
        if (card.suit == fourthFlip[0].suit) {
            size_t n = sizeof(fourthFlip);
            fourthFlip[n+1] = card;
            moved = true;
        }

    }
}

void startGame() {
    printf("Buona fortuna");
    printf("\n");
    s_osmosis* game = calloc(1, sizeof(s_osmosis));
    game->fDeck = calloc(1, sizeof(s_stack));
    game->fDeck->cards = calloc(35, sizeof(s_card));
    game->deck = calloc(1, sizeof(s_stack));
    game->deck->cards = calloc(35, sizeof(s_card));
    game->fStack = calloc(1, sizeof(s_stack));
    game->fStack->cards = calloc(4, sizeof(s_card));
    game->sStack = calloc(1, sizeof(s_stack));
    game->sStack->cards = calloc(4, sizeof(s_card));
    game->tStack = calloc(1, sizeof(s_stack));
    game->tStack->cards = calloc(4, sizeof(s_card));
    game->fourthStack = calloc(1, sizeof(s_stack));
    game->fourthStack->cards = calloc(4, sizeof(s_card));
    game->fFlippedStack = calloc(1, sizeof(s_stack));
    game->fFlippedStack->cards = calloc(4, sizeof(s_card));
    game->sFlippedStack = calloc(1, sizeof(s_stack));
    game->sFlippedStack->cards = calloc(4, sizeof(s_card));
    game->tFlippedStack = calloc(1, sizeof(s_stack));
    game->tFlippedStack->cards = calloc(4, sizeof(s_card));
    game->fourthFlippedStack = calloc(1, sizeof(s_stack));
    game->fourthFlippedStack->cards = calloc(4, sizeof(s_card));
    createOsmosisGame(game);

    int choice;

    do {
        printBoard(game);
        printGameCommands();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
        }
    } while (!game->isFinished);

}
int main() {
    displayMenu();
    return 0;
}


