#include "ConsoleFeatures.h"

const void ConsoleFeatures::cinReset() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

const void ConsoleFeatures::clearConsole() {
	std::cout << "\033c";
}

const void ConsoleFeatures::pauseANDclear() {
	std::cout << "\nPress to continue...";
	std::cin.get();
	clearConsole();
}

const int ConsoleFeatures::cinInt(std::string message) {
	int val = -1;
	while (val < 0) {
		std::cout << message;
		std::cin >> val;

		// want to get '\n'
		char check = std::cin.get();

		// input wasn't valid
		if (!std::cin.good() || check != '\n') {
			val = -1;
			cinReset();
		}
	}

	return val;
}

const char ConsoleFeatures::cinChar(std::string message) {
	char val = 0;
	while (!val) {
		std::cout << message;
		std::cin >> val;

		// want to get '\n'
		char check = std::cin.get();

		// if check != '\n', cinReset will skip all symbol until '\n' and '\n' itself
		if (!std::cin.good() || check != '\n') {
			cinReset();
			val = 0;
			continue;
		}
	}

	return val;
}