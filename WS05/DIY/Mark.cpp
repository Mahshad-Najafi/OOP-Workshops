/*
    Name:           Mahshad Najafi Ragheb

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"

using namespace std;
namespace sdds {

	Mark::Mark() {
        setEmpty();
	}
    Mark::Mark(int mark) {
        m_mark = mark;
    }
    void Mark::setEmpty() {
        m_mark = 0;
    }
    Mark::operator bool() const {
        return (m_mark >= 0 && m_mark <= 100);
    }
    Mark::operator int() const {
        if (*this) {
            return m_mark;
        }
        return 0;
    }
    Mark& Mark::operator += (int addMark) {
        //call bool operator to check the value of mark. If mark has a valid value, perform addition.
        if (*this) m_mark += addMark;
        return *this;
    }
    Mark& Mark::operator = (int assignMark) {
        m_mark = assignMark;
        return* this;
    }
    Mark::operator double() const {
        if (0 <= m_mark && m_mark < 50) return 0.0;
        if (m_mark < 60) return 1.0;
        if (m_mark < 70) return 2.0;
        if (m_mark < 80) return 3.0;
        if (m_mark <= 100) return 4.0;
        return 0;
    }
    Mark::operator char() const {
        if (0 <= m_mark && m_mark < 50) return 'F';
        if (m_mark < 60) return 'D';
        if (m_mark < 70) return 'C';
        if (m_mark < 80) return 'B';
        if (m_mark <= 100) return 'A';
        return 'X';
    }
   int operator+= (int& val, const Mark& mark) {
        if (mark) val += int(mark);
        return val;
    }
}
