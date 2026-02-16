#pragma once

#include <string>
#include <any>

namespace qlang {
    namespace core {
        class Variable {
        protected:
            void* data;
            size_t size;
            std::string type;
        public:
            virtual void set() = 0;
            virtual void get() = 0;
        };
    }
}