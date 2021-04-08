// Name:           Mahshad Najafi Ragheb
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Bill.h"
using namespace std;
namespace sdds {
    double Bill::totalTax()const {
        double total_tax = 0;
        for (int i = 0; i < m_noOfItems; i++) {
            total_tax += m_items[i].tax();
        }
        return total_tax;
    }
    double Bill::totalPrice()const {
        double total_price = 0;
        for (int i = 0; i < m_noOfItems; i++) {
            total_price += m_items[i].price();
        }
        return total_price;
    }
    void Bill::Title()const {
        cout << "+--------------------------------------+" << endl;
        if (isValid()) {
            cout << "| ";
            cout.width(36); cout << left  << m_title << " |" << endl;
        }
        else {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
    }
    void Bill::footer()const {
        cout << "+----------------------+---------+-----+" << endl;
        if (isValid()) {
            cout << fixed;
            cout << setprecision(2);
            cout << "|                Total Tax: ";
            cout.width(10); cout << totalTax() << " |" << endl;
            cout << "|              Total Price: ";
            cout.width(10); cout << totalPrice() << " |" << endl;
            cout << "|          Total After Tax: ";
            cout.width(10); cout << totalTax() + totalPrice() << " |" << endl;
        }
        else {
            cout << "| Invalid Bill                         |" << endl;

        }
        cout << "+--------------------------------------+" << endl;
    }
    void Bill::setEmpty() {
        m_title[0] = '\0';
        m_items = nullptr;
    }
    bool Bill::isValid()const {
        bool flag = false;
        if (m_title[0] != '\0' && m_items != nullptr) {
            flag = true;
            for (int i = 0; i < m_noOfItems && flag; i++) {
                if (!m_items[i].isValid()) {
                    flag = false;
                }
            }
        }
        return flag;
    }

    void Bill::init(const char* title, int noOfItems) {
        if (title[0] == '\0' || noOfItems < 0) {
            setEmpty();
        }
        else {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
            strcpy(m_title, title);
            m_items = new Item[m_noOfItems];
            //The dynamically allocated Items are set to empty!
            for (int i = 0; i < m_noOfItems; i++) {
                m_items[i].setEmpty();
            }
        }
    }
    bool Bill::add(const char* item_name, double price, bool taxed) {
        bool flag = false;
        if (m_itemsAdded < m_noOfItems) {
            m_items[m_itemsAdded].set(item_name, price, taxed);
            m_itemsAdded++;
            flag = true;
        }
        return flag;
    }
    void Bill::display()const {
        Title();
        for (int i = 0; i < m_noOfItems; i++) {
            m_items[i].display();
        }
        footer();
    }
    void Bill::deallocate() {
        delete[] m_items;
        m_items = nullptr;
    }
}