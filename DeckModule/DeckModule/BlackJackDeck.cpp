#include "BlackJackDeck.h"
#include <vector>
#include "Card.h"

using namespace std;


BlackJackDeck::BlackJackDeck()
{

	

}

void BlackJackDeck::initDeck() {

	// Make jack king queen ace

	vector <Card> tempCards(52);

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
			suit = 'S';
			break;
		case 3:
			suit = 'H';
			break;

		}


		// A Card
		tempCards.at(card).setFace('A');
		tempCards.at(card).setSuit(suit);
		tempCards.at(card).setVal(1);
		++card;

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

		

	}

		
	

	/*
	for (int card = 0; card < 4; ++card) {

		tempCards.at(card).setFace('A');

		switch (card) {

		case 0:
			tempCards.at(card).setSuit('C');
			break;

		case 1:
			tempCards.at(card).setSuit('D');
			break;

		case 2:
			tempCards.at(card).setSuit('H');
			break;

		case 3:
			tempCards.at(card).setSuit('S');
			break;

		default:
			tempCards.at(card).setSuit('#');

		}

		for (int card = 4; card < 8; ++card) {

			tempCards.at(card).setFace('J');
			tempCards.at(card).setSuit('C');
		}
		*/

		/*
		tempCards.at(card).setFace('J');
		tempCards.at(card).setFace('K');
		tempCards.at(card).setFace('Q');
		*/

	

	for (int card = 0; card < 52; ++card) {

		cout << "Card: " << card + 1 << " -> " << tempCards.at(card).getFace() 
			<< tempCards.at(card).getSuit() << " >" << tempCards.at(card).getVal() << "< " << endl;
	}

}


BlackJackDeck::~BlackJackDeck() {

}
