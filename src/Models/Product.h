#pragma once
#include <string>
#include <iostream>

namespace YMM {
    class Product {
        public:
            Product();
            Product(std::string, std::string, float, int);
            ~Product();

            std::string getTitle() const;
            float getPrice() const;
            int getAmount() const;
            std::string getProductType() const;

            void setTitle(std::string);
            void setProductType(std::string);
            void setPrice(float);
            void setAmount(int);

            void printData() const;

            friend std::ostream& operator<<(std::ostream&, Product&);
            friend std::istream& operator>>(std::istream&, Product&);
            friend bool operator>(const Product&, const Product&);
            friend bool operator<(const Product&, const Product&);
            friend bool operator==(const Product&, const Product&);
            friend bool operator!=(const Product&, const Product&);
            bool operator<(Product &object) const;
            Product& operator=(const Product &obj);
            Product* operator=(const Product *obj);

        protected:
            std::string m_title;
            std::string m_productType;
            float m_price;
            int m_amount;
    };
}
