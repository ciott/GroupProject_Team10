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
	void initDeck();

private:

	

	vector<Card> tempCards;
	stack<Card> deckCards;
};

