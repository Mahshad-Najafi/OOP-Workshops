#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Stats.h"
namespace sdds {
    Stats::Stats(unsigned columnWidth, unsigned noOfColumns, unsigned precision) {
        m_columnWidth = columnWidth;
        m_noOfColumns = noOfColumns;
        m_precision = precision;
    }
    Stats::Stats(const char* filename, unsigned columnWidth, unsigned noOfColumns, unsigned precision) {
        m_columnWidth = columnWidth;
        m_noOfColumns = noOfColumns;
        m_precision = precision;

        if (filename) {
            ifstream infile(filename);
            if (infile.good()) {
                m_filename = new char[strlen(filename) + 1];
                strcpy(m_filename, filename);
                loadNumbers();
            }
            infile.close();
        }
    }
    Stats::Stats(const Stats&) {

    }
    Stats& Stats::operator=(const Stats&) {

    }
    double& Stats::operator[](unsigned idx) {

    }
    double Stats::operator[](unsigned idx)const {
    }  // do we need this one as well?
    Stats::operator bool()const {}
    void Stats::sort(bool ascending) {

    }
    unsigned Stats::size()const {

    }
    const char* Stats::name()const {

    }
    unsigned Stats::occurrence(double min, double max, std::ostream& ostr = std::cout) {

    }
    std::ostream& operator<<(std::ostream& ostr, const Stats& S) {}
    std::istream& operator>>(std::istream& istr, Stats& S) {}
}
