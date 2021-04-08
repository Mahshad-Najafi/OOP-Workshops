/*
    Name:           Mahshad Najafi Ragheb
    Student ID:     136115201
    email:          mnajafi-ragheb@myseneca.ca
    Date:           2021-03-25

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Rectangle.h"

using namespace std;
namespace sdds {
    //Sets the width and height member variables to zero.
    Rectangle::Rectangle(): LblShape (), m_width(0), m_height(0) {
    }
    Rectangle::Rectangle(const char* label, unsigned width, unsigned height) : LblShape(label), m_width(width), m_height(height) {
        if (m_height < 3 || m_width < strlen(label) + 2) {
            m_width = 0;
            m_height = 0;
        }
    }
    Rectangle::~Rectangle() {
    }
    void Rectangle::getSpecs(std::istream& IS) {
        LblShape::getSpecs(IS);
        IS >> m_width;
        IS.ignore(500, ',');
        IS >> m_height;
        IS.ignore(500, '\n');
    }
    void Rectangle::draw(std::ostream& OS)const {
        if (m_height > 0 && m_width > 0 && this->label()) {
            OS << "+";
            for (unsigned i = 0; i < (m_width - 2); i++) {
                OS << "-";
            }
            OS << "+" << endl;
            OS << "|";
            OS << this->label();
            OS.fill(' ');
            OS.width(m_width - 1 - strlen(this->label()));
            OS << "|" << endl;
            for (unsigned j = 0; j < (m_height - 3); j++) {
                OS << "|";
                for (unsigned i = 0; i < (m_width - 2); i++) {
                    OS << " ";
                }
                OS << "|" << endl;
            }
            OS << "+";
            for (unsigned i = 0; i < (m_width - 2); i++) {
                OS << "-";
            }
            OS << "+";
        }
    }
}