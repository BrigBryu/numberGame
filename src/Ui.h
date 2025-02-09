#ifndef UI_H
#define UI_H

#include "deck.h"
#include "equation.h"
#include <ncurses.h>

void init_ncurses();
void cleanup_ncurses();
void draw_screen(Hand *hand, Equation *eq, int score);
int get_user_input();

#endif
