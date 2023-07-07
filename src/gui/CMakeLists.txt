set(LIB_SOURCES ./sources/containers/about.cc ./sources/containers/preferences.cc ./sources/containers/inquiry.cc ./sources/top_level/app_window.cc)

set(LIBNAME AppGUI)

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

