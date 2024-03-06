# C++ Stock Widget

A simple stock widget that queries Yahoo Finance with an inputted ticker symbol. 

### Dependencies
- [wxWidgets](https://docs.wxwidgets.org/3.0/index.html)
- [Niels Lohmann's JSON for Modern C++](https://github.com/nlohmann/json)
- [CPR](https://github.com/libcpr/cpr), a libcurl wrapper

### Executables
- tester - runs testing functions
- trader - launches main app

### Notes
This software architecture is based on designs by Daniel Moreno at Brown University (in which App.cpp contains an instance of the AppWindow class, which in turn contains an instance of the ControlPanel class).

### To-do:
- Add error checking to Yahoo's API version (sometimes V7 in DataGetter::queryYahoo() returns error:{"code":"Unauthorized","description":"Invalid Crumb"} and V6 must be used)