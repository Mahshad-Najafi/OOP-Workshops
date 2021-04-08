#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include "Shape.h"

namespace sdds {
	//This class will implement the pure virtual function getSpecs but will not implement the draw function; 
	class LblShape :public Shape {
		char* m_label = nullptr; 
	protected:
		char* label() const; 
	public:
		void allocate(const char* label);
		LblShape();
		LblShape(const char* label);
		~LblShape();
		LblShape(const LblShape& source) = delete;
		LblShape& operator=(const LblShape& source) = delete;
		void getSpecs(std::istream& IS);
	};
}
#endif // !SDDS_LBLSHAPE_H