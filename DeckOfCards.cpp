//
// Created by Yosiah on 24/09/2020.
//

#include <iostream>
#include <cstdlib>
#include <string.h>
#include <sstream>
#include "DeckOfCards.h"

std::string DeckOfCards::intToString(int n) {
    std::stringstream ss;
    std::string s;
    ss<<n;
    ss>>s;
    return s;
}


DeckOfCards::DeckOfCards() {
    data = new Queue<Card>;
    // Initialize all cards here
    // I made this at 1am, it could be crap
    for (int i = 0; i <= 3; i++) { // Suit
        for(int j = 2; j <= 14; j++) {  // card
            std::string face;
            if (i == 0) { // clubs
                face = "-C";
            } else if (i == 1) { // diamonds
                face = "-D";
            } else if (i == 2) { // hearts
                face = "-H";
            } else if (i == 3) { // spades
                face = "-S";
            }
            if ( j <= 10) {
                face = intToString(j) + face;
            } else {
                if (j == 11) { // ace
                    face = "J" + face;
                    data->enqueue(Card(face, 10 , false));
                    continue;
                } else if (j == 12) { // king
                    face = "Q" + face;
                    data->enqueue(Card(face, 10 , false));
                    continue;
                } else if (j == 13) { // queen
                    face = "K" + face;
                    data->enqueue(Card(face, 10 , false));
                    continue;
                } else if (j == 14) { //jack
                    face = "A" + face;
                    data->enqueue(Card(face, 11 , false ));
                    continue;
                }
            }
            data->enqueue(Card(face, j , false ));
        }
    }
}

DeckOfCards::~DeckOfCards() {

}

void DeckOfCards::shuffle() {

}

Card DeckOfCards::draw() {
    return data->dequeue();
}

int DeckOfCards::size() {
    return data->size();
}

std::string DeckOfCards::printDeck() {
    std::string deck;
    for ( int i = 0; i < data->size(); i++) {
        Card tempCard = data->dequeue();
        deck += tempCard.getFace() + " ";
        data->enqueue(tempCard);
    }
    return deck;
}

std::ostream &operator<<(std::ostream &out, DeckOfCards &l) {
    out << l.printDeck();
    return out;
}