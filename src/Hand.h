#include "Card.h"
#include "Deck.h"

#ifndef HAND_H
#define HAND_H
typedef struct{
    Card **cards;
    int numCards;
    int capacity;
} Hand;
void initHand(Hand *hand);
void populateHand(Hand *hand, Deck *deck);
int evalHandBasic(Hand *hand);
void freeHand(Hand *hand);
#endif
