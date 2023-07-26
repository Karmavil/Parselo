#  Parselo - Query the journal about your progam.
#  Copyright (C) 2023 Federico Gallo Herosa. https://www.terifel.com
#  Find the full description of the license in the following URL:
#  https://github.com/Karmavil/Parselo/blob/main/LICENSE
#
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License along
#  with this program; if not, write to the Free Software Foundation, Inc.,
#  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.


cmake_minimum_required(VERSION 3.5)

if (POLICY CMP0066)
    cmake_policy(SET CMP0066 NEW)
endif (POLICY CMP0066)

project(Parselo 
    VERSION 0.1.0 
    HOMEPAGE_URL https://www.terifel.com/parselo  
    LANGUAGES C CXX
)

# Control where the static and shared libraries are built
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

find_package(Threads) 
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKmm REQUIRED gtkmm-4.0)

set(SOURCES src/components/contextual_menu.cc src/components/about.cc src/components/preferences.cc src/components/toolbar.cc src/components/headerbar_menu.cc src/components/starter.cc src/components/inquiry.cc src/components/buttons/decobutton.cc src/parselo.c src/app.cc src/windows/appwindow.cc src/main.cc)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE include/ ${GTKmm_INCLUDE_DIRS})
target_link_directories(${PROJECT_NAME} PRIVATE ${GTKmm_LIBRARY_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${GTKmm_LIBRARIES})
target_compile_definitions(${PROJECT_NAME} PRIVATE VERSION="${CMAKE_PROJECT_VERSION}")

# Testing
if(BUILD_TESTING)
    if (POLICY CMP0110)
        cmake_policy(SET CMP0110 NEW)
    endif (POLICY CMP0110)

    set(TESTNAME TestParselo)
    set(TSRC src/components/contextual_menu.cc src/components/about.cc src/components/preferences.cc src/components/toolbar.cc src/components/headerbar_menu.cc src/components/starter.cc src/components/inquiry.cc src/components/buttons/decobutton.cc src/parselo.c src/app.cc src/windows/appwindow.cc)
    set(TEST_SOURCES test/unit_tests/main.cc ${TSRC})

    add_subdirectory(dependencies/gtest)

    add_executable(${TESTNAME} ${TEST_SOURCES})
    target_include_directories(${TESTNAME} PRIVATE include/ ${GTKmm_INCLUDE_DIRS})
    target_link_directories(${TESTNAME} PRIVATE ${GTKmm_LIBRARY_DIRS})
    target_link_libraries(${TESTNAME} PRIVATE gtest ${GTKmm_LIBRARIES})
    target_compile_definitions(${TESTNAME} PRIVATE VERSION="${CMAKE_PROJECT_VERSION}")
endif()
