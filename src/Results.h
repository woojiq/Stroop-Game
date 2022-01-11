#ifndef RESULTS_H
#define RESULTS_H

// file handling
#include <fstream>
// setprecision
#include <iomanip>
// istringstream
#include <sstream>
// time(), localtime()
#include <ctime>
// regex_search
#include <regex>
// fprintf
#include <cstdio>
#include <string>
#include <iostream>

#include "ConsoleFeatures.h"

/// <summary>
/// contain game results in one file
/// </summary>
class Results {
public:
	// constructor with time; take current date
	Results(double t);
	// constructor that take data from formatted string
	Results(std::string data);

	// save game result to the file
	const void save();

	// returns place among all records
	static const int rating(double tim);

	// returns number of all records in file
	static const int numOfRecords();

	// grabs time from recorded line
	static const double getTime(std::string line);

	// output info about the best result
	static const void showBest();

	// output info about last N games
	static const void showLastN(int N);

	static const int Precision = 4;

private:
	// output data to console with explanatory words
	const void printToUser();

	// time in sec
	double timeSec;
	// current day
	int day;
	// current month
	int month;
	// current year
	int year;
	// current hour
	int hour;
	// current min
	int min;

	// name of the file where the game results will be stored
	static const char* filename;
};

#endif