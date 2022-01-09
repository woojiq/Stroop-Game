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
		menu();
		choice = ConsoleFeatures::cinInt("Enter: ");
		cout << "\n";

		ConsoleFeatures::clearConsole();

		switch (choice) {
		case 1: {
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

			Game game(mode);

			game.start();

			break;
		}
		case 2: {
			Game::howtoplay();
			ConsoleFeatures::pauseANDclear();
			break;
		}
		default: {
			cout << "\033[1mSee you next time!\033[0m\n\n";
			break;
		}
		}
	} while (choice >= 1 && choice <= 2);

	return 0;
}