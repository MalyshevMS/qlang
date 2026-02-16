#include <print>
#include "lang/parser.hpp"

int main(int argc, char const *argv[]) {
    auto l = qlang::parser::Line("k1 k2 k3");
    std::println("{}", l.getToken());
    std::println("{}", l.getArgs());
    return 0;
}
