cmake_minimum_required(VERSION 3.20)

project(Trader)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(/permissive-)
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(third-party)
add_subdirectory(app)