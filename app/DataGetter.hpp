#pragma once
#include <nlohmann/json.hpp>
using json = nlohmann::json;

namespace trader{
    class DataGetter{
    public:
        DataGetter();
        ~DataGetter();
        double getPrice();
        json queryYahoo();
    };
}