#ifndef YANDEX_BASE_TYPES_HPP
#define YANDEX_BASE_TYPES_HPP

#include <string>

namespace yandex
{
  struct resource_t
  {
    std::string id;
    std::string path;
    std::string type;
    std::string name;

    bool isFile() const noexcept
    {
      return (type == "file");
    }
  };
}

#endif
