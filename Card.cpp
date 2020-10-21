/*
 * Name: Yosiah de Koeyer
 * Student No: c3329520
 * Course: SENG1120 - A2
 */

#include "Card.h"

Card::Card() {

}

Card::Card(std::string givenFace, int givenValue, bool givenFaceUp) {
    face = givenFace;
    value = givenValue;
    faceUp = givenFaceUp;
}

Card::~Card() {
 // Nothing to delete here
}

std::string Card::getFace() {
    return face;
}

void Card::setFace(std::string s) {
    face = s;
}

int Card::getValue() {
    return value;
}

void Card::setValue(int v) {
    value = v;
}

bool Card::getFaceUp() {
    return faceUp;
}

void Card::setFaceUp(bool v) {
    faceUp = v;
}

std::ostream& operator << (std::ostream& out, Card& c) {
    out << c.getFace();
    return out;
}