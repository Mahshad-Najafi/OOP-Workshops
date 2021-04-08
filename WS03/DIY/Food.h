//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:           Mahshad Najafi Ragheb

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef SDDS_FOOF_H_
#define SDDS_FOOF_H_
namespace sdds {
	class Food {
		char m_name[31];
		int m_cal; //valid between 0 to 3000 (including 3000)
		int m_consumeTime; //valid values: 1-4
	public:
		void display(); 
		void setName(const char* name);
		void setEmpty();
		void set(const char* name, int cal, int time);
		bool isValid()const;
		int calorie()const;
		int time()const;
		void printTime(int);
	};
}
#endif // !SDDS_FOOF_H_