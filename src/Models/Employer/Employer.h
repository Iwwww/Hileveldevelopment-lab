#pragma once
#include <string>
#include <iostream>
#include "../User.h"

namespace YMM {
    class Employer:public User {
        public:
            Employer();
            Employer(std::string _name, std::string _surname, std::string _login, std::string _password, std::string _position);

            std::string getPosition() const;

            void setPosition(std::string _position);

            void printData() const;

            friend std::ostream& operator<<(std::ostream& out, Employer& object);
            friend std::istream& operator>>(std::istream& in, Employer& object);
            friend bool operator<(const Employer &item_1, const Employer &item_2);
            friend bool operator>(const Employer &item_1, const Employer &item_2);
            friend bool operator==(const Employer &item_1, const Employer &item_2);
            friend bool operator!=(const Employer &item_1, const Employer &item_2);
            Employer& operator=(Employer &obj);
            Employer* operator=(Employer *obj);

            Employer* new_instance();

        private:
            std::string m_position;
    };
}
