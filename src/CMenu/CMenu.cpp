#include "CMenu.h"
#include <iostream>

namespace YMM {
    CMenu::CMenu(char *title, CMenuItem *items, size_t count) : m_title(title), m_items(items), m_count(count) {
    }

    int CMenu::getSelect() const {
        return m_select;
    }

    bool CMenu::isRun() const {
        return m_running;
    }

    char *CMenu::getTitle() {
        return m_title;
    }

    CMenuItem *CMenu::getItems() {
        return m_items;
    }

    void CMenu::print() {
        for (size_t i = 0; i < m_count; i++) {
            std::cout << i + 1 << ". ";
            m_items[i].print();
            std::cout << "\n";
        }
        std::cout << "0. Exit\n"; 
    }

    int CMenu::runCommand() {
        print();
        do {
            std::cout << "\n Select >> ";
            std::cin >> m_select;
        } while (m_select == -1 || m_select > m_count);
        
        return m_items[m_select - 1].run();
    }
}
