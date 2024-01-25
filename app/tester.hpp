#pragma once
#include "DataGetter.cpp"

namespace trader{
    class tester{
    public:
        bool testGetPrice();
        bool testQueryYahoo();
        bool testSpoofGetPrice();
    };
}