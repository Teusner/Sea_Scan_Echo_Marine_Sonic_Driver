#include <Reply.hpp>

#include <iostream>
#include <vector>
#include <string_view>

int main() {
    std::vector<std::string_view> replies = {
        "$MSALT,COM,9600*09\r\n",
        "$MSALT,BOOT*7D\r\n",
        
        "$MSALT,ACK*22\r\n",
        "$MSALT,NACK*6C\r\n",
        "$MSALT,POLO*77\r\n",
        "$MSALT,INFO,1,6,0,5ECHO2-00-1001*54\r\n",
        "$MSALT,DATA,16.751,16.453*7A\r\n"
    };

    for (const auto rep: replies) {
        Reply s(rep);

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
}