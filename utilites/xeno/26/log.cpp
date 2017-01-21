#include "log.h"

#include <windows.h>
#include <sstream>



Logger::Logger(const std::string &logFilename)
{
	logFile.open(logFilename.c_str(), std::ios_base::trunc);

	if (!logFile.is_open())
	{
		std::cout << "Warning: error while opening " << logFilename << " for writing.\n";
	}
}



Logger::~Logger()
{
	if (logFile.is_open())
	{
		logFile.close();
	}
}



void Logger::log(const char *log_text, ...)
{
	if (logFile.is_open())
	{
		char* buf = new char[1024];
		va_list ap;
		time_t t;

		// Use a temporary buffer to fill in the variables
		va_start(ap, log_text);
		vsprintf(buf, log_text, ap);
		va_end(ap);

		// Get the current system time
		time(&t);

		// Print the log entry
		std::stringstream timeStr;
		timeStr << "[";
		timeStr << ((((t / 60) / 60) % 24 < 10) ? "0" : "");
		timeStr << (int)(((t / 60) / 60) % 24);
		timeStr << ":";
		timeStr << (((t / 60) % 60 < 10) ? "0" : "");
		timeStr << (int)((t / 60) % 60);
		timeStr << ":";
		timeStr << ((t % 60 < 10) ? "0" : "");
		timeStr << (int)(t % 60);
		timeStr << "] ";

		logFile << timeStr.str() << buf << std::endl;

		// Delete temporary buffer
		delete[] buf;
	}
}



void Logger::error(const std::string &error_text)
{
	log("Error: %s", error_text.c_str());
	MessageBox(NULL, error_text.c_str(), "Error", MB_ICONERROR | MB_OK);
	exit(1);
}