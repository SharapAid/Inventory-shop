#pragma once
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

class Inventory{
private:
    std::vector<Product> m_products;
public:
    Inventory();

    void AddProduct(const Product& new_product);
    bool UpdateProductQuantity(const std::string& product_Id, int change);
    bool RemoveProduct(const std::string& product_Id);
    Product* FindProduct(const std::string& product_Id);
    void DisplayAllProducts() const;
};

