/*
	Name:           Mahshad Najafi Ragheb

	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> 
#include "LabelMaker.h"

namespace sdds {
	LabelMaker::LabelMaker(int noOfLabels) {
		arrOfLabels = new Label[noOfLabels];
		m_noOfLabels = noOfLabels;
	}
	LabelMaker::~LabelMaker() {
		for (auto i = 0; i < m_noOfLabels; i++) {
			arrOfLabels[i].deallocate();
		}
		delete[] arrOfLabels;
		arrOfLabels = nullptr;
	}
	void LabelMaker::readLabels() {
		std::cout << "Enter " << m_noOfLabels << " labels:" << std::endl;
		for (auto i = 0; i < m_noOfLabels; i++) {
			std::cout << "Enter label number " << i + 1 << std::endl;
			std::cout << "> ";
			arrOfLabels[i].readLabel();
		}
	}
	void LabelMaker::printLabels() {
		for (auto i = 0; i < m_noOfLabels; i++) {
			arrOfLabels[i].printLabel();
			std::cout << std::endl;
		}
	}
}