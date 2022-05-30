#pragma onec
#include "Provider.h"

namespace YMM {
    Provider::Provider() {
        m_product = new Product();
    }
    Provider::Provider(std::string _name, std::string _surname, std::string _login, std::string _password, Product *_product) {
        m_name = _name;
        m_surname = _surname;
        m_login = _login;
        m_password = _password;
        m_product = _product;
    }

     void Provider::printData() const {
        std::cout << "Name: " << Provider::getName() << "\n";
        std::cout << "Surname: " << Provider::getSurname() << "\n";
        std::cout << "Login: " << Provider::getLogin() << "\n";
        std::cout << "Password: " << Provider::getPassword() << "\n";
        std::cout << Provider::m_product;
    }

   std::ostream& operator<<(std::ostream& out, Provider& object) {
        std::cout << "Name: " << object.getName() << "\n";
        std::cout << "Surname: " <<  object.getSurname() << "\n";
        std::cout << "Login: " << object.getLogin() << "\n";
        std::cout << "Password: " << object.getPassword() << "\n";
        std::cout << "---------" << "\n";
        std::cout << *object.m_product;

       // object.printData();

        return out;
    }

    std::istream& operator>>(std::istream& in, Provider& object) {
        std::cout << "Name: "; 
        std::cin >> object.m_name;

        std::cout << "Surname: ";
        std::cin >> object.m_surname;

        std::cout << "Login: ";
        std::cin >> object.m_login;

        std::cout << "Password: ";
        std::cin >> object.m_password;

        std::cout << "---------" << "\n";

        std::cout << "Product" << "\n";
        std::cin >> *object.m_product;

        return in;
    }

    bool operator<(const Provider &item_1, const Provider &item_2) {
        return item_1.m_name[0] < item_2.m_name[0];
    }

    bool operator>(const Provider &item_1, const Provider &item_2) {
        return item_1.m_name[0] > item_2.m_name[0];
    }

    bool operator==(const Provider &item_1, const Provider &item_2) {
        return item_1.m_name[0] == item_2.m_name[0];
    }

    bool operator!=(const Provider &item_1, const Provider &item_2) {
        return item_1.m_name[0] != item_2.m_name[0];
    }

    Provider& Provider::operator=(const Provider &obj) {
        m_name = obj.m_name;
        m_surname = obj.m_surname;
        m_login = obj.m_login;
        m_password = obj.m_password;
        m_product = obj.m_product;
        return *this;
    }

    Provider* Provider::operator=(const Provider *obj) {
        m_name = obj->m_name;
        m_surname = obj->m_surname;
        m_login = obj->m_login;
        m_password = obj->m_password;
        m_product = obj->m_product;
        return this;
    }
}
