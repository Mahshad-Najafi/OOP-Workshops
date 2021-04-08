//   Name:           Mahshad Najafi Ragheb
//   email:          mnajafi-ragheb@myseneca.ca
//   Student ID:     136115201
//   Date:           2021-04-04
//   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Workshop 9:
// Student.h
// 2021-03-26
// Version: 1.0 
// Author: Fardad Soleimanloo
/////////////////////////////////////////////
#include <iostream>
#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_
#include "ReadWrite.h"
namespace sdds {
   class Student : public ReadWrite {
      int m_stno;
      char m_name[41];
      double m_gpa;
   public:
      Student();
      Student(int stno, const char* name, double gpa);
      void set(int stno, const char* name, double gpa);
      std::ostream& display(std::ostream& os)const;
      std::istream& read(std::istream& is);
      bool operator==(double gpa)const;
   };
}
#endif // !SDDS_STUDENT_H_

