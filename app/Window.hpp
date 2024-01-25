#pragma once
#include <wx/wx.h>

namespace trader{
    class AppWindow : public wxFrame{
    public:
        AppWindow();
        ~AppWindow();
    private:
        void onExit(wxCommandEvent& event);

        wxMenu* menuFile_;
        wxMenu* menuHelp_;
    };
}