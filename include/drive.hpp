#ifndef DRIVE_HPP_INCLUDED
#define DRIVE_HPP_INCLUDED

#include <yandex/yandex.hpp>
#include <vector>

namespace yandex
{
  class Drive:
    public Yandex
  {
  public:
    Drive(const std::string &access_token);
    std::vector<resource_t> getResources(const std::string &path, const size_t limit = 20, size_t offset = 0) const;
    std::string getFileLink(const std::string &path) const;
  };
}

#endif
