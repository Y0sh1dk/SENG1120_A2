//
// Created by Yosiah on 24/09/2020.
//

#include "string.h"
#include "Queue.h"
#include "Card.h"

#ifndef UNTITLED2_HANDOFCARDS_H
#define UNTITLED2_HANDOFCARDS_H

class HandOfCards {
public:

    HandOfCards();

    ~HandOfCards();

    void add(Card c, bool b);

    int count();

    int countAll();

    std::string value();

    void faceUp();



private:
    Queue<Card>* data;


};


std::ostream &operator<<(std::ostream &out, HandOfCards &h);

#endif //UNTITLED2_HANDOFCARDS_H
