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

set(TEST_EXE TestParselo)
set(TEST_SOURCES unit_tests/main_window.cc)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(${TEST_EXE} ${TEST_SOURCES})
target_include_directories(${TEST_EXE} PRIVATE src/gui/headers GoogleTest ${GTKmm_INCLUDE_DIRS})
target_link_directories(${TEST_EXE} PRIVATE ${GTKmm_LIBRARY_DIRS})
target_link_libraries(${TEST_EXE} PRIVATE parselo_interface gtest ${GTKmm_LIBRARIES})

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    target_compile_definitions(${TEST_EXE} PRIVATE DEBUG=1)
endif() 
