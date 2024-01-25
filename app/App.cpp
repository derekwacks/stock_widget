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
        datagetter_ = new DataGetter();
        return true;
    }

    AppWindow& App::window(){
        return *window_; 
    }

    DataGetter& App::getter(){
        return *datagetter_; 
    }

    void App::test(){
        std::cout << "Launching app\n";
    }
}


int main(int argc, char* argv[]){
    trader::App a; 
    a.test();
    trader::DataGetter dg; 
    double price = dg.getPrice();
    std::cout << "Price = " << price << std::endl; 
    return wxEntry(argc, argv);
}