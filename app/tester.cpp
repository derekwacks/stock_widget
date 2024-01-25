#include "tester.hpp"
#include <cassert>

namespace trader{
    bool tester::testDataGetter(){
        DataGetter* dg = new DataGetter();

        double price = dg->getPrice();
        assert(price == 10.0);

        dg->getData();
        return true;
    }
}

int main(){
    trader::tester t;
    bool ret = t.testDataGetter();
    return 0;
}