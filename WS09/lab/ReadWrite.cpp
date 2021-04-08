//   Name:           Mahshad Najafi Ragheb
//   email:          mnajafi-ragheb@myseneca.ca
//   Student ID:     136115201
//   Date:           2021-04-04
//   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Workshop 9:
// ReadWrite.cpp
// 2021-03-26
// Version: 1.0 
// Author: Fardad Soleimanloo
/////////////////////////////////////////////
#include <iostream>
#include "ReadWrite.h"
using namespace std;
namespace sdds {
   ostream& operator<<(ostream& os, const ReadWrite& c) {
      return c.display(os);
   }

   istream& operator >> (istream& is, ReadWrite& c) {
      return c.read(is);
   }
}