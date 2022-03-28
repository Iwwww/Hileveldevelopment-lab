#include <string>
#include <iostream>
#include "Employer.h"

namespace YMM {
    std::string Employer::getPosition() {
        return m_position;
    }

    void Employer::setPosition(std::string _position) {
        m_position = _position;
    }

    void Employer::printData() {
        std::cout << "Name " << Employer::getName() << std::endl;
        std::cout << "Surname " << Employer::getSurname() << std::endl;
        std::cout << "Login " << Employer::getLogin() << std::endl;
        std::cout << "Password " << Employer::getPassword() << std::endl;
    }

    Employer::Employer() {}

    Employer::Employer(std::string _name, std::string _surname, std::string _login, std::string _password, std::string _position) {
        m_name = _name;
        m_surname = _surname;
        m_login = _login;
        m_password = _password;
        m_position = _position;
    }
}