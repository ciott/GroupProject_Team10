#pragma once

#include <iostream>
#include <vector>
#include <stack>



using namespace std;

class Players {

};

// Make cards into enum
class card {


};

class GameModule
{
public:
	GameModule(int numPlayers, int bank, int numDecks);
	~GameModule();

	// Make decks
	void setDecks();
	void getDeck();

	// Make a dealer
	void setDealer();

	// Recieve numPlayers
	// setNumPlayers();
	void setNumPlayers(int num);
	
	// Ask each player for a bet.
	// setBets();
	void setBets(int bet);

	// Distribute 2 cards from decks to each player
	void distribute();

	// Ask each player for choice
	// setChoice();
	void setChoice();

	// Checks if bust or win
	void BustOrWin();
	// All players asked, dealer deals itself until 
	// bust, wins, or dealer deck greater than largest player hand.
	// until bust, wins, or more cards than the largest
	//
	// hand among the players.
	//
	// Distribute winnings.
	int getWinnings();

private:

	// create num players
	// createPlayers();
	void createPlayers();
	void setProfile();

	void setCard(card playerCard);
	int numPlayers;

	// Could potentially be a double.
	// Would require rounding specifications.
	int bank;
	int numDeck;

	// May have to make cards enum.
	vector <Players> profiles;
	vector <stack<card>> decks;
};

