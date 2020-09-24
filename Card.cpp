//
// Created by Yosiah on 23/09/2020.
//

#include "Card.h"

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