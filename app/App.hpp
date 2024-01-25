#pragma once
#include <wx/app.h>
#include "Window.hpp"
#include "DataGetter.hpp"

namespace trader{
    class App : public wxApp{
        AppWindow* window_;
        DataGetter* datagetter_;

    public:
        App();
        ~App();
        AppWindow& window();
        DataGetter& getter();
        virtual bool OnInit() override;
        void test();
    };
    
    wxDECLARE_APP(App);
}