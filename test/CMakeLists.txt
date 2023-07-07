set(TEST_EXE TestParselo)
set(TEST_SOURCES unit_tests/main_window.cc)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(${TEST_EXE} ${TEST_SOURCES})
target_include_directories(${TEST_EXE} PRIVATE src/gui/headers GoogleTest ${GTKmm_INCLUDE_DIRS})
target_link_directories(${TEST_EXE} PRIVATE ${GTKmm_LIBRARY_DIRS})
target_link_libraries(${TEST_EXE} PRIVATE AppGUI gtest ${GTKmm_LIBRARIES})

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    target_compile_definitions(${TEST_EXE} PRIVATE DEBUG=1)
endif() 
