/*
    Name:           Mahshad Najafi Ragheb

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      bool isValidAccountNumber(int);
      bool isInvalidAccountNumber(int, double);
      bool isNewAccount(int);
      operator bool() const;
      operator int() const;
      operator double() const;
      bool operator ~() const;
      Account& operator = (int number);
      Account& operator = (Account& account);
      Account& operator += (double balance);
      Account& operator -= (double balance);
      Account& operator << (Account& right);
      Account& operator >> (Account& left);

   };
   double operator + (const Account& leftBalance, const Account& rightBalance);
   double operator += (double& balance, const Account& right);
   
   
}
#endif // SDDS_ACCOUNT_H_