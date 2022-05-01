#include <iostream>
#include <cmath>
#include "CMenu/CMenu.h"
#include "CMenu/CMenuItem.h"
#include "Models/User.h"
#include "Models/Employer/Employer.h"
#include "Models/Provider/Provider.h"

#pragma region функции-заглушки
int f1() {
    using namespace YMM;
    Product* productList[4]{
        new Product(std::string("Treska"), Product::ProductType{}, 50.67, 1000),
        new Product(std::string("Banana"), Product::ProductType{}, 10.05, 2500),
        new Product(std::string("Apple"), Product::ProductType{}, 6.75, 5000)
    };
    std::cout << "1 < 2 = " << (productList[0] < productList[1]) << std::endl;

    return 1;
}

int HelloWorld() {
    int i = 5;
    return i;
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

int AEnstain() {
    using namespace YMM;
    Employer worker("Albert", "Enstain", "emc2", "universe", "physicist");
    std::cout << worker << std::endl;
    std::cout << "======" << std::endl;
    std::cin >> worker;
    std::cout << "======" << std::endl;
    std::cout << worker << std::endl;
    return 3;
}

int LTorvalds() {
    using namespace YMM;
    Product::ProductType product{};
    Provider liunxBiography("Linus", "Torvalds", "GNU/Linux", "C is the way", product);
    //std::cout << liunxBiography << std::endl;
    //printData(liunxBiography);
    return 4;
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
    //Worker.printData();
    std::cout << Worker << std::endl;
    return 6;
}

int provider() {
    using namespace YMM;
    Product::ProductType myProduct{};
    Provider Boss("Man", "Best", "lucky", "nopasswd", myProduct);
    //Boss.printData();
    std::cout << Boss << std::endl;
    return 7;
}

int product() {
    using namespace YMM;
    Product::ProductType myProduct{};
    Product SomeProduct("Greatfruit", myProduct, 12.5, 800);
    //SomeProduct.printData();
    std::cout << SomeProduct << std::endl;
    return 8;
}

int printProviderData() {
    using namespace YMM; 
    
    std::cout << "Provider data" << std::endl;

    return 1;
}

int printEmployerData() {
    using namespace YMM; 
    
    std::cout << "Employer data" << std::endl;
    std::cout << "sd" << std::endl;

    return 1;
}

int printProductData() {
    using namespace YMM; 
    
    std::cout << "Product data" << std::endl;

    return 1;
}

#pragma endregion функции-заглушки

const int items_number = 8;

int main() {
    using namespace YMM;

    Product apples(std::string("Treska"), Product::ProductType{}, 50.67, 1000);
    User *data[2] {};

    data[0] = new Provider(
            std::string("Nikita"),
            std::string("Organizator"), 
            std::string("Boss"), 
            std::string("strong_pswd"), 
            apples.getProductType());

    data [1] = new Employer(
            "hello",
            "Main",
            "yes",
            "monkey",
            "Pos");

    CMenuItem subItems1[2] {
        CMenuItem("sub 1-1", f1),
        CMenuItem("sub 1-2", AEnstain)
    };

    CMenuItem subItems2[2] {
        CMenuItem("sub 2-1", provider),
        CMenuItem("sub 2-2", product)
    };

    CMenuItem items[items_number] {
        CMenuItem("first item", f1),
        CMenuItem("second item", f2),
        CMenuItem("Albert Enstain", AEnstain),
        CMenuItem("Linux Torvalds", LTorvalds),
        CMenuItem("fives item", f2),
        CMenuItem("Employer", employer),
        CMenuItem("Provider", provider),
        CMenuItem("Product", product)

    };

    CMenu subMenuArr[2] {
        CMenu("My sub menu 1", subItems1, 2),
        CMenu("My sub menu 2", subItems2, 2)
    };
    
    CMenu menu("My console menu", items, items_number);
    while (menu.runCommand(subMenuArr));
    //while (menu.runCommand());
    switch(1) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
    }

    return 0;
}

