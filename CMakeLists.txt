cmake_minimum_required(VERSION 3.15)
project(Baristamatic)

set(CMAKE_CXX_STANDARD 11)

add_library(Drinks
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/Drink.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/CoffeeMachine.cpp
        #${CMAKE_CURRENT_SOURCE_DIR}/Source/Coffee.cpp
        )
target_include_directories(Drinks PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

add_executable(runCoffeeMaker ${CMAKE_CURRENT_SOURCE_DIR}/Source/main.cpp)
target_link_libraries(runCoffeeMaker PUBLIC Drinks)