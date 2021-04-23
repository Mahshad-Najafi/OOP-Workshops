#include "Truck.h"
using namespace std;
namespace sdds {
    Truck::Truck(const char* licensePlate, int year, double capacity, const char* address) : MotorVehicle(licensePlate, year) {
        m_capacity = capacity;
        m_cargoLoad = 0.0;
        moveTo(address);
    }
    bool Truck::addCargo(double cargo) {
        if (m_cargoLoad + cargo <= m_capacity) {
            m_cargoLoad += cargo;
            return true;
        }
        return false;
    }
    bool Truck::unloadCargo() {
        if (m_cargoLoad != 0.0) {
            m_cargoLoad = 0.0;
            return true;
        }
        return false;
    }
    ostream& Truck::write(ostream& OS) const {
        MotorVehicle::write(OS);
        OS << " | " << m_cargoLoad << "/" << m_capacity;
        return OS;
    }
    istream& Truck::read(istream& IS) {
        MotorVehicle::read(IS);
        cout << "Capacity: ";
        IS >> m_capacity;
        cout << "Cargo: ";
        IS >> m_cargoLoad;
        return IS;
    }
    ostream& operator<<(ostream& OS, const Truck& truck) {
        return truck.write(OS);
    }
    istream& operator>>(istream& IS, Truck& truck) {
        return truck.read(IS);
    }
}