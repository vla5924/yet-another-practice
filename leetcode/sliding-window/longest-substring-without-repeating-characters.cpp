// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <string>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstringNaive(string s) {
        string ss;
        auto sz = s.size();
        ss.reserve(sz);
        int maxlen = 0;
        for (size_t i = 0; i < sz; i++) {
            unordered_set<string::value_type> chars;
            for (size_t j = i; j < sz; j++) {
                const auto &c = s[j];
                if (chars.contains(c))
                    break;
                chars.emplace(c);
                ss.push_back(c);
            }
            maxlen = max(static_cast<int>(ss.size()), maxlen);
            ss.clear();
        }
        return maxlen;
    }
};

int main() {
    return 0;
}
