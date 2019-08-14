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

	void hitCards(Card aCard);
	vector<Card> giveCards();

	int getScore();
	void setScore(int newScore);

	void setBet(double wager);
	double getBet();

	void seeCards();
	void setName(string name, string surname);
	string getName();

	void reset();

private:

	double wallet = -1;
	vector<Card> hand;
	int score = -1;
	double bet = -1;
	string playerId = "NOBODY";

};

