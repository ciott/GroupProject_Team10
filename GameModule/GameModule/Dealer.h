#pragma once

#include "Card.h"
#include "BlackJackDeck.h"
#include "Player.h"

class Dealer : public Player
{
public:
	Dealer();
	~Dealer();

	void distCards(Player& P, BlackJackDeck& aDeck);
	void distBet(Player& P);
	void housePlays(BlackJackDeck& aDeck);

};