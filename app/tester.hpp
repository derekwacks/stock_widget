#pragma once
#include "DataGetter.cpp"
#include "DataFound.cpp"

namespace trader{
    class tester{
    public:
        bool testQueryYahoo();
        bool testParseDataWithValidData();
        bool testParseDataWithMissingResults();
        bool testParseDataWithMissingQuote();
    };
}