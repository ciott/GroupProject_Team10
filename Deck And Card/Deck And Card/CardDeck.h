#pragma once

#include<iostream>
#include<vector>
using namespace std;

class CardDeck {
public:
	CardDeck();
	void shuffleDeck();
	bool isEmpty() const; //return true if empty
	Card draw();
private:
	vector<Card> Deck;
	vector<Card> Cards;
};