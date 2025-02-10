#ifndef UI_H
#define UI_H

#include "Deck.h"
#include "Hand.h"
#include <ncurses.h>

void initNcurses();
void freeNcurses();
void drawEquationScreen(Hand *hand, int score);
int getInput();

#endif
