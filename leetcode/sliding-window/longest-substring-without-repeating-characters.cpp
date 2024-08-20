// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <string>
#include <unordered_map>
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

    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> counts;
        unordered_set<char> repeatingChars;
        int len = 0;
        for (int i = 0; i < s.size(); i++) {
            char curr = s[i];
            // do we want to append s[i] to EXISTING window?
            // yes, if it is unique for it AND there are no other repeating characters
            bool unique = ++counts[curr] == 1;
            if (unique && repeatingChars.empty()) {
                len += 1; // append s[i] to EXISTING window
            }
            // no, if there is already same character
            // OR there are some repeating characters remaining inside the window
            // in that case we SLIDE this window
            // therefore s[i - len] element goes out
            else {
                if (!unique)
                    repeatingChars.insert(curr);
                char last = s[i - len];
                int rem = --counts[last];
                if (rem <= 1)
                    repeatingChars.erase(last);
            }
        }
        return len;
    }
};

int main() { return 0; }
