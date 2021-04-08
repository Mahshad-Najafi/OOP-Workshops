/*
    Name:           Mahshad Najafi Ragheb

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_MARK_H
#define SDDS_MARK_H

namespace sdds {
    class Mark {
        int m_mark;
    public:
        Mark();
        Mark(int mark);
        void setEmpty();
        operator bool() const;
        operator int() const;
        Mark& operator = (int assignMark);
        Mark& operator+= (int addMark);
        operator double() const;
        operator char() const;
    };
    int operator+= (int& val, const Mark& mark);
}
#endif // !SDDS_MARK_H
