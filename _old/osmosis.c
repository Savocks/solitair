#include <time.h>
#include <langinfo.h>
#include "cards.h"


void displayMenu();

void startGame();

void shuffle(s_card *array, int n);




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

                break;
            case 0:
                exit(0);
            default:
                break;
        }
    } while (!game->isFinished);

}

int main() {
    srand(time(NULL));
    displayMenu();
    return 0;
}


