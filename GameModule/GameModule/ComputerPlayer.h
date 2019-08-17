#pragma once

#include <iostream>
#include <vector>
#include "Player.h"
#include "Card.h"
#include "BlackJackDeck.h"
#include "Dealer.h"

using namespace std;

class ComputerPlayer : public Player
{
public:
	ComputerPlayer();
	~ComputerPlayer();
};

