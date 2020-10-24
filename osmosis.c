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
    printf("%d", game->fStack->cards[0].value);
    distributeCards(deck, game);
    int choice;
    do {
        printBoard(game);
        printGameCommands();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                moveCard(&game->fStack, &game);
                break;
            case 2:
                moveCard(&game->sStack, &game);
                break;
            case 3:
                moveCard(&game->tStack, &game);
                break;
            case 4:
                moveCard(&game->fourthStack, &game);
                break;
            case 5:
                break;
            case 6:
                break;
        }
    } while (!game->isFinished);

}

int main() {
    srand(time(NULL));
    displayMenu();
    return 0;
}


