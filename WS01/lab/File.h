#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
#include <iostream>
#include <cstring>
#include "ShoppingRec.h"
namespace sdds {
	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
}
#endif // !SDDS_FILE_H_
