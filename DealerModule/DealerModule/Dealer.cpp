#include "Dealer.h"
#include "Card.h"
#include "BlackJackDeck.h"
#include "Player.h"


Dealer::Dealer()
{
}

void Dealer::distCards(Player& P, BlackJackDeck& aDeck) {

	Card hold;
	hold = aDeck.takeCard();

	P.hitCards(hold);

}

void Dealer::distBet(Player& P) {


	double holdBet;
	holdBet = P.getBet();

	double holdMoney;
	holdMoney = P.getWallet();

	if (P.getScore() > 21) {

		holdMoney = holdMoney - P.getBet();
		P.setWallet(holdMoney);
	}
	else if ((P.getScore() < this->getScore()) && !(this->getScore() > 21)) {

		holdMoney = holdMoney - P.getBet();
		P.setWallet(holdMoney);
	}
	else if (P.getScore() <= 21 && (this->getScore() < P.getScore() || this->getScore() > 21)) {

		holdMoney = holdMoney + P.getBet();
		P.setWallet(holdMoney);
	}
	else if (P.getScore() == this->getScore()) {

		holdMoney = holdMoney + (0.5 * P.getBet());
		P.setWallet(holdMoney);
	}
	
	/*
	if ((this->getScore() > P.getScore() && this->getScore <= 21) || P.getScore() > 21) {

		holdMoney = holdMoney - P.getBet();
		P.setWallet(holdMoney);
	}
	else if (this->getScore() == P.getScore() && this->getScore() <= 21) {

		holdMoney += 0.5 * P.getBet();
		P.setWallet(holdMoney);
	}
	else if (this->getScore() < P.getScore() && P.getScore() <= 21) {

		holdMoney += P.getBet();
		P.setWallet(holdMoney);
	}
	*/
}


void Dealer::housePlays(BlackJackDeck& aDeck) {

	Card hold;

	while (this->getScore() <= 16) {

		hold = aDeck.takeCard();
		hitCards(hold);
	}
}


Dealer::~Dealer()
{
}