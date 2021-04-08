/*
	Name:           Mahshad Najafi Ragheb

	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> 
#include "Label.h"

namespace sdds {
	Label::Label() {
		strcpy(m_frame, "+-+|+-+|");
		m_labelContent = new char[2];
		m_labelContent[0] = '\0';
	}
	Label::Label(const char* frameArg) {
		strcpy(m_frame, frameArg);
		m_labelContent = new char[2];
		m_labelContent[0] = '\0';
	}
	Label::Label(const char* frameArg, const char* content) {
		strcpy(m_frame, frameArg);
		m_labelContent = new char[strlen(content)+1];
		strcpy(m_labelContent, content);
	}
	Label::~Label(){
		deallocate();
	}
	void Label::deallocate() {
		delete[] m_labelContent;
		m_labelContent = nullptr;
	}
	void Label::readLabel() {
		char temp[71];
		std::cin.getline(temp, sizeof(temp));
		temp[70] = '\0';
		m_labelContent = new char[sizeof(temp) + 1];
		strcpy(m_labelContent, temp);
	}
	std::ostream& sdds::Label::printLabel()const {
		int length = strlen(m_labelContent);
		if (m_labelContent[0] != '\0') { 
			std::cout << m_frame[0];
			for (auto i = 0; i < (length + 2); i++) {
				std::cout << m_frame[1];
			}
			std::cout << m_frame[2] << std::endl;
			
			std::cout << m_frame[7];
			for (auto i = 0; i < (length + 2); i++) {
				std::cout << " ";
			}
			std::cout << m_frame[3] << std::endl;

			std::cout << m_frame[7] << " " << m_labelContent << " " << m_frame[3] << std::endl;

			std::cout << m_frame[7];
			for (auto i = 0; i < (length + 2); i++) {
				std::cout << " ";
			}
			std::cout << m_frame[3] << std::endl;

			std::cout << m_frame[6];
			for (auto i = 0; i < (length + 2); i++) {
				std::cout << m_frame[5];
			}
			std::cout << m_frame[4];
		}
		return std::cout;
	}
}