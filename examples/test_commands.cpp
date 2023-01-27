#include <SeaScanEcho/Command.hpp>
#include <SeaScanEcho/SeaScanEchoCommands.hpp>

#include <iostream>
#include <memory>
#include <vector>

int main() {
    std::vector<SeaScanEcho::Command> command = {
        SeaScanEcho::Commands::Boot,
        SeaScanEcho::Commands::Com9600,
        SeaScanEcho::Commands::Filter,
        SeaScanEcho::Commands::Info,
        SeaScanEcho::Commands::Lockout,
        SeaScanEcho::Commands::Marco,
        SeaScanEcho::Commands::Range,
        SeaScanEcho::Commands::Reset,
        SeaScanEcho::Commands::Sos,
        SeaScanEcho::Commands::Trigger,
        SeaScanEcho::Commands::Threshold,
        SeaScanEcho::Commands::Tx
    };

    std::cout << "\033[32m";
    for (const auto &c: command ){
        std::cout << c();
        for (auto car: c()) {
            std::cout << int(car) << " ";
        }
        std::cout << std::endl;
    }
}