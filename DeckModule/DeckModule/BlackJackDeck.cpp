#include "BlackJackDeck.h"
#include <random>
#include <algorithm>
#include <stack>
#include <vector>
#include <ctime>
#include "Card.h"

using namespace std;


BlackJackDeck::BlackJackDeck()
{
	initDeck();

}

void BlackJackDeck::initDeck() {

	// Make jack king queen ace

	vector<Card> tempCards(deckSize);

	int card = 0;
	char suit;

	for (int type = 0; type < 4; ++type) {

		switch (type) {

		case 0:
			suit = 'C';
			break;
		case 1:
			suit = 'D';
			break;
		case 2:
			suit = 'H';
			break;
		case 3:
			suit = 'S';
			break;

		}

		// A Card
		tempCards.at(card).setFace('A');
		tempCards.at(card).setSuit(suit);
		tempCards.at(card).setVal(11);
		++card;

		for (int symbol = 2; symbol < 11; ++symbol) {

			// A Card
			if (symbol < 10) {
			tempCards.at(card).setFace(symbol + '0');
		}
			else {

				tempCards.at(card).setFace('T');
			}

			
			tempCards.at(card).setSuit(suit);
			tempCards.at(card).setVal(symbol);
			++card;
		}

		// A Card
		tempCards.at(card).setFace('J');
		tempCards.at(card).setSuit(suit);
		tempCards.at(card).setVal(10);
		++card;

		// A Card
		tempCards.at(card).setFace('K');
		tempCards.at(card).setSuit(suit);
		tempCards.at(card).setVal(10);
		++card;

		// A Card
		tempCards.at(card).setFace('Q');
		tempCards.at(card).setSuit(suit);
		tempCards.at(card).setVal(10);
		++card;

		

	}

	shuffledCards = tempCards;
}

void BlackJackDeck::shuffle() {

	srand(time(0));

	random_shuffle(shuffledCards.begin(), shuffledCards.end());

	initStack();
}

void BlackJackDeck::addCard(Card addedCard) {

	shuffledCards.push_back(addedCard);
	deckCards.push(addedCard);

}

void BlackJackDeck::removeCard() {

	shuffledCards.pop_back();
	deckCards.pop();

	if (shuffledCards.size() < 30 && deckCards.size() < 30) {

		shuffle();
	}
}

void BlackJackDeck::initStack() {

	// Empty the stack
	while (deckCards.size() != 0) {

			deckCards.pop();
	}

	int size = shuffledCards.size();

	// Check for potential duplicates
	for (int card = 0; card < size; ++card) {

			deckCards.push(shuffledCards.at(card));
	}
}

void BlackJackDeck::peek() {

	cout << "Deck Cards" << endl;
	for (int card = 0; card < shuffledCards.size(); ++card) {

		cout << "Card: " << card + 1 << " -> " << shuffledCards.at(card).getFace()
			<< shuffledCards.at(card).getSuit() << " >" << shuffledCards.at(card).getVal() << "< " << endl;
	}

}

int BlackJackDeck::getSize() {


	return deckCards.size();
}

void BlackJackDeck::peekStack() {

	int size = deckCards.size();

	cout << "Stack Cards" << endl;

	while (!(size <= 0)) {

		cout << "Card: " << size << " -> " << deckCards.top().getFace()
			<< deckCards.top().getSuit() << " >" << deckCards.top().getVal() << "< " << endl;
		deckCards.pop();

		--size;
	}

	initStack();
}

BlackJackDeck::~BlackJackDeck() {

}
