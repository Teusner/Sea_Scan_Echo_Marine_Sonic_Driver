#pragma once

#include "SeaScanEcho/Command.hpp"

namespace SeaScanEcho {
    namespace Commands {
        Command Boot = Command({"MSALT", "BOOT"});
        Command Com9600 = Command({"MSALT", "COM", "9600"});
        Command Com115200 = Command({"MSALT", "COM", "115200"});
        Command Filter = Command({"MSALT", "FILTER", "10"});
        Command Info = Command({"MSALT", "INFO"});
        Command Lockout = Command({"MSALT", "LOCKOUT", "1.0"});
        Command Marco = Command({"MSALT", "MARCO"});
        Command Range = Command({"MSALT", "RANGE", "100.0"});
        Command Reset = Command({"MSALT", "RESET"});
        Command Sos = Command({"MSALT", "SOS", "1480.0"});
        Command Trigger = Command({"MSALT", "TRIGGER", "3"});
        Command Threshold = Command({"MSALT", "THRESHOLD", "50"});
        Command Tx = Command({"MSALT", "TX", "0"});
    } // namespace Command
} // namespace SeaScanEcho