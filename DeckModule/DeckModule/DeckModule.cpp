#include <iostream>
#include "BlackJackDeck.h"
#include "Card.h"

using namespace std;

int main() {

	cout << "Hello World!" << endl;

	Card One;
	BlackJackDeck deck1;
	deck1.peek();

	cout << " AFTER SHUFFLE " << endl;
	deck1.shuffle();
	deck1.peek();

	// vdeck1.initStack();
	deck1.peekStack();
	deck1.peekStack();

	cout << "=======TAKE 2=========" << endl;
	cout << "SHUFFLE" << endl;
	deck1.shuffle();
	cout << " === " << endl;


	deck1.peek();
	deck1.peekStack();

	cout << "=======TAKE 3=========" << endl;
	cout << "SHUFFLE" << endl;
	deck1.shuffle();
	cout << " === " << endl;


	deck1.peek();
	deck1.peekStack();

	cout << "===ADD CARD===" << endl;

	Card newCard1;
	Card newCard2;
	Card newCard3;

	deck1.addCard(newCard1);
	deck1.addCard(newCard2);
	deck1.addCard(newCard3);
	
	deck1.peek();
	deck1.peekStack();

	cout << "===SHUFFLE CHECK===" << endl;

	deck1.shuffle();
	deck1.peek();
	deck1.peekStack();

	cout << "=== REMOVE CARD ===" << endl;

	cout << "BEFORE" << endl;
	deck1.peek();
	deck1.peekStack();

	deck1.removeCard();

	cout << "AFTER" << endl;
	

	deck1.peek();
	deck1.peekStack();

	cout << "SHUFFLE CHECK" << endl;
	deck1.shuffle();

	deck1.peek();
	deck1.peekStack();

	deck1.removeCard();
	deck1.removeCard();

	cout << "30 LIMIT SHUFFLE CHECK" << endl;
	cout << "BEFORE" << endl;
	deck1.peek();
	deck1.peekStack();

	for (int i = 0; i < 23; ++i) {

		deck1.removeCard();
	}
	cout << "AFTER " << endl;

	deck1.peek();
	deck1.peekStack();

	cout << "GIVE CARD TEST" << endl;
	// FIRST CARD SHOULD BE THE TOP OF EACH CONTAINER
	cout << "BEFORE TAKEN" << endl;
	cout << "CURRENT DECK SIZE" << endl;
	cout << "SIZE: " << deck1.getSize() << endl;
	cout << "AFTER TAKEN" << endl;

	Card tempCard;
	tempCard = deck1.takeCard();

	cout << "CARD TAKEN" << endl;
	cout << "F:" << tempCard.getFace() << endl;
	cout << "S: " <<  tempCard.getSuit() << endl;
	cout << "V: " << tempCard.getVal() << endl;

	cout << "CURRENT DECK SIZE" << endl;
	cout << "SIZE: " << deck1.getSize() << endl;

	system("pause");
	return 0;
}