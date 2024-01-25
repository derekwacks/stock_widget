add_executable(trader
    App.hpp
    App.cpp
    Window.hpp
    Window.cpp
)
target_link_libraries(trader wx::core wx::gl)