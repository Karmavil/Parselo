set(TEST_EXE TestParselo)
set(TEST_SOURCES unit_tests/main_window.cc)

add_executable(${TEST_EXE} ${TEST_SOURCES})
target_include_directories(${TEST_EXE} PRIVATE ../include GoogleTest ${GTKmm_INCLUDE_DIRS})
target_link_directories(${TEST_EXE} PRIVATE ${GTKmm_LIBRARY_DIRS})
target_link_libraries(${TEST_EXE} PRIVATE gtest ${GTKmm_LIBRARIES})

