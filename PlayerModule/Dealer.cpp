#include "Dealer.h"



Dealer::Dealer()
{
}


Dealer::~Dealer()
{
}

void Dealer::deal(int num, int& tot)
{
	int i, n;
	for (i = 0;i < num;i++)
	{
		n = rand() % 13 + 1;
		if (n == 1)
			tot += 11;
		else if (n >= 10)
			tot += 10;
		else
			tot += n;
	}

}

void Dealer::deal(int num, int& aces, int &tot)
{
	int i, n;
	for (i = 0;i < num;i++)
	{
		n = rand() % 13 + 1;
		if (n == 1)
		{
			aces++;
			tot += 11;
		}
		else if (n >= 10)
			tot += 10;
		else
			tot += n;
	}
	if (tot > 21)
		if (aces == 0)
			return;
		else
		{
			aces--;
			tot -= 10;
		}
}
int Dealer::getbet(int enterWallet)
{
		int bet;
		cout << "You have $" << enterWallet << " enter your bet: ";
		cin >> bet;
		while (bet > enterWallet)
		{
			cout << "You cannot bet more then you have!!!\n";
			cout << "You have $" << enterWallet << " enter your bet: ";
			cin >> bet;
		}
		return bet;
}
