//BlackJackDemo - Main Program
/******************************/
//Author: Alex Mendes
//Course: SENG1120
//Program Description: This program demonstrates the use of basic data structures for a card game. 

#include <iostream>
#include <cstdlib>
#include "DeckOfCards.h"
#include "HandOfCards.h"
using namespace std;

int main()
{
	DeckOfCards deck;
	cout << "Initial deck: " << deck << endl;
	deck.shuffle();
	cout << "After shuffling: " << deck << endl;

    HandOfCards player;
	HandOfCards dealer;
	
	// inititalize game
	player.add(deck.draw(), true); // true means the card is added to the player's hand face-up
	dealer.add(deck.draw(), true);
	player.add(deck.draw(), true); 
	dealer.add(deck.draw(), false); // false means the card is added to the player's hand face-down
	
	// game main loop
	int answer;
	bool gameEnded = false;
	
	while (!gameEnded)
	{
		cout << "Player: " << player << endl; // remember to print out all cards and the total of points
		cout << "Dealer: " << dealer << endl;
		
		// check for end of the game 
		if ((player.count() == 21) && (dealer.countAll() == 21)) {cout << "IT IS A TIE!" << endl; return 0;}
		if (player.count() == 21) {cout << "THE PLAYER WON!" << endl; return 0;}
		if (dealer.countAll() == 21) {cout << "THE DEALER WON!" << endl; return 0;}
		if ((player.count() > 21) || (dealer.countAll() > 21)) {cout << "Double ace - no winner" << endl; return 0;} // this is a simplification of the rules
		
		cout << "Player, do you want to Hit (1) or Stand (2)?" << endl;
		cin >> answer;
		
		if (answer == 1) 
		{
			player.add(deck.draw(), true); 
			if (player.count() > 21) {cout << "THE DEALER WON!" << endl; return 0;}
		}
		else // player has stood - now it is the dealer's turn
		{
			while (dealer.countAll() <= 16) {dealer.add(deck.draw(), true);}
		    dealer.faceUp();
			
			cout << "Player: " << player << endl; // remember to print out all cards and the total of points
			cout << "Dealer: " << dealer << endl;
			
			if (dealer.countAll() > 21) {cout << "THE PLAYER WON!" << endl; return 0;}
			if (player.count() == dealer.count()) {cout << "IT IS A TIE!" << endl; return 0;}
			if (player.count() > dealer.count()) {cout << "THE PLAYER WON!" << endl; return 0;}
			if (player.count() < dealer.count()) {cout << "THE DEALER WON!" << endl; return 0;}
		}
	}
		
	return 0;
}
