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
#include "Line.h"

using namespace std;
namespace sdds {
    Line::Line() {
        m_lenght = 0;
    }
    Line::Line(const char* label, unsigned lenght) : LblShape(label) , m_lenght(lenght){
    }
    Line::~Line(){
    }
    void Line::getSpecs(std::istream& IS) {
        LblShape::getSpecs(IS);
        IS >> m_lenght;
        IS.ignore(500, '\n');
    }
    void Line::draw(std::ostream& OS)const {
        if (m_lenght > 0 && label()) {
            OS << label() << endl;
            for (unsigned i = 0; i < m_lenght; i++) {
                OS << "="; 
            }
        }
    }
}