#include "CMenu.h"
#include <iostream>

namespace YMM {
    CMenu::CMenu(char *title, CMenuItem *items, size_t count) : m_title(title), m_items(items), m_count(count), m_running(true) {
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

    int* CMenu::getPosition() {
        return position;
    }

    size_t CMenu::getCount() const {
        return m_count;
    }

    void CMenu::print() {
        for (size_t i = 0; i < m_count; i++) {
            std::cout << i + 1 << ". " << m_items[i].getName();
            std::cout << "\n";
        }
        std::cout << "0. Exit\n"; 
    }

    int CMenu::runCommand() {
        print();
        do {
            std::cout << "\n Select l->> ";
            std::cin >> m_select;
        } while (m_select == -1 || m_select > m_count);

        // Exit from menu
        if (m_select == 0) {
            if (m_submenu) {
                m_running = false;
            } else {
                return 1;
            }
        }

        return m_items[m_select - 1].run();
    }

    void CMenu::runCommand(CMenu *subMenu) {
        if (!isRun()) return;
        m_submenu = true;
        if (position[1] == 0) {
            print();
            do {
                std::cout << "\n Select -> ";
                std::cin >> m_select;
            } while (m_select == -1 || m_select > m_count);
            position[0] = m_select;
        }
        
        // Exit from menu
        if (position[0] == 0) {
            m_running = false;
        } else {
            subMenu[m_select - 1].runSubMenuCommand();
        }
    } 

    void CMenu::runSubMenuCommand() {
        print();

        do {
            std::cout << "\n Select l->> ";
            std::cin >> m_select;
        } while (m_select == -1 || m_select > m_count);

        position[1] = m_select;
        if (m_select == 0) {
            m_position[0] = 0;
        }
    }
}

