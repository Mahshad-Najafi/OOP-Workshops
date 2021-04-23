#ifndef SDDS_SHOPPINGLIST_H
#define SDDS_SHOPPINGLIST_H
#include <iostream>
#include <cstring>

const int MAX_NO_OF_RECS = 15;

namespace sdds {
	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();
}
#endif // !SDDS_SHOPPINGLIST_H
