#include "Product.h"

namespace YMM {
    Product::Product() {
        m_title = "";
        m_productType = "";
        m_price = 0.0;
        m_amount = 0;
    }

    Product::Product(std::string _title, std::string _productType, float _price, int _amount) {
        m_title = _title;
        m_productType = _productType;
        m_price = _price;
        m_amount = _amount;
    }

    Product::~Product() {}

    std::string Product::getTitle() const {
        return m_title;
    }

    float Product::getPrice() const {
        return m_price;
    }

    int Product::getAmount() const {
        return m_amount;
    }

    std::string Product::getProductType() const {
        return m_productType;
    }

    void Product::setTitle(std::string _title) {
        m_title = _title;
    }

    void Product::setProductType(std::string _productType) {
        m_productType = _productType;
    }

    void Product::setAmount(int _amount) {
        m_amount = _amount;
    }

    void Product::printData() const {
        std::cout << "Title " << Product::getTitle() << std::endl;
        std::cout << "Price " << Product::getPrice() << std::endl;
        std::cout << "Amout " << Product::getAmount() << std::endl;
        std::cout << "Product Type " << Product::getProductType() << std::endl;
    }

    std::ostream& operator<<(std::ostream& out, Product& obj) {
        std::cout << "Title: " << obj.getTitle() << std::endl;
        std::cout << "Type: " << obj.getProductType() << std::endl;
        std::cout << "Price: " << obj.getPrice() << std::endl;
        std::cout << "Amout: " << obj.getAmount() << std::endl;
        
        return out;
    }

    std::istream& operator>>(std::istream& in, Product& object) {
        std::cout << "Title: ";
        std::cin >> object.m_title;

        std::cout << "Type: ";
        std::cin >> object.m_productType;

        std::cout << "Price: ";
        std::cin >> object.m_price;

        std::cout << "Amount: ";
        std::cin >> object.m_amount;

        return in;
    }

    bool operator>(const Product& object1, const Product& object2) {
        return (object1.m_amount > object2.m_amount);
    }

    bool operator<(const Product& object1, const Product& object2) {
        return (object1.m_amount < object2.m_amount);
    }

    bool operator==(const Product& object1, const Product& object2) {
        return (object1.m_amount == object2.m_amount);
    }

    bool operator!=(const Product& object1, const Product& object2) {
        return (object1.m_amount != object2.m_amount);
    }

    Product& Product::operator=(const Product &obj) {
        m_title = obj.m_title;
        m_productType = obj.m_productType;
        m_price = obj.m_price;
        m_amount = obj.m_amount;
        return *this;
    }
    Product* Product::operator=(const Product *obj) {
        m_title = obj->m_title;
        m_productType = obj->m_productType;
        m_price = obj->m_price;
        m_amount = obj->m_amount;
        return this;
    }
}

