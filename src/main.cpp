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

const int MAX_ITEMS_COUNT = 50;

#pragma region функции-заглушки

#pragma region example-funcions

void f1(void) {
    std::cout << "Sqrt(25) = " << sqrt(25) << '\n';
}

void f2(void) {
    for (int i = 1; i < 8; i++) {
        for (int j = 1; j < i; j++) { 
            std::cout << "* ";
        }
        std::cout << "\n";
    }
}

#pragma endregion example-funcions

#pragma region Employers

/* int addUser() {
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
 */
template<typename T>
void addUser(T *t) {
    using namespace YMM;
    int count{};
    std::cout << "Введите количество элементов: ";
    std::cin >> count;
    for (int i = T::count; i < count + T::count; i++) {
        std::cout << "=========" << "\n";
        std::cin >> t[i];
    }
    T::count += count;
}

template<typename T>
void deleteUser(T *t) {
    using namespace YMM;
    int index{};
    std::cout << "Всего элементов: " << T::count << "\n";
    std::cout << "Удалить элемент номер: ";
    std::cin >> index;
    if (index > T::count || index < 1) {
        std::cout << "Не существует элемента с номером: " << index << "\n";
    } else {
        if (index != MAX_ITEMS_COUNT){
            for (int i = index-1; i < T::count; i++) {
                t[i] = t[i+1];
            }
        }
        T::count--;
    }
}

template<typename T>
void sortUser(T *t) {
    using namespace YMM;
    std::cout << "Сортировка ..." << "\n";
    for (int i = 0; i < T::count; i++) {
        int index = i;
        for (int j = i; j < T::count; j++) {
            if (t[i] > t[j]) {
                if (index == i) {
                    index = j;
                } else if (j > index) {
                    index = j;
                }
            }
        }
        Employer tmp = t[i];
        t[i] = t[index];
        t[index] = tmp;
    }
}

template<typename T>
void showUser(T *t) {
    using namespace YMM;
    std::cout << "Всего элементов: " << T::count << "\n";
    int index{};
    std::cout << "Показать элемент номер: ";
    std::cin >> index;
    if (index > T::count || index < 1) {
        std::cout << "Не существует элемента с номером: " << index << "\n";
    } else {
        std::cout << t[index-1];
    }
}

#pragma endregion Employers

/* 
#pragma region Providers

int addProviders() {
    return 1;
};

int deleteProviders() {
    return 2;
};

int sortProviders() {
    return 3;
};

int showProviders() {
    return 4;
};

void addProviders(YMM::Provider *providers) {
    using namespace YMM;
    int count{};
    std::cout << "Введите количество элементов: ";
    std::cin >> count;
    for (int i = providers_count; i < count + providers_count; i++) {
        std::cout << "=========" << "\n";
        std::cin >> providers[i];
    }
    providers_count += count;
}

void deleteProviders(YMM::Provider *providers) {
    using namespace YMM;
    int index{};
    std::cout << "Всего элементов: " << providers_count << "\n";
    std::cout << "Удалить элемент номер: ";
    std::cin >> index;
    std::cout << "=========" << "\n";
    if (index > providers_count || index < 1) {
        std::cout << "Не существует элемента с номером: " << index << "\n";
    } else {
        if (index != MAX_ITEMS_COUNT){
            for (int i = index-1; i < providers_count; i++) {
                providers[i] = providers[i+1];
            }
        }
        providers_count--;
    }
}

void sortProviders(YMM::Provider *providers) {
    using namespace YMM;
    std::cout << "Сортировка ..." << "\n";
    for (int i = 0; i < providers_count; i++) {
        int index = i;
        for (int j = i; j < providers_count; j++) {
            if (providers[i] > providers[j]) {
                if (index == i) {
                    index = j;
                } else if (j > index) {
                    index = j;
                }
            }
        }
        Provider tmp = providers[i];
        providers[i] = providers[index];
        providers[index] = tmp;
    }
}

void showProviders(YMM::Provider *providers) {
    using namespace YMM;
    std::cout << "Всего элементов: " << providers_count << "\n";
    int index{};
    std::cout << "Показать элемент номер: ";
    std::cin >> index;
    std::cout << "=========" << "\n";
    if (index > providers_count || index < 1) {
        std::cout << "Не существует элемента с номером: " << index << "\n";
    } else {
        std::cout << providers[index-1];
    }
}

#pragma endregion Providers
*/

#pragma endregion функции-заглушки

unsigned int YMM::Employer::count = 3;
unsigned int YMM::Provider::count = 3;

int main() {
    using namespace YMM;

    const int items_number = 3;

    // data
    Provider *providers = new Provider[MAX_ITEMS_COUNT];
    Employer *employers = new Employer[MAX_ITEMS_COUNT];

    providers[0] = new Provider("Harry", "Potter", "Wizard", "617", new Product("History books", "book", 49.9, 350));
    providers[1] = new Provider("Abcd", "Surname", "MyLogin", "123", new Product("apple", "fruit", 10.2, 1500));
    providers[2] = new Provider("Sticker", "Wander", "helper", "968", new Product("Magic wand", "wand", 7.0, 6500));
    employers[0] = new Employer("Stive", "Jobs", "alive", "09876", "Boss");
    employers[1] = new Employer("Albus", "Dumbledore", "MainWizard", "5353535", "Director");
    employers[2] = new Employer("Mikhail", "Empty", "qwerty", "okmmjj0987987", "Developer");

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
/* 
    CMenuItem providerItems[4] {
        CMenuItem("Добавить", addProviders),
        CMenuItem("Удалить", deleteProviders),
        CMenuItem("Сортировать", sortProviders),
        CMenuItem("Вывести в консоль", showProviders)
    };

    CMenuItem producutItems[4] {
        CMenuItem("Добавить", addProviders),
        CMenuItem("Удалить", deleteProviders),
        CMenuItem("Сортировать", sortProviders),
        CMenuItem("Вывести в консоль", showProviders)
    };
 */
    CMenuItem items[items_number] {
        CMenuItem("Example functions"),
        CMenuItem("Employer"),
        CMenuItem("Provider")
    };

    CMenu subMenuArr[3] {
        CMenu("My sub menu 1", exampleItems, 2),
        CMenu("Employers", userItems, 4),
        CMenu("Providers", userItems, 4)
    };

    CMenu menu("My console menu", items, items_number);
 
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
                    addUser<Employer>(employers);
                    break;
                case 2:
                    deleteUser<Employer>(employers);
                    break;
                case 3:
                    sortUser<Employer>(employers);
                    break;
                case 4:
                    showUser<Employer>(employers);
                    break;
                default:
                    break;
            }
          break;
        case 3:
            switch (position[1]) {
                case 1:
                    addUser<Provider>(providers);
                    break;
                case 2:
                    deleteUser<Provider>(providers);
                    break;
                case 3:
                    sortUser<Provider>(providers);
                    break;
                case 4:
                    showUser<Provider>(providers);
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

