#include "day2.h"

#include <cmath>
#include <sstream>
#include <vector>

bool is_valid(const std::vector<int32_t>& numbers) {
    const bool direction = std::signbit(numbers[1] - numbers[0]);
    for (size_t i = 1; i < numbers.size(); i++) {
        if (direction != std::signbit(numbers[i] - numbers[i - 1])) {
            return false;
        }
        const int32_t distance = std::abs(numbers[i] - numbers[i - 1]);
        if (distance == 0 || distance > 3) {
            return false;
        }
    }
    return true;
}

int64_t solve_part1(const std::string& input) {
    int64_t sum = 0;
    std::istringstream input_stream(input);
    for (std::string line; std::getline(input_stream, line);) {
        if (line.empty()) {
            continue;
        }
        std::vector<int32_t> numbers;
        std::istringstream line_stream(line);
        int32_t num;
        while (line_stream >> num) {
            numbers.push_back(num);
        }

        if (is_valid(numbers)) {
            sum++;
        }
    }
    return sum;
}

int64_t solve_part2(const std::string& input) {
    int64_t sum = 0;
    std::istringstream input_stream(input);
    for (std::string line; std::getline(input_stream, line);) {
        if (line.empty()) {
            continue;
        }
        std::vector<int32_t> numbers;
        std::istringstream line_stream(line);
        int32_t num;
        while (line_stream >> num) {
            numbers.push_back(num);
        }

        if (is_valid(numbers)) {
            sum++;
        } else {
            bool probably_valid = false;
            for (int i = 0; i < numbers.size(); i++) {
                std::vector<int32_t> modified_numbers = numbers;
                modified_numbers.erase(modified_numbers.begin() + i);
                if (is_valid(modified_numbers)) {
                    probably_valid = true;
                    break;
                }
            }
            if (probably_valid) {
                sum++;
            }
        }
    }
    return sum;
}
