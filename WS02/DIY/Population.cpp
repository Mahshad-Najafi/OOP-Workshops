/*
    Name:           Mahshad Najafi Ragheb

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Population.h"
#include "File.h"

using namespace std;
namespace sdds {

    int no_Of_Records;
    Population* populations;
    int totalPopulation = 0;


    void sort() {

        int i, j;
        Population temp;

       for (i = no_Of_Records - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (populations[j].m_population > populations[j + 1].m_population) {
                    temp = populations[j];
                    populations[j] = populations[j + 1];
                    populations[j + 1] = temp;
                }
            }
        }
    }

    // loads a population structue with its values from the file
    bool load(Population& population) {
        bool flag = false;
        //char postalCode[4];

        if (read((population.m_postalCode)) && read((population.m_population))) {
            flag = true;
        }
        return flag;
    }

    bool load(const char* fileName) {
        bool flag = false;
        int i = 0;
        if (openFile(fileName))
        {
            no_Of_Records = noOfRecords();
            populations = new Population[no_Of_Records];
            //In a loop load the employee records from the file into the dynamic array.
            for (i = 0; i < no_Of_Records && !flag; i++)
            {
                if (!load(populations[i]))
                {
                    cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
                    flag = true;
                }
            }
            closeFile();
        }

        else
        {
            cout << "Could not open data file: " << fileName << endl;
        }
        return !flag;
    }

    // displays a employee record on the screen:
    void display(Population& population) {
        cout << population.m_postalCode << ":  " << population.m_population << endl;
    }

    // first sorts the employees then displays all the employees on the screen
    void display() {
        int i;
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;

        sort();
        for (i = 0; i < no_Of_Records; i++)
        {
            cout << i + 1 << "- ";
            display(populations[i]);
            totalPopulation += populations[i].m_population;

        }
        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << totalPopulation << endl;
    }

    void deallocateMemory() {
        delete[] populations;
    }
}