// https://leetcode.com/problems/time-based-key-value-store/

#include <iterator>
#include <map>
#include <string>
#include <unordered_map>

using namespace std;

class TimeMap {
    unordered_map<string, map<int, string>> storage;

  public:
    TimeMap() {}

    void set(string key, string value, int timestamp) { storage[key][timestamp] = value; }

    string get(string key, int timestamp) {
        auto it = storage.find(key);
        if (it == storage.end())
            return "";
        auto lb = it->second.lower_bound(timestamp);
        if (timestamp == lb->first)
            return lb->second;
        if (lb == it->second.begin())
            return "";
        return prev(lb)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main() { return 0; }
