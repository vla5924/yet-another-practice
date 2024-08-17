// https://leetcode.com/problems/group-anagrams

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> charsets;
        for (auto &str : strs) {
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            charsets[sorted].push_back(str);
        }
        vector<vector<string>> groups;
        groups.reserve(charsets.size());
        for (const auto &[key, group] : charsets)
            groups.emplace_back(group.begin(), group.end());
        return groups;
    }
};

int main() { return 0; }
