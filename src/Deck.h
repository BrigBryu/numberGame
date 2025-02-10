#ifndef DECK_H
#define DECK_H

#include "Card.h"

typedef struct {
    Card **cards;
    int numCards;
    int capacity;
} Deck;

void initDeck(Deck *deck);
void addCard(Deck *deck, int level);
void removeCard(Deck *deck, Card *card);
void initDefaultDeck(Deck *deck);
int drawCard(Deck *deck, Card **card);
void freeDeck(Deck *deck);

#endif
