#ifndef _SDDS_MOTORVEHICLE_H
#define _SDDS_MOTORVEHICLE_H
#include <iostream>
#include <string>
#include <cstring>
namespace sdds {
    class MotorVehicle {
        char m_licencePlate[9];
        char m_address[64];
        int m_year;
    public:
        MotorVehicle(const char* licensePlate, int year);
        void moveTo(const char* address);
        std::ostream& write(std::ostream& OS)const;
        std::istream& read(std::istream& IS);
    };
    std::ostream& operator<<(std::ostream& OS, const MotorVehicle& vehicle);
    std::istream& operator>>(std::istream& IS, MotorVehicle& vehicle);
}

#endif //_SDDS MOTORVEHICLE_H