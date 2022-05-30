#include "Employer.h"

namespace YMM {
    std::string Employer::getPosition() const {
        return m_position;
    }

    void Employer::setPosition(std::string _position) {
        m_position = _position;
    }

    void Employer::printData() const {
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

    bool operator<(const Employer &item_1, const Employer &item_2) {
        return item_1.m_name[0] < item_2.m_name[0];
    }

    bool operator>(const Employer &item_1, const Employer &item_2) {
        return item_1.m_name[0] > item_2.m_name[0];
    }

    bool operator==(const Employer &item_1, const Employer &item_2) {
        return item_1.m_name[0] == item_2.m_name[0];
    }

    bool operator!=(const Employer &item_1, const Employer &item_2) {
        return item_1.m_name[0] != item_2.m_name[0];
    }

    std::ostream& operator<<(std::ostream& out, Employer& object) {
        object.printData();

        return out;
    }

    std::istream& operator>>(std::istream& in, Employer& object) {
        std::cout << "Name: ";
        std::cin >> object.m_name;

        std::cout << "Surname: ";
        std::cin >> object.m_surname;

        std::cout << "Login: ";
        std::cin >> object.m_login;

        std::cout << "Password: ";
        std::cin >> object.m_password;

        return in;
    }

    Employer& Employer::operator=(Employer &obj){
        m_name = obj.m_name;
        m_surname = obj.m_surname;
        m_login = obj.m_login;
        m_password = obj.m_password;
        m_position = obj.m_position;
        return *this;
    }

    Employer* Employer::operator=(Employer *obj){
        m_name = obj->m_name;
        m_surname = obj->m_surname;
        m_login = obj->m_login;
        m_password = obj->m_password;
        m_position = obj->m_position;
        return this;
    }
}
