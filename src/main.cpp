#include <iostream>
#include <cmath>
#include "CMenu/CMenu.h"
#include "CMenu/CMenuItem.h"
#include "Models/Employer/Employer.h"
#include "Models/Provider/Provider.h"

#pragma region функции-заглушки
int f1() {
    std::cout << "sqrt(25) = " << sqrt(25) << std::endl;
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

int employer() {
    using namespace YMM;
    // Employer Worker;
    Employer Worker("hello", "Main", "yes", "monkey", "Pos");
    Worker.setName("hello world");
    Worker.setSurname("Master");
    Worker.setLogin("Lololo");
    Worker.setPosition("1234569878");
    std::cout << Worker.getName() << std::endl;
    Worker.printData();
    return 6;
}

int provider() {
    using namespace YMM;
    Product::ProductType myProduct{};
    Provider Boss("Man", "Best", "lucky", "nopasswd", myProduct);
    Boss.printData();
    return 7;
}

int product() {
    using namespace YMM;
    Product::ProductType myProduct{};
    Product SomeProduct("Greatfruit", myProduct, 12.5, 800);
    SomeProduct.printData();
    return 8;
}


#pragma endregion функции-заглушки

const int items_number = 8;

int main() {
    using namespace YMM;

    CMenuItem items[items_number] {
        CMenuItem("first item", f1),
        CMenuItem("second item", f2),
        CMenuItem("third item", f3),
        CMenuItem("fourth item", f4),
        CMenuItem("fives item", f5),
        CMenuItem("Employer", employer),
        CMenuItem("Provider", provider),
        CMenuItem("Product", product)

    };

    CMenu menu("My console menu", items, items_number);
    while (menu.runCommand()){};

    return 0;
}
