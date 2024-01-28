#include "DataFound.hpp"

namespace trader{
    DataFound::DataFound(double p, std::string n, std::string ex, bool er) : price_{p}, name_{n}, exchange_{ex}, error_{er}{
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

    bool DataFound::datafoundGetError(){
        return error_; 
    }

    void DataFound::datafoundSetError(bool err){
        error_ = err; 
    }
}