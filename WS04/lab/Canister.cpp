/*
    Name:           Mahshad Najafi Ragheb

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include <cstring>  // using strlen, strcpy and strcmp 
#include "Canister.h"

#define LIMIT 0.267
const double PI = 3.14159265;
using namespace std;
namespace sdds {
    void Canister::setToDefault() {
        m_contentName = nullptr;
        m_diameter = 10.0; // in centimeters 
        m_height = 13.0;   // in centimeters
        m_contentVolume = 0.0;
        m_usable = true;
    }
    void Canister::setName(const char* Cstr) {
        if (Cstr != nullptr && m_usable) {
            delete[] m_contentName;
            m_contentName = new char[strlen(Cstr) + 1];
            strcpy(m_contentName, Cstr);
        }
    }
    bool Canister::isEmpty()const {
        return (m_contentVolume < 0.00001 ? true : false);
    }
    bool Canister::hasSameContent(const Canister& C)const {
        if (m_contentName) {
           return (!strcmp(m_contentName, C.m_contentName));
        }
        return false;
    }
    Canister::Canister() {
        setToDefault();
    }
    Canister::Canister(const char* contentName) {
        setToDefault();
        setName(contentName);
    }
    Canister::Canister(double height, double diameter,
        const char* contentName) {
        setToDefault();
        if (diameter >= 10 && diameter <= 30 && height >= 10 && height <= 40) {
            setName(contentName);
            m_height = height;
            m_diameter = diameter;
            m_contentVolume = 0.0;
        }
        else {
            m_usable = false;
        }
    }
    Canister::~Canister() {
        delete[] m_contentName;
    }
    Canister& Canister::setContent(const char* contentName) {
        if (!contentName ) {
            m_usable = false;
        }
        else if (isEmpty()) {
            setName(contentName);
        }
        else if (!hasSameContent(Canister(contentName))) {
            m_usable = false;
        }
        return *this;
    }
    Canister& Canister::pour(double quantity) {
        if (m_usable && quantity > 0 && ((quantity + volume()) <= capacity())){
            m_contentVolume += quantity;
        }
        else {
            m_usable = false;
        }
        return *this;
    }
    Canister& Canister::pour(Canister& C) {
        setContent(C.m_contentName);
        if (C.volume() > (capacity() - volume())) {
            C.m_contentVolume -= (capacity() - volume());
            m_contentVolume = capacity();
        }
        else {
            pour(C.m_contentVolume);
            C.m_contentVolume = 0.0;
        }
        return *this;
    }
    double Canister::volume()const {
        return m_contentVolume;
    }
    std::ostream& Canister::display()const {
        cout << fixed;
        cout << setprecision(1);
        cout << setw(7) << capacity() << "cc (" << m_height << "x" << m_diameter << ") Canister";
        if (!m_usable)
            cout << " of Unusable content, discard!";
        else if (m_contentName)
            cout << " of " << setw(7) << volume() << "cc   " << m_contentName;
        return cout;
    }
    double Canister::capacity()const {
        return PI * (m_height - LIMIT) * (m_diameter / 2) * (m_diameter / 2);
    }
    void Canister::clear() {
        delete[] m_contentName;
        m_contentName = nullptr;
        m_contentVolume = 0.0;
        m_usable = true;
    }
}