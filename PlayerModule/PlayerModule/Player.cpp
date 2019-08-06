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

void Player::setCards(Card aCard) {

	pair.push_back(aCard);

}

vector <Card> Player::getCards() {

	cout << "Get card successful!" << endl;
	return pair;
}

int Player::getScore() {

	return score;
}

void Player::setScore(int newScore) {

	this->score = newScore;
}

Player::~Player()
{

}
