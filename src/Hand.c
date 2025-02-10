#include "Hand.h"
#include "Deck.h"
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_HAND_CAPACITY 5

void initHand(Hand *hand) {
    hand->capacity = INITIAL_HAND_CAPACITY;
    hand->numCards = 0;
    hand->cards = malloc(hand->capacity * sizeof(Card *));
    if(hand->cards == NULL){
        perror("Failed to allocate memory for hand");
        exit(EXIT_FAILURE);
    }
}

void populateHand(Hand *hand, Deck *deck) {
    hand->numCards = 0;
    int cardsToDraw = (hand->capacity < deck->numCards) ? hand->capacity : deck->numCards;
    for (int i = 0; i < cardsToDraw; i++){
        hand->cards[i] = deck->cards[i];
        hand->numCards++;
    }
}

int evalHandBasic(Hand *hand) {
    int total = 0;
    for(int i = 0; i < hand->numCards; i++){
        switch(hand->cards[i]->op) {
            case ADD:
                total += hand->cards[i]->value;
                break;
            case MULT:
                printf("MULT not implemented.\n");
                break;
            case NTH:
                printf("NTH not implemented.\n");
                break;
            case EQ:
                printf("EQ not implemented.\n");
                break;
            default:
                printf("Unknown operator.\n");
                break;
        }
    }
    return total;
}

void freeHand(Hand *hand) {
    free(hand->cards);
}
