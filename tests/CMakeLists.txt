find_package(gtest REQUIRED)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(SeqList_test SeqList_test.cc)

target_link_libraries(SeqList_test
    GTest::gtest_main
    SeqList
)

include(GoogleTest)

gtest_discover_tests(SeqList_test)
