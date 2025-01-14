/*
    Name:           Mahshad Najafi Ragheb
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }
    // define read functions    
    bool read(char* name) {
        return fscanf(fptr, "%[^\n]\n", name);
    }
    bool read(int& empNo) {
        return fscanf(fptr, "%d,", &empNo);
    }
    bool read(double& salary) {
        return fscanf(fptr, "%lf,", &salary);
    }
}