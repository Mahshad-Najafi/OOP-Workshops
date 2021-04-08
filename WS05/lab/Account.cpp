/*
    Name:           Mahshad Najafi Ragheb

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }
   bool Account::isValidAccountNumber(int number) {
       return (number >= 10000 && number <= 99999);
   }
   bool Account::isInvalidAccountNumber(int number, double balance) {
       return (number == -1 && balance == 0);
   }
   bool Account::isNewAccount(int number) {
       return (number == 0);
   }
   //type conversion operators:
   Account::operator bool() const {
       return (m_number >= 10000 && m_number <= 99999
           && m_balance >= 0);
   }
   Account::operator int() const {
       return m_number;
   }
   Account::operator double() const {
       return m_balance;
   }
   //Unary member operator:
   bool Account::operator~() const {
       return (m_number == 0);
   }
   //Binary member operators:
   Account& Account::operator = (int number) {
       if (m_number == 0) {
           if (number >= 10000 && number <= 99999) {
               m_number = number;
           }
           else {
                setEmpty();
           }
       }
       return *this;
   }
   Account& Account::operator = (Account& account) {
       if (m_number != 0 || account.m_number == -1) {
           return *this;
       }
       m_number = account.m_number;
       m_balance = account.m_balance;
       account.m_number = 0;
       account.m_balance = 0.0;
       return *this;
   }
   Account& Account::operator += (double balance) {
       if (m_number == -1 || balance < 0) {
           return *this;
       }
       m_balance += balance;
       return *this;
   }
   Account& Account::operator -= (double balance) {
       if (m_number == -1 || balance < 0 || m_balance < balance) {
           return *this;
       }
       m_balance -= balance;
       return *this;
   }
   Account& Account::operator << (Account& account) {
       if (m_number != account.m_number) {
           *this += account.m_balance;
           account.m_balance = 0.0;
       }
       return *this;
   }
   Account& Account::operator >> (Account& account) {
       if (m_number != account.m_number) {
           account += m_balance;
           m_balance = 0.0;
       }
       return *this;
   }
   //Binary helper operators:
   double operator + (const Account& leftAccount, const Account& rightAccount) {
       if (leftAccount && rightAccount) {
           return double(leftAccount) + double(rightAccount);
        }
       return 0.0;
   }
   double operator += (double& balance, const Account& account) {
       balance += double(account);
       return balance;
   }
}