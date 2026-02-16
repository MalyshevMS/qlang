#include "parser.hpp"
#include <ranges>

qlang::parser::Line::Line(std::string_view line) {
    view = helper::split(line);
}
std::vector<std::string> qlang::parser::helper::split(std::string_view str, char sep) {
    std::vector<std::string> result;
    std::string current;
    bool opened_quot = false;  // ' (single quot)
    bool opened_quot2 = false; // " (double quot)

    for (char c : str) {
        if (c == sep && !opened_quot && !opened_quot2) {
            if (!current.empty()) {
                result.push_back(current);
                current.clear();
            }
        } else if (c == '\'' && !opened_quot2) {
            opened_quot = !opened_quot;
        } else if (c == '\"' && !opened_quot) {
            opened_quot2 = !opened_quot2;
        } else {
            current += c;
        }
    }

    if (!current.empty()) {
        result.push_back(current);
    }

    return result;
}

std::string qlang::parser::Line::getToken() {
    return view[0];
}

std::vector<std::string> qlang::parser::Line::getArgs() {
    return view | std::ranges::views::drop(1) | std::ranges::to<std::vector>();
}
