#include "GameModule.h"



GameModule::GameModule(int numPlayers = 1, int bank = 0, int numDecks = 1)
{
	this->numPlayers = numPlayers;
	this->bank = bank;
	this->numDecks = numDecks;
}


void GameModule::setDealer() {

	//FIXME
	// Make a dealer instance
}

void GameModule::setNumPlayers(int num) {

	//FIXME
	//  sets player, and default amount 100
	//  calls private create player function.

}

void GameModule::setBets(int bet) {

	//FIXME
	// recieve bet from player
	// store it

}

void GameModule::distribute() {

	//FIXME
	// Gives two cards to player
	// calls setCards() twice
}

void GameModule::setCard(card playerCard) {

	//FIXME
	// gives 1 card.
}

void GameModule::setChoice() {

	//FIXME
	// sets player choice
}

int GameModule::getWinnings() {

	//FIXME
	return 1;
}

void GameModule::BustOrWin() {

	// FIXME
	// Determines if player busts or wins.
}

void GameModule::createPlayers() {

	// FIXME
	// Creates instances of players
}

void GameModule::setDecks() {

	// FIXME
	// Makes instances of decks.

}

void GameModule::getDeck() {

	// FIXME
	// Retrieves deck in deck array.
}

void GameModule::setProfile() {

	//FIXME
	// Creates instance of player
	// adds to vector of players: profile
}

GameModule::~GameModule()
{
}
