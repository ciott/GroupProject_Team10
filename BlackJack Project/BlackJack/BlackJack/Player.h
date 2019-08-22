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
	void checkAce();



	void setBet(double wager);

	double getBet();



	void seeCards();



	vector <Card> getHand() {



		return hand;

	}



	void setName(string name, string surname);

	string getName();



	Card topCard();



	void reset();



protected:

	vector<Card> hand;



private:



	double wallet = 0;

	int score = 0;

	double bet = 0;

	string playerId = "NOBOBY";



};