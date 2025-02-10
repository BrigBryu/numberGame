#ifndef CARD_H
#define CARD_H

typedef enum {
    BASIC = 0,
    RARE,
    EPIC
} CardType;

typedef enum {
    ADD = 0,
    MULT,
    NTH,
    EQ
} OperatorType;

typedef struct {
    CardType type;
    int value;
    OperatorType op;
    int position; //position 0 is next to serve position -1 is not to be served any positive is number away from next serve
} Card;

void generateCard(Card *cardp, int level);
#endif
