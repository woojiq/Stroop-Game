#ifndef CONSOLEFEATURES_H
#define CONSOLEFEATURES_H

#include <iostream>
#include <string>

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
	/// read int until it's really int (if char -> read one more time)
	/// </summary>
	/// <param name="message">message to output before reading</param>
	/// <returns>read int</returns>
	static const int cinInt(std::string message);

	/// <summary>
	/// read char until it's really one char (not two or more)
	/// </summary>
	/// <param name="message">message to output before reading</param>
	/// <returns>one char</returns>
	static const char cinChar(std::string message);
};

#endif