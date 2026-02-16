#pragma once

#include <string_view>
#include <unordered_map>
#include "var.hpp"

namespace qlang {
    namespace core {
        class Interpreter {
        private:
            std::unordered_map<std::string, Variable> globalVariables;
        public:
            Interpreter();

            int run(std::string_view line);
        };
    }
}