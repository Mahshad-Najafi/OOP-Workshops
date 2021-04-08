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
	// Declare read prototypes
	bool read(char* name);
	bool read(int& empNo);
	bool read(double& salary);
}
#endif // !SDDS_FILE_H_

