#include "Results.h"

const char *Results::filename = "results.txt";

const void Results::saveTime(double time) {
	if (time <= 0.0) throw ("Wrong time to save!");

	std::ofstream out(filename, std::ios_base::app);
	// output game result
	out << std::fixed << std::setprecision(4) << time;

	// output data when this result was set
	std::array<int, 5> date = currentData();
	for (int i = 0; i < 5; i++) {
		out << " | " << date[i];
	}
	out << "\n";
}

const std::array<int, 5> Results::currentData() {
	// consists of sec, min, hour, day, month, year etc
	tm date;
	// time since 1 january 1900
	time_t now = time(0);
	// convert time since epoch to calendar local time
	localtime_s(&date, &now);

	return { date.tm_mday, date.tm_mon+1, date.tm_year+1900, date.tm_hour, date.tm_min };
}

const int Results::rating(double time) {
	int place = 1;
	// go through all the records
	std::ifstream in(filename);
	std::string line;
	while (getline(in, line)) {
		double res;
		std::istringstream read(line);
		read >> res;

		if (time > res) place++;
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