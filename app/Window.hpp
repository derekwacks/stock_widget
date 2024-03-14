#pragma once
#include <wx/wx.h>
#include "ControlPanel.hpp"
#include "LoginPanel.hpp"

namespace trader{
    class AppWindow : public wxFrame{
    public:
        AppWindow();
        ~AppWindow();
        
    private:
        void onExit(wxCommandEvent& event);
        void onAbout(wxCommandEvent& event);

        wxMenu* menuFile_;
        wxMenu* menuHelp_;
        LoginPanel* login_;

        //wxDECLARE_EVENT_TABLE();
    };
}