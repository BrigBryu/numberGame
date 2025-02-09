#include "Card.h"

#ifndef DECK_H
#define DECK_H

typedef struct {
    Card *cards;
    int numCards;
    int capacity;
} Deck;

void addCard(Deck *deck, Card card);
/*
 * removes first found based on same type, value, op, position
 */
void removeCard(Deck *deck, Card card);
void initDefaultDeck(Deck *deck);
int drawCard(Deck *deck, Card *card);


#endif
