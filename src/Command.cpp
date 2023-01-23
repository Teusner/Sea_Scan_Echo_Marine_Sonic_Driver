#include "SeaScanEcho/Command.hpp"

#include <algorithm>
#include <bitset>
#include <iterator>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

namespace SeaScanEcho {
    std::string Command::operator()() const {
        // Returned command
        std::stringstream command;
        command << "$";

        // Computing checksum
        std::bitset<8> b;
        for (auto ic=command_.begin(); ic<command_.end(); ++ic) {
            for (const auto c: *ic) {
                b ^= std::bitset<8>(c);
                command << c;
            }
            if (ic < command_.end()-1) {
                b ^= std::bitset<8>(',');
                command << ",";
            }
        }

        command << "*" << std::hex << std::setfill('0') << std::setw(2) << std::uppercase << b.to_ullong();
        command << "\r\n";
        return command.str();
    }
} // namespace SeaScanEcho