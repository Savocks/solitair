//
// Created by giuli on 10/01/2021.
//

#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include "lib/deck/deck.h"

int main() {
    initscr(); /* Start curses mode */
    printw("Hello World !!!"); /* Print Hello World */
    refresh(); /* Print it on to the real screen */
    getch(); /* Wait for user input */
    endwin(); /* End curses */
    return 0;
}