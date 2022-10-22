cmake_minimum_required(VERSION 3.16)
project(cat LANGUAGES CXX)

find_package(
    nlohmann_json 3.11.2 REQUIRED
)

add_subdirectory(
    src/libs/cpr
)

add_compile_definitions(
    src/libs/cpr
)

add_executable(${PROJECT_NAME}
    src/main.cpp

    src/modules/getImage.cpp
    src/modules/getImage.h

    src/modules/clear.cpp
    src/modules/clear.h
)

target_link_libraries(${PROJECT_NAME}
    cpr
)

target_include_directories(${PROJECT_NAME} PRIVATE
    src/libs/cpr/include
)