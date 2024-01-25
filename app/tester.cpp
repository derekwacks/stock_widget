#include "tester.hpp"
#include <cassert>

namespace trader{

    bool tester::testGetPrice(){
        DataGetter* dg = new DataGetter();
        double price = dg->getPrice();
        assert(price == 10.0);
    }

    bool tester::testQueryYahoo(){
        DataGetter* dg = new DataGetter();
        json data = dg->queryYahoo();
        assert(data["status"] == 200);
        return true;
    }
}

int main(){
    trader::tester t;
    bool ret = t.testGetPrice();
    bool ret2 = t.testQueryYahoo();
    return 0;
}