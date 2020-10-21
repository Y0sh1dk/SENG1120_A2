/*
 * Name: Yosiah de Koeyer
 * Student No: c3329520
 * Course: SENG1120 - A2
 */

#include <iostream>
#include <cstdlib>
#include <string.h>
#include <sstream>
#include <time.h>
#include "DeckOfCards.h"
#include "Queue.h"
#include "Card.h"

std::string DeckOfCards::intToString(int n) {
    std::stringstream ss;
    std::string s;
    ss<<n;
    ss>>s;
    return s;
}


DeckOfCards::DeckOfCards() {
    data = new Queue<Card>;
    // TODO: Make better
    // Initialize all cards here
    // I made this at 1am, it could be crap (it is)
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
    delete(data);
}

void DeckOfCards::shuffle() {
    Queue<Card> decks[4];
    for (int i = 0; i < 4; i++) { // 4 decks
        for (int j = 0; j <= 12; j++) {
            decks[i].enqueue(data->dequeue());
        }
    }
    srand((unsigned int)time(NULL)); // Or else it possible for dealer to win automatically over and over
    int randn;
    Card temp;
    bool dequeueSuccess;
    for (int i = 0; i < 1000; i++) {
        randn = rand() % 4;
        try {
            temp = decks[randn].dequeue();
            randn = rand() % 4;
            decks[randn].enqueue(temp);
        } catch (std::logic_error) { // happens when trying to dequeue() from a empty queue.

        }

    }
    for (int i = 0; i < 4; i++) {
        int deckSize = decks[i].size();
        for (int j = 0; j < deckSize ; j++ ) {
            data->enqueue(decks[i].dequeue());
        }
    }
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