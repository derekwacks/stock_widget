#pragma once
#include <string>

namespace trader{
    class DataFound{
    public:
        DataFound(double p = 0.0, std::string n = "name", std::string ex = "exchange");
        ~DataFound();
        double price();
        std::string name();
        std::string exchange();
    private:
        double price_; 
        std::string name_;
        std::string exchange_;
    };
}