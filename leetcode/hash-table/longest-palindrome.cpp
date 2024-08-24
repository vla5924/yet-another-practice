// https://leetcode.com/problems/longest-palindrome/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int longestPalindrome(string s) {
        unordered_map<char, int> occurs;
        for (int i = 0; i < s.size(); i++)
            occurs[s[i]]++;
        int len = 0;
        int rem = 0;
        for (auto rec : occurs) {
            len += rec.second / 2 * 2;
            rem += rec.second % 2;
        }
        return len + int(rem > 0);
    }
};

int main() { return 0; }
