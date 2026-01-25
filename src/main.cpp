#include <print>
#include "files/reader.hpp"

int main(int argc, char const *argv[]) {
    qlang::Reader read("file.txt");
    while (const auto& l = read.getLine()) {
        std::println("{}", *l);
    }
    return 0;
}
