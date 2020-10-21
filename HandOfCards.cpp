/*
 * Name: Yosiah de Koeyer
 * Student No: c3329520
 * Course: SENG1120 - A2
 *
 * File: HandOfCards.cpp
 * Description: HandOfCards Implementation
 */

#include <sstream>
#include "HandOfCards.h"
#include "Queue.h"
#include "Card.h"

/**********************************************************************************************************************/

HandOfCards::HandOfCards() {
    data = new Queue<Card>;
}

/**********************************************************************************************************************/

HandOfCards::~HandOfCards() {
    delete(data);
}

/**********************************************************************************************************************/

void HandOfCards::add(Card c, bool b) {
    data->enqueue(Card(c.getFace(), c.getValue(), b));
}

/**********************************************************************************************************************/

int HandOfCards::count() {
    int c = 0;
    for( int i = 0; i < data->size(); i++) {    // for all cards in hand
        Card tempCard = data->dequeue();        // dequeue into temp to read face
        if (tempCard.getFaceUp() == true) {
            c += tempCard.getValue();           // only add value if face up
        }
        data->enqueue(tempCard);                // enqueue temp
    }
    return c;
}

/**********************************************************************************************************************/

int HandOfCards::countAll() {
    int c = 0;
    for( int i = 0; i < data->size(); i++) {    // for all cards in hand
        Card tempCard = data->dequeue();        // dequeue into temp
        c += tempCard.getValue();               // add value
        data->enqueue(tempCard);                // enqueue temp
    }
    return c;
}

/**********************************************************************************************************************/

std::string HandOfCards::value() {
    std::string cardSequence;
    for( int i = 0; i < data->size(); i++) {            // for all cards in hand
        Card tempCard = data->dequeue();                // dequeue into temp
        if (tempCard.getFaceUp() == true) {
            cardSequence += tempCard.getFace() + " ";   // if card is facing up, get its face
        }
        else {
            cardSequence += "?-? ";                     // if card isnt facing up, "?-?"
        }
        data->enqueue(tempCard);                        // enqueue temp
    }
    return cardSequence;
}

/**********************************************************************************************************************/

void HandOfCards::faceUp() {                    // Could be more efficient using front()?
    for( int i = 0; i < data->size(); i++) {    // for all cards in hand
        Card tempCard = data->dequeue();        // dequeue into temp
        tempCard.setFaceUp(true);               // set faceup
        data->enqueue(tempCard);                // requeue
    }
}

/**********************************************************************************************************************/

std::ostream &operator<<(std::ostream &out, HandOfCards &h) {
    std::stringstream ss;
    std::string s;
    ss<< h.count();
    ss>>s;              // convert count to string
    out << h.value() + +"(" + s + " points)";
    return out;
}