/*
 * Name: Yosiah de Koeyer
 * Student No: c3329520
 * Course: SENG1120 - A2
 *
 * File: DeckOfCards.cpp
 * Description: DeckOfCards Implementation
 */

#include <iostream>
#include <cstdlib>
#include <string.h>
#include <sstream>
#include <time.h>
#include "DeckOfCards.h"
#include "Queue.h"
#include "Card.h"

/**********************************************************************************************************************/

std::string DeckOfCards::intToString(int n) {
    std::stringstream ss;
    std::string s;
    ss<<n;
    ss>>s;
    return s;
}

/**********************************************************************************************************************/

DeckOfCards::DeckOfCards() {
    data = new Queue<Card>;
    // TODO: Make better
    // Initialize all cards here
    // I made this at 1am, it could be crap (it is)
    for (int i = 0; i <= 3; i++) {          // Suit
        for(int j = 2; j <= 14; j++) {      // card
            std::string face;
            if (i == 0) {                   // clubs
                face = "-C";
            } else if (i == 1) {            // diamonds
                face = "-D";
            } else if (i == 2) {            // hearts
                face = "-H";
            } else if (i == 3) {            // spades
                face = "-S";
            }
            if ( j <= 10) {
                face = intToString(j) + face;   // If a number card
            } else {
                if (j == 11) {              // ace
                    face = "J" + face;
                    data->enqueue(Card(face, 10 , false));
                    continue;
                } else if (j == 12) {       // king
                    face = "Q" + face;
                    data->enqueue(Card(face, 10 , false));
                    continue;
                } else if (j == 13) {       // queen
                    face = "K" + face;
                    data->enqueue(Card(face, 10 , false));
                    continue;
                } else if (j == 14) {       //jack
                    face = "A" + face;
                    data->enqueue(Card(face, 11 , false ));
                    continue;
                }
            }
            data->enqueue(Card(face, j , false )); // add card to deck
        }
    }
}

/**********************************************************************************************************************/

DeckOfCards::~DeckOfCards() {
    delete(data);
}

/**********************************************************************************************************************/

void DeckOfCards::shuffle() {
    Queue<Card> decks[4];
    for (int i = 0; i < 4; i++) {       // 4 decks
        for (int j = 0; j <= 12; j++) { // split equally into 4 decks
            decks[i].enqueue(data->dequeue());
        }
    }
    srand((unsigned int)time(NULL));        // Or else it possible for dealer to win automatically over and over
    int randn;
    Card temp;
    for (int i = 0; i < 1000; i++) {        // loop 1000 times
        randn = rand() % 4;                 // get a random deck
        try {
            temp = decks[randn].dequeue();  // dequeue card into temp
            randn = rand() % 4;             // get another random deck
            decks[randn].enqueue(temp);     // enqueue card onto new random deck
        } catch (std::logic_error const&) { // happens when trying to dequeue() from a empty queue.

        }

    }
    for (int i = 0; i < 4; i++) {   // the 4 decks, add them all back into this instances deck
        int deckSize = decks[i].size();
        for (int j = 0; j < deckSize ; j++ ) {
            data->enqueue(decks[i].dequeue());
        }
    }
}

/**********************************************************************************************************************/

Card DeckOfCards::draw() {
    return data->dequeue();
}
/**********************************************************************************************************************/


int DeckOfCards::size() {
    return data->size();
}

/**********************************************************************************************************************/

std::string DeckOfCards::printDeck() {
    std::string deck;
    for ( int i = 0; i < data->size(); i++) {   // for all cards in deck
        Card tempCard = data->dequeue();        // dequeue into temp
        deck += tempCard.getFace() + " ";       // get its face
        data->enqueue(tempCard);                // enqueue back into deck
    }
    return deck;
}

/**********************************************************************************************************************/

std::ostream &operator<<(std::ostream &out, DeckOfCards &l) {
    out << l.printDeck();
    return out;
}