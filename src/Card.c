#include <stdlib.h>
#include "Card.h"

CardType generateCardType(int);
OperatorType generateCardOp(int);
int generateCardValue(int);
int generateCardPrice(int);

void generateCard(Card *cardp, int level){
    cardp->type = generateCardType(level);
    cardp->op = generateCardOp(level);
    card->value = generateCardValue(level);
    card->price = generateCardPrice(level);
}

CardType generateCardType(int level){
    return BASIC;
    int chance = rand() % 100 + 1;

    if(chance < 75 - level) {
        //common

    } else if (chance < 95 - level) {
        //rare
    } else if(chance <= 100 - level) {
        //epic
    } else {
        //common to catch mistakes
    }
}

OperatorType generateCardOp(int level){
    return ADD;
}

int generateCardValue(int level){
    return 5;
}

int generateCardPrice(int level){
    return 10;
}
