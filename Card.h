//
// Created by Yosiah on 23/09/2020.
//
#include <string>

#ifndef SENG1120_A2_CARD_H
#define SENG1120_A2_CARD_H

class Card {
public:

    Card();

    Card(std::string givenFace, int givenValue, bool givenFaceUp);

    std::string getFace();
    void setFace(std::string s);

    int getValue();
    void setValue(int v);

    bool getFaceUp();
    void setFaceUp(bool v);

private:



    std::string face;
    int value;
    bool faceUp;

};

std::ostream& operator << (std::ostream& out, Card& c);

#endif //SENG1120_A2_CARD_H
