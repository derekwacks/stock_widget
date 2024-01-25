add_executable(trader
    App.hpp
    App.cpp
    Window.hpp
    Window.cpp
    DataGetter.hpp
    DataGetter.cpp
)

add_executable(tester
    tester.hpp
    tester.cpp
)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 3b15fa82ea74739b574d705fea44959b58142eb8)
FetchContent_MakeAvailable(cpr)

target_link_libraries(trader wx::core wx::gl cpr::cpr)
target_link_libraries(tester cpr::cpr)
