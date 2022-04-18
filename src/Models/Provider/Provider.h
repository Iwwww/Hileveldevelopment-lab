#pragma once
#include <string.h>
#include "../User.h"
#include "../Product.h"

namespace YMM {
    class Provider : public User, public Product {
        public:
            void printData() const;
            Provider();
            Provider(std::string _name, std::string _surname, std::string _login, std::string _password, ProductType _productType);
    };
}