// https://leetcode.com/problems/subsets/

#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
        res.reserve(1UL << nums.size());
        res.emplace_back();
        for (int i = 0; i < nums.size(); i++) {
            int backtrack = res.size();
            for (int j = 0; j < backtrack; j++) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};

int main() { return 0; }
