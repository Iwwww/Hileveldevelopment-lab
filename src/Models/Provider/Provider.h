#pragma once
#include <string.h>
#include <iostream>
#include "../User.h"
#include "../Product.h"

namespace YMM {
    class Provider : public User, public Product {
        public:
            static unsigned int count;

            Provider();
            Provider(std::string _name, std::string _surname, std::string _login, std::string _password, Product *);

            virtual void printData() const;

            Product *getProduct();

            friend std::ostream& operator<<(std::ostream&, Provider&);
            friend std::istream& operator>>(std::istream&, Provider&);
            friend bool operator<(const Provider &item_1, const Provider &item_2);
            friend bool operator>(const Provider &item_1, const Provider &item_2);
            friend bool operator==(const Provider &item_1, const Provider &item_2);
            friend bool operator!=(const Provider &item_1, const Provider &item_2);
            Provider& operator=(const Provider &obj);
            Provider* operator=(const Provider *obj);

        private:
            Product *m_product = nullptr;
    };
}
