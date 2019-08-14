#include <iostream>
#include <vector>
#include <string>
#include <random>
#include "Dealer.h"
#include "Card.h"
#include "Player.h"
#include "BlackJackDeck.h"

using namespace std;

int main() {

	// Irrelevant
	Card card1;
	Dealer deal;
	BlackJackDeck one;
	
	// Actual
	Player P1;
	Player P2;
	Dealer D1;
	BlackJackDeck B1;
	BlackJackDeck B2;
	BlackJackDeck B3;

	B1.peek();
	B1.peekStack();

	cout << endl;
	cout << "DISTRIBUTING CARDS" << endl;
	cout << "BEFORE" << endl;

	for (int i = 0; i < 52; ++i) {

		D1.distCards(P1, B1);
	}

	cout << "AFTER" << endl;

	cout << "Player P1 Hand" << endl;
	P1.seeCards();
	cout << endl << "Player P1 Score " << P1.getScore() << endl;

	cout << endl;
	cout << "CHECKING DECK" << endl;
	B1.peek();
	B1.peekStack();

	cout << "TEST HOUSE PLAYS" << endl;

	B2.shuffle();
	D1.housePlays(B2);
	cout << "Dealer score: ";
	cout << D1.getScore() << endl;

	cout << "TEST BETS" << endl;
	P2.setBet(10);
	P2.setWallet(100);
	D1.housePlays(B3);
	D1.distBet(P2);

	cout << "Dealer cards" << endl;
	D1.seeCards();
	cout << "DEALER SCORE" << D1.getScore() << endl;

	cout << "Player Cards" << endl;
	D1.distCards(P2, B2);
	D1.distCards(P2, B2);
	P2.seeCards();
	cout << endl;

	cout << "Player's wallet" << endl;
	cout << P2.getWallet() << endl;
	cout << "PLAYER'S SCORE " << endl;
	cout << P2.getScore() << endl;
	cout << "DEALER SCORE " << endl;
	cout << D1.getScore() << endl;

	Card Ditto;
	Ditto.setFace('T');
	Ditto.setVal(10);
	Ditto.setSuit('C');

	D1.reset();
	D1.hitCards(Ditto);
	D1.hitCards(Ditto);

	P2.reset();
	P2.hitCards(Ditto);
	P2.hitCards(Ditto);
	P2.setWallet(100);
	P2.setBet(10);

	cout << "Player Cards" << endl;
	//D1.distCards(P2, B2);
	//D1.distCards(P2, B2);
	P2.seeCards();
	cout << endl;

	cout << "Dealer Cards" << endl;
	//D1.distCards(P2, B2);
	//D1.distCards(P2, B2);
	D1.seeCards();
	cout << endl;

	D1.distBet(P2);

	cout << "Player's wallet" << endl;
	cout << P2.getWallet() << endl;
	cout << "PLAYER'S SCORE " << endl;
	cout << P2.getScore() << endl;
	cout << "DEALER SCORE " << endl;
	cout << D1.getScore() << endl;

	cout << "DEALER HAND: " << endl;
	D1.seeCards();

	cout << "DEALER CARD TOP" << endl;
	cout << D1.topCard().getFace() << D1.topCard().getSuit() << D1.topCard().getVal() << endl;

	cout << endl;
	system("pause");
	return 0;
}