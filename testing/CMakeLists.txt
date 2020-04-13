cmake_minimum_required(VERSION 3.1)

#adding gtest subdir with its own cmake file
ADD_SUBDIRECTORY(googletest-master)
#include gtest library. gtest_SOURCE_DIR is available from subdir addition
INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR}/include/gtest ${gtest_SOURCE_DIR})

set ( TEST_ENV_PATH_OPTIONS "PATH=${CMAKE_CURRENT_BINARY_DIR}/../bin:$ENV{PATH}")
#set ( TEST_ENV_LD_OPTIONS
#        "LD_LIBRARY_PATH=${CMAKE_CURRENT_BINARY_DIR}/lib:\
#${CMAKE_CURRENT_BINARY_DIR}/../lib")

# --------------------------------Testing Executables -------------------------
add_executable(runMakeDrinksTest ${CMAKE_CURRENT_SOURCE_DIR}/testMakeDrink.cpp)
target_link_libraries(runMakeDrinksTest PUBLIC gtest gtest_main Drinks CoffeeMachine)
target_include_directories(runMakeDrinksTest
        PUBLIC
        $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/Include>)

add_executable(runProcessInputTest ${CMAKE_CURRENT_SOURCE_DIR}/testProcessInput.cpp)
target_link_libraries(runProcessInputTest PUBLIC gtest gtest_main Drinks CoffeeMachine)
target_include_directories(runProcessInputTest
        PUBLIC
        $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/Include>)

add_executable(runDrinkTest ${CMAKE_CURRENT_SOURCE_DIR}/testDrink.cpp)
target_link_libraries(runDrinkTest PUBLIC gtest gtest_main Drinks CoffeeMachine)
target_include_directories(runDrinkTest
        PUBLIC
        $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/Include>)

# --------------------------------Add tests to CTest --------------------------
add_test(NAME makeDrinks
        COMMAND ${PROJECT_BINARY_DIR}/bin/runMakeDrinksTest
        WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/testing)

add_test(NAME processInput
        COMMAND ${PROJECT_BINARY_DIR}/bin/runProcessInputTest
        WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/testing)

add_test(NAME drinkClass
        COMMAND ${PROJECT_BINARY_DIR}/bin/runDrinkTest
        WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/testing)
