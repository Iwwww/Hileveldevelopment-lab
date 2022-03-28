#include <iostream>
#include "User.h"

namespace YMM {
    void User::setName(std::string _name) {
        m_name = _name;
    }

    void User::setSurname(std::string _surname) {
        m_surname = _surname;
    }

    void User::setLogin(std::string _login) {
        m_login = _login;
    }

    void User::setPassword(std::string _password) {
        m_password = _password;
    }

    std::string User::getName() {
        return m_name;
    }

    std::string User::getSurname() {
        return m_surname;
    }

    std::string User::getLogin() {
        return m_login;
    }

    std::string User::getPassword() {
        return m_password;
    }

    void User::printData() {
        std::cout << "Name " << User::getName() << std::endl;
        std::cout << "Surname " << User::getSurname() << std::endl;
        std::cout << "Login " << User::getLogin() << std::endl;
        std::cout << "Password " << User::getPassword() << std::endl;
    }

    // User::User(std::string _name, std::string _surname, std::string _login, std::string _password) {
    //     m_name = _name;
    //     m_surname = _surname;
    //     m_login = _login;
    //     m_password = _password;
    // }
}