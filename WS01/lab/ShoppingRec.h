#ifndef SDDS_SHOPPINGREC_H
#define SDDS_SHOPPINGREC_H
#include <iostream>
#include <cstring>

const int MAX_TITLE_LENGTH = 50;
namespace sdds {
    struct ShoppingRec {
        char m_title[MAX_TITLE_LENGTH + 1];
        int m_quantity;
        bool m_bought;
    };

    ShoppingRec getShoppingRec();
    void displayShoppingRec(const ShoppingRec* shp);
    void toggleBoughtFlag(ShoppingRec* rec);
    bool isShoppingRecEmpty(const ShoppingRec* shp);
}
#endif // !SDDS_SHOPPINGREC_H
