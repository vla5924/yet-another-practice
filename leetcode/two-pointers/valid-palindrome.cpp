// https://leetcode.com/problems/valid-palindrome/

#include <string>

using namespace std;

class Solution {
    char evaluate(char c) {
        if (c >= 'A' && c <= 'Z')
            return 'a' + (c - 'A');
        if (c >= 'a' && c <= 'z' || c >= '0' && c <= '9')
            return c;
        return 0;
    }

  public:
    bool isPalindrome(string s) {
        int valid = 0;
        for (int i = 0; i < s.size(); i++)
            valid += evaluate(s[i]) ? 1 : 0;
        if (valid < 2)
            return true;
        int left = 0;
        int right = s.size() - 1;
        for (int i = 0; i < valid / 2; i++) {
            char cleft = evaluate(s[left]), cright = evaluate(s[right]);
            while (!cleft && left < right) {
                left++;
                cleft = evaluate(s[left]);
            }
            while (!cright && right > left) {
                right--;
                cright = evaluate(s[right]);
            }
            if (cleft != cright)
                return false;
            left++;
            right--;
        }
        return true;
    }
};

int main() { return 0; }
