#pragma once



#include "Card.h"

#include <iostream>

#include <vector>



using namespace std;



#include <stack>

class BlackJackDeck

{

public:

	BlackJackDeck();

	~BlackJackDeck();



	// put back in private eventually



	// put in private

	void peek();

	void peekStack();



	void addCard(Card addedCard);

	void removeCard();

	void shuffle();

	int getSize();



	Card takeCard() {



		Card takenCard = deckCards.top();

		removeCard();



		return takenCard;

	}



	// Put in private

	void initStack();



private:



	void initDeck();



	vector<Card> shuffledCards;

	stack<Card> deckCards;

	int deckSize = 52;

};

