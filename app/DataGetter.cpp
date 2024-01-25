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

    json DataGetter::queryYahoo(){
        std::string ticker = "KC=F";
        std::string api_url = "https://query1.finance.yahoo.com/v7/finance/options/";
        std::string full_url = api_url + ticker; 
        cpr::Response r = cpr::Get(cpr::Url{full_url},
        cpr::Authentication{"user", "pass", cpr::AuthMode::BASIC});
        json response = {
            {"status", r.status_code},
            {"header", r.header["content-type"]},
            {"body", json::parse(r.text)}
        };
        return response;
    }

}