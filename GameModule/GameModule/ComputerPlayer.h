#pragma once

#include <iostream>
#include <vector>
#include "Player.h"
#include "Card.h"
#include "BlackJackDeck.h"
#include "Dealer.h"

using namespace std;

class ComputerPlayer : public Player
{
public:
	ComputerPlayer();
	~ComputerPlayer();

	void autoPlay(Dealer& D, BlackJackDeck& deck) {

		vector<Card> tempHand;
		tempHand = getHand();

		//tempHand.at()
		Card hold;

		if ((D.topCard().getVal() == 2 || D.topCard().getVal() == 3) && ((getScore() >= 2 && getScore() <= 12))) {
			//NPC hits
			hold = deck.takeCard();
			hitCards(hold);
		}

		if (((D.topCard().getVal() == 2 || D.topCard().getVal() == 3)) && ((getScore() >= 13 && getScore() <= 20))) {
			//NPC stands

		}

		if (((D.topCard().getVal() == 4 || D.topCard().getVal() == 5 || D.topCard().getVal() == 6)) && ((getScore() >= 2 && getScore() <= 11))) {
			//NPC hits
			hold = deck.takeCard();
			hitCards(hold);
		}

		if (((D.topCard().getVal() == 4 || D.topCard().getVal() == 5 || D.topCard().getVal() == 6)) && ((getScore() >= 12 && getScore() <= 20))) {
			//NPC stands

		}

		if ((((D.topCard().getVal() == 7 || D.topCard().getVal() == 8 || D.topCard().getVal() == 9) 
			|| D.topCard().getVal() == 10 || D.topCard().getFace() == 'A')) && ((getScore() >= 2 && getScore() <= 16))) {
			//NPC hits
			hold = deck.takeCard();
			hitCards(hold);
		}

		if ((((D.topCard().getVal() == 7 || D.topCard().getVal() == 8 || D.topCard().getVal() == 9) 
			|| D.topCard().getVal() == 10 || D.topCard().getFace() == 'A')) && ((getScore() >= 17 && getScore() <= 20))) {
		//NPC stands

		}

	}
};

