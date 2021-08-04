cmake_minimum_required(VERSION 3.18)
project(StringHelpers VERSION 0.1.0 LANGUAGES CXX)
set(CXX_STANDARD_REQUIRED 20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -fexceptions -g -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-g -fprofile-arcs -ftest-coverage")
include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.1)
FetchContent_MakeAvailable(Catch2)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)

add_library(StringHelpers STATIC  include/StringHelpers.h src/StringHelpers.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION} LINKER_LANGUAGE CXX)
target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE src)

 
enable_testing()
add_executable(StringHelpersTesting test/main.cpp)
target_link_libraries(StringHelpersTesting PRIVATE Catch2::Catch2)
include(CTest)
include(Catch)
catch_discover_tests(StringHelpersTesting)


