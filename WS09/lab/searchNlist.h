//   Name:           Mahshad Najafi Ragheb
//   email:          mnajafi-ragheb@myseneca.ca
//   Student ID:     136115201
//   Date:           2021-04-04
//   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SDDS_SEARCHNLIST_H
#define SDDS_SEARCHNLIST_H
#include <iostream>
#include "Collection.h"
using namespace std;
namespace sdds {
	//This function template contains two types. It receives four arguments and returns a bool. The first argument is a reference to a Collection object. The second argument is an array of objects from Collection. The third argument is an integer type that indicates the length of the second argument and finally, the last argument is a constant array.
	template <typename T1, typename T2>
	bool search(Collection<T1>& founds, T1* arrayofObjects, int len, const T2 key) {
		int counter = 0;
		for (int i = 0; i < len; i++) {
			if (arrayofObjects[i] == key) {
				founds[counter] = arrayofObjects[i];
				counter++;
			}
		}
		return counter;
	}
	//This function template contains one type. It receives three arguments and returns nothing. The first argument is a const Cstring, the second one is a const array and the last one is the lenght of the second arguments.
	template <typename T>
	void listArrayElements(const char* title, const T* arrayofelm, int len) {
		cout << title << endl;
		for (int i = 0; i < len; i++) {
			cout << i+1 << ": " << arrayofelm[i] << endl;
		 }
	}
}
#endif // !SDDS_SEARCHNLIST_H
