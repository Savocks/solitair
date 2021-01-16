//
// Created by giuli on 10/01/2021.
//

#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include "lib/deck/deck.h"
#include "lib/pile/pile.h"

int main() {
    initscr(); /* Start curses mode */
    int height, width, start_y, start_x;
    height = 200;
    width = 400;
    start_x = 10;
    start_y = 10;

    WINDOW* win = newwin(height, width, start_y, start_x);

    int c = getch();

    endwin();

    return 0;
}