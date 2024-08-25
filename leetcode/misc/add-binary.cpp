// https://leetcode.com/problems/add-binary/

#include <string>

using namespace std;

class Solution {
  public:
    string addBinary(string a, string b) {
        int sz = max(a.size(), b.size()) + 1;
        string pa(sz, '0');
        copy(a.rbegin(), a.rend(), pa.begin());
        string pb(sz, '0');
        copy(b.rbegin(), b.rend(), pb.begin());
        string pc(sz, '0');
        int carry = 0;
        for (int i = 0; i < sz; i++) {
            int lhs = pa[i] == '1';
            int rhs = pb[i] == '1';
            int sum = lhs + rhs + carry;
            pc[i] = sum % 2 == 0 ? '0' : '1';
            carry = sum / 2;
        }
        size_t pos = pc.rfind('1');
        if (pos == string::npos)
            return "0";
        return {pc.rbegin() + (pc.size() - pos - 1), pc.rend()};
    }
};

int main() { return 0; }
