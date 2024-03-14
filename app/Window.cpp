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
            menuHelp_{ new wxMenu{} }{//,
            //controls_{ new ControlPanel{this} }{
            //login_{ new LoginPanel{this} }{
        
        //controls_ = new ControlPanel(this);
        login_ = new LoginPanel(this);
        std::cout << "login_: " << login_ << std::endl;

        
        menuFile_->Append(wxID_EXIT, wxGetStockLabel(wxID_EXIT), "Quit");
        menuHelp_->Append(wxID_ABOUT, wxGetStockLabel(wxID_ABOUT), "Display information");

        wxMenuBar* menuBar{ new wxMenuBar{} };
        menuBar->Append(menuFile_, "&File");
        menuBar->Append(menuHelp_, "&Help");
        SetMenuBar(menuBar);

        Bind(wxEVT_MENU, &AppWindow::onExit, this, wxID_EXIT);
        Bind(wxEVT_MENU, &AppWindow::onAbout, this, wxID_ABOUT);

        CreateStatusBar(5);
        
        wxBoxSizer* hbox{new wxBoxSizer{wxHORIZONTAL}};
        hbox->Add(login_, 1, wxEXPAND | wxALL, 5);

        //wxBoxSizer* hbox{new wxBoxSizer{wxVERTICAL}};
        //hbox->Add(login_, 1, wxEXPAND | wxALL, 5);
        /*
        wxBoxSizer* hbox{new wxBoxSizer{wxVERTICAL}};
        wxFlexGridSizer* ctrl_login = new wxFlexGridSizer(2,1,10,10);
        ctrl_login->Add(controls_, 1, wxEXPAND | wxALL);
        ctrl_login->Add(login_, 1, wxEXPAND | wxALL);
        hbox->Add(ctrl_login, 0, wxEXPAND);
        */
        Centre();
        Show();
        std::cout << "AppWindow wxFrame ptr: " << this << std::endl;
    }

    AppWindow::~AppWindow(){
    }

    void AppWindow::onExit(wxCommandEvent& event){
        Close();
    }

    void AppWindow::onAbout(wxCommandEvent& event){
        wxMessageBox("Commodity Trading Info\n"
        "by Derek Wacks");
    }

}