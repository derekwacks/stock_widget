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
        // If ticker=="AAPL"
        std::string ticker{"AAPL"};
        // When querying Yahoo
        json* data = dg->queryYahoo(ticker);
        // Then status==200
        assert((*data)["status"] == 200);

        ticker = "asdfasdf";
        data = dg->queryYahoo(ticker);
        assert((*data)["status"] == 404);

        ticker = "";
        data = dg->queryYahoo(ticker);
        assert((*data)["status"] == 404);
        return true;
    }


    bool tester::testParseDataWithValidData(){
        DataGetter* dg = new DataGetter();
        // If response body == ... 
        json valid_body = json::parse(R"({
            "optionChain" : {
                "result" : [
                   {
                        "quote": {
                            "regularMarketPrice" : 1.0,
                            "shortName" : "EarthCo",
                            "fullExchangeName" : "GetYourStoinksHere"
                        }
                   } 
                ]
            }
        })");
        json* response = new json({
            {"status", 200},
            {"header", "content-type"},
            {"body", valid_body}
        });
        // When we try to parse it
        DataFound* result = dg->parseData(response);
        // Then price, name, and exchange should equal these values
        double price{result->price()};
        std::string name{result->name()};
        std::string exchange{result->exchange()};
        assert(price == 1.0);
        assert(name == "EarthCo");
        assert(exchange == "GetYourStoinksHere");
        return true; 
    }

    bool tester::testParseDataWithMissingResults(){
        DataGetter* dg = new DataGetter();
        // If response body == ... 
        json invalid_body = json::parse(R"({
            "optionChain" : {
                "result" : [
                ]
            }
        })");
        json* response = new json({
            {"status", 200},
            {"header", "content-type"},
            {"body", invalid_body}
        });
        // When we try to parse it
        DataFound* result = dg->parseData(response);
        // Then price, name, and exchange should equal these values
        double price{result->price()};
        std::string name{result->name()};
        std::string exchange{result->exchange()};
        assert(price == 0);
        assert(name == "name");
        assert(exchange == "exchange");
        return true; 
    }

    bool tester::testParseDataWithMissingQuote(){
        DataGetter* dg = new DataGetter();
        // If response body == ... 
        json invalid_body = json::parse(R"({
            "optionChain" : {
                "result" : [
                   {
                        "notAQuote": {
                        }
                   } 
                ]
            }
        })");
        json* response = new json({
            {"status", 200},
            {"header", "content-type"},
            {"body", invalid_body}
        });
        // When we try to parse it
        DataFound* result = dg->parseData(response);
        // Then price, name, and exchange should equal these values
        double price{result->price()};
        std::string name{result->name()};
        std::string exchange{result->exchange()};
        assert(price == 0);
        assert(name == "name");
        assert(exchange == "exchange");
        return true; 
    }

    // other functions to test
    // responseValid(json* data)
    // getData(std::string ticker)
}

int main(){
    std::cout << "Testing\n";
    trader::tester t;
    //bool ret = t.testQueryYahoo();
    //bool ret2 = t.testParseDataWithValidData();
    //bool ret3 = t.testParseDataWithMissingResults();
    bool ret4 = t.testParseDataWithMissingQuote();
    std::cout << "Testing complete!\n";
    return 0;
}