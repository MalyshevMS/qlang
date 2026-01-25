#pragma once

#include <string>
#include <fstream>
#include <optional>
#include "fs.hpp"

namespace qlang {
    class Reader {
    private:
        fs::path path;
        std::ifstream ifs;
        size_t last_line = 0;
    public:
        Reader() {}
        Reader(fs::path path);
        std::optional<std::string> getLine(size_t line);
        std::optional<std::string> getLine();
        size_t countLines();
    };
}