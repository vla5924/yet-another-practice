// https://leetcode.com/problems/remove-invalid-parentheses/

#include <bitset>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

template <typename T>
void print(const T &values) {
    std::cout << "{ ";
    for (const auto &x : values)
        std::cout << '"' << x << "\" ";
    std::cout << "}\n";
}

class Solution {
    using Mask = bitset<25>;
    unordered_map<Mask, bool> memo;

    static bool isLetter(char c) {
        return c != '(' && c != ')';
    }

    bool isValid(const string &s, const Mask &removed) {
        stack<char> ss;
        for (int i = 0; i < s.size(); i++) {
            if (removed.test(i))
                continue;
            char c = s[i];
            if (isLetter(c)) {
                continue;
            }
            if (c == '(') {
                ss.push(c);
                continue;
            }
            if (ss.empty())
                return false;
            auto t = ss.top();
            ss.pop();
            if (t == '(' && c == ')')
                continue;
            return false;
        }
        return ss.empty();
    }

    bool checkOne(const string &s, Mask removed, unordered_set<string> &valid) {
        bool is = false;
        auto it = memo.find(removed);
        if (it != memo.end()) {
            is = it->second;
        } else {
            is = isValid(s, removed);
            memo[removed] = is;
        }
        if (!is) {
            return false;
        }
        int len = s.size() - removed.count();
        string validStr;
        validStr.resize(len);
        for (int i = 0, j = 0; i < s.size(); i++) {
            if (removed.test(i))
                continue;
            validStr[j++] = s[i];
        }
        valid.insert(validStr);
        return true;
    }

    void bfs(const string &s, unordered_set<Mask> &removeds, unordered_set<Mask> &removedChecked,
             unordered_set<string> &valid) {
        bool anyValid = false;
        unordered_set<Mask> nextRemoveds;
        for (const auto &removed : removeds) {
            if (removedChecked.contains(removed))
                return;
            for (int i = 0; i < s.size(); i++) {
                if (removed.test(i))
                    continue;
                if (isLetter(s[i]))
                    continue;
                auto nextRemoved = removed;
                nextRemoved.set(i);
                if (checkOne(s, nextRemoved, valid)) {
                    anyValid = true;
                } else {
                    nextRemoveds.insert(nextRemoved);
                }
            }
            removedChecked.insert(removed);
        }
        if (anyValid) {
            return;
        }
        for (const auto &nextRemoved : nextRemoveds)
            bfs(s, nextRemoveds, removedChecked, valid);
    }

  public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> valid;
        unordered_set<Mask> removeds;
        unordered_set<Mask> removedChecked;
        removeds.emplace();
        if (!checkOne(s, *removeds.begin(), valid))
            bfs(s, removeds, removedChecked, valid);
        return {valid.begin(), valid.end()};
    }
};

int main() {
    print(Solution().removeInvalidParentheses("(j))("));
    print(Solution().removeInvalidParentheses(")((())))))()(((l(((("));
    return 0;
}
