// https://leetcode.com/problems/longest-repeating-character-replacement/

// I gave up on this one...

#include <deque>
#include <iostream>
#include <string>

using namespace std;

ostream &operator<<(ostream &os, deque<char> dq) {
    for (char c : dq)
        os << c;
    return os;
}

class Solution {
  public:
    int characterReplacement(string s, int k) {
        // char counts[int('Z') + 1] = {0};
        // int maxCount = 0;
        // int windowSize = 0;
        // deque<char> window;
        // for (int i = 0; i < s.size(); i++) {
        //     window.push_back(s[i]);
        //     cout << "input " << s[i] << " window " << window;
        //     int curCount = ++counts[s[i]];
        //     if (curCount > maxCount) {
        //         maxCount = curCount;
        //         windowSize++;
        //     } else {
        //         if (i >= windowSize) {
        //             counts[s[i - windowSize]]--;
        //             window.pop_front();
        //         }
        //     }
        //     cout << " windowSize " << windowSize << " maxCount " << maxCount << "\n";
        // }
        // cout << "MAX " << windowSize << "\n";
        // return maxCount + k;

        char counts[int('Z') + 1] = {0};
        int maxCount = 0;
        int left = 0;
        int right = 1;
        int maxLen = 0;
        for (int i = 0; i < s.size(); i++) {
            int curCount = ++counts[s[i]];
            if (curCount > maxCount) {
                maxCount = curCount;
            }
            int curLen = right - left;
            if (curLen > maxCount + k) {
                left += curLen - maxCount - k;
                curLen = right - left;
            }
            if (curLen > maxLen)
                maxLen = curLen;
            right++;
        }
        cout << "MAX " << maxLen << "\n";
        return maxLen;
    }
};

int main() {
    Solution().characterReplacement("ABAB", 2);    // 4
    Solution().characterReplacement("AABABBA", 1); // 4
    return 0;
}
