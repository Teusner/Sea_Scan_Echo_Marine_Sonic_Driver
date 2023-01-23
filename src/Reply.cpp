#include "Reply.hpp"

#include <algorithm>
#include <bitset>
#include <iterator>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

Reply::Reply(std::string_view sentence) {
    // Sentence storage
    s_ = sentence;
    
    // Splitting fields
    std::size_t last_pos = 1;
    std::string_view delimiters(",*");
    for (std::size_t i=last_pos; i<s_.size(); ++i) {
        if (delimiters.find(s_[i]) != delimiters.npos) {
            fields_.push_back(s_.substr(last_pos,i-last_pos));
            ++i;
            last_pos = i;
        }
    }
}

std::vector<std::string_view> Reply::Fields() const {
    return fields_;
}

bool Reply::Valid() const {
    if (s_.front() != '$' or s_.at(s_.size()-2) != '\r' or s_.back() != '\n' or !_checksum()) {
        return false;
    }
    return true;
}

bool Reply::_checksum() const {
    // Reading checksum
    uint16_t c;
    std::size_t nc = s_.find("*")+1;
    std::stringstream ss;
    ss << std::hex << s_.substr(nc, nc+1);
    ss >> c;
    std::bitset<8> check_sum(c);

    // Computing checksum
    std::bitset<8> b;
    std::string_view sv = s_.substr(1, s_.find("*")-1);
    for (const auto &c : sv) {
        b ^= std::bitset<8>(c);
    }
    return (check_sum == b);
}

