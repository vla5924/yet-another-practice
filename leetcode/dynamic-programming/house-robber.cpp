// https://leetcode.com/problems/house-robber/

// Based on this step-by-step explanation on how to approach DP solution:
// https://leetcode.com/problems/house-robber/solutions/156523/From-good-to-great.-How-to-approach-most-of-DP-problems

#include <numeric>
#include <vector>

using namespace std;

class Solution {
    // Call it like: robRec(nums, nums.size() - 1);
    int robRec(vector<int> &nums, int i) {
        if (i < 0)
            return 0;
        // either we dont rob ith because we robbed i-1th
        // or we rob this because we didnt rob i-1th and robbed i-2th
        return max(robRec(nums, i - 1), nums[i] + robRec(nums, i - 2));
    }

    // Initialize memo with [-1] * nums.size() before calling
    int robMemo(vector<int> &nums, int i, vector<int> &memo) {
        if (i < 0)
            return 0;
        if (memo[i] != -1)
            return memo[i];
        return memo[i] = max(robMemo(nums, i - 1, memo), nums[i] + robMemo(nums, i - 2, memo));
    }

    int robDp(vector<int> &nums) {
        if (nums.size() < 2)
            return nums.front();
        vector<int> dp(nums.size() + 1, -1);
        // dp[i] = max money after i houses robbed
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            // eventually this can be optimized up to two variables instead of a vector
            // since we only need current and previous step anyway
            dp[i + 1] = max(dp[i], nums[i] + dp[i - 1]);
        }
        return dp.back();
    }

  public:
    int rob(vector<int> &nums) { return robDp(nums); }
};

int main() { return 0; }
