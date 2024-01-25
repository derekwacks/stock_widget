#include "App.hpp"
#include <iostream>

namespace trader{
    wxIMPLEMENT_APP_NO_MAIN(App);

    App::App() : wxApp{}{
        //trader_ = new Trader();
    }

    App::~App(){
        // delete trader_; 
    }

    bool App::OnInit(){
        window_ = new AppWindow();
        datagetter_ = new DataGetter();
        return true;
    }

    AppWindow& App::window(){
        return *window_; 
    }

    DataGetter& App::getter(){
        return *datagetter_; 
    }

}


int main(int argc, char* argv[]){
    return wxEntry(argc, argv);
}