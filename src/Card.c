#include "Card.h"
#include <stdlib.h>

CardType generateCardType(int level){
    int chance = rand() % 100 + 1;
    if(chance < 75 - level) {
        return BASIC;
    } else if(chance < 95 - level) {
        return RARE;
    } else {
        return EPIC;
    }
}

OperatorType generateCardOp(int level){
    return ADD;
}

int generateCardValue(int level){
    return 5;
}

void generateCard(Card *cardp, int level){
    cardp->type = generateCardType(level);
    cardp->op = generateCardOp(level);
    cardp->value = generateCardValue(level);
    cardp->position = 0;  // default starting position
}
