#pragma once
#include <string>
#include <iostream>

namespace YMM {
    class User {
        public:
            void setName(std::string _name);
            void setSurname(std::string _surname);
            void setLogin(std::string _login);
            void setPassword(std::string _password);

            std::string getName() const;
            std::string getSurname() const;
            std::string getLogin() const;
            std::string getPassword() const;

            virtual void printData() const = 0;

        protected:
            std::string m_name;
            std::string m_surname;
            std::string m_login;
            std::string m_password;
    };
}

