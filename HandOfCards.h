/*
 * Name: Yosiah de Koeyer
 * Student No: c3329520
 * Course: SENG1120 - A2
 *
 * File: HandOfCards.h
 * Description: HandOfCards Declaration
 */

#include "string.h"
#include "Queue.h"
#include "Card.h"

#ifndef UNTITLED2_HANDOFCARDS_H
#define UNTITLED2_HANDOFCARDS_H

class HandOfCards {
public:

    // Pre-Condition: None
    // Creates a empty HandOfCards instance
    // Post-Condition: None
    HandOfCards();

    // Pre-Condition:
    // Deletes the private data instance properly
    // Post-Condition: None
    ~HandOfCards();

    // Pre-Condition: A instance of Card, and a Boolean representing if facing up/down
    //
    // Post-Condition: None
    void add(Card c, bool b);

    // Pre-Condition: None
    //
    // Post-Condition: Returns a int value of all face up cards
    int count();

    // Pre-Condition: None
    //
    // Post-Condition: Returns a int value of all cards, face up and face down
    int countAll();

    // Pre-Condition: None
    //
    // Post-Condition: Returns string representation of the cards in the hand
    std::string value();

    // Pre-Condition: None
    // Sets all cards in hand to faceup
    // Post-Condition: None
    void faceUp();

private:
    Queue<Card>* data;  // Instance of Queue class of type Card

};

// overloaded << operator for string representation of cards in hand
std::ostream &operator<<(std::ostream &out, HandOfCards &h);

#endif
