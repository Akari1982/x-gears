#ifndef _LOG_H
#define _LOG_H

#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <string>
#include <iostream>
#include <fstream>

// The Log Class : Useful to write debug or info messages
class Logger
{
public:
	// Constructor, opens log file for writing.
	Logger(const std::string &logFilename);

	// Destructor, closes log file.
	~Logger();

	// Enters a message in the log. The message will be timestamped.
	void log(const char *log_text, ...);

	// Log an error and quit. The error will pop-up in Windows
	void error(const std::string &error_text);

private:
	std::ofstream logFile;
};



extern Logger *logger;
#endif