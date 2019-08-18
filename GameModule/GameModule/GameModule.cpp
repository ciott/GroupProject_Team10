#include <iostream>
#include <vector>
#include <string>
#include <ios>
#include <stack>

#include "Card.h"
#include "BlackJackDeck.h"
#include "Dealer.h"
#include "Player.h"
#include "ComputerPlayer.h"
#include <iomanip>

// Allow for a second round
// 

using namespace std;

int main() {

	int numPlayers;
	int pass = 'N';
	int round = 0;
	int bustedPlayers = 0;
	int const MAX_AMOUNT_MONEY = 100;
	int walletAI = MAX_AMOUNT_MONEY;
	// PUT BACK TO 1
	int const MAX_BET_AI = 1;

	BlackJackDeck gameDeck;
	vector <Player> participant;
	Dealer dealer;
	ComputerPlayer robot;

	

	// Initialize 6 decks and shuffle.
	for (int deck = 0; deck < 6; ++deck) {

		BlackJackDeck* deckPtr = new BlackJackDeck;
		deckPtr->shuffle();

		for (int card = 0; card < 52; ++card) {

			gameDeck.addCard(deckPtr->takeCard());

		}

		//cout << "DECK " << deck + 1 << endl;
		//cout << "----------------" << endl;

		delete deckPtr;
	}

	string name;
	string surname;
	string playerChoice = "Hit";
	string playAgn = "N";
	int score;

	double money;
	double wager;

	vector<Card> tempHand;
	string tempId;

	cout << setfill('=') << setw(30) << "WELCOME TO BLACKJACK!";
	cout << setfill('=') << setw(11) << " " << endl;

	// Initialize player amounts
	while (pass != 'Y') {

		cout << "Enter number of players:";
		cout << " (Limit 10)" << endl;
		cout << ": ";
		cin >> numPlayers;

		if (numPlayers > 10 || numPlayers < 0) {

			cout << "ONLY 0-10 PLAYERS ALLOWED" << endl;
			pass = 'N';
		}
		else {

			pass = 'Y';
		}

	}

	// initialize AI

	robot.setBet(MAX_BET_AI);
	robot.setWallet(walletAI);

	// Initialize players
	for (int player = 0; player < numPlayers; ++player) {

		Player *playerPtr = new Player;

		cout << "PLAYER " << player + 1 << endl;
		cout << "ENTER NAME: ";
		cin >> name;

		cout << "ENTER SURNAME: ";
		cin >> surname;

		playerPtr->setName(name, surname);
		playerPtr->setWallet(MAX_AMOUNT_MONEY);


		participant.push_back(*playerPtr);
		delete playerPtr;
	}

	
	

	// See initialize players

	do {

		// BEGIN ROUND

			cout << setfill('=') << setw(24) << "ROUND " << round + 1;
			cout << setfill('=') << setw(16) << " " << endl;

		
			for (int check = 0; check < participant.size(); ++check) {

				if (participant.at(check).getWallet() > 0) {
				cout << "PLAYER " << check + 1 << endl;
				cout << "NAME " << participant.at(check).getName() << endl;
				cout << "WALLET $" << participant.at(check).getWallet() << endl;
				
				if (check != participant.size()) {

					cout << "ENTER BET: $";
					cin >> wager;
					participant.at(check).setBet(wager);

				}

				if (wager < 0) {

					wager = wager * -1;
				}

				
				}
				else {

					cout << "PLAYER " << check + 1 << " HAS NO MONEY" << endl;
				}
			}

		// first distributing the cards
		

		for (int player = 0; player < numPlayers; ++player) {

			if (gameDeck.getSize() > 0) {


				dealer.distCards(participant.at(player), gameDeck);
			}
			else if (gameDeck.getSize() <= 0 && gameDeck.getSize() > 0) {


				dealer.distCards(participant.at(player), gameDeck);
			}
			else {

				cout << "ERROR: NO DECKS!" << endl;
			}
		}

		

		// First Dealer distrubes his/her own cards
		if (gameDeck.getSize() > 0) {

			dealer.distCards(dealer, gameDeck);
		}
		else if (gameDeck.getSize() <= 0 && gameDeck.getSize() > 0) {

			dealer.distCards(dealer, gameDeck);
		}
		else {

			cout << "ERROR: NO DECKS!" << endl;
		}

		// second distributing the cards
		for (int player = 0; player < numPlayers; ++player) {

			if (gameDeck.getSize() > 0) {


				dealer.distCards(participant.at(player), gameDeck);
			}
			else if (gameDeck.getSize() <= 0 && gameDeck.getSize() > 0) {


				dealer.distCards(participant.at(player), gameDeck);
			}
			else {


				cout << "ERROR: NO DECKS!" << endl;
			}
		}

		dealer.distCards(robot, gameDeck);
		dealer.distCards(robot, gameDeck);

		// Second Dealer distrubes his/her own cards
		if (gameDeck.getSize() > 0) {

			dealer.distCards(dealer, gameDeck);
		}
		else if (gameDeck.getSize() <= 0 && gameDeck.getSize() > 0) {

			dealer.distCards(dealer, gameDeck);
		}
		else {

			cout << "ERROR: NO DECKS!" << endl;
		}

		for (int turn = 0; turn < numPlayers; ++turn) {

			cout << setfill('=') << setw(41) << " " << endl;
			cout << "DEALER TOP CARD: ";

			switch (dealer.topCard().getFace()) {

			case 'A':

				cout << "Ace of";
				break;

			case 'J':

				cout << "Jack of";
				break;

			case 'Q':

				cout << "Queen of";
				break;

			case 'K':

				cout << "King of";
				break;

			case 'T':

				cout << "10 of";
				break;

			default:

				cout << dealer.topCard().getVal() << " of";
				break;

			}

			switch (dealer.topCard().getSuit()) {

			case 'C':

				cout << " Clubs" << endl;
				break;

			case 'H':

				cout << " Hearts" << endl;
				break;

			case 'S':

				cout << " Spades" << endl;
				break;

			case 'D':

				cout << " Diamonds" << endl;
				break;
			}

			cout << setfill('=') << setw(25) << "PLAYER " << turn + 1;
			cout << setfill('=') << setw(15) << " " << endl;

			do {

				if (!(participant.at(turn).getWallet() <= 0)) {
					cout << "PLAYER " << turn + 1 << " HAND: " << endl;
					participant.at(turn).seeCards();

					cout << "PLAYER SCORE: " << participant.at(turn).getScore() << endl;
					cout << "PLAYER WALLET: $" << participant.at(turn).getWallet() << endl;
					cout << "PLAYER BET: $" << participant.at(turn).getBet() << endl;

					cout << "Hit or Stand?" << endl;
					cin >> playerChoice;

					cout << setfill('=') << setw(20) << " " << endl;

					if (playerChoice == "Hit" && participant.at(turn).getScore() <= 21) {

						dealer.distCards(participant.at(turn), gameDeck);
					}
					else {

						cout << "STATUS: STAND" << endl;
					}

				}
				else {

					cout << "PLAYER " << turn + 1 << ": BANKRUPT." << endl;
					participant.at(turn).setScore(0);
					playerChoice = "Stand";
				}

				if (participant.at(turn).getScore() > 21) {

					participant.at(turn).seeCards();

					cout << "PLAYER SCORE: " << participant.at(turn).getScore() << endl;
					cout << "STATUS: BUSTED" << endl;
				}

				robot.autoPlay(dealer, gameDeck);

				cout << setfill('=') << setw(41) << " " << endl;
			} while (participant.at(turn).getScore() <= 21 && playerChoice != "Stand");
		}

		// Dealer must deal itself
		dealer.housePlays(gameDeck);

		cout << "DEALER HAND: " << endl;
		dealer.seeCards();

		cout << "DEALER SCORE: " << dealer.getScore() << endl;

		// Dealer goes through each player and determines who wins!
		participant.push_back(robot);

		// OBSERVE
		for (int player = 0; player < participant.size(); ++player) {

			cout << setfill('=') << setw(30) << " " << endl;


			cout << "PLAYER " << player + 1 << " NAME: ";
			cout << participant.at(player).getName() << endl;

			cout << "PLAYER " << player + 1 << " SCORE: ";
			cout << participant.at(player).getScore();
			cout << endl;

			if (participant.at(player).getWallet() <= 0) {

				cout << "PLAYER " << player + 1 << ": BANKRUPT" << endl;

			}
			else if (((dealer.getScore() > participant.at(player).getScore())
				|| (participant.at(player).getScore() > 21)) && dealer.getScore() <= 21) {

				//OBSERVE

				dealer.distBet(participant.at(player));


				cout << "DEALER WINS!" << endl;
				cout << "PLAYER  " << player + 1 << " BET: $" << participant.at(player).getBet() << endl;
				cout << "PLAYER  " << player + 1 << " WALLET: $" << participant.at(player).getWallet() << endl;
			}
			else if (dealer.getScore() == participant.at(player).getScore() 
				&& participant.at(player).getScore() <= 21) {

				dealer.distBet(participant.at(player));
				cout << "BOTH WIN!" << endl;
				cout << "PLAYER " << player + 1 << " BET: $" << participant.at(player).getBet() << endl;
				cout << "PLAYER " << player + 1 << " WALLET: $" << participant.at(player).getWallet() << endl;
			}
			else if (dealer.getScore() < participant.at(player).getScore() 
				&& participant.at(player).getScore() <= 21) {

				dealer.distBet(participant.at(player));
				cout << "PLAYER WINS!" << endl;
				cout << "PLAYER " << player + 1 << " BET: $" << participant.at(player).getBet() << endl;
				cout << "PLAYER " << player + 1 << " WALLET: $" << participant.at(player).getWallet() << endl;
			}
			else if (dealer.getScore() > 21 && participant.at(player).getScore() <= 21) {

				dealer.distBet(participant.at(player));
				cout << "PLAYER WINS!" << endl;
				cout << "PLAYER " << player + 1 << " BET: $" << participant.at(player).getBet() << endl;
				cout << "PLAYER " << player + 1 << " WALLET: $" << participant.at(player).getWallet() << endl;
			}
			else if (dealer.getScore() > 21 && participant.at(player).getScore() > 21) {

			cout << "TIE" << endl;
			cout << "PLAYER  " << player + 1 << " BET: $" << participant.at(player).getBet() << endl;
			cout << "PLAYER  " << player + 1 << " WALLET: $" << participant.at(player).getWallet() << endl;
			}


		}

		for (int player = 0; player < participant.size(); ++player) {

			if (participant.at(player).getWallet() <= 0) {

				++bustedPlayers;
			}

		}

		if (bustedPlayers != participant.size() 
			&& !(participant.at(participant.size() - 1).getWallet() <= 0)) {

			cout << "PLAY ANOTHER ROUND? Y/N " << endl;
			cout << ">";
			cin >> playAgn;
		}
		else {

			cout << "ALL PLAYERS HAVE NO MONEY" << endl;
		}

		for (int redo = 0; redo < participant.size(); ++redo) {

			participant.at(redo).reset();
			dealer.reset();
		}

		//participant.at(participant.size() - 1).setBet(MAX_BET_AI);
		// playerChoice = "Stand";
		participant.pop_back();
		++round;

	} while ((playAgn != "N" || playAgn != "n") && bustedPlayers != participant.size());
		//&& !(participant.at(participant.size() - 1).getWallet() <= 0));
	

	cout << setfill('=') << setw(21) << "END";
	cout << setfill('=') << setw(20) << " " << endl;

	system("pause");
	return 0;
}