#include <iostream>
#include <fstream>

#include "Game.h"
#include "Results.h"
#include "ConsoleFeatures.h"

using namespace std;

// program menu
void menu() {
	cout << "=====Game menu=====\n";
	cout << "Press 0 - EXIT\n";
	cout << "Press 1 - Start the Game\n";
	cout << "Press 2 - How to Play\n";
	cout << "\n";
}

int main() {
	int choice = 0;
	do {
		// show menu and read user's choice
		menu();
		choice = ConsoleFeatures::cinInt("Enter: ");
		cout << "\n";

		ConsoleFeatures::clearConsole();

		switch (choice) {
		case 1: {
			// read valid number of words to play
			int mode = 0;
			while (mode < Game::minWords || mode > Game::maxWords) {
				mode = ConsoleFeatures::cinInt(
					"Enter number of words to play (" + 
					to_string(Game::minWords) + 
					"<=x<=" + 
					to_string(Game::maxWords) + 
					"): "
				);
			}
			ConsoleFeatures::clearConsole();

			// start the game
			Game game(mode);
			game.start();

			// save time to results
			if (game.getScore() > 0.0) Results::saveTime(game.getScore());

			break;
		}
		case 2: {
			// show how to play this game
			Game::howtoplay();
			ConsoleFeatures::pauseANDclear();
			break;
		}
		default: {
			// exit
			cout << "\033[1mSee you next time!\033[0m\n\n";
			break;
		}
		}
	} while (choice >= 1 && choice <= 2);

	return 0;
}