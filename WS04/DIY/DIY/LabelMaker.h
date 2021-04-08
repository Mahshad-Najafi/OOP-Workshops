/*
	Name:           Mahshad Najafi Ragheb

	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_LABELMARKER_H
#define SDDS_LABELMARKER_H
#include "Label.h"
namespace sdds {
	class LabelMaker {
		Label* arrOfLabels = nullptr;
		int m_noOfLabels;
	public:
		LabelMaker(int noOfLabels);
		~LabelMaker();
		void readLabels();
		void printLabels();
	};
}
#endif // !SDDS_LABELMARKER_H

