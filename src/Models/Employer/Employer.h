#pragma once
#include <string>
#include "../User.h"

namespace YMM {
    class Employer:public User {
        public:

            std::string getPosition();

            void setPosition(std::string _position);

            void printData();

            Employer();
            Employer(std::string _name, std::string _surname, std::string _login, std::string _password, std::string _position);

        private:
            std::string m_position;
    };
}