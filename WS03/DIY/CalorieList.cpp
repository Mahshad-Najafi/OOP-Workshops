//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:           Mahshad Najafi Ragheb
//
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "CalorieList.h"
using namespace std;
namespace sdds {

	//calculate total calorie:
	int CalorieList::totalCal()const {
		int totalCalorie = 0;
		for (int i = 0; i < m_size; i++) {
			totalCalorie += m_food[i].calorie();
		}
		return totalCalorie;
	}
	void CalorieList::title()const {
		cout << "+----------------------------------------------------+" << endl;
		if (isValid()) {
			cout << "|  Daily Calorie Consumption                         |" << endl;
		}
		else {
			cout << "| Invalid Calorie Consumption list                   |" << endl;
		}
		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;
	}
	void CalorieList::footer()const {
		cout << "+--------------------------------+------+------------+" << endl;
		if (isValid()) {
			cout << "|    Total Calories for today:   ";
			cout << right;
			cout << setw(6) << totalCal() << " |" << "            |" << endl;
		}
		else {
			cout << "|    Invalid Calorie Consumption list                |" << endl;
		}
		cout << "+----------------------------------------------------+" << endl;
	}
	void CalorieList::setEmpty() {
		m_food = nullptr;
		m_size = 0;
	}
	bool CalorieList::isValid()const {
		bool flag = false;
		if (m_food != nullptr) {
			flag = true;
			for (int i = 0; i < m_size && flag; i++) {
				if (!m_food[i].isValid()) {
					flag = false;
				}
			}
		}
		return flag;
	}
	// This function is called to prepare the CalorieList for accepting food items
	void CalorieList::init(int size) {
		if (size < 0) {
			setEmpty();
		}
		else
		{
			m_size = size;
			m_itemsAdded = 0;
			m_food = new Food[m_size];
			for (int i = 0; i < m_size; i++) {
				m_food[i].setEmpty();
			}
		}
	}
	// Adds Food Items using their Name, Calorie count and time of consumption up to 
	bool CalorieList::add(const char* item_name, int calories, int when) {
		bool flag = false;
		if (m_itemsAdded < m_size) {
			m_food[m_itemsAdded].set(item_name, calories, when);
			m_itemsAdded++;
			flag = true;
		}
		return flag;
	}
	// Displays the report with food information and the total calorie consumed in the day
	void CalorieList::display()const {
		title();
		for (int i = 0; i < m_size; i++) {
			m_food[i].display();
		}
		footer();
	}
	void CalorieList::deallocate() {
		delete[] m_food;
	}
}

