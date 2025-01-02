#include "day1.h"
#include <gtest/gtest.h>

std::string input_string = R"(
3   4
4   3
2   5
1   3
3   9
3   3
)";

TEST(Day1, Part1) {
    const auto result = solve_part1(input_string);
    EXPECT_EQ(result, 11);
}

TEST(Day1, Part2) {
    const auto result = solve_part2(input_string);
    EXPECT_EQ(result, 31);
}
