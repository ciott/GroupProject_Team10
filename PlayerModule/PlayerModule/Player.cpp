#include "Player.h"
#include "Card.h"
#include <vector>
#include <iostream>

using namespace std;

Player::Player()
{


}

void Player::setWallet(int money) {

	this->wallet = money;
}

double Player::getWallet() {

	return wallet;
}

void Player::hitCards(Card aCard) {

	score += aCard.getVal();

	for (int card = 0; card < hand.size(); ++card) {
		
		if (score > 21) {

			if (hand.at(card).getFace() == 'A' && hand.at(card).getVal() == 11) {

				score -= 10;
				hand.at(card).setVal(1);
			}

		}

	}

	hand.push_back(aCard);

}

void Player::setBet(double wager) {

	this->bet = wager;
}

double Player::getBet() {

	return this->bet;
}

vector<Card> Player::giveCards() {

	cout << "Get card successful!" << endl;
	return hand;
}

int Player::getScore() {

	return score;
}

void Player::setScore(int newScore) {

	this->score = newScore;
}

void Player::seeCards() {

	if (hand.empty() != true) {
		for (int card = 0; card < hand.size(); ++card) {

			switch (hand.at(card).getFace()) {

			case 'A':

				cout << "Ace of";
				break;

			case 'J':

				cout << "Jack of";
				break;

			case 'Q':

				cout << "Queen of";
				break;

			case 'K':

				cout << "King of";
				break;

			case 'T':

				cout << "10 of";
				break;

			default:

				cout << hand.at(card).getFace() << " of";
				break;

			}

			switch (hand.at(card).getSuit()) {

			case 'C':

				cout << " Clubs" << endl;
				break;

			case 'H':

				cout << " Hearts" << endl;
				break;

			case 'S':

				cout << " Spades";
				break;

			case 'D':

				cout << " Diamonds";
				break;
			}
		}
	}
	else {

		cout << "EMPTY";
	}
}

void Player::setName(string name, string surname) {

	this->playerId = name + " " + surname;
}

string Player::getName() {

	return playerId;
}

void Player::reset() {

	this->wallet = -1;
	this->hand.clear();
	this->score = -1;
	this->bet = -1;
	this->playerId = -1;

}

Player::~Player()
{

}
