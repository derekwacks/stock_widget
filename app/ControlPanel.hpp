#pragma once
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/wx.h>
#include <wx/panel.h>
#include <wx/button.h>

namespace trader{
    class ControlPanel : public wxPanel{
    public:
        ControlPanel(wxWindow* parent);
        ~ControlPanel();
    private:
        void onGetDataButtonClick(wxCommandEvent& event);
        std::string getTicker();
        wxButton* getButton_; 
        wxStaticBox* paramsBox_; 
        wxTextCtrl* symbol_; 
        wxStaticText* price_;
        wxStaticText* name_;  
        wxStaticText* exchange_; 
    };
}