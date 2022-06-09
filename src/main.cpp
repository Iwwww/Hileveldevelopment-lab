#include <cstdint>
#include <ctime>
#include <iostream>
#include <cmath>
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
    std::cin >> count;
    while (count--) {
        std::cout << "=========" << "\n";
        v.addItem();
        std::cin >> v[v.size() - 1];
    }
}

template<typename T>
void deleteUser(T &v) {
    using namespace YMM;
    int index{};
    std::cout << "Всего элементов: " << v.size() << "\n";
    std::cout << "Удалить элемент номер: ";
    std::cin >> index;
    if (index > v.size() || index < 1) {
        std::cout << "Не существует элемента с номером: " << index << "\n";
    } else {
        v.removeItem(index - 1);
    }
}

template<typename T>
void sortUser(T &t) {
    using namespace YMM;
    std::cout << "Сортировка ..." << "\n";
    t.sort();
}

template<typename T>
void showUser(T &t) {
    using namespace YMM;
    std::cout << "Всего элементов: " << t.size() << "\n";
    int index{};
    std::cout << "Показать элемент номер: ";
    std::cin >> index;
    if (index > t.size() || index < 0) {
        std::cout << "Не существует элемента с номером: " << index << "\n";
    } else if (index == 0) {
        for (auto item: t) {
            std::cout << "=========" << std::endl;
            std::cout << item;
        }
    } else {
        std::cout << t[index-1];
    }
}

#pragma endregion User

int main() {
    using namespace YMM;

    // data
    MyVector<Provider> providers{};
    MyVector<Employer> employers{};

    providers += new Provider("Harry", "Potter", "Wizard", "617", new Product("History books", "book", 49.9, 350));
    providers += new Provider("Abcd", "Surname", "MyLogin", "123", new Product("apple", "fruit", 10.2, 1500));
    providers += new Provider("Sticker", "Wander", "helper", "968", new Product("Magic wand", "wand", 7.0, 6500));

    employers += new Employer("Stive", "Jobs", "alive", "09876", "Boss");
    employers += new Employer("Albus", "Dumbledore", "MainWizard", "5353535", "Director");
    employers += new Employer("Mikhail", "Empty", "qwerty", "okmmjj0987987", "Developer");

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
                    addUser<MyVector<Employer>>(employers);
                    break;
                case 2:
                    deleteUser<MyVector<Employer>>(employers);
                    break;
                case 3:
                    sortUser<MyVector<Employer>>(employers);
                    break;
                case 4:
                    showUser<MyVector<Employer>>(employers);
                    break;
                default:
                    break;
            }
          break;
        case 3:
            switch (position[1]) {
                case 1:
                    addUser<MyVector<Provider>>(providers);
                    break;
                case 2:
                    deleteUser<MyVector<Provider>>(providers);
                    break;
                case 3:
                    sortUser<MyVector<Provider>>(providers);
                    break;
                case 4:
                    showUser<MyVector<Provider>>(providers);
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

