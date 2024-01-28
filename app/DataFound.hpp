#pragma once
#include <string>

namespace trader{
    class DataFound{
    public:
        DataFound(double p = 0.0, std::string n = "name", std::string ex = "exchange", bool error_ = false);
        ~DataFound();
        double price() const;
        std::string name() const;
        std::string exchange() const;
        bool datafoundGetError() const;
        void datafoundSetError(const bool err);
    private:
        double price_;
        std::string name_;
        std::string exchange_;
        bool error_;
    };
}