#include <NMEAParser.hpp>

#include <iostream>
#include <vector>
#include <string_view>

int main() {
    std::string_view sv("$MSALT,INFO,1,6,0,5ECHO2-00-1001*54\r\n");
    // std::string_view sv("$MSALT,COM,9600*09\r\n");
    // std::string_view sv("$MSALT,BOOT*7D\r\n");
    NMEAParser s(sv);

    if (s.Valid()) {
        std::cout << "\033[32m";
    } else {
        std::cout << "\033[31m";
    }

    // Showing fields
    std::vector<std::string_view> fields = s.Fields();
    std::size_t i=0;
    for (const auto &f: fields) {
        std::cout << f;
        if (++i < fields.size()) {
            std::cout << " | ";
        }
    }
    std::cout << std::endl;
}