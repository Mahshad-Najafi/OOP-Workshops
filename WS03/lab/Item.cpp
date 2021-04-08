// Name:           Mahshad Najafi Ragheb
//
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Item.h"
using namespace std;
namespace sdds {
    void Item::setName(const char* name) {
        strcpy(m_itemName, name);
        m_itemName[20] = '\0';
    }
    void Item::setEmpty() {
        m_price = 0.0;
        m_itemName[0] = '\0';
    }
    void Item::set(const char* name, double price, bool taxed) {
        if (!name || price < 0.0) {
            setEmpty();
        }
        else{
            setName(name);
            m_price = price;
            m_taxed = taxed;
        }
    }
    void Item::display()const {
        if (isValid()) {
            cout << fixed;
            cout << setprecision(2);
            cout << "| ";
            cout << left;
            cout.fill('.');
            cout.width(20);
            cout << m_itemName << " | ";
            cout << right;
            cout.fill(' ');
            cout << setw(7) << m_price << " | " << (m_taxed ? "Yes" : "No ") << " |" << endl;
        }
        else {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
        }

    }
    bool Item::isValid()const {
        bool flag = true;
        if (m_itemName[0] == '\0' || m_price == 0.0) {
            flag = false;
        }
        return flag;
    }
    double Item::price()const {
        return m_price;
    }
    double Item::tax()const {
        if (m_taxed) {
            return m_price * taxRate;
        }
        return 0.0;
    }
}