#pragma once

#include <map>
#include <string>

namespace qlang {
    namespace core {
        const auto basicTypes = std::map<std::string, size_t> { // Basic variable types in bytes
            {"byte",    1},
            {"int32",   4},
            {"float32", 4},
        };
    }
}