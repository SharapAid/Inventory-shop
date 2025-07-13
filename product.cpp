#include "product.h"
#include "inventory.h"
#include "app.h"

inline std::ostream& operator<<(std::ostream& os,const Product& product){
    os<<"Name: "<<product.GetName()<<" ,price: "<<product.GetPrice()
      <<" quantity: "<<product.GetQuantity()<<'\n'
      <<"ID: "<<product.GetId()<<'\n';
    return os;
}

void Product::SetQuantity(int quantity){
    m_quantity = quantity;
}
    
void Product::SetPrice(double price){
    m_price = price;
}

void Product::SetName(const std::string& name){
    m_name = name;
}

void Product::SetID(const std::string& id){
    m_id = id;
}