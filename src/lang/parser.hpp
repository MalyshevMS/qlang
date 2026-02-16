#pragma once

#include <string_view>
#include <string>
#include <vector>

namespace qlang {
    namespace parser {
        namespace helper {
            std::vector<std::string> split(std::string_view str, char sep = ' ');
        }

        class Line {
        private:
            std::vector<std::string> view;
        public:
            Line(std::string_view line);
            std::string getToken();
            std::vector<std::string> getArgs();
        };
    }
}