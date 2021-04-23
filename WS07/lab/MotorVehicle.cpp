#define _CRT_SECURE_NO_WARNINGS
#include "MotorVehicle.h"
using namespace std;
namespace sdds {
    MotorVehicle::MotorVehicle(const char* licensePlate, int year) {
        strcpy(m_licencePlate, licensePlate);
        m_licencePlate[8] = '\0';
        m_year = year;
        strcpy(m_address, "Factory");
    }
    void MotorVehicle::moveTo(const char* address) {
        if (strcmp(m_address, address) != 0) {
            cout << "|" << right;
            cout.width(8);
            cout << m_licencePlate;
            cout << "| |" << right;
            cout.width(20);
            cout << address;
            cout << " ---> " << left;
            cout.width(20);
            cout << m_address;
            cout << "|" << endl;
            strcpy(m_address, address);
        }
    }
    ostream& MotorVehicle::write(ostream& OS)const {
        OS << "| " << m_year << " | " << m_licencePlate << " | " << m_address;
        return OS;
    }
    istream& MotorVehicle::read(istream& IS) {
        string licencePlate, address;
        cout << "Built year: ";
        IS >> m_year;

        cout << "License plate: ";
        IS >> licencePlate;
        strcpy(m_licencePlate, licencePlate.c_str());
        m_licencePlate[8] = '\n';

        cout << "Current location: ";
        IS >> address;
        strcpy(m_address, address.c_str());
        m_address[63] = '\n';

        return IS;
    }
    ostream& operator<<(ostream& OS, const MotorVehicle& vehicle) {
        return vehicle.write(OS);
    }
    istream& operator>>(istream& IS, MotorVehicle& vehicle) {
        return vehicle.read(IS);
    }
}