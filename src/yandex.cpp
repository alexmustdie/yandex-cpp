#include <yandex/yandex.hpp>

using namespace yandex;
using namespace nlohmann;
using namespace std;

Yandex::Yandex(const string &access_token)
{
  http_client_ = new http_client::HttpClient(map<string, string> {{"Authorization", "OAuth " + access_token}});
}

Yandex::~Yandex()
{
  delete http_client_;
}

json Yandex::call(const string &request_path, const std::map<string, string> &params) const
{
  string params_str = params.empty() ? "" : ("?" + http_client_->buildQuery(params));
  string data = http_client_->makeRequest("https://cloud-api.yandex.net/v1/disk/" + request_path + params_str);

  json j = json::parse(data);

  return j;
}
