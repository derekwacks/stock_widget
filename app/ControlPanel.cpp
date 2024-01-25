#include "ControlPanel.hpp"
#include "App.hpp"
#include <iostream>

namespace trader{
    enum ControlPanelIds{
        ControlPanel_StartId = 2000,
        ID_ButtonGet
    };

    ControlPanel::ControlPanel(wxWindow* parent) : wxPanel{parent}{
        wxBoxSizer* vBox{new wxBoxSizer{wxVERTICAL}};
        getButton_ = new wxButton{this, ID_ButtonGet, "Get Data"};
        Bind(wxEVT_BUTTON, &ControlPanel::onGetDataButtonClick, this, ID_ButtonGet);
        vBox->Add(getButton_, 0, wxEXPAND);
    }

    ControlPanel::~ControlPanel(){
    }

    void ControlPanel::onGetDataButtonClick(wxCommandEvent& event){
        //DataGetter* dg = new DataGetter();
        //double price = dg->getPrice();
        double price = wxGetApp().getter().getPrice();
        // Set visual price, print instead to test
        std::cout << price << std::endl; 
    }

}