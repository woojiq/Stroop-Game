#include "Results.h"

#if 1
const char *Results::filename = "results.txt";
#else
const char* Results::filename = "testresults.txt";
#endif

Results::Results(double t) {
	if (t <= 0.0) throw ("Wrong time to save!");
	timeSec = t;

	tm date;
	time_t now = time(0);
	localtime_s(&date, &now);
	
	day = date.tm_mday;
	month = date.tm_mon;
	year = date.tm_year;
	hour = date.tm_hour;
	min = date.tm_hour;
}

const void Results::save() {
	std::ofstream out(filename, std::ios_base::app);

	// output game result
	out << std::fixed << std::setprecision(4) << timeSec;
	out << " | " << day;
	out << " | " << month;
	out << " | " << year;
	out << " | " << hour;
	out << " | " << min;
	out << "\n";
}

const int Results::rating(double tim) {
	int place = 1;
	// go through all the records
	std::ifstream in(filename);
	std::string line;
	while (getline(in, line)) {
		double res;
		std::istringstream read(line);
		read >> res;

		if (tim > res) place++;
	}
	return place;
	return 0;
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