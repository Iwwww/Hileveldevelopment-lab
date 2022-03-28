#pragma onec
#include <iostream>
#include "Provider.h"

namespace YMM {
    void Provider::printData() {
        std::cout << "Name " << Provider::getName() << std::endl;
        std::cout << "Surname " << Provider::getSurname() << std::endl;
        std::cout << "Login " << Provider::getLogin() << std::endl;
        std::cout << "Password " << Provider::getPassword() << std::endl;
    }

    Provider::Provider() {}
    Provider::Provider(std::string _name, std::string _surname, std::string _login, std::string _password, Provider::ProductType _productType) {
        m_name = _name;
        m_surname = _surname;
        m_login = _login;
        m_password = _password;
        m_productType = _productType;
    }
}