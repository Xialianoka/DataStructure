add_executable(SequentialListTest SequentialListTest.cc)

target_link_libraries(SequentialListTest
    GTest::gtest_main
    SequentialList
)

include(GoogleTest)

gtest_discover_tests(SequentialListTest)
