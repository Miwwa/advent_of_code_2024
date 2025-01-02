#include "day1.h"

#include <algorithm>
#include <cstdint>
#include <sstream>
#include <unordered_map>
#include <vector>

struct InputData {
    std::vector<int> left_column;
    std::vector<int> right_column;
};

InputData parse_input(const std::string& input) {
    std::vector<int> left_column;
    std::vector<int> right_column;

    int a, b;
    std::istringstream input_stream(input);
    while (input_stream >> a >> b) {
        left_column.push_back(a);
        right_column.push_back(b);
    }
    return {left_column, right_column};
}

int64_t solve_part1(const std::string& input) {
    auto [left_column, right_column] = parse_input(input);
    std::ranges::sort(left_column);
    std::ranges::sort(right_column);
    int64_t sum = 0;
    for (size_t i = 0; i < left_column.size(); i++) {
        sum += std::abs(left_column[i] - right_column[i]);
    }
    return sum;
}

int64_t solve_part2(const std::string& input) {
    auto [left_column, right_column] = parse_input(input);
    int64_t sum = 0;
    std::unordered_map<int, int> index;
    for (int value : right_column) {
        if (index.contains(value)) {
            index[value]++;
        } else {
            index[value] = 1;
        }
    }
    for (int value : left_column) {
        if (index.contains(value)) {
            sum += value * index[value];
        }
    }
    return sum;
}
