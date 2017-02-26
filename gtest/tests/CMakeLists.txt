project(tests)

add_executable(run_tests
        main.cpp 001_two_sum.cpp 002_add_two_nums.cpp 003_longest_substr.cpp 004_median_of_two_sorted_array.cpp 005_longest_palindromic_substr.cpp 006_zigzag_conversion.cpp)

target_link_libraries(run_tests gtest gtest_main)
target_link_libraries(run_tests Main)