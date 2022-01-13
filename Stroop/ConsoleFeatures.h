#ifndef CONSOLEFEATURES_H
#define CONSOLEFEATURES_H

#include <iostream>
#include <string>
// _getch()
#include <conio.h>

/// <summary>
/// some console custom functions to make code easier to read
/// </summary>
class ConsoleFeatures {
public:
	// reset cin-stream
	static const void cinReset();

	// clear console (like new page of console)
	static const void clearConsole();

	// pause console until any button will not be pressed AND clear console after
	static const void pauseANDclear();

	/// <summary>
	/// reads int until it's really int (if char -> read one more time)
	/// </summary>
	/// <param name="message">message to output before reading</param>
	/// <returns>read int</returns>
	static const int cinInt(std::string message);

	/// <summary>
	/// reads one char using method _getch()
	/// </summary>
	/// <param name="message">message to output before reading</param>
	/// <returns>one char</returns>
	static const char getchChar(std::string message);
};

#endif