#include <yandex/drive.hpp>

using namespace yandex;
using namespace nlohmann;
using namespace std;

Drive::Drive(const string &access_token):
  Yandex(access_token)
{}

vector<resource_t> Drive::getResources(const string &path, const size_t limit, size_t offset) const
{
  vector<resource_t> resources;
  json items;

  do
  {
    map<string, string> params
    {
      {"path", path},
      // {"limit", "20"},
      {"offset", to_string(offset)},
      {"fields", "_embedded.items.resource_id,_embedded.items.path,_embedded.items.type,_embedded.items.name"}
    };

    items = call("resources", params)["_embedded"]["items"];

    for (json item: items)
    {
      resources.push_back({
        item["resource_id"].get<string>(),
        item["path"].get<string>(),
        item["type"].get<string>(),
        item["name"].get<string>()
      });
    }

    offset += limit;
  }
  while (items.size() == limit);

  return resources;
}

string Drive::getFileLink(const std::string &path) const
{
  json response = call("resources/download", map<string, string> {{"path", path}});

  return response["href"].get<string>();
}
