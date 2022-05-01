#pragma once
#include <string>
#include <iostream>

namespace YMM {
    class Product {
        public:
            enum class ProductType;

            std::string getTitle() const;
            ProductType getProductType() const;
            float getPrice() const;
            int getAmount() const;

            void setTitle(std::string);
            void setProductType(ProductType);
            void setPrice(float);
            void setAmount(int);

            void printData() const;

            Product();
            Product(std::string, ProductType, float, int);

            friend std::ostream& operator<<(std::ostream&, Product&);
            friend std::istream& operator>>(std::istream&, Product&);

            friend bool operator>(const Product&, const Product&);
            friend bool operator<(const Product&, const Product&);

            bool operator<(Product &object) const;

        protected:
            std::string m_title;
            ProductType m_productType;
            float m_price;
            int m_amount;
    };
}
