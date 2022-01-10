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
#include <string>
#include <iostream>

/// <summary>
/// contain game results in one file
/// </summary>
class Results {
public:
	// constructor with time; take current date
	Results(double t);

	// save game result to the file
	const void save();

	// returns place among all records
	static const int rating(double tim);

	// returns number of all records in file
	static const int numOfRecords();

private:
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