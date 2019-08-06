#pragma once
#include <vector>
#include "Card.h"

using namespace std;


class Player
{

public:
	Player();
	~Player();

	double getWallet();
	void setWallet(int money);

	void setCards(Card aCard);
	vector<Card> getCards();

	int getScore();
	void setScore(int newScore);

private:

	double wallet = 0;
	vector<Card> pair;
	int score = 0;
	double bet = 0;

};

