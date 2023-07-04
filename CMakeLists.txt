cmake_minimum_required(VERSION 3.5)

if (POLICY CMP0066)
    cmake_policy(SET CMP0066 NEW)
endif (POLICY CMP0066)

project(Parselo 
    VERSION 0.1.0 
    HOMEPAGE_URL https://www.terifel.com/parselo  
    LANGUAGES CXX
)

# Control where the static and shared libraries are built
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib/static")
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib/shared")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

find_package(Threads) 
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKmm REQUIRED IMPORTED_TARGET gtkmm-4.0>=gtkm-4.11.3)

set(SOURCES src/layouts/about.cc src/layouts/preferences.cc src/layouts/inquiry.cc src/main.cc src/top_level/app_window.cc)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE include ${GTKmm_INCLUDE_DIRS})
target_link_directories(${PROJECT_NAME} PRIVATE ${GTKmm_LIBRARY_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${GTKmm_LIBRARIES})

if(NOT ${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    target_link_directories(${PROJECT_NAME} PRIVATE Threads::Threads)
    message("Threads enabled")
endif()

# Testing
enable_testing()
if(CMAKE_TESTING_ENABLED)
    if (POLICY CMP0110)
        cmake_policy(SET CMP0110 NEW)
    endif (POLICY CMP0110)

    add_subdirectory(dependencies/gtest)
    add_subdirectory(test)
    add_test("Init TestParselo" TestParselo)
endif()

