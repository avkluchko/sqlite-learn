include_directories(../libs/googletest/googletest/include)

file(GLOB all_tests_SRC
        "*.cpp"
        "*.h"
        )

add_executable(all_tests ${all_tests_SRC})
target_link_libraries(all_tests gtest gtest_main)