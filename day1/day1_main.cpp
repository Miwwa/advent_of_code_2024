#include "day1.h"

#include <fstream>
#include <iostream>

int main(const int argc, const char* argv[]) {
    std::string input_file = "input.txt";
    if (argc >= 2) {
        input_file = argv[1];
    }
    std::ifstream f(input_file);
    if (!f.is_open()) {
        std::cerr << "Error opening file " << input_file << std::endl;
        return 1;
    }
    const std::string content((std::istreambuf_iterator(f)), std::istreambuf_iterator<char>());

    const auto part1_result = solve_part1(content);
    const auto part2_result = solve_part2(content);

    std::cout << "Part 1: " << part1_result << '\n';
    std::cout << "Part 2: " << part2_result << '\n';
    return 0;
}
