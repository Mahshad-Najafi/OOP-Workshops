#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>

namespace sdds {
	class Shape {
	public:
		virtual ~Shape();
		virtual void draw(std::ostream& OS)const = 0;
		virtual void getSpecs(std::istream& IS) = 0;
	};
	// helper functions:
	std::ostream& operator<<(std::ostream& OS, const Shape& S);
	std::istream& operator>>(std::istream& IS, Shape& S);
}
#endif // !SDDS_SHAPE_H
