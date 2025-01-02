#include <gtest/gtest.h>
#include "day2.h"

std::string input_string = R"(
7 6 4 2 1
1 2 7 8 9
9 7 6 2 1
1 3 2 4 5
8 6 4 4 1
1 3 6 7 9
)";

TEST(Day1, Part1) {
    const auto result = solve_part1(input_string);
    EXPECT_EQ(result, 2);
}

TEST(Day1, Part2) {
    const auto result = solve_part2(input_string);
    EXPECT_EQ(result, 4);
}
