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
