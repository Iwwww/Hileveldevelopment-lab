#pragma once
#include <string>

namespace YMM {
    class Product {
        public:
            enum class ProductType;

            std::string getTitle();
            ProductType getProductType();
            float getPrice();
            int getAmount();

            void setTitle(std::string _title);
            void setProductType(ProductType _productType);
            void setPrice(float _price);
            void setAmount(int _amount);

            void printData();

            Product();
            Product(std::string _title, ProductType _productType, float _price, int _amount);

        protected:
            std::string m_title;
            ProductType m_productType;
            float m_price;
            int m_amount;
    };
}