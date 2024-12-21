#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

std::pair<std::string, std::string> split_string_on_space(const std::string& str) {
    std::string left, right;
    bool have_seen_space = false;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            if (!have_seen_space) {
                have_seen_space = true;
            }
            continue;
        }

        if (!have_seen_space) {
            left += str[i];
        } else {
            right += str[i];
        }
    }
    return std::move(std::make_pair(left, right));
}

int part_1() {
    std::ifstream filein("Input.txt");
    std::vector<int> left, right;

    for (std::string line; std::getline(filein, line);) {
        std::pair<std::string, std::string> nums = split_string_on_space(line);
        left.push_back(std::stoi(nums.first));
        right.push_back(std::stoi(nums.second));
    }

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    int answer = 0;
    for (int i = 0; i < left.size(); i++) {
        answer += std::max(left[i], right[i]) - std::min(left[i], right[i]);
    }
    return answer;
}

int part_2() {
    std::ifstream filein("Input.txt");
    std::vector<int> left, right;

    for (std::string line; std::getline(filein, line);) {
        std::pair<std::string, std::string> nums = split_string_on_space(line);
        left.push_back(std::stoi(nums.first));
        right.push_back(std::stoi(nums.second));
    }

    std::unordered_map<int, int> occurences;
    for (const int& i : left) {
        if (occurences.find(i) != occurences.end()) continue;
        for (const int& j : right) {
            if (i == j) {
                occurences[i]++;
            }
        }
    }

    int answer = 0;
    for (const auto& num : occurences) {
        answer += num.first * num.second;
    }
    return answer;
}

int main(int argc, char** argv) {
    // https://adventofcode.com/2024/day/1
    std::cout << "Part 1: " << part_1() << "\n";
    std::cout << "Part 2: " << part_2() << "\n";
    return 0;
}