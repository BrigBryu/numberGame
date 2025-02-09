#include "Card.h"

#ifndef HAND_H
#define HAND_H
typedef struct{
    Card **cards;
    int numCards;
    int capacity;
} Hand;
void populateHand(Hand *hand, Deck *deck);
int evalHandBasic(Hand *hand);
#endif
