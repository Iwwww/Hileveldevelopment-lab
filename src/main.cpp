#include <cstdint>
#include <iostream>
#include <cmath>
#include "CMenu/CMenu.h"
#include "CMenu/CMenuItem.h"
#include "Models/Product.h"
#include "Models/User.h"
#include "Models/Employer/Employer.h"
#include "Models/Provider/Provider.h"

const int MAX_ITEMS_COUNT = 50;

int providers_count = 0;
int employers_count = 0;

#pragma region функции-заглушки

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

#pragma region Employers

int addEmployers() {
    return 1;
};

int deleteEmployers() {
    return 2;
};

int sortEmployers() {
    return 3;
};

int showEmployers() {
    return 4;
};

void addEmployers(YMM::Employer *employers) {
    using namespace YMM;
    int count{};
    std::cout << "Введите количество элементов: ";
    std::cin >> count;
    for (int i = employers_count; i < count + employers_count; i++) {
        std::cout << "=========" << "\n";
        std::cin >> employers[i];
    }
    employers_count += count;
}

void deleteEmployers(YMM::Employer *employers) {
    using namespace YMM;
    int index{};
    std::cout << "Всего элементов: " << employers_count << "\n";
    std::cout << "Удалить элемент номер: ";
    std::cin >> index;
    if (index > employers_count || index < 1) {
        std::cout << "Не существует элемента с номером: " << index << "\n";
    } else {
        if (index != MAX_ITEMS_COUNT){
            for (int i = index-1; i < employers_count; i++) {
                employers[i] = employers[i+1];
            }
        }
        employers_count--;
    }
}

void sortEmployers(YMM::Employer *employers) {
    using namespace YMM;
    std::cout << "Сортировка ..." << "\n";
    for (int i = 0; i < employers_count; i++) {
        int index = i;
        for (int j = i; j < employers_count; j++) {
            if (employers[i] > employers[j]) {
                if (index == i) {
                    index = j;
                } else if (j > index) {
                    index = j;
                }
            }
        }
        Employer tmp = employers[i];
        employers[i] = employers[index];
        employers[index] = tmp;
    }
}

void showEmployers(YMM::Employer *employers) {
    using namespace YMM;
    std::cout << "Всего элементов: " << employers_count << "\n";
    int index{};
    std::cout << "Показать элемент номер: ";
    std::cin >> index;
    if (index > employers_count || index < 1) {
        std::cout << "Не существует элемента с номером: " << index << "\n";
    } else {
        std::cout << employers[index-1];
    }
}

#pragma endregion Employers

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

#pragma endregion функции-заглушки

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
    providers_count = 3;
    employers_count = 3;

    // menu items
    CMenuItem subItems1[2] {
        CMenuItem("squrt(25)", f1),
        CMenuItem("triangle", f2)
    };

    CMenuItem employerItems[4] {
        CMenuItem("Добавить", addEmployers),
        CMenuItem("Удалить", deleteEmployers),
        CMenuItem("Сортировать", sortEmployers),
        CMenuItem("Вывести в консоль", showEmployers)
    };

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

    CMenuItem items[items_number] {
        CMenuItem("Example functions"),
        CMenuItem("Employer"),
        CMenuItem("Provider")
    };

    CMenu subMenuArr[3] {
        CMenu("My sub menu 1", subItems1, 2),
        CMenu("Employers", employerItems, 4),
        CMenu("Providers", providerItems, 4)
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
                    addEmployers(employers);
                    break;
                case 2:
                    deleteEmployers(employers);
                    break;
                case 3:
                    sortEmployers(employers);
                    break;
                case 4:
                    showEmployers(employers);
                    break;
                default:
                    break;
            }
          break;
        case 3:
            switch (position[1]) {
                case 1:
                    addProviders(providers);
                    break;
                case 2:
                    deleteProviders(providers);
                    break;
                case 3:
                    sortProviders(providers);
                    break;
                case 4:
                    showProviders(providers);
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

