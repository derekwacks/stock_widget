#include "tester.hpp"
#include <cassert>

namespace trader{

    bool tester::testSpoofGetPrice(){
        DataGetter* dg = new DataGetter();
        double price = dg->spoofGetPrice();
        assert(price == 10.0);
        return true;
    }

    bool tester::testQueryYahoo(){
        DataGetter* dg = new DataGetter();
        json* data = dg->queryYahoo();
        assert((*data)["status"] == 200);
        std::cout << (*data)["status"] << std::endl;
        //delete[] data;
        /*
        json data = dg->queryYahoo();
        assert(data["status"] == 200);
        std::cout << data["status"] << std::endl;
        */
        double price = dg->parseData(data);
        std::cout << "Price = " << price << std::endl; 
        return true;
    }

    bool tester::testGetPrice(){
        DataGetter* dg = new DataGetter();
        double price = dg->getPrice();
        assert(price != 10.0); // ex: 187.4
        return true;
    }
}

int main(){
    trader::tester t;
    bool ret = t.testGetPrice();
    bool ret2 = t.testQueryYahoo();
    return 0;
}