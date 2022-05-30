#ifndef MYMENU_CPP_CMENUITEM_H
#define MYMENU_CPP_CMENUITEM_H

namespace YMM {
class CMenuItem {
    public:
        using Func = int(*)();
        CMenuItem(char *, Func);
        CMenuItem(char *);
        Func m_func{};
        char *m_item_name{};
        char * getName();
        void print() const;
        bool isFunc() const;
        int run();
    };
}

#endif // MYMENU_CPP_CMENUITEM_H
