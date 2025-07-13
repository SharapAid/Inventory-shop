#pragma once
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

enum class state{
    MENU,
    ADD_ITEM,
    REMOVE_ITEM,
    FIND_ITEM,
    UPDATA_QUANTITY,
    SHOW_ITEM,
    EXIT
};

class App{
private:
    Inventory m_inventory;
    state m_state;

    void StateADD_ITEM();
    void StateREMOVE_ITEM();
    void StateFIND_ITEM();
    void StateUPDATA_QUANTITY();
    void StateSHOW_ITEM();
    short StateMenu();
    void UpdataState(short ciose);
    std::string CinId();

public:
    App(){
        m_state = state::MENU;
    }

    ~App();

    void SetState(const state& state){m_state = state;}
    void RunApp();

};
