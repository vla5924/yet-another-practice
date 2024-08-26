// https://leetcode.com/problems/longest-increasing-subsequence/

#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

constexpr int sentinel = numeric_limits<int>::min();

class Solution {
    // lengthOfLIS is max(lengthRec(nums, i) for i=0,1,...,nums.size())
    int lengthRec(vector<int> &nums, int i) {
        int sz = nums.size();
        if (i < 0 || i >= nums.size())
            return 0;
        if (i == sz - 1)
            return 1;
        int nexti;
        int maxlen = 0;
        for (nexti = i + 1; nexti < sz; nexti++) {
            if (nums[nexti] > nums[i])
                maxlen = max(maxlen, 1 + lengthRec(nums, nexti));
        }
        return maxlen;
    }

    // Initialize memo as vector<int>(nums.size(), sentinel)
    int lengthMemo(vector<int> &nums, int i, vector<int> &memo) {
        int sz = nums.size();
        if (i < 0 || i >= nums.size())
            return 0;
        if (i == sz - 1)
            return 1;
        if (memo[i] != sentinel)
            return memo[i];
        int nexti;
        int maxlen = 0;
        for (nexti = i + 1; nexti < sz; nexti++) {
            if (nums[nexti] > nums[i])
                maxlen = max(maxlen, 1 + lengthRec(nums, nexti));
        }
        return memo[i] = maxlen;
    }

    int lengthDp(vector<int> &nums) {
        int sz = nums.size();
        if (sz < 2)
            return sz;
        vector<int> dp(sz, 1);
        // dp[i] = max lengthOfLIS that ENDS with nums[i]
        for (int i = 1; i < sz; i++) {
            for (int previ = 0; previ < i; previ++) {
                if (nums[previ] < nums[i])
                    dp[i] = max(dp[i], dp[previ] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

  public:
    int lengthOfLIS(vector<int> &nums) { return lengthDp(nums); }
};

int main() { return 0; }
