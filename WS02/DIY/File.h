/*
    Name:           Mahshad Najafi Ragheb

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read(char* postalCode);
   bool read(int& population);
}
#endif // !SDDS_FILE_H_
