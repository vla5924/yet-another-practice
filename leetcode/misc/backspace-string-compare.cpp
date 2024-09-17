// https://leetcode.com/problems/backspace-string-compare/

#include <string>

using namespace std;

class Solution {
    string simulate(string s) {
        string res;
        res.reserve(s.size());
        for (auto c : s) {
            if (c == '#') {
                if (res.empty())
                    continue;
                res.pop_back();
                continue;
            }
            res.push_back(c);
        }
        return res;
    }

  public:
    bool backspaceCompare(string s, string t) { return simulate(s) == simulate(t); }
};

int main() { return 0; }
