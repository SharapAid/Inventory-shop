#pragma once
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

class Product{
private:
    std::string m_name;
    std::string m_id;
    double m_price;
    int m_quantity;
public:
    Product(): m_name(""), m_id(""), m_price(0.0), m_quantity(0) {}

    Product(const std::string& name, const std::string& id, double price, int quantity)
    :  m_name(name), m_id(id), m_price(price), m_quantity(quantity) {}

    friend std::ostream& operator<< (std::ostream& os,const Product& product);

    std::string GetName() const{return m_name;}
    std::string GetId() const{return m_id;}
    double GetPrice() const{return m_price;}
    int GetQuantity() const{return m_quantity;}

    void SetQuantity(int quantity);
    void SetPrice(double price);
    void SetName(const std::string& name);
    void SetID(const std::string& id);
};