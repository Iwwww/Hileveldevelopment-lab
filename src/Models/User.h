#pragma once
#include <string>

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

            // User(std::string _name, std::string _surname, std::string _login, std::string _password);

        protected:
            std::string m_name;
            std::string m_surname;
            std::string m_login;
            std::string m_password;
    };
}