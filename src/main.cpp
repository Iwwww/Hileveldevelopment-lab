#include <iostream>
#include <cmath>
#include "CMenu/CMenu.h"
#include "CMenu/CMenuItem.h"

#pragma region функции-заглушки
int f1() {
    std::cout << "sqrt(25) = " << sqrt(25);
    return 1;
}

int f2() {
    for (int i = 1; i < 8; i++) {
        for (int j = 1; j < i; j++) { 
            std::cout << "* ";
        }
    std::cout << "\n";
    }
    std::cout << "function f2 is running...\n\n";
    return 2;
}

int f3() {
    std::cout << "function f3 is running...\n\n";
    return 3;
}

int f4() {
    std::cout << "function f4 is running...\n\n";
    return 4;
}

int f5() {
    std::cout << "function f5 is running...\n\n";
    return 5;
}
#pragma endregion функции-заглушки

const int items_number = 5;

int main() {
    using namespace YMM;

    CMenuItem items[items_number] {
        CMenuItem("first item", f1),
        CMenuItem("second item", f2),
        CMenuItem("third item", f3),
        CMenuItem("fourth item", f4),
        CMenuItem("fives item", f5)
    };

    CMenu menu("My console menu", items, items_number);
    while (menu.runCommand()){};

    return 0;
}
