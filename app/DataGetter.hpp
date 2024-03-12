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
        DataFound* getData(const std::string& ticker) const;
    private:
        json* queryYahoo(const std::string& ticker, bool second_attempt = false) const;
        DataFound* parseData(json* data) const;
    };
}