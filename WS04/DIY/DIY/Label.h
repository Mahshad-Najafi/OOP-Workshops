/*
	Name:           Mahshad Najafi Ragheb
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
namespace sdds {
	class Label {
		char m_frame[9] = {};
		char* m_labelContent = nullptr;
	public:
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label();
		void readLabel();
		std::ostream& printLabel()const;
		void deallocate();
	};
}
#endif // !SDDS_LABEL_H
