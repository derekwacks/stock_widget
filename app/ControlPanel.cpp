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
        paramsBox_ = new wxStaticBox{this, wxID_ANY, ""};
        wxStaticBoxSizer* staticBoxSizer{new wxStaticBoxSizer{paramsBox_, wxVERTICAL}};
        constexpr int rows{5};
        constexpr int cols{2};
        constexpr int vGap{4};
        constexpr int hGap{8};

        wxFlexGridSizer* fgs = new wxFlexGridSizer{rows, cols, vGap, hGap};
        
        wxStaticText* symbol_label{new wxStaticText{paramsBox_, wxID_ANY, "Symbol:"}};
        symbol_ = new wxTextCtrl{paramsBox_, wxID_ANY, "KC=F", wxDefaultPosition, wxDefaultSize, wxTE_RIGHT};
        fgs->Add(symbol_label);
        fgs->Add(symbol_, 1, wxEXPAND);

        wxStaticText* price_label{new wxStaticText{paramsBox_, wxID_ANY, "Price:"}};
        price_ = new wxStaticText{paramsBox_, wxID_ANY, "0.0"};
        fgs->Add(price_label);
        fgs->Add(price_, 2, wxEXPAND);
        
        wxStaticText* name_label{new wxStaticText{paramsBox_, wxID_ANY, "Name:"}};
        name_ = new wxStaticText{paramsBox_, wxID_ANY, "name"};
        fgs->Add(name_label);
        fgs->Add(name_, 3, wxEXPAND);

        wxStaticText* exchange_label{new wxStaticText{paramsBox_, wxID_ANY, "Exchange:"}};
        exchange_ = new wxStaticText{paramsBox_, wxID_ANY, "exchange"};
        fgs->Add(exchange_label);
        fgs->Add(exchange_, 4, wxEXPAND);

        staticBoxSizer->Add(fgs);
        vBox->Add(staticBoxSizer, 0, wxEXPAND);

        getButton_ = new wxButton{this, ID_ButtonGet, "Get Data"};
        Bind(wxEVT_BUTTON, &ControlPanel::onGetDataButtonClick, this, ID_ButtonGet);
        vBox->Add(getButton_, 0, wxCENTER);

        SetSizer(vBox);
    }

    ControlPanel::~ControlPanel(){
    }

    void ControlPanel::onGetDataButtonClick(wxCommandEvent& event){
        std::string ticker_symbol = getTicker();
        DataFound* datafound = wxGetApp().getter().getData(ticker_symbol);
        bool err = datafound->datafoundGetError();
        double price = datafound->price();
        std::string name = datafound->name();
        std::string exchange = datafound->exchange();
        price_->SetLabel(std::to_string(price));
        name_->SetLabel(name);
        exchange_->SetLabel(exchange);
        if(err){
            showErrOnStatBar();
        }
    }

    std::string ControlPanel::getTicker(){
        return symbol_->GetValue().ToStdString();
    }

    void ControlPanel::showErrOnStatBar(){
        wxMessageBox("Invalid ticker symbol");
    }

}