#pragma once
#include <wx/app.h>
#include "Window.hpp"

namespace trader{
    class App : public wxApp{
        AppWindow* window_;

    public:
        App();
        ~App();
        AppWindow& window();
        virtual bool OnInit() override;
        void test();
    };
    
    wxDECLARE_APP(App);
}