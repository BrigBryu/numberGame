#include "Card.h"

void realocDeck(Deck *deck){
    int newCapacity = deck->capacity*2;
    deck->cards = realloc(deck->cards, newCapacity *sizeof(Card));
    if(deck->cards == NULL){
        //could not realloc so try with less capacity
        newCapacity -= capacity/2; //1.5 of original size
        realloc(deck->cards, newCapacity *sizeof(Card));
        if(deck->cards == NULL){
            printf("Failled to allocate memory for a larger deck");
            exit(1); //1 is fail
        }
    }
    deck->capacity = newCapacity;
}

void addCard(Deck *deck, Card card){
    if(deck->numCards <= deck->capacity){
        realocDeck(deck);
    }
    deck->cards[deck->numCards] = card;
    numCards++;
}


void removeDeckIndex(Deck *deck, int index){
    if(index < 0 || index >= deck->numCards){
        Sy
    }
    for(int i = index; i < numCards - 1; i++){
        deck->cards[i] = deck->cards[i + 1]; //both are actual memory so = moves one memory into the other if they were both pointers would not affect the actual memeory values
    }
    numCards--;
}

void removeCard(Deck *deck, Card card){
    for(int i = 0; i < numCards; i++){
        if(deck->cards[i].type == card.type 
                && deck->cards[i].value == card.valye
                && deck->cards[i].op == card.op
                && deck->cards[i].position == card.position) {
            removeDeckIndex(deck,i);
            break;
        }
    }
}

void discardTopCard(Deck *deck){
    for(int i = 0; i < deck->numCards; i++){
        if(deck->cards[i].position == 0) {
            deck->cards[i].position = -1;
        } else if (deck->cards[i].position != -1){
            deck->cards[i].position--;
        }
    }
}

int drawCard(Deck *deck, Card *card){
    int foundCard 
    for(int i = 0; i < deck->numCards; i++){
        if(deck->cards[i].position == 0){
            //found top card now update other cards
            discardTopCard(deck);
            card = deck->cards[i];
        }
    }
}

void intitDefaultDeck(Deck *deck){
    addCard(deck, (Card){BASIC, 5, ADD, 0});
    addCard(deck, (Card){BASIC, 4, ADD, 1});
    addCard(deck, (Card){BASIC, 3, ADD, 2});
    addCard(deck, (Card){BASIC, 2, ADD, 3});
    addCard(deck, (Card){BASIC, 1, ADD, 4});
    addCard(deck, (Card){BASIC, 1, ADD, 5});
}
