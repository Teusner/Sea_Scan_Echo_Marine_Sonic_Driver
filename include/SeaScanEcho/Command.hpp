#pragma once

#include <string>
#include <vector>

namespace SeaScanEcho {
    class Command {
        public:
            Command(std::initializer_list<std::string> c) : command_(c) {};

            // Command getter
            std::string operator()() const;

        private:
            // Command vector which is filled by sub commands
            std::vector<std::string> command_;
    };
} // namespace SeaScanEcho
