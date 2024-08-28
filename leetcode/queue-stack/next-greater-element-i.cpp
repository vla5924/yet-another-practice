// https://leetcode.com/problems/next-greater-element-i/

#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        stack<int> monostack; // monotonically decreasing stack
        unordered_map<int, int> nextGreater;
        for (int i = 0; i < nums2.size(); i++) {
            while (!monostack.empty() && nums2[i] >= monostack.top()) {
                nextGreater[monostack.top()] = nums2[i];
                monostack.pop();
            }
            monostack.push(nums2[i]);
        }
        vector<int> res;
        res.reserve(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            auto it = nextGreater.find(nums1[i]);
            if (it == nextGreater.end())
                res.push_back(-1);
            else
                res.push_back(it->second);
        }
        return res;
    }
};

int main() { return 0; }
