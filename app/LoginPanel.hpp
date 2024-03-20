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
        bool userIsValid(wxString username, wxString password);
        wxTextCtrl* usernameCtrl;
        wxTextCtrl* passwordCtrl;
        ControlPanel* controls_;
    };
}