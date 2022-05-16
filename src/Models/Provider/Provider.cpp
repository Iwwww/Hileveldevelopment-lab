#pragma onec
#include "Provider.h"

namespace YMM {
    Provider::Provider() {}
    Provider::Provider(std::string _name, std::string _surname, std::string _login, std::string _password, Product *_product) {
        m_name = _name;
        m_surname = _surname;
        m_login = _login;
        m_password = _password;
        m_product = _product;
    }

     void Provider::printData() const {
        std::cout << "Name " << Provider::getName() << std::endl;
        std::cout << "Surname " << Provider::getSurname() << std::endl;
        std::cout << "Login " << Provider::getLogin() << std::endl;
        std::cout << "Password " << Provider::getPassword() << std::endl;
    }

     // Product *getProduct() {
         // return m_product ;
     // }

   std::ostream& operator<<(std::ostream& out, Provider& object) {
        object.printData();

        return out;
    }

    std::istream& operator>>(std::istream& in, Provider& object) {
        std::cout << "Name ";
        std::cin >> object.m_name;

        std::cout << "Surname ";
        std::cin >> object.m_surname;

        std::cout << "Login ";
        std::cin >> object.m_login;

        std::cout << "Password ";
        std::cin >> object.m_password;

        std::cout << "Product Type ";
        std::cin >> object.m_productType;

        return in;
    }
}
