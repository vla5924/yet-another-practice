// https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include <cstdint>
#include <stack>
#include <string>
#include <variant>
#include <vector>

using namespace std;

class Solution {
    enum Op : uint8_t { Add, Sub, Mul, Div };
    using Token = variant<int, Op>;

    Token asToken(const string &s) {
        if (s.size() == 1) {
            if (s.front() == '+')
                return Add;
            if (s.front() == '-')
                return Sub;
            if (s.front() == '*')
                return Mul;
            if (s.front() == '/')
                return Div;
        }
        return static_cast<int>(stol(s));
    }

  public:
    int evalRPN(vector<string> &tokens) {
        stack<Token> rpn;
        for (auto it = tokens.rbegin(); it != tokens.rend(); ++it)
            rpn.push(asToken(*it));
        stack<int> calc;
        int result = 0;
        while (!rpn.empty()) {
            Token token = rpn.top();
            rpn.pop();
            if (holds_alternative<Op>(token)) {
                int rhs = calc.top();
                calc.pop();
                int lhs = calc.top();
                calc.pop();
                auto op = get<Op>(token);
                if (op == Add)
                    calc.push(lhs + rhs);
                else if (op == Sub)
                    calc.push(lhs - rhs);
                else if (op == Mul)
                    calc.push(lhs * rhs);
                else
                    calc.push(lhs / rhs);
            } else {
                calc.push(get<int>(token));
            }
        }
        return calc.top();
    }
};

int main() { return 0; }
