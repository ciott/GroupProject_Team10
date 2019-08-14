#include <iostream>
#include "Player.h"
#include "Card.h"

using namespace std;

int main() {

	Card temp;
	Card temp2;

	temp.setSuit('C');
	temp.setVal(10);
	temp.setFace('K');

	temp2.setSuit('D');
	temp2.setVal(10);
	temp2.setFace('J');

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
	P1.hitCards(temp);
	P1.hitCards(temp2);

	vector<Card> tempPair;

	//FIX ME
	cout << "Seeing a Cards" << endl;
	//tempPair = P1.Cards();

	cout << endl << "SEE CARD" << endl;
	P1.seeCards();
	cout << endl;

	P1.reset();
	cout << endl << "SEE CARD" << endl;
	P1.seeCards();
	cout << endl;

	string tempName;
	string tempSur;

	cout << "ENTER PLAYER ID" << endl;
	cin >> tempName;
	cout << endl;
	cin >> tempSur;
	cout << endl;

	P1.setName(tempName, tempSur);

	cout << "PLAYER NAME: ";
	cout << P1.getName();

	system("pause");
	return 0;
}