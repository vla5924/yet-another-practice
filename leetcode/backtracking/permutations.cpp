// https://leetcode.com/problems/permutations/

#include <vector>

using namespace std;

constexpr int sentinel = -100;

class Solution {
    void backtrack(vector<int> &nums, int index, const vector<int> &curr, vector<vector<int>> &perms) {
        if (index == nums.size()) {
            perms.emplace_back(curr);
            return;
        }
        for (int j = 0; j < nums.size(); j++) { // where to place
            if (curr[j] != sentinel)            // already occupied, go check next seat
                continue;
            vector<int> next = curr;
            next[j] = nums[index];
            backtrack(nums, index + 1, next, perms);
        }
    }

  public:
    vector<vector<int>> permute(vector<int> &nums) {
        if (nums.size() < 2)
            return {nums};
        int numPerms = 1;
        for (int i = 1; i <= nums.size(); i++) {
            numPerms *= i;
        }
        vector<vector<int>> perms;
        perms.reserve(numPerms);
        backtrack(nums, 0, vector<int>(nums.size(), sentinel), perms);
        return perms;
    }
};

int main() { return 0; }
