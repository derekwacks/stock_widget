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

        paramsBox_ = new wxStaticBox{this, wxID_ANY, ""};
        wxStaticBoxSizer* staticBoxSizer{new wxStaticBoxSizer{paramsBox_, wxVERTICAL}};
        constexpr int rows{2};
        constexpr int cols{2};
        constexpr int vGap{4};
        constexpr int hGap{8};
        wxFlexGridSizer* fgs = new wxFlexGridSizer{rows, cols, vGap, hGap};

        wxStaticText* symbol_label{new wxStaticText{paramsBox_, wxID_ANY, "Symbol:"}};
        symbol_ = new wxTextCtrl{paramsBox_, wxID_ANY, "AAPL", wxDefaultPosition, wxDefaultSize, wxTE_RIGHT};
        wxStaticText* price_label{new wxStaticText{paramsBox_, wxID_ANY, "Price:"}};
        price_ = new wxStaticText{paramsBox_, wxID_ANY, "0.0"};

        fgs->Add(symbol_label);
        fgs->Add(symbol_, 1, wxEXPAND);
        fgs->Add(price_label);
        fgs->Add(price_, 2, wxEXPAND);

        staticBoxSizer->Add(fgs);
        vBox->Add(staticBoxSizer, 0, wxEXPAND);

        SetSizer(vBox);
    }

    ControlPanel::~ControlPanel(){
    }

    void ControlPanel::onGetDataButtonClick(wxCommandEvent& event){
        //DataGetter* dg = new DataGetter();
        //double price = dg->getPrice();
        double price = wxGetApp().getter().getPrice();
        price_->SetLabel(std::to_string(price)); 

    }

}