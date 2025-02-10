#include "Deck.h"
#include "Card.h"
#include <stdlib.h>
#include <stdio.h>

#define INITIAL_DECK_CAPACITY 6

// Helper function to grow the deck's pointer array.
static void reallocDeck(Deck *deck) {
    int newCapacity = deck->capacity * 2;
    Card **temp = realloc(deck->cards, newCapacity * sizeof(Card *));
    if(temp == NULL){
        newCapacity = deck->capacity + (deck->capacity / 2);
        temp = realloc(deck->cards, newCapacity * sizeof(Card *));
        if(temp == NULL){
            fprintf(stderr, "Failed to allocate memory for a larger deck\n");
            exit(EXIT_FAILURE);
        }
    }
    deck->cards = temp;
    deck->capacity = newCapacity;
}

void initDeck(Deck *deck) {
    deck->capacity = INITIAL_DECK_CAPACITY;
    deck->numCards = 0;
    deck->cards = malloc(deck->capacity * sizeof(Card *));
    if(deck->cards == NULL){
        perror("Failed to allocate memory for deck");
        exit(EXIT_FAILURE);
    }
}

void addCard(Deck *deck, int level) {
    if(deck->numCards >= deck->capacity){
        reallocDeck(deck);
    }
    // Allocate a new Card on the heap.
    Card *newCard = malloc(sizeof(Card));
    if(newCard == NULL){
        perror("Failed to allocate memory for new card");
        exit(EXIT_FAILURE);
    }
    generateCard(newCard, level);
    deck->cards[deck->numCards++] = newCard;
}

// This helper frees a card at a given index and shifts the rest.
static void removeDeckIndex(Deck *deck, int index) {
    if(index < 0 || index >= deck->numCards){
        fprintf(stderr, "Invalid index in removeDeckIndex\n");
        return;
    }
    free(deck->cards[index]);
    for(int i = index; i < deck->numCards - 1; i++){
        deck->cards[i] = deck->cards[i + 1];
    }
    deck->numCards--;
}

void removeCard(Deck *deck, Card *card) {
    for(int i = 0; i < deck->numCards; i++){
        if(deck->cards[i] == card) {
            removeDeckIndex(deck, i);
            break;
        }
    }
}

// Helper: adjust positions after drawing.
static void discardTopCard(Deck *deck) {
    for(int i = 0; i < deck->numCards; i++){
        if(deck->cards[i]->position == 0){
            deck->cards[i]->position = -1;
        } else if(deck->cards[i]->position != -1){
            deck->cards[i]->position--;
        }
    }
}

// Returns 1 if a card was found and drawn, 0 otherwise.
// The drawn card pointer is returned via the output parameter.
int drawCard(Deck *deck, Card **card) {
    for(int i = 0; i < deck->numCards; i++){
        if(deck->cards[i]->position == 0){
            discardTopCard(deck);
            *card = deck->cards[i];
            return 1;
        }
    }
    return 0;
}

// Add a few default cards to the deck.
void initDefaultDeck(Deck *deck) {
    addCard(deck, 0);  // level 0 card
    addCard(deck, 0);
    addCard(deck, 0);
    addCard(deck, 0);
    addCard(deck, 0);
    addCard(deck, 0);
}

void freeDeck(Deck *deck) {
    for (int i = 0; i < deck->numCards; i++){
        free(deck->cards[i]);
    }
    free(deck->cards);
}
