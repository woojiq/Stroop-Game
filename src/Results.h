#ifndef RESULTS_H
#define RESULTS_H

// file handling
#include <fstream>
// setprecision
#include <iomanip>
// to know current data
#include <ctime>
#include <array>

/// <summary>
/// save results from Class Game to file in format: GameResut|Day|Month|Year|Hours|Minutes
/// </summary>
class Results {
public:
	// save time to the file
	static const void saveTime(double time);

	// return current date in format Day-Month-Year-Hours-Mins
	static const std::array<int, 5> currentData();

private:
	// name of the file where the game results will be stored
	static const char* filename;
};

#endif