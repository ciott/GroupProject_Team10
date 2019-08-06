
#pragma once

#include <iostream>
#include <string>

using namespace std;

class Card
{
public:
	Card();
	~Card();

	char getSuit() { return suit; }
	void setSuit(char suit) { this->suit = suit; }

	char getFace() { return face; };
	void setFace(char face) { this->face = face; }

	int getVal() { return value; }
	void setVal(int value) { this->value = value; }

	string getColor() { return color; }
	string setColor(string color) { this->color = color; }

	void setUp();
	void setDown();
	// bool isUp() { return isUp; };

private:

	char face = '@';
	char suit = '#';
	int value = -1;
	string color = "Blank";

	//bool isUp = false;

};
