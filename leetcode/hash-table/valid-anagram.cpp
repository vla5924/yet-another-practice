// https://leetcode.com/problems/valid-anagram/

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }

    bool isAnagramHash(string s, string t) {
        if (s.size() != t.size())
            return false;
        vector<int> occur(26, 0);
        for (int i = 0; i < s.size(); i++) {
            occur[s[i] - 'a']++;
            occur[t[i] - 'a']--;
        }
        return all_of(occur.begin(), occur.end(), [](int i) { return i == 0; });
    }
};

int main() { return 0; }
