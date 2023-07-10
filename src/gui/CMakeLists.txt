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


set(LIB_SOURCES ./sources/components/about.cc ./sources/components/preferences.cc ./sources/components/decobutton.cc ./sources/components/inquiry.cc ./sources/windows/app_window.cc)

set(LIBNAME parselo_interface)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_library(${LIBNAME} STATIC ${LIB_SOURCES})
target_include_directories(${LIBNAME} PUBLIC ./headers ${GTKmm_INCLUDE_DIRS})
target_link_directories(${LIBNAME} PUBLIC ${GTKmm_LIBRARY_DIRS})
target_link_libraries(${LIBNAME} PUBLIC ${GTKmm_LIBRARIES})

if(NOT ${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    target_link_directories(${LIBNAME} PUBLIC Threads::Threads)
    message("Threads enabled")
else()
    target_compile_definitions(${LIBNAME} PRIVATE DEBUG=1)
endif()

