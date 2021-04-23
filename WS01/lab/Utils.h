#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
#include <cstring>
namespace sdds {
	void flushkeys();
	bool ValidYesResponse(char ch);
	bool yes();
	void readCstr(char cstr[], int len);
	int readInt(int min, int max);
}
#endif // !SDDS_UTILS_H_
