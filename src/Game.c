#include "Game.h"
#include "Ui.h"
#include "Deck.h"
#include "Hand.h"
#include <stdlib.h>

void runGame() {
    Deck deck;
    Hand hand;
    int score = 0;

    initDeck(&deck);
    initHand(&hand);

    initDefaultDeck(&deck);

    populateHand(&hand, &deck);
    
    initNcurses();
    
    while (1) {
        drawEquationScreen(&hand, score);
        int input = getInput();

        if (input == 'q') {
            break; 
        } else if (input == ' ') {
            score += evalHandBasic(&hand);
            populateHand(&hand, &deck);
        }
        
    }

    freeNcurses();
    freeHand(&hand);
    freeDeck(&deck);
}
