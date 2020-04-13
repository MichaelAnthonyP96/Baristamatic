cmake_minimum_required(VERSION 3.1)

# set project metadata ########################################################
set(BARISTAMATIC_MAJOR_VERSION 1)
set(BARISTAMATIC_MINOR_VERSION 0)
set(BARISTAMATIC_PATCH_VERSION 0)
set(BARISTAMATIC_EXTRA_VERSION "" CACHE STRING "BARISTAMATIC extra version string")
set(BARISTAMATIC_VERSION "${BARISTAMATIC_MAJOR_VERSION}.${BARISTAMATIC_MINOR_VERSION}")
set(BARISTAMATIC_VERSION
        "${BARISTAMATIC_VERSION}.${BARISTAMATIC_PATCH_VERSION}${BARISTAMATIC_EXTRA_VERSION}")
set(BARISTAMATIC_AUTHOR "Michael Pope (lead)")
set(BARISTAMATIC_AUTHOR_EMAIL "michaelpope96@gmail.com")
set(BARISTAMATIC_DESCRIPTION "BARISTAMATIC coffee machine source code")
set(PROJECT_NAME "BARISTAMATIC version ${BARISTAMATIC_VERSION}")
project(${PROJECT_NAME} CXX)

# Set project defaults ########################################################
set(default_build_type "Release")
# creating code compilation database
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Options
option(BUILD_SHARED_LIBS "Build shared libraries." ON)
option(ENABLE_TESTS "Build with tests." ON)
option(BUILD_DOCUMENTATION "Create and install the HTML based API documentation (requires Doxygen)" OFF)

# Setting compile and link options #############################################

# Adding flags to Debug
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

# Compiled objects output paths
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Turn on default warnings as errors for GNU compilers.
if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    # Update if necessary
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wpedantic")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wold-style-cast \
    -Wnon-virtual-dtor -Wno-unused-parameter -Wno-invalid-offsetof")
endif()

mark_as_advanced(LIBRARY_OUTPUT_PATH EXECUTABLE_OUTPUT_PATH)

# set up RPATH
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

set(CMAKE_CXX_STANDARD 14)

include(GNUInstallDirs)

# TODO(mapope): separate coffeMachine and Drinks libraries
add_library(Drinks
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/Drink.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/CoffeeMachine.cpp
        )
target_include_directories(Drinks PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include>)

add_executable(runCoffeeMaker ${CMAKE_CURRENT_SOURCE_DIR}/Source/main.cpp)
target_link_libraries(runCoffeeMaker PUBLIC Drinks)


if(ENABLE_TESTS)
    enable_testing()
    add_subdirectory(testing)
endif()

# Export BARISTAMATIC as a CMake package
#install(FILES Lab_BARISTAMATICConfig.cmake
#        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/BARISTAMATIC)
#install(EXPORT BARISTAMATIC
#        NAMESPACE BARISTAMATIC::
#        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/BARISTAMATIC)

# Documentation
if(BUILD_DOCUMENTATION)
    find_package(Doxygen)
    if(NOT DOXYGEN_FOUND)
        message(FATAL_ERROR "Doxygen is needed to build the documentation.")
    endif()
    set(doxyfile_in ${CMAKE_CURRENT_SOURCE_DIR}/doc/BARISTAMATIC.cfg.in)
    set(doxyfile ${CMAKE_CURRENT_BINARY_DIR}/BARISTAMATIC.cfg)
    set(documentation ${CMAKE_CURRENT_BINARY_DIR}/docs)
    configure_file(${doxyfile_in} ${doxyfile} @ONLY)
    add_custom_command(OUTPUT ${documentation}
            COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
            MAIN_DEPENDENCY ${doxyfile} ${doxyfile_in}
            DEPENDS ${doxyfile} ${doxy_extra_files}
            COMMENT "Generating documentation")
    add_custom_target(docs ALL DEPENDS ${documentation})
    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/docs DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/Lab_BARISTAMATIC)
endif()