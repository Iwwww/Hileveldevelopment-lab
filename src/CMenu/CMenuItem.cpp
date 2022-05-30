#include "CMenuItem.h"
#include <iostream>

namespace YMM {
    CMenuItem::CMenuItem(char *item_name, Func func): m_item_name(item_name), m_func(func) {}

    CMenuItem::CMenuItem(char *item_name): m_item_name(item_name) {}

    char * CMenuItem::getName() {
        return m_item_name;
    }

    void CMenuItem::print() const {
        std::cout << m_item_name;
    }

    bool CMenuItem::isFunc() const {
        if (m_func == nullptr) {
            return false;
        } else {
            return true;
        }
    }

    int CMenuItem::run() {
        return m_func();
    }
}
