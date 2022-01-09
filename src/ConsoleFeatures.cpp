#include "ConsoleFeatures.h"

void ConsoleFeatures::cinReset() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void ConsoleFeatures::clearConsole() {
	std::cout << "\033c";
}

void ConsoleFeatures::pauseANDclear() {
	std::cout << "\nPress to continue...";
	std::cin.get();
	clearConsole();
}

int ConsoleFeatures::cinInt(std::string message) {
	int val = -1;
	while (val < 0) {
		std::cout << message;
		std::cin >> val;

		char check = std::cin.get();

		if (!std::cin.good() || check != '\n') {
			val = -1;
			cinReset();
		}
	}

	return val;
}

char ConsoleFeatures::cinChar(std::string message) {
	char val = 0;
	while (!val) {
		std::cout << message;
		std::cin >> val;

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