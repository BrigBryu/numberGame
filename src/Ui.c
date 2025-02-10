#include "Ui.h"

void initNcurses() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
}

void freeNcurses() {
    endwin();
}

void drawEquationScreen(Hand *hand, int score) {
    clear();
    
    // score.
    mvprintw(1, 2, "Score: %d", score);
     
    // hand.
    mvprintw(5, 2, "Your Hand:");
    for (int i = 0; i < hand->numCards; i++) {
        mvprintw(6 + i, 4, "[%d] Type: %d, Value: %d, Operator: %d, Position: %d",
                 i, hand->cards[i]->type, hand->cards[i]->value,
                 hand->cards[i]->op, hand->cards[i]->position);
    }
    
    refresh();
}

int getInput() {
    return getch();
}
