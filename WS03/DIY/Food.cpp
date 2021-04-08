//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:           Mahshad Najafi Ragheb

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Food.h"
using namespace std;
namespace sdds {
	void Food::printTime(int time) {
		switch (time) {
		case 1:
			cout << "Breakfast";
			break;
		case 2:
			cout << "Lunch";
			break;
		case 3:
			cout << "Dinner";
			break;
		case 4:
			cout << "Snack";
		}
	}
	//If the Food item holds invalid information all the data are replaced with "x":
	void Food::display() {
		char tempName[31] = { "" };
		strncpy(tempName, m_name, 30);
		if (isValid()) {
			cout << fixed;
			cout << "| ";
			cout << left;
			cout.fill('.');
			cout << setw(30) << tempName << " | ";
			cout << right;
			cout.fill(' ');
			cout << setw(4) << m_cal << " | ";
			cout << left;
			cout << setw(10);
			printTime(m_consumeTime);
			cout << " |" << endl;
		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
	}
	void Food::setName(const char* name) {
		strcpy(m_name, name);
	}
	void Food::setEmpty() {
		m_name[0] = '\0';
		m_cal = 0;
		m_consumeTime = 0; 
	}
	void Food::set(const char* name, int cal, int timeCode) {
		if (!name || cal < 0 || timeCode < 1) {
			setEmpty();
		}
		else {
			setName(name);
			m_cal = cal;
			m_consumeTime = timeCode;
		}
	}
	bool Food::isValid()const {
		bool flag = true;
		if (m_name[0] == '\0' || m_cal <= 0 || m_cal > 3000 || m_consumeTime <= 0 || m_consumeTime > 4) {
			flag = false;
		}
		return flag;
	}
	int Food::calorie()const {
		return m_cal;
	}
	int Food::time()const {
		return m_consumeTime;
	}
}