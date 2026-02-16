#pragma once

#include "../core/var.hpp"

namespace qlang {
    namespace type {
        class Int32 : public core::Variable {
            Int32(int value = 0);

            void set(int value);
            void* get();
        };
    }
}