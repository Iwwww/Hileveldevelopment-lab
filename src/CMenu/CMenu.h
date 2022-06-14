#ifndef MYMENU_CMENU_H
#define MYMENU_CMENU_H

#include "CMenuItem.h"
#include <cstddef>

namespace YMM {
class CMenu {
    public:
        inline static int position[2] {0, 0};

        CMenu(char *, CMenuItem *, size_t);
        int getSelect() const;
        bool isRun() const;
        char *getTitle();
        size_t getCount() const;
        CMenuItem *getItems();
        void print();
        int runCommand();
        void runSubMenuCommand();
        void runCommand(CMenu*);

    private:
        int m_select{-1};
        size_t m_count{};
        bool m_running{};
        char *m_title = nullptr;
        CMenuItem *m_items{};
        bool m_submenu{};
        int m_position[2]{-1, -1};
    };
}

#endif // MYMENU_CMENU_H
