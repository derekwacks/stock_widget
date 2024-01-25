#pragma once

namespace trader{
    class DataGetter{
    public:
        DataGetter();
        ~DataGetter();
        double getPrice();
        int getData();
    };
}