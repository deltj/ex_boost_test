cmake_minimum_required(VERSION 2.8)

project(ex_boost_test)
enable_testing()

find_package(Boost 1.53 REQUIRED COMPONENTS unit_test_framework)

add_executable(StatSet_test StatSet_test.cpp)
target_link_libraries(StatSet_test ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_test(StatSet_test StatSet_test)
