/* 
    Name:           Mahshad Najafi Ragheb
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>  // not implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

    int noOfEmployees;
    Employee* employees;


    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // 1 arg load function which reads one employee record from the file
    // and loads it into the employee reference argument
    bool load(Employee& employee) {
        bool ok = false;
        char name[128];
        int nameLength;
        if (read((employee.m_empNo)) && read((employee.m_salary)) && read(name))
        {
            nameLength = strlen(name) + 1;
            employee.m_name = new char[nameLength];
            strcpy(employee.m_name, name);
            ok = true;
        }
        return ok;
    }
    // Implementation of the 0 arg load function 
    bool load() {

        bool ok = false;
        int i = 0;
        if (openFile(DATAFILE))
        {
            noOfEmployees = noOfRecords();
            employees = new Employee[noOfEmployees];
            //Load the employee records from the file into the dynamic array.
            for (i = 0; i < noOfEmployees && !ok ; i++)
            {
                if (!load(employees[i]))
                {
                    cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
                    ok = true;
                }
            }
            closeFile();
        }
        else
        {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        return !ok;
    }

    void display(Employee& employee)
    {
        cout << employee.m_empNo << ": " << employee.m_name << ", " << employee.m_salary << endl;
    }
    void display()
    {
        int i;
        cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;

        sort();

        for (i = 0; i < noOfEmployees; i++)
        {
            cout << i + 1 << "- ";
            display(employees[i]);
        }
    }
    void deallocateMemory()
    {
         int i;
         for (i = 0; i < noOfEmployees; i++)
         {
             delete[] employees[i].m_name;
         }
        delete[] employees;
    }
}