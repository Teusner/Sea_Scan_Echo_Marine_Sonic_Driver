#include <Command.hpp>
#include <Reply.hpp>
#include <SeaScanEchoCommands.hpp>

#include <iostream>
#include <memory>
#include <vector>

int main() {
    std::vector<Command> command = {
        Boot,
        Com9600,
        Filter,
        Info,
        Lockout,
        Marco,
        Range,
        Reset,
        Sos,
        Trigger,
        Threshold,
        Tx
    };

    std::cout << "\033[32m";
    for (const auto &c: command ){
        std::cout << c();
    }
}