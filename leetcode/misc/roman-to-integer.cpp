// https://leetcode.com/problems/roman-to-integer

#include <string>

using namespace std;

class Solution {
    int letters[256] = {0};

  public:
    int romanToInt(string s) {
        letters['I'] = 1;
        letters['V'] = 5;
        letters['X'] = 10;
        letters['L'] = 50;
        letters['C'] = 100;
        letters['D'] = 500;
        letters['M'] = 1000;
        int result = 0;
        for (size_t i = 0; i < s.size() - 1; i++) {
            auto curr = s[i];
            auto next = s[i + 1];
            bool add = true;
            if (curr == 'I' && (next == 'V' || next == 'X'))
                add = false;
            else if (curr == 'X' && (next == 'L' || next == 'C'))
                add = false;
            else if (curr == 'C' && (next == 'D' || next == 'M'))
                add = false;
            if (add)
                result += letters[curr];
            else
                result -= letters[curr];
        }
        result += letters[s.back()];
        return result;
    }
};

int main() {
    return 0;
}
