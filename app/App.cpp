#include "App.hpp"
#include <iostream>

namespace trader{
    App::App() : wxApp{}{
        //trader_ = new Trader();
    }

    App::~App(){
        // delete trader_; 
    }

    bool App::OnInit(){
        window_ = new AppWindow();
        return true;
    }

    AppWindow& App::window(){
        return *window_; 
    }

    void App::test(){
        std::cout << "Launching app\n";
    }
}


int main(int argc, char* argv[]){
    trader::App a; 
    a.test();
    return wxEntry(argc, argv);
}