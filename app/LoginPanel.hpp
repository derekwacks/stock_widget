#pragma once
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/wx.h>
#include <wx/panel.h>
#include <wx/button.h>
#include "ControlPanel.hpp"

namespace trader{
    class LoginPanel : public wxPanel{
    public:
        LoginPanel(wxWindow* parent);
        ~LoginPanel();
    private:
        void onLoginButtonClick(wxCommandEvent& event);
        void createAppWindow();
        wxTextCtrl* usernameCtrl;
        wxTextCtrl* passwordCtrl;
        ControlPanel* controls_;
    };
}