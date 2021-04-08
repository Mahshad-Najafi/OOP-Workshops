/*
    Name:           Mahshad Najafi Ragheb

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {
	//added by me:
	struct Population {
		char m_postalCode[4];
		int m_population;
	};
    void sort();
    // loads a population structue with its values from the file
    bool load(Population& population);
    // allocates the dyanmic array of employees and loads all the file
    // recoreds into the array
    //bool load(const char (&postal_code)[4]); same as bool load(const char*&);
    bool load(const char*);

    // displays a employee record on the screen:
    void display(Population& poulation);

    // first sorts the employees then displays all the employees on the screen
    void display();

    // first will deallocate all the names in the employee elements
    // then it will deallocate the employee array 
    void deallocateMemory();


}
#endif // SDDS_POPULATION_H_