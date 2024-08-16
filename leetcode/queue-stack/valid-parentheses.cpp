// https://leetcode.com/problems/valid-parentheses

#include <stack>
#include <string>

using namespace std;

class Solution {
  public:
    bool isValid(string s) {
        stack<string::value_type> ss;
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') {
                ss.push(c);
                continue;
            }
            if (ss.empty())
                return false;
            auto t = ss.top();
            ss.pop();
            if (t == '(' && c == ')')
                continue;
            if (t == '[' && c == ']')
                continue;
            if (t == '{' && c == '}')
                continue;
            return false;
        }
        return ss.empty();
    }
};

int main() {
    return 0;
}
