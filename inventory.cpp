#include "product.h"
#include "inventory.h"
#include "app.h"

void Inventory::AddProduct(const Product& new_product){
    auto it = std::find_if(m_products.begin(), m_products.end(), [&](const Product& product){
        std::string name_lower = product.GetId();
        std::string new_name_lower = new_product.GetId();
        std::transform(name_lower.begin(), name_lower.end(), name_lower.begin(), ::tolower);
        std::transform(new_name_lower.begin(), new_name_lower.end(), new_name_lower.begin(), ::tolower);

        return name_lower == new_name_lower;
    });
    if(it == m_products.end()){
        m_products.push_back(new_product);
    }
    else{
        it->SetQuantity(it->GetQuantity() + new_product.GetQuantity());
    }
}

bool Inventory::RemoveProduct(const std::string& product_Id){
    std::string copy_product = product_Id;
    auto it = std::remove_if(m_products.begin(), m_products.end(), [&](const Product& product){
        std::string name_lower = product.GetId();
        std::transform(name_lower.begin(), name_lower.end(), name_lower.begin(), ::tolower);
        std::transform(copy_product.begin(), copy_product.end(), copy_product.begin(), ::tolower);

        return name_lower == copy_product;
    });
    if(it != m_products.end()){
        m_products.erase(it, m_products.end());
        return true;
    }
    return false;
}

Product* Inventory::FindProduct(const std::string& product_Id){
    std::string copy_product = product_Id;
    auto it = std::find_if(m_products.begin(), m_products.end(), [&](const Product& product){
        std::string name_lower = product.GetId();
        std::transform(name_lower.begin(), name_lower.end(), name_lower.begin(), ::tolower);
        std::transform(copy_product.begin(),copy_product.end(), copy_product.begin(), ::tolower);

        return name_lower == copy_product;
    });
    if(it != m_products.end()){
        return &(*it);
    }
    return nullptr;
}

bool Inventory::UpdateProductQuantity(const std::string& product_Id, int change){
    auto it = FindProduct(product_Id);
    if( it != nullptr){
        if(change < 0){
            if(it->GetQuantity() + change < 0){
                return false;
            }
            else{
                it->SetQuantity(it->GetQuantity() + change);
                return true;
            }
        }
        else{
            it->SetQuantity(it->GetQuantity() + change);
            return true;
        }
    }
    return false;
}

void Inventory::DisplayAllProducts() const{
    if(m_products.empty()){
        std::cout<<"There are currently no products available!"<<'\n';
    }
    for(const auto& element : m_products){
        std::cout<<element;
    }
}