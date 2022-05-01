#include <string>
#include "Product.h"

namespace YMM {
    enum class Product::ProductType {
       fish,
       vegetable,
       fruit
    };

    std::string Product::getTitle() const {
        return m_title;
    }

    Product::ProductType Product::getProductType() const {
        return m_productType;
    }

    float Product::getPrice() const {
        return m_price;
    }

    int Product::getAmount() const {
        return m_amount;
    }

    void Product::setTitle(std::string _title) {
        m_title = _title;
    }

    void Product::setProductType(Product::ProductType _productType) {
        m_productType = _productType;
    }

    void Product::setAmount(int _amount) {
        m_amount = _amount;
    }

    void Product::printData() const {
        std::cout << "Title " << Product::getTitle() << std::endl;
        std::cout << "Price " << Product::getPrice() << std::endl;
        std::cout << "Amout " << Product::getAmount() << std::endl;
        std::string productTypeStr = "";
        switch((int)m_productType) {
            case 0:
                productTypeStr = "fish";
                break;
            case 1:
                productTypeStr = "vegetable";
                break;
            case 2:
                productTypeStr = "fruit";
                break;
            default:
                productTypeStr = "";
        }
        std::cout << "Product Type " << productTypeStr << std::endl;
    }

    Product::Product() {}

    Product::Product(std::string _title, ProductType _productType, float _price, int _amount) {
        m_title = _title;
        m_price = _price;
        m_amount = _amount;
    }

    std::ostream& operator<<(std::ostream& out, Product& object) {
        object.printData();
        
        return out;
    }

    std::istream& operator>>(std::istream& in, Product& object) {
        object.printData();
        
        return in;
    }

    bool operator>(const Product& object1, const Product& object2) {
        return (object1.m_amount > object2.m_amount);
    }

    bool operator<(const Product& object1, const Product& object2) {
        return (object1.m_amount < object2.m_amount);
    }
}

