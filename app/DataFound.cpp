#include "DataFound.hpp"

namespace trader{
    DataFound::DataFound(double p, std::string n, std::string ex) : price_{p}, name_{n}, exchange_{ex}{
    }

    DataFound::~DataFound(){
    }

    double DataFound::price(){
        return price_; 
    }

    std::string DataFound::name(){
        return name_;
    }

    std::string DataFound::exchange(){
        return exchange_; 
    }
}