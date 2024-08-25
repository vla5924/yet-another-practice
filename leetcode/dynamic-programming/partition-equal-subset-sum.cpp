// https://leetcode.com/problems/partition-equal-subset-sum/

// Unfortunately, I couldn't come up with a concise DP solution for this prblem by myself,
// so both solutions below are written based on some accepted submissions from other authors.

#include <numeric>
#include <vector>

using namespace std;

namespace recursive_memo {
class Solution {
  public:
    bool helper(int ind, int sum, vector<vector<int>> &dp, vector<int> &nums) {
        if (sum == 0)
            return true;
        if (sum < 0)
            return false;
        if (ind == 0)
            return (nums[ind] == sum);
        if (dp[ind][sum] != -1)
            return dp[ind][sum];
        return dp[ind][sum] = helper(ind - 1, sum - nums[ind], dp, nums) || helper(ind - 1, sum, dp, nums);
    }
    bool canPartition(vector<int> &nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1)
            return false;
        sum /= 2;
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return helper(n - 1, sum, dp, nums);
    }
};
} // namespace recursive_memo

// https://leetcode.com/problems/partition-equal-subset-sum/solutions/5370742/4-different-ways-complexity-analysis-constant-space-beats-100/

namespace dp_tabulation {
class Solution {
  public:
    bool canPartition(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)
            return false;
        sum /= 2;
        int sz = nums.size();
        vector<vector<bool>> dp(sz + 1, vector<bool>(sum + 1, false));
        // it is possible to get subset sum=0 after traversing i items (i=0,1,...,sz)
        for (int i = 0; i <= sz; i++)
            dp[/* item */ i][/* sum */ 0] = true;
        for (int i = 1; i <= sz; i++) {
            for (int s = 1; s <= sum; s++) {
                if (s - nums[i - 1] < 0) {
                    // negative sum -> do not include nums[i] in subset
                    dp[i][s] = dp[i - 1][s];
                } else {
                    // either include or not include nums[i] in subset
                    dp[i][s] = dp[i - 1][s] || dp[i - 1][s - nums[i - 1]];
                }
            }
        }
        return dp[sz][sum];
    }
};
} // namespace dp_tabulation

int main() { return 0; }
