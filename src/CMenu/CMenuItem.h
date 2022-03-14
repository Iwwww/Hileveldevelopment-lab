#ifndef MYMENU_CPP_CMENUITEM_H
#define MYMENU_CPP_CMENUITEM_H

namespace YMM {
class CMenuItem {
    public:
        typedef int(*Func)();
        CMenuItem(char *, Func);
        Func m_func{};
        char *m_item_name{};
        char * getName();
        void print();
        int run();
    };
}

#endif // MYMENU_CPP_CMENUITEM_H