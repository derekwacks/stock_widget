#pragma once
#include <nlohmann/json.hpp>
using json = nlohmann::json;

namespace trader{
    class DataGetter{

        friend class tester;

    public:
        DataGetter();
        ~DataGetter();
        double getPrice();
        double spoofGetPrice();
    private:
        json* queryYahoo();
        double parseData(json* data);
    };
}