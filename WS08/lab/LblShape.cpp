/*
    Name:           Mahshad Najafi Ragheb
    Date:           2021-03-25

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "LblShape.h"

using namespace std;
namespace sdds {
    char* LblShape::label() const {
        return m_label;
    }
    void LblShape::allocate(const char* label) {
        m_label = new char[strlen(label) + 1];
        strcpy(m_label, label);
    }
    LblShape::LblShape() {
    }
    LblShape::LblShape(const char* label) {
        allocate(label);
    }
    LblShape::~LblShape() {
        delete[] m_label;
    }
    //receive a label (Cstring) from istream up to the ',' character, and then extract and ignore the comma
    void LblShape::getSpecs(std::istream& IS) {
        if (m_label != nullptr) delete[] m_label;        
        char inputLabel[100];
        IS.get(inputLabel, sizeof(inputLabel),',');
        IS.ignore(sizeof(inputLabel), ',');
        allocate(inputLabel);
    }
}
