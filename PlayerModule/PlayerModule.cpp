#include <iostream>
#include <ctime>
#include<iomanip>
#include "Player.h"
#include "Card.h"
#include "Dealer.h"

using namespace std;


int main() {

	Card temp;
	temp.setSuit('C');
	temp.setVal(10);
	temp.setFace('F');

	Player P1;
	double enterWallet;
	int enterScore, totdealer, totplayer, bet, aces;
	char yesno = 'Y';
	bool again;
	srand(time(0));

	Dealer d1;

	cout << "How much money do you have? Please Enter wallet" << endl;
	cin >> enterWallet;

	P1.setWallet(enterWallet);
	cout << "Wallet contents: " << P1.getWallet() << endl;

	
	while (enterWallet > 0 && toupper(yesno) == 'Y')
	{
		bet = d1.getbet(enterWallet);
		totdealer = 0;
		d1.deal(2, totdealer);
		aces = 0;
		totplayer = 0;
		d1.deal(2, aces, totplayer);
		cout << "Your total is " << totplayer << endl;
		cout << "You have " << aces << " aces" << endl;
		again = false;
		while (totdealer < 21 && totplayer < 21 && !again)
		{
			cout << "\ndo you want another card? ";
			cin >> yesno;
			if (toupper(yesno) == 'Y')
			{
				d1.deal(1, aces, totplayer);
				cout << "Your total is " << totplayer << endl;
				cout << "You have " << aces << " aces" << endl;
			}
			else
				again = true;
		}
		cout << "Dealer total: " << totdealer << endl;
		cout << "Your total: " << totplayer << endl;
		if (totdealer > totplayer || totplayer > 21)
			enterWallet -= bet;
		else if (totdealer < totplayer&&totplayer <= 21)
			enterWallet += bet;
		cout << "\nGame over\nYou have $" << enterWallet << " left\n";
		if (enterWallet > 0)
		{
			cout << "\nPlay again (Y/N)?";
			cin >> yesno;
		}
	}

	cout << "Set score" << endl;
	cin >> enterScore;

	P1.setScore(enterScore);
	cout << "Score: " << P1.getScore();

	cout << endl;

	cout << "Setting a Card" << endl;
	P1.setCards(temp);

	vector<Card> tempPair;
	cout << "Seeing a Card" << endl;
	tempPair = P1.getCards();

	cout << endl << "SEE CARD" << endl;

	cout << "This is the face: " << tempPair.at(0).getFace() << endl;

	cout << "This is the suit: " << tempPair.at(0).getSuit() << endl;

	cout << "This is the value: " << tempPair.at(0).getVal() << endl;

	cout << "This is the color: " << tempPair.at(0).getColor() << endl;


	system("pause");
	return 0;
}