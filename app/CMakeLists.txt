
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
    LoginPanel.hpp
    LoginPanel.cpp
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


find_package(ZLIB REQUIRED)
add_executable(cognito_tester Cognito_auth.cpp)

include(ExternalProject)
ExternalProject_Add(Trader
    GIT_REPOSITORY    https://github.com/aws/aws-sdk-cpp.git
    GIT_TAG           1.11.286
    LIST_SEPARATOR    "|"
    CMAKE_ARGS       -DBUILD_SHARED_LIBS=OFF 
                     -DBUILD_ONLY=cognito-identity|cognito-idp
    BUILD_ALWAYS      TRUE
    TEST_COMMAND      ""
)

set(CMAKE_PREFIX_PATH "../build/app/Trader-prefix") #src/Trader-build/generated/src/aws-cpp-sdk-cognito-identity")
set(SERVICE_COMPONENTS cognito-identity cognito-idp)
#set(SERVICE_COMPONENTS cognito-idp)
find_package(AWSSDK REQUIRED COMPONENTS ${SERVICE_COMPONENTS})
target_link_libraries(cognito_tester ${AWSSDK_LINK_LIBRARIES} aws-cpp-sdk-core aws-cpp-sdk-cognito-identity aws-cpp-sdk-cognito-idp)

