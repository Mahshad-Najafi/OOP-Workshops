#ifndef SDDS_STATS_H__
#define SDDS_STATS_H__
#include <iostream>
namespace sdds {
   class Stats {
       unsigned m_columnWidth;
       unsigned m_noOfColumns;
       unsigned m_precision;
       char* m_filename = nullptr;
       int* m_numbers;
       unsigned m_noOfNumbers = 0;
   public:
       Stats(unsigned columnWidth = 15, unsigned noOfColumns = 4, unsigned precision = 2);
       Stats(const char* filename, unsigned columnWidth = 15, unsigned noOfColumns = 4, unsigned precision = 2);
       Stats(const Stats&);
       Stats& operator=(const Stats&);
       double& operator[](unsigned idx);
       double operator[](unsigned idx)const;  // do we need this one as well?
       operator bool()const;
       void sort(bool ascending);
       unsigned size()const;
       const char* name()const;
       unsigned occurrence(double min, double max, std::ostream& ostr = std::cout);
   };
   std::ostream& operator<<(std::ostream& ostr, const Stats& S);
   std::istream& operator>>(std::istream& istr, Stats& S);
}
#endif // !SDDS_STATS_H__
