#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"

namespace sdds {
	class Line :
		public LblShape {
		unsigned m_lenght;
	public:
		Line();
		Line(const char* label, unsigned lenght = 0);
		~Line();
		void getSpecs(std::istream& IS);
		void draw(std::ostream& OS)const;
	};
}
#endif // !SDDS_LINE_H
