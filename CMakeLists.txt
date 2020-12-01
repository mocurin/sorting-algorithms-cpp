cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

include("${CMAKE_CURRENT_SOURCE_DIR}/tools/gate/cmake/HunterGate.cmake")

HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.23.254.tar.gz"
    SHA1 "017e688b9848c1f695303e8cfe9f35d40e154112"
)

project(ads)

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

add_library(lib STATIC
  ${CMAKE_CURRENT_SOURCE_DIR}/sources/library.cpp
)
target_include_directories(lib PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/headers/
)

add_library(misc STATIC
  ${CMAKE_CURRENT_SOURCE_DIR}/sources/misc.cpp
)
target_include_directories(misc PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/headers/
)

add_executable(tests
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test.cpp
)
target_include_directories(tests PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/headers/
)

target_link_libraries(tests GTest::gtest_main lib misc)

enable_testing()
add_test(NAME unit_tests COMMAND tests)
