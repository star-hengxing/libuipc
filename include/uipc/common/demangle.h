#pragma once
#include <uipc/common/dllexport.h>
#include <string>
#include <typeinfo>

namespace uipc
{
UIPC_CORE_API std::string demangle(const std::string& mangled_name);

template <typename T>
inline std::string demangle() noexcept
{
    return demangle(typeid(T).name());
}
}  // namespace uipc
