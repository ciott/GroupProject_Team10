#include <iostream>
#include "Player.h"
#include "Card.h"

using namespace std;

int main() {

	Card temp;

	temp.setSuit('C');
	temp.setVal(10);
	temp.setFace('F');

	Player P1;

	double enterWallet;
	int enterScore;

	cout << "Enter wallet" << endl;
	cin >> enterWallet;
	P1.setWallet(enterWallet);

	cout << "Wallet contents: " << P1.getWallet() << endl;

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