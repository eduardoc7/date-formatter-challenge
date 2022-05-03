#pragma once

#include <iostream>
#include <sstream>
#include <vector>

class Utils {
public:
    static auto rsortDates(const std::string &date1, const std::string &date2) -> std::pair<std::string, std::string>;
    static auto transformDate(const std::string &date) -> std::string;
    static auto sumIntegers(std::vector<std::uint64_t> vec) -> std::uint64_t;
    static auto verificaPalindromo(std::string palavra) -> bool;

    static auto split(const std::string &value, const std::string &delimiter) -> std::vector<std::string> {
        size_t pos_start{0}, pos_end, delimiter_length{delimiter.length()};
        std::string token;
        std::vector<std::string> result;

        while ((pos_end = value.find(delimiter, pos_start)) != std::string::npos) {
            token = value.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + delimiter_length;
            result.push_back(token);
        }

        result.push_back(value.substr(pos_start));
        return result;
    }

    static auto validateEntries(const std::string &date1, const std::string &date2) -> bool {
        if(date1.empty() || date2.empty()) {
            return false;
        }
        if(date1.length() != 10 || date2.length() != 8) {
            return false;
        }

        return true;
    }

    Utils() = default;
    ~Utils() = default;
};

