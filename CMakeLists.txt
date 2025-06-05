cmake_minimum_required(VERSION 3.10)
project(DataStructures)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# data_structures
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(DataStructures
    src/main.cc
)

add_library(SequentialList INTERFACE)
target_include_directories(SequentialList INTERFACE include)

target_link_libraries(DataStructures SequentialList)

# data_structures_test
enable_testing()
add_subdirectory(tests)
