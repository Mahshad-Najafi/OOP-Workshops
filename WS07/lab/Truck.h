#ifndef _SDDS_TRUCK_H
#define _SDDS_TRUCK_H
#include <iostream>
#include "MotorVehicle.h"

namespace sdds {
    class Truck : public MotorVehicle {
        double m_capacity;
        double m_cargoLoad;
    public:
        Truck(const char* licensePlate, int year, double capacity, const char* address);
        bool addCargo(double cargo);
        bool unloadCargo();
        std::ostream& write(std::ostream& OS) const;
        std::istream& read(std::istream& IS);
    };
    std::ostream& operator<<(std::ostream& OS, const Truck& truck);
    std::istream& operator>>(std::istream& IS, Truck& truck);
}

#endif // _SDDS_TRUCK_H