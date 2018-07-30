#ifndef YANDEX_HPP_INCLUDED
#define YANDEX_HPP_INCLUDED

#include <yandex/base-types.hpp>
#include <http-client/http-client.hpp>
#include <nlohmann/json.hpp>
#include <string>
#include <map>

namespace yandex
{
  class Yandex
  {
  public:
    Yandex(const std::string &access_token);
    ~Yandex();
    nlohmann::json call(const std::string &request_path = "", const std::map<std::string, std::string> &params = {}) const;

  protected:
    const http_client::HttpClient *http_client_;
  };
}

#endif
