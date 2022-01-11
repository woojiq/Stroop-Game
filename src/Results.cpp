#include "Results.h"

#if 1
const char *Results::filename = "results.txt";
#else
const char* Results::filename = "testresults.txt";
#endif

// TODO - use regex library to more elegant solution

Results::Results(double t) {
	if (t <= 0.0) throw ("Wrong time to save!");
	timeSec = t;

	tm date;
	time_t now = time(0);
	localtime_s(&date, &now);
	
	day = date.tm_mday;
	month = date.tm_mon + 1;
	year = date.tm_year + 1900;
	hour = date.tm_hour;
	min = date.tm_hour;
}

Results::Results(std::string data) {
	// regular expression to find all numbers from file
	std::regex record("^([0-9]+.[0-9]+)...([0-9]+)...([0-9]+)...([0-9]+)...([0-9]+)...([0-9]+)");
	std::smatch find;
	std::regex_search(data, find, record);

	timeSec = stod(find.str(1));
	day = stoi(find.str(2));
	month = stoi(find.str(3));
	year = stoi(find.str(4));
	hour = stoi(find.str(5));
	min = stoi(find.str(6));
}

const void Results::save() {
	std::ofstream out(filename, std::ios_base::app);

	// output game result
	out << std::fixed << std::setprecision(4) << timeSec;
	out << " | " << day << " | " << month << " | " << year << " | " << hour << " | " << min;
	out << "\n";
}

const int Results::rating(double tim) {
	int place = 1;

	// go through all the records
	std::ifstream in(filename);
	std::string line;
	while (getline(in, line)) {
		double cur = getTime(line);

		if (tim > cur) place++;
	}
	return place;
}

const int Results::numOfRecords() {
	int cnt = 0;

	std::string line;
	std::ifstream in(filename);
	while (getline(in, line)) {
		cnt++;
	}
	return cnt;
}

const double Results::getTime(std::string line) {
	double res;
	std::istringstream read(line);
	read >> res;
	return res;
}

const void Results::showBest() {
	std::ifstream in(filename);
	double bestT = 0.0;
	std::string bestS;
	std::string curS;
	
	while (getline(in, curS)) {
		double curT = getTime(curS);
		if (!bestT || curT < bestT) {
			bestS = curS;
			bestT = getTime(bestS);
		}
	}
	if (!bestT) {
		std::cout << "You haven't played yet!\n";
	}
	else {
		Results best(bestS);
		best.printToUser();
	}

	ConsoleFeatures::pauseANDclear();
}

const void Results::printToUser() {
	std::cout << "Time: " << std::fixed << std::setprecision(4) << timeSec << "\n";
	std::cout << "Date: " << day << "-" << month << "-" << year << " " << hour << ":" << min << "\n";
}