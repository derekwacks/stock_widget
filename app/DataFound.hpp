#pragma once
#include <string>

namespace trader{
    class DataFound{
    public:
        DataFound(double p = 0.0, std::string n = "name", std::string ex = "exchange", bool error_ = false);
        ~DataFound();
        double price();
        std::string name();
        std::string exchange();
        bool datafoundGetError();
        void datafoundSetError(bool err);
    private:
        double price_; 
        std::string name_;
        std::string exchange_;
        bool error_;
    };
}