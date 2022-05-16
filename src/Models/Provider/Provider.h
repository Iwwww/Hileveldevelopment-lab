#pragma once
#include <string.h>
#include <iostream>
#include "../User.h"
#include "../Product.h"

namespace YMM {
    class Provider : public User, public Product {
        public:
            Provider();
            Provider(std::string _name, std::string _surname, std::string _login, std::string _password, Product *);

            void printData() const;

            Product *getProduct();

            friend std::ostream& operator<<(std::ostream&, Provider&);
            friend std::istream& operator>>(std::istream&, Provider&);

        private:
            Product *m_product = nullptr;
    };
}
