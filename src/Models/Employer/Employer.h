#pragma once
#include <string>
#include <iostream>
#include "../User.h"

namespace YMM {
    class Employer:public User {
        public:
            static unsigned int count;

            std::string getPosition() const;
            int getCount() const;

            void setPosition(std::string _position);

            void printData() const;

            Employer();
            Employer(std::string _name, std::string _surname, std::string _login, std::string _password, std::string _position);

            friend std::ostream& operator<<(std::ostream& out, Employer& object);
            friend std::istream& operator>>(std::istream& in, Employer& object);
            friend bool operator<(const Employer &item_1, const Employer &item_2);
            friend bool operator>(const Employer &item_1, const Employer &item_2);
            friend bool operator==(const Employer &item_1, const Employer &item_2);
            friend bool operator!=(const Employer &item_1, const Employer &item_2);
            Employer& operator=(Employer &obj);
            Employer* operator=(Employer *obj);

        private:
            std::string m_position;
    };
}
