#include "reader.hpp"

using namespace qlang;

Reader::Reader(fs::path path)
 : path(path), ifs(path) {

}

std::optional<std::string> Reader::getLine(size_t line) {
    if (!ifs.is_open()) return std::nullopt;
    if (line < 1) return "";

    ifs.clear();
    ifs.seekg(0);

    std::string res;
    int current = 0;

    while (std::getline(ifs, res)) {
        current++;
        if (current == line) return res;
    }

    return std::nullopt;
}

std::optional<std::string> Reader::getLine() {
    last_line++;
    return getLine(last_line);
}

size_t Reader::countLines() {
    if (!ifs.is_open()) return 0;

    size_t lines = std::count(
        std::istreambuf_iterator(ifs),
        std::istreambuf_iterator<char>(),
        '\n'
    );

    return lines == 0 ? 0 : ++lines;
}