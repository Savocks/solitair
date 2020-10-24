#include <time.h>
#include "cards.h"


void displayMenu();

void startGame();

void shuffle(s_card *array, int n);
s_osmosis* createOsmosisGame();

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

void startGame() {
    printf("Buona fortuna");
    printf("\n");
    s_osmosis* game = createOsmosisGame();
    s_stack* deck = initializeDeckOfCards();
    distributeCards(deck, game);

    int choice;
    do {
        printBoard(game);
        printGameCommands();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                moveCard(&game->fStack, &game, false);
                break;
            case 2:
                moveCard(&game->sStack, &game, false);
                break;
            case 3:
                moveCard(&game->tStack, &game, false);
                break;
            case 4:
                moveCard(&game->fourthStack, &game, false);
                break;
            case 5:
                flipDeckCard(&game->deck, &game);
                break;
            case 6:
                moveCard(&game->fDeck, &game, true);
                break;
            case 0:
                exit(0);
                break;
        }
    } while (!game->isFinished);

}

int main() {
    srand(time(NULL));
    displayMenu();
    return 0;
}


