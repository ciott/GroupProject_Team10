#include <iostream>
#include<time.h>
#include "Card.h"
#include "CardDeck.h"
using namespace std;



CardDeck::CardDeck()
{
	/*13 cards in each suit */
	/*52 new card */
	for (int i = 2; i<15; ++i) {
		Deck.push_back(Card('S', i));
		Deck.push_back(Card('H', i));
		Deck.push_back(Card('D', i));
		Deck.push_back(Card('C', i));
	}
	srand(time(NULL));
}
Card CardDeck::draw() {
	/*Draw and return one card. */
	if (Deck.empty()) {
		exit(1);
	}
	Card Card = Deck.back(); //Draw card.
	Deck.pop_back(); //Remove card
					 //Retain card for shuffle.
	Cards.push_back(Card);
	return(Card);
}
void CardDeck::shuffleDeck() {
	/*Replace drawn cards */
	for (int i = 0; i<Cards.size(); ++i) {
		Deck.push_back(Cards[i]);
	}
	//Clear the vector
	Cards.resize(0);
	//Use the top level function from algorithm
	random_shuffle(Deck.begin(), Deck.end());
}
bool CardDeck::isEmpty() const {
	if (Deck.size() == 0)
		return true;
	return false;
}