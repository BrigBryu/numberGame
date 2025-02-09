#include "Hand.h"

void populateHand(Hand *hand, Deck *deck){
    for(int i = 0; i < deck->numCards && i < hand->size; i++){
        int drew = drawCard(deck, hand->cards[i]); //add a card from the deck to the array of pointers to cards that point to some card in the deck
        if(drew){
            hand->numCards++;
        } else {
            printf("could not draw card when populating hand");
            return;
        }
    }
}

int evalHandBasic(Hand *hand){
    int total = 0;
    for(int i = 0; i < hand->numCards; i++){
        switch(*(hand->cards[i]).op) {
            case ADD:
                total += *(hand->cards[i].value);
                break;
            case MULT:
                printf("not done yet!");
                break;
            case NTH:
                printf("not done yet!");
                break;
            case EQ:
                printf("not done yet!");
                break;
            default:
                printf("unknown operator not done yet!");
                break;
        }
    }
}
