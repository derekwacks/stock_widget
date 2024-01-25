add_executable(trader
    App.hpp
    App.cpp
    Window.hpp
    Window.cpp
    DataGetter.hpp
    DataGetter.cpp
    ControlPanel.hpp
    ControlPanel.cpp
    DataFound.hpp
    DataFound.cpp
)

add_executable(tester
    tester.hpp
    tester.cpp
)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 3b15fa82ea74739b574d705fea44959b58142eb8)
FetchContent_MakeAvailable(cpr)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

target_link_libraries(trader wx::core wx::gl cpr::cpr nlohmann_json::nlohmann_json)
target_link_libraries(tester cpr::cpr nlohmann_json::nlohmann_json)
