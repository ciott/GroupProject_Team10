#pragma once
#include<string> //Required for string
#include<iostream> //Required for ostream
#include<vector> //Required for Vector
#include<ctime> //Required for time()
#include<algorithm> //Required for random_shuffle()
using namespace std;

class Card {
public:
	//Constructors
	Card(); //default
	Card(char suit, int Rank);
	int getRank() const;
	char getSuit() const;
	void displayCard(ostream& outstream) const;
	//Comparator
	bool operator<(const Card& c) const;
	bool operator>(const Card& c) const;
	bool operator==(const Card& c) const;
	friend ostream &operator<<(ostream &output, const Card &c)
	{
		output << "Player 1 draws ";
		output << "Player 2 draws ";
		return output;
	}
private:
	char suit;
	int rank;
};
