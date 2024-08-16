// https://leetcode.com/problems/longest-common-prefix

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    string longestCommonPrefix(vector<string> &strs) {
        size_t prefixlen = 201;
        for (size_t i = 0; i < strs.size(); i++)
            if (strs[i].size() < prefixlen)
                prefixlen = strs[i].size();
        string prefix;
        prefix.reserve(prefixlen);
        for (size_t i = 0; i < prefixlen; i++) {
            auto l = strs.front()[i];
            if (all_of(strs.begin() + 1, strs.end(), [i, l](const string &s) { return s[i] == l; }))
                prefix.push_back(l);
            else
                break;
        }
        return prefix;
    }
};

int main() {
    return 0;
}
