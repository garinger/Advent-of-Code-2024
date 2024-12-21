#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<int> split_string_on_spaces(std::string str) {
    std::vector<int> nums;
    std::string curr;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ' || i == str.size() - 1) {
            if (i == str.size() - 1) curr += str[i];
            nums.push_back(std::stoi(curr));
            curr = "";
        } else {
            curr += str[i];
        }
    }
    return nums;
}

int part_1() {
    std::ifstream filein("Input.txt");
    std::vector<std::vector<int>> reports;

    for (std::string line; std::getline(filein, line);) {
        reports.emplace_back(split_string_on_spaces(line));
    }

    int num_of_safe_reports = 0;
    for (const auto& report : reports) {
        bool increasing = report[1] - report[0] > 0;
        bool safe = true;
        for (int i = 0; i < report.size() - 1; i++) {
            int diff = report[i + 1] - report[i];
            int delta = abs(diff);
            if (increasing && diff < 0
            || !increasing && diff >= 0
            || delta < 1 || delta > 3) {
                safe = false;
                break;
            }
        }
        if (safe) num_of_safe_reports++;
    }
    return num_of_safe_reports;
}

int part_2() {
    return 0;
}

int main(int argc, char** argv) {
    // https://adventofcode.com/2024/day/2
    std::cout << "Part 1: " << part_1() << "\n";
    std::cout << "Part 2: " << part_2() << "\n";
    return 0;
}