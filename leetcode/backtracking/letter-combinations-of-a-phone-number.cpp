// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    void backtrack(string &digits, int index, vector<string> &combs, unordered_map<char, string> &mapping) {
        if (index >= digits.size()) {
            return;
        }
        int n = combs.size();
        string &variants = mapping[digits[index]];
        // append first variant
        for (int i = 0; i < n; i++) {
            combs[i].push_back(variants[0]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < variants.size(); j++) {
                combs.push_back(combs[i]);
                combs.back().back() = variants[j];
            }
        }
        backtrack(digits, index + 1, combs, mapping);
    }

  public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        unordered_map<char, string> mapping;
        mapping['2'] = "abc";
        mapping['3'] = "def";
        mapping['4'] = "ghi";
        mapping['5'] = "jkl";
        mapping['6'] = "mno";
        mapping['7'] = "pqrs";
        mapping['8'] = "tuv";
        mapping['9'] = "wxyz";
        vector<string> combs;
        int numCombs = 1;
        for (char c : digits)
            numCombs *= mapping[c].size();
        combs.reserve(numCombs);
        string map0 = mapping[digits[0]];
        for (char c : map0) {
            combs.emplace_back(&c, 1);
        }
        backtrack(digits, 1, combs, mapping);
        return combs;
    }
};

int main() { return 0; }
