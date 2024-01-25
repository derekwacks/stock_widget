#include "Window.hpp"
#include "App.hpp"

namespace trader{
    enum MenuWindowIds{
        MenuWindow_StartId = 1000,
    };

    AppWindow::AppWindow() : wxFrame{
            NULL,
            wxID_ANY,
            "Trader",
            wxDefaultPosition,
            wxSize{600,400},
            wxDEFAULT_FRAME_STYLE | wxMINIMIZE_BOX },
            menuFile_{ new wxMenu{} },
            menuHelp_{ new wxMenu{} }{
        menuFile_->Append(wxID_EXIT, wxGetStockLabel(wxID_EXIT), "Quit");
        menuHelp_->Append(wxID_ABOUT, wxGetStockLabel(wxID_ABOUT), "Display information");

        wxMenuBar* menuBar{ new wxMenuBar{} };
        menuBar->Append(menuFile_, "&File");
        menuBar->Append(menuHelp_, "&Help");
        SetMenuBar(menuBar);

        CreateStatusBar(5);

        Centre();
        Show();
    }

    AppWindow::~AppWindow(){
    }

    void AppWindow::onExit(wxCommandEvent& event){
        Close();
    }

}