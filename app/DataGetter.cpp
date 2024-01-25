#include "DataGetter.hpp"
#include <iostream>
#include <cpr/cpr.h>
#include <string>


namespace trader{
    DataGetter::DataGetter(){
    }

    DataGetter::~DataGetter(){
    }

    double DataGetter::getPrice(){
        std::cout << "Getting data...\n";
        double price{10.0};
        return price; 
    }

    int DataGetter::getData(){
        std::string url = "https://query1.finance.yahoo.com/v7/finance/options/KC=F";
        cpr::Response r = cpr::Get(cpr::Url{url},
        cpr::Authentication{"user", "pass", cpr::AuthMode::BASIC});
        std::cout << r.status_code << std::endl;
        std::cout << r.header["content-type"] << std::endl;
        std::cout << r.text << std::endl;
        return 0;
    } 

}