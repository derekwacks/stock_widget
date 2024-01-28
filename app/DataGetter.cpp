#include "DataGetter.hpp"
#include <iostream>
#include <cpr/cpr.h>
#include <string>

namespace trader{
    DataGetter::DataGetter(){
    }

    DataGetter::~DataGetter(){
    }

    double DataGetter::spoofGetPrice(){
        std::cout << "Getting data...\n";
        double price{10.0};
        return price;
    }

    json* DataGetter::queryYahoo(std::string ticker){
        //std::string api_url = "https://query1.finance.yahoo.com/v7/finance/options/";
        std::string api_url = "https://query1.finance.yahoo.com/v6/finance/options/";
        std::string full_url = api_url + ticker; 
        cpr::Response r = cpr::Get(cpr::Url{full_url},
        cpr::Authentication{"user", "pass", cpr::AuthMode::BASIC});
        json* response = new json({
            {"status", r.status_code},
            {"header", r.header["content-type"]},
            {"body", json::parse(r.text)}
        });
        return response;
    }

    DataFound* DataGetter::parseData(json* data){
        DataFound* data_found_ = new DataFound();
        if((*data)["status"] != 200){
            data_found_->datafoundSetError(true);
            return data_found_;
        }
        json result = (*data)["body"]["optionChain"]["result"];
        if(result[0].is_null()){
            data_found_->datafoundSetError(true);
            return data_found_;
        }
        if(!result[0].contains("quote")){
            data_found_->datafoundSetError(true);
            return data_found_;
        }
        json quote = result[0]["quote"]; 
        if (!quote.contains("regularMarketPrice") || !quote.contains("shortName") || !quote.contains("fullExchangeName")){
            data_found_->datafoundSetError(true);
            return data_found_;
        }
        double price{(*data)["body"]["optionChain"]["result"][0]["quote"]["regularMarketPrice"]};
        std::string name{(*data)["body"]["optionChain"]["result"][0]["quote"]["shortName"]};
        std::string exchange{(*data)["body"]["optionChain"]["result"][0]["quote"]["fullExchangeName"]};
        data_found_ = new DataFound(price, name, exchange);
        return data_found_;
    }

    DataFound* DataGetter::getData(std::string ticker){
        json* data_ = DataGetter::queryYahoo(ticker);        
        DataFound* data_found_ = DataGetter::parseData(data_);
        return data_found_;
    }

}