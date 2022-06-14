#include <cstdint>
#include <ctime>
#include <iostream>
#include <cmath>
#include <iterator>
#include <new>
#include <stdexcept>
#include <execution>
#include <string>
#include "CMenu/CMenu.h"
#include "CMenu/CMenuItem.h"
#include "Models/Product.h"
#include "Models/User.h"
#include "Models/Employer/Employer.h"
#include "Models/Provider/Provider.h"
#include "Containers/MyVector.h"

#pragma region example-funcions

int f1() {
    std::cout << "Sqrt(25) = " << sqrt(25) << '\n';
    return 1;
}

int f2() {
    for (int i = 1; i < 8; i++) {
        for (int j = 1; j < i; j++) { 
            std::cout << "* ";
        }
        std::cout << "\n";
    }

    return 2;
}

#pragma endregion example-funcions

#pragma region User

int addUser() {
    return 1;
};

int deleteUser() {
    return 2;
};

int sortUser() {
    return 3;
};

int showUser() {
    return 4;
};

template<typename T>
void addUser(T &v) {
    using namespace YMM;
    int count{};
    std::cout << "Введите количество элементов: ";
    try {
        std::string tmp_str{};
        std::cin >> tmp_str;
        count = std::stoi(tmp_str);
        if (count < 1) throw ("invalid value");

    } catch(const char* exception) {
        std::cout << "error: " << exception << std::endl;
    } catch(std::invalid_argument exception) {
        std::cout << "error: only numbers are allowed" << std::endl;
        std::cerr << "error: " << exception.what() << std::endl;
    } catch(std::out_of_range exception) {
        std::cout << "error: too big number";
        std::cerr << "error: " << exception.what() << std::endl;
    } catch(...) {
        std::cout << "error:: unknown error" << std::endl;
    }


    for (int i = 0; i < count; i++) {
        std::cout << "=========" << "\n";
        try {
            v.addItem();
        } catch(std::bad_alloc) {
            std::cout << "error: can not allocate enough memory" << std::endl;
        }
        std::cin >> v[v.size() - 1];
    }
}

template<typename T>
void deleteUser(T &v) {
    using namespace YMM;
    int index{};
    std::cout << "Всего элементов: " << v.size() << "\n";
    std::cout << "Удалить элемент номер: ";
    try {
        std::string tmp_str{};
        std::cin >> tmp_str;
        index = std::stoi(tmp_str);
        if (index > v.size() || index < 1) throw ("invalid value");

    } catch(const char* exception) {
        std::cout << "error: " << exception << std::endl;
    } catch(std::invalid_argument exception) {
        std::cout << "error: only numbers are allowed" << std::endl;
        std::cerr << "error: " << exception.what() << std::endl;
    } catch(std::out_of_range exception) {
        std::cout << "error: too big number";
        std::cerr << "error: " << exception.what() << std::endl;
    } catch(...) {
        std::cout << "error:: unknown error" << std::endl;
    }

    v.removeItem(index - 1);
}

template<typename T>
void sortUser(T &v) {
    using namespace YMM;
    std::cout << "Сортировка ..." << "\n";
    v.sort();
}

template<typename T>
void showUser(T &v) {
    using namespace YMM;
    std::cout << "Всего элементов: " << v.size() << "\n";
    int index{};
    std::cout << "Показать элемент номер: ";
    try {
        std::string tmp_str{};
        std::cin >> tmp_str;
        index = std::stoi(tmp_str);
        if (index > v.size() || index < 0) throw ("invalid value");

    } catch(const char* exception) {
        std::cout << "error: " << exception << std::endl;
    } catch(std::invalid_argument exception) {
        std::cout << "error: only numbers are allowed" << std::endl;
        std::cerr << "error: " << exception.what() << std::endl;
    } catch(std::out_of_range exception) {
        std::cout << "error: too big number";
        std::cerr << "error: " << exception.what() << std::endl;
    } catch(...) {
        std::cout << "error:: unknown error" << std::endl;
    }

    if (index == 0) {
        for (auto item: v) {
            std::cout << "=========" << std::endl;
            std::cout << item << std::endl;
        }
    } else {
        std::cout << v[index - 1];
    }
}

#pragma endregion User

int main() {
    using namespace YMM;

    // data
    MyVector<Provider> providers;
    MyVector<Employer> employers;
    // Provider 

    providers += new Provider("Harry", "Potter", "Wizard", "617", new Product("History books", "book", 49.9, 350));
    providers += new Provider("Abcd", "Surname", "MyLogin", "123", new Product("apple", "fruit", 10.2, 1500));
    providers += new Provider("Sticker", "Wander", "helper", "968", new Product("Magic wand", "wand", 7.0, 6500));

    employers += new Employer("Stive", "Jobs", "alive", "09876", "Boss");
    employers += new Employer("Albus", "Dumbledore", "MainWizard", "5353535", "Director");
    employers += new Employer("Mikhail", "Empty", "qwerty", "okmmjj0987987", "Developer");

    providers.sort();

    const int items_count = 3;

    // menu items
    CMenuItem exampleItems[2] {
        CMenuItem("squrt(25)", f1),
        CMenuItem("triangle", f2)
    };

    CMenuItem userItems[4] {
        CMenuItem("Добавить", addUser),
        CMenuItem("Удалить", deleteUser),
        CMenuItem("Сортировать", sortUser),
        CMenuItem("Вывести в консоль", showUser)
    };

    CMenuItem items[items_count] {
        CMenuItem("Example functions"),
        CMenuItem("Employer"),
        CMenuItem("Provider")
    };

    CMenu subMenuArr[3] {
        CMenu("My sub menu 1", exampleItems, 2),
        CMenu("Employers", userItems, 4),
        CMenu("Providers", userItems, 4)
    };

    CMenu menu("My console menu", items, items_count);
 
    int *position = nullptr;
    while (true) {
        position = menu.runCommand(subMenuArr);
        switch (position[0]) {
        case 1:
            switch (position[1]) {
                case 1:
                    f1();
                    break;
                case 2:
                    f2();
                    break;
            }
              break;
        case 2:
            switch (position[1]) {
                case 1:
                    try {
                        addUser<MyVector<Employer>>(employers);
                    } catch(std::invalid_argument exception) {
                        std::cerr << "error: std::invalid_argument" << std::endl;
                        std::cerr << exception.what() << std::endl;
                    }
                    break;
                case 2:
                    try {
                        deleteUser<MyVector<Employer>>(employers);
                    } catch(std::invalid_argument exception) {
                        std::cerr << "error: std::invalid_argument" << std::endl;
                        std::cerr << exception.what() << std::endl;
                    }
                    break;
                case 3:
                    try {
                        sortUser<MyVector<Employer>>(employers);
                    } catch(std::invalid_argument exception) {
                        std::cerr << "error: std::invalid_argument" << std::endl;
                        std::cerr << exception.what() << std::endl;
                    }
                    break;
                case 4:
                    try {
                        showUser<MyVector<Employer>>(employers);
                    } catch(std::invalid_argument exception) {
                        std::cerr << "error: std::invalid_argument" << std::endl;
                        std::cerr << exception.what() << std::endl;
                    }
                    break;
                default:
                    break;
            }
          break;
        case 3:
            switch (position[1]) {
                case 1:
                    try {
                        addUser<MyVector<Provider>>(providers);
                    } catch(std::invalid_argument exception) {
                        std::cerr << "error: std::invalid_argument" << std::endl;
                        std::cerr << exception.what() << std::endl;
                    }
                    break;
                case 2:
                    try {
                        deleteUser<MyVector<Provider>>(providers);
                    } catch(std::invalid_argument exception) {
                        std::cerr << "error: std::invalid_argument" << std::endl;
                        std::cerr << exception.what() << std::endl;
                    }
                    break;
                case 3:
                    try {
                        sortUser<MyVector<Provider>>(providers);
                    } catch(std::invalid_argument exception) {
                        std::cerr << "error: std::invalid_argument" << std::endl;
                        std::cerr << exception.what() << std::endl;
                    }
                    break;
                case 4:
                    try {
                        showUser<MyVector<Provider>>(providers);
                    } catch(std::invalid_argument exception) {
                        std::cerr << "error: std::invalid_argument" << std::endl;
                        std::cerr << exception.what() << std::endl;
                    }
                    break;
                default:
                    break;
            }
            break;
        case -1:
        default:
            return 0;
            break;
        }
 
        std::cout << '\n';
    }

    return 0;
}

