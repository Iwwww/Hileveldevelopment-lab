#include "CMenuItem.h"
#include <iostream>

namespace YMM {
    CMenuItem::CMenuItem(char *item_name, Func func): m_item_name(item_name), m_func(func) {}

    char * CMenuItem::getName() {
        return m_item_name;
    }

    void CMenuItem::print() {
        std::cout << m_item_name;
    }

    int CMenuItem::run() {
        return m_func();
    }
}
