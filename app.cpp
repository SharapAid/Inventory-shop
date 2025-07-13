#include "product.h"
#include "inventory.h"
#include "app.h"

short App::StateMenu(){
    short ciose = -1;
    std::cout<<"What you want to do: "<<'\n'
             <<"0 - Exit, "<<'\n'
             <<"1 - Add product, "<<'\n'
             <<"2 - Remove product, "<<'\n'
             <<"3 - Find product, "<<'\n'
             <<"4 - Updata quantity of product, "<<'\n'
             <<"5 - Show all product"<<'\n';
    std::cout<<"Enter ciose ";
    if(ciose < 0 || ciose > 5 || !std::cin>>ciose){
        while(ciose < 0 || ciose > 5 || !std::cin>>ciose){
            std::cerr<<"The value must not be a character or >0<5!"<<'\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin>>ciose;
        } 
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return ciose;
}

void App::UpdataState(short ciose){
    short m_ciose = StateMenu();
    switch (m_ciose){
        case 0:
            SetState(state::EXIT);
            break;
        case 1:
            SetState(state::ADD_ITEM);
            break;
        case 2:
            SetState(state::REMOVE_ITEM);
            break;
        case 3:
            SetState(state::FIND_ITEM);
            break;
        case 4:
            SetState(state::UPDATA_QUANTITY);
            break;
        case 5:
            SetState(state::SHOW_ITEM);
            break;
        default:
            std::cout<<"Your chiose is not value!!!"<<std::endl;
            SetState(state::MENU);
            break;
    }
}

std::string App::CinId(){
    std::string id;
    std::cout<<"Enter id of product: ";
    std::getline(std::cin, id);
    if(id.empty() || std::cin.fail()){
        while(id.empty() || std::cin.fail()){
            std::cerr<<"id must not be empty!"<<'\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, id);
        }
    }
    return id;
}

void App::StateSHOW_ITEM(){
    m_inventory.DisplayAllProducts();
    SetState(state::MENU);
}

void App::StateUPDATA_QUANTITY(){
    int change = 0;
    std::string id = CinId();
    std::cout<<"Enter quantity of product: ";
    if(change == 0 || !std::cin>>change){
        while(!std::cin>>change || change == 0){
            std::cerr<<"The value must not be a character or 0.!"<<'\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin>>change;
        } 
    }
    bool result = m_inventory.UpdateProductQuantity(id, change); 
    if(result){
        std::cout<<"Quantity of "<<id<<" change clear =)"<<'\n';
    }
    else{
        std::cout<<"Quantity of "<<id<<" dont change =("<<'\n';
    }
    SetState(state::MENU);
}  

void App::StateFIND_ITEM(){
    std::string id = CinId();
    auto it = m_inventory.FindProduct(id);
    if(it != nullptr){
        std::cout<<"Product: "
             <<*it<<'\n';
    }
    else{
        std::cout<<"Product "<<id<<" not find!";
    }
}

void App::StateREMOVE_ITEM(){
    std::string id = CinId();
    bool is_remove = m_inventory.RemoveProduct(id);
    if(is_remove){
        std::cout<<"Product "<<id<<" is remove"<<'\n';
    }
    else{
        std::cout<<"Product not remove =("<<'\n';
    }
}

 void App::StateADD_ITEM(){
    Product new_product;
    std::string name;
    double price = 0.0;
    int quantity = 0;
    std::cout<<"Enter name of product: ";
    std::getline(std::cin, name);
    if(name.empty() || std::cin.fail()){
        while(name.empty() || std::cin.fail()){
            std::cerr<<"id must not be empty!"<<'\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, name);
        }
    }
    new_product.SetName(name);
    std::string id = CinId();
    new_product.SetID(id);
    std::cout<<"Enter price of product: ";
    if(price == 0.0 || !(std::cin>>price)){
        while(!(std::cin>>price)|| price == 0.0){
            std::cerr<<"The value must not be a character or 0.!"<<'\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin>>price;
        } 
    }
    new_product.SetPrice(price);
    std::cout<<"Enter quantity of product: ";
    if(quantity == 0 || !std::cin>>quantity){
        while(!std::cin>>quantity|| quantity == 0){
            std::cerr<<"The value must not be a character or 0.!"<<'\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin>>quantity;
        } 
    }
    new_product.SetQuantity(quantity);
    m_inventory.AddProduct(new_product);
    std::cout<<"Product "<<new_product<<" entered."<<'\n';
}

void App::RunApp(){
    while(true){
        switch (m_state){
            case state::MENU:
                StateMenu();
                break;
            case state::ADD_ITEM:
                StateADD_ITEM();
                break;
            case state::REMOVE_ITEM:
                StateREMOVE_ITEM();
                break;
            case state::FIND_ITEM:
                StateFIND_ITEM();
                break; 
            case state::UPDATA_QUANTITY:
                StateUPDATA_QUANTITY();
                break; 
            case state::SHOW_ITEM:
                StateSHOW_ITEM();
                break; 
            case state::EXIT:
                if (m_state == state::EXIT){ 
                    return;
                }
                break;   
        }
    }  
}