#include <unordered_map>
#include <map>
#include <string>

using namespace std;

class TimeMap {
public:
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        data[key].insert({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (data.find(key) == data.end()) {
            return "";
        }

        const auto& values = data[key];
        auto it = values.upper_bound(timestamp);

        if (it == values.begin()) {
            return "";
        }

        --it;
        return it->second;
    }

private:
    unordered_map<string, map<int, string>> data;
};

