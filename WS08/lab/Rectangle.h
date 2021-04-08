#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include "LblShape.h"

namespace sdds {
	class Rectangle :
		public LblShape {
		unsigned m_width;
		unsigned m_height;
	public:
		Rectangle();
		Rectangle(const char* label, unsigned width, unsigned height);
		~Rectangle();
		void getSpecs(std::istream& IS);
		void draw(std::ostream& OS)const;
	};
}
#endif // !SDDS_RECTANGLE_H
