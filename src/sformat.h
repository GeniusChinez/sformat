#pragma once

#include <string>
#include <vector>
#include <initializer_list>
#include <sstream>

namespace gc {
    template <typename ...Args>
    [[nodiscard]] 
    std::string format(std::string_view fmt, Args&&... args) {
        std::ostringstream ss;
        auto format_iterator = fmt.begin();
 
        (void)std::initializer_list<int>{([&](const auto& arg) {
            while (format_iterator != std::end(fmt)) {
                if (*format_iterator == '\\') {
                    if (*++format_iterator == '%') {
                        ss << "%";
                        format_iterator++;
                    }
                    else {
                        ss << '\\';
                    }
                }
                else if (*format_iterator == '%') {
                    format_iterator++;
                    ss << std::boolalpha << arg;
                    return;
                }
                else {
                    ss << *format_iterator++;
                }
            }
        }(args), 0)...};

        while (format_iterator != std::end(fmt)) {
            ss << std::boolalpha << *format_iterator++;
        }

        return ss.str();
    }
}
