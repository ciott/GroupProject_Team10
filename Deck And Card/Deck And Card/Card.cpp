#include<iostream>
#include<string>
#include "Card.h"
using namespace std;

Card::Card()
{
	suit = 'S';
	rank = 2;
}
Card::Card(char ch, int i)
{
	suit = toupper(ch);
	rank = i;
}
//Accessor Methods
int Card::getRank() const
{
	return rank;
}
char Card::getSuit() const
{
	return suit;
}
//Formatted Display Method
void Card::displayCard(ostream& out) const
{
	string suitString;
	switch (suit) {
	case 'S':
		suitString = "Spades";
		break;
	case 'H':
		suitString = "Hearts";
		break;
	case 'D':
		suitString = "Diamonds";
		break;
	case 'C':
		suitString = "Clubs";
		break;
	default:
		suitString = "Invalid Suit";
	}
	if (rank >= 2 && rank<11) {
		out << rank << "of" << suitString;
	}
	else {
		switch (rank) {
		case 11:
			out << "JACK of " << suitString;
			break;
		case 12:
			out << "Queen of " << suitString;
			break;
		case 13:
			out << "KING of " << suitString;
			break;
		case 14:
			out << "ACE of " << suitString;
			break;
		}
	}
	return;
}
bool Card::operator==(const Card& c) const
{
	Card card1;
	Card card2;
	if (card1 == card2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Card::operator>(const Card& c) const
{
	Card card1;
	Card card2;
	return card1 > card2;
}
bool Card::operator<(const Card& c) const
{
	Card card1;
	Card card2;
	return card1 < card2;
}