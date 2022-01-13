#include "Game.h"

Game::Game(int words) {
	if (words < minWords || words > maxWords) throw std::string("Wrong number of words!");

	score = 0.0;
	mode = words;
}

const void Game::howtoplay() {
	std::cout << "==========HOW TO PLAY==========\n";
	std::cout << "\033[3;100;30mYou will be presented with a series of color words.\n";
	std::cout << "These words will appear in different colors.\n";
	std::cout << "Your job is to indicate the color in which the word is written as quickly and accurately as possible.\n";
	std::cout << "You must enter first letter of the color (without Enter).\033[0m\n";
	std::cout << "For example: " << "\033[0;32m" << "yellow" << Game::codes[num_of_colors] << "\n";
	std::cout << "Answer: g (because the word " << "\033[0;32m" << "yellow" << "\033[0m" << " is green)\n";
	std::cout << "List of possible colors and their names: \n";
	for (int i = 0; i < num_of_colors; i++) {
		std::cout << codes[i] << colors_name[i] << codes[num_of_colors] << " - Answer is " << colors_name[i][0] << "\n";
	}
	std::cout << "\033[3;100;30mYour result is average time per word.\033[0m\n";
	std::cout << "==========HOW TO PLAY==========\n";
}

const void Game::sleepT(double sec) {
	clock_t begin = clock();
	clock_t now = begin;

	while (true) {
		now = clock();
		clock_t duration = (now - begin);
		if (duration / CLOCKS_PER_SEC >= sec) break;
	}
}

const void Game::startPrep() {
	std::cout << "The game is ready to start === Number of words: " << mode << "\n";
	ConsoleFeatures::pauseANDclear();

	// countdown: 3; 2; 1; GO
	for (int i = 3; i >= 0; i--) {
		ConsoleFeatures::clearConsole();
		if (!i) std::cout << "GO";
		else std::cout << i;
		sleepT(1.0);
	}
	ConsoleFeatures::clearConsole();
}

const bool Game::tryToGuess(const char correct) {
	// user has only 3 attempts to guess the color (otherwise he is silly)
	for (int i = 1; i <= 3; i++) {
		char attempt = ConsoleFeatures::getchChar("Your Answer: ");
		if (attempt == correct) return 1;
	}
	return 0;
}

void Game::start() {
	startPrep();

	clock_t begin, end;

	srand(time(NULL));

	for (int i = 1; i <= mode; i++) {
		// generate word with color
		int word = rand() % num_of_colors;
		int color = rand() % num_of_colors;
		std::string final_word = codes[color] + colors_name[word] + codes[num_of_colors];
		std::cout << final_word << "\n";

		begin = clock();

		// check whether user is right
		bool right = tryToGuess(colors_name[color][0]);
		ConsoleFeatures::clearConsole();
		
		end = clock();
		// time that user spent to guess the color
		score += double(end - begin) / double(CLOCKS_PER_SEC);

		if (!right || double(end-begin)/double(CLOCKS_PER_SEC) > 100.0) {
			std::cout << "You're so bad. Relax and then try again!\n";
			ConsoleFeatures::pauseANDclear();
			// score == 0.0 means that game result isn't valid
			score = 0.0;
			break;
		}

		if (i < mode) sleepT(1);
	}

	return finish();
}

const void Game::finish() {
	// calculate score (average time per word)
	if (score == 0.0) return;

	score /= double(mode);
	// save time to results
	Results res(score);
	res.save();

	std::cout << "Your Average time per word = " << std::fixed << std::setprecision(Results::Precision) << score << " sec\n";

	int place = Results::rating(score);
	int all = Results::numOfRecords();

	if (place == 1) {
		std::cout << "Congratulations. You beat your personal record!\n";
	}
	else if (place == all) {
		std::cout << "This is your worst result. But don't give up (Never give up).\n";
	}
	else {
		std::cout << "This is " << place << "/" << all << " place among your all results\n";
	}

	ConsoleFeatures::pauseANDclear();
}

const std::string Game::colors_name[] = {
	"green",
	"blue",
	"red",
	"purple",
	"yellow",
	"white"
};

const std::string Game::codes[] = {
	"\033[0;32m",
	"\033[0;36m",
	"\033[0;31m",
	"\033[0;35m",
	"\033[0;33m",
	"\033[0;37m",
	// go to normal color
	"\033[0m"
};