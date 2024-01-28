#pragma once
#include "DataGetter.cpp"
#include "DataFound.cpp"

namespace trader{
    class tester{
    public:
        bool testQueryYahoo();
        bool testSpoofGetPrice();
        bool testParseDataWithValidData();
        bool testParseDataWithMissingResults();
        bool testParseDataWithMissingQuote();
    };
}