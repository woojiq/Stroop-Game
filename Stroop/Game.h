#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>
// setprecision
#include <iomanip>
// clock
#include <time.h>
// rand
#include <stdlib.h>
#include "ConsoleFeatures.h"
#include "Results.h"

/// <summary>
/// Creates an object for playing the stroop (or words). The player must name the color of the word, not the word itself
/// </summary>
class Game {
public:
	/// <summary>
	/// class constructor
	/// </summary>
	/// <param name="">number of words to play</param>
	Game(int);

	// prints rules of this game and how to play
	static const void howtoplay();

	/// <summary>
	/// Starts the game
	/// </summary>
	void start();

	/// <summary>
	/// pause console for time = parametr
	/// </summary>
	/// <param name="">time to sleep</param>
	static const void sleepT(double);

	static const int minWords = 5;
	static const int maxWords = 50;

private:
	// preparation before the game
	const void startPrep();

	/// <summary>
	/// actions after game like save results
	/// </summary>
	const void finish();

	/// <summary>
	/// check if user's answer = correct. User has 3 attempts else he loses; and score == 0
	/// </summary>
	/// <param name="correct">correct answer</param>
	/// <returns>whether the user gave the correct answer</returns>
	const bool tryToGuess(const char correct);

	// game duration in sec (if mode = 0 -> smth went wrong; don't take it)
	double score;

	// how many words will be in this game
	int mode;

	// number of available colors
	static const int num_of_colors = 6;

	// available words in game
	static const std::string colors_name[num_of_colors];

	// codes to write color text in the console. codes[i] matches colors_name[i]
	// codes[num_of_colors] - to end the output of multicolored text
	static const std::string codes[num_of_colors + 1];
};

#endif