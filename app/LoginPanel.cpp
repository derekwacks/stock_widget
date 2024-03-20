#include "LoginPanel.hpp"

namespace trader{

//    wxBEGIN_EVENT_TABLE(AppWindow, wxFrame)
//    EVT_BUTTON(wxID_ANY, AppWindow::OnLogin)
//    wxEND_EVENT_TABLE()
    
    LoginPanel::LoginPanel(wxWindow* parent) : wxPanel{parent}{
        
        // Create sizers
        wxBoxSizer* mainSizer{new wxBoxSizer{wxVERTICAL}};
        wxFlexGridSizer* gridSizer{new wxFlexGridSizer(3,2,20,20)};

        // Add controls to the sizers
        gridSizer->Add(new wxStaticText(this, wxID_ANY, "Username:"), 0, wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        usernameCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
        gridSizer->Add(usernameCtrl, 1, wxEXPAND);

        gridSizer->Add(new wxStaticText(this, wxID_ANY, "Password:"), 0, wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        passwordCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD | wxTE_PROCESS_ENTER);
        gridSizer->Add(passwordCtrl, 1, wxEXPAND);
        
        wxButton* loginBtn = new wxButton(this, wxID_ANY, "Login");
        gridSizer->Add(loginBtn, 0, wxALIGN_RIGHT);
        
        // Add sizers to the main sizer
        mainSizer->Add(gridSizer, 1, wxALL | wxEXPAND, 20);
        // Set the main sizer for the panel
        this->SetSizer(mainSizer);
        // Connect the login button to the event handler
        loginBtn->Bind(wxEVT_BUTTON, &LoginPanel::onLoginButtonClick, this);
        //usernameCtrl->SetFocus();
    }

    LoginPanel::~LoginPanel(){
    }

    void LoginPanel::createAppWindow(void){
        wxWindow* parent_ = GetParent();
        controls_ = new ControlPanel(parent_);
        this->Destroy();
        parent_->Layout();
    }

    bool LoginPanel::userIsValid(wxString username, wxString password){
        // Cognito here
        if (username == "user" && password == "password"){
            return true;
        }
        return false;
    }

    void LoginPanel::onLoginButtonClick(wxCommandEvent& event){
        wxString username = usernameCtrl->GetValue();
        wxString password = passwordCtrl->GetValue();
        if(userIsValid(username, password)){
            LoginPanel::createAppWindow();
        }
        else{
            wxMessageBox("Login failed. Please check your username and password.", "Error", wxOK | wxICON_ERROR);
        }
        return;
    }
}