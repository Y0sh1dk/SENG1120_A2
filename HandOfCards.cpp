/*
 * Name: Yosiah de Koeyer
 * Student No: c3329520
 * Course: SENG1120 - A2
 */

#include <sstream>
#include "HandOfCards.h"
#include "Queue.h"
#include "Card.h"


HandOfCards::HandOfCards() {
    data = new Queue<Card>;
}

HandOfCards::~HandOfCards() {
    delete(data);
}

void HandOfCards::add(Card c, bool b) {
    data->enqueue(Card(c.getFace(), c.getValue(), b));
}

int HandOfCards::count() {
    int c = 0;
    for( int i = 0; i < data->size(); i++) {
        Card tempCard = data->dequeue();
        if (tempCard.getFaceUp() == true) {
            c += tempCard.getValue();
        }
        data->enqueue(tempCard);
    }
    return c;
}

int HandOfCards::countAll() {
    int c = 0;
    for( int i = 0; i < data->size(); i++) {
        Card tempCard = data->dequeue();
        c += tempCard.getValue();
        data->enqueue(tempCard);
    }
    return c;
}

std::string HandOfCards::value() {
    std::string cardSequence;
    for( int i = 0; i < data->size(); i++) {
        Card tempCard = data->dequeue();
        if (tempCard.getFaceUp() == true) {
            cardSequence += tempCard.getFace() + " ";
        }
        else {
            cardSequence += "?-? ";
        }
        data->enqueue(tempCard);
    }
    return cardSequence;
}

void HandOfCards::faceUp() {
    for( int i = 0; i < data->size(); i++) {
        Card tempCard = data->dequeue();
        tempCard.setFaceUp(true);
        data->enqueue(tempCard);
    }
}


std::ostream &operator<<(std::ostream &out, HandOfCards &h) {
    std::stringstream ss;
    std::string s;
    ss<< h.count();
    ss>>s;
    out << h.value() + +"(" + s + " points)";
    return out;
}