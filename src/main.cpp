#include <iostream>
#include <fstream>
#include <string>

#include "Game.h"
#include "Results.h"
#include "ConsoleFeatures.h"

using namespace std;

// choices for statistics_menu
void statistics_info() {
	cout << "======Statistics menu======\n";
	cout << "Press 0 - EXIT\n";
	//cout << "Press 1 - Show my Person Record\n";
	cout << "\n";
}

void statistics_menu() {
	int choice = 0;
	do {
		// show menu and read user's choice
		statistics_info();
		choice = ConsoleFeatures::cinInt("Enter: ");
		cout << "\n";

		ConsoleFeatures::clearConsole();

		switch (choice) {
		default: {
			break;
		}
		}

	} while (choice >= 1 && choice <= 1);
}

// choices for main_menu
void main_info() {
	cout << "=====Game menu=====\n";
	cout << "Press 0 - EXIT\n";
	cout << "Press 1 - Start the Game\n";
	cout << "Press 2 - How to Play\n";
	cout << "Press 3 - My statistics\n";
	cout << "\n";
}

void main_menu() {
	int choice = 0;
	do {
		// show menu and read user's choice
		main_info();
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

			break;
		}
		case 2: {
			// show how to play this game
			Game::howtoplay();
			ConsoleFeatures::pauseANDclear();
			break;
		}
		case 3: {
			statistics_menu();
			break;
		}
		default: {
			// exit
			cout << "\033[1mSee you next time!\033[0m\n\n";
			break;
		}
		}
	} while (choice >= 1 && choice <= 3);
}

int main() {
	main_menu();
	return 0;
}