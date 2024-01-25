#pragma once
#include <wx/wx.h>
#include "ControlPanel.hpp"

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
        ControlPanel* controls_;
    };
}