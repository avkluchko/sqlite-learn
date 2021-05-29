include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/master.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB all_tests_SRC
        "*.cpp"
        "*.h"
#        "../src/filename.cpp"
        )

add_executable(all_tests ${all_tests_SRC})
target_link_libraries(all_tests gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(all_tests)