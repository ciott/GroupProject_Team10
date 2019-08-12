#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include "Player.h"
#include "Card.h"

using namespace std;

class Dealer
{
private: 


public:
	Dealer();
	~Dealer();

	int getbet(int);
	void deal(int, int&);
	void deal(int, int&, int&);

};

