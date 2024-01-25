#pragma once
#include <nlohmann/json.hpp>
using json = nlohmann::json;
#include "DataFound.hpp"

namespace trader{
    class DataGetter{

        friend class tester;

    public:
        DataGetter();
        ~DataGetter();
        DataFound* getData(std::string ticker);
        double spoofGetPrice();
    private:
        json* queryYahoo(std::string ticker);
        bool responseValid(json* data);
        DataFound* parseData(json* data);
    };
}