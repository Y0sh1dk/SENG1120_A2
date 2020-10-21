/*
 * Name: Yosiah de Koeyer
 * Student No: c3329520
 * Course: SENG1120 - A2
 *
 * File: DeckOfCards.h
 * Description: DeckOfCards Implementation
 */

#include "Queue.h"
#include "Card.h"
#include "string.h"

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

class DeckOfCards {
public:

    // Pre-Condition: None
    // Initialises a DeckOfCards instance
    // Post-Condition: None
    DeckOfCards();

    // Pre-Condition: None
    // Deletes private data instance properly
    // Post-Condition: None
    ~DeckOfCards();

    // Pre-Condition: None
    // Shuffles the deck, will be random each time is ran.
    // Post-Condition: None
    void shuffle();

    // Pre-Condition: None
    //
    // Post-Condition: Returns Card instance off the top of the deck
    Card draw();

    // Pre-Condition: None
    //
    // Post-Condition: Returns a int of the size of the deck
    int size();

    // Pre-Condition: None
    //
    // Post-Condition: Returns a string representation of the deck
    std::string printDeck();

private:
    std::string intToString(int n);     // Method to convert int to string

    Queue<Card>* data;                  // Instance of Queue class of type Card

};

//Overloaded << operator for string representation of cards in deck
std::ostream &operator<<(std::ostream &out, DeckOfCards &l);


#endif
