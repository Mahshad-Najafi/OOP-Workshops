/*
    Name:           Mahshad Najafi Ragheb
    Date:           2021-03-25

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Shape.h"
using namespace std;
namespace sdds {
    Shape::~Shape() {
    }
    std::ostream& operator<<(std::ostream& OS, const Shape& S) {
        S.draw(OS);
        return OS;
    }
    std::istream& operator>>(std::istream& IS, Shape& S) {
        S.getSpecs(IS);
        return IS;
    }
}