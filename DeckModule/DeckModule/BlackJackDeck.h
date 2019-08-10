#pragma once

#include "Card.h"
#include <iostream>

using namespace std;

#include <stack>
class BlackJackDeck
{
public:
	BlackJackDeck();
	~BlackJackDeck();

private:

	stack<Card> deckCards;
};

