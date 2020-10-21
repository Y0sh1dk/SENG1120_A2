//
// Created by Yosiah on 24/09/2020.
//
#include "Queue.h"
#include "Card.h"
#include "string.h"

#ifndef UNTITLED2_DECKOFCARDS_H

class DeckOfCards {
public:

    DeckOfCards();
    
    ~DeckOfCards();

    void shuffle();

    Card draw();

    int size();

    std::string printDeck();

private:
    std::string intToString(int n);

    Queue<Card>* data;

};


std::ostream &operator<<(std::ostream &out, DeckOfCards &l);

#define UNTITLED2_DECKOFCARDS_H

#endif //UNTITLED2_DECKOFCARDS_H
