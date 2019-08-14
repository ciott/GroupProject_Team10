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
	Dealer D1;
	BlackJackDeck B1;
	BlackJackDeck B2;

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


	system("pause");
	return 0;
}