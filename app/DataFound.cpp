#include "DataFound.hpp"

namespace trader{
    DataFound::DataFound(double p, std::string n, std::string ex, bool er) : price_{p}, name_{n}, exchange_{ex}, error_{er}{
    }

    DataFound::~DataFound(){
    }

    double DataFound::price() const{
        return price_; 
    }

    std::string DataFound::name() const{
        return name_;
    }

    std::string DataFound::exchange() const{
        return exchange_; 
    }

    bool DataFound::datafoundGetError() const{
        return error_; 
    }

    void DataFound::datafoundSetError(const bool err){
        error_ = err; 
    }
}