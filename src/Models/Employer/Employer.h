#pragma once
#include <string>
#include "../User.h"

namespace YMM {
    class Employer:public User {
        public:

            std::string getPosition() const;

            void setPosition(std::string _position);

            void printData() const;

            Employer();
            Employer(std::string _name, std::string _surname, std::string _login, std::string _password, std::string _position);

        private:
            std::string m_position;
    };
}