// https://leetcode.com/problems/lru-cache/

#include <iterator>
#include <list>
#include <unordered_map>
#include <utility>

using namespace std;

class LRUCache {
    using ValueList = list<pair<int, int>>;
    using KeyMap = unordered_map<int, ValueList::iterator>;
    ValueList values;
    KeyMap keys;
    int capacity;

    void touch(ValueList::iterator item) {
        if (item != values.end() && next(item) != values.end())
            values.splice(values.end(), values, item);
    }

  public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = keys.find(key);
        if (it == keys.end())
            return -1;
        touch(it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = keys.find(key);
        if (it == keys.end()) {
            auto valueIt = values.insert(values.end(), make_pair(key, value));
            it = keys.emplace(key, valueIt).first;
        } else {
            it->second->second = value;
            touch(it->second);
        }
        if (values.size() > capacity) {
            int key = values.front().first;
            keys.erase(key);
            values.pop_front();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() { return 0; }
