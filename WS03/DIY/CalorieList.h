// Name:           Mahshad Najafi Ragheb

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////
#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_
#include "Food.h"
namespace sdds{
	//The CalorieList class should dynamically hold series of Food items and display them in a report.
	class CalorieList {
		int m_size;
		Food* m_food;
		int m_itemsAdded;
		int totalCal()const;
		void title()const;
		void footer()const;
		void setEmpty();
		bool isValid()const;

	public:
		void init(int size);
		bool add(const char* item_name, int calories, int when);
		void display()const;
		void deallocate();
	};
}
#endif // !SDDS_CALORIELIST_H_
