// https://leetcode.com/problems/palindrome-number

#include <vector>

using namespace std;

class Solution {
  public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x <= 9)
            return true;
        vector<char> digits;
        int xx = x;
        while (xx > 0) {
            digits.push_back(xx % 10);
            xx /= 10;
        }
        for (int i = 0; i < digits.size() / 2; i++) {
            if (digits[i] != digits[digits.size() - i - 1])
                return false;
        }
        return true;
    }
};

int main() {
    return 0;
}
