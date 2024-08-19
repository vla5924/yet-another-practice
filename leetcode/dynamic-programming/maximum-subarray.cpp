// https://leetcode.com/problems/maximum-subarray

#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxSubArrayNaive(vector<int> &nums) {
        int maxSum = numeric_limits<int>::min();
        for (int first = 0; first < nums.size(); first++) {
            for (int last = first + 1; last <= nums.size(); last++) {
                int sum = 0;
                for (int i = first; i < last; i++)
                    sum += nums[i];
                if (sum > maxSum)
                    maxSum = sum;
            }
        }
        return maxSum;
    }

    int maxSubArrayMemoryIneffective(vector<int> &nums) {
        int maxSum = numeric_limits<int>::min();
        // dp[i] = max sum of array which has nums[i] as last element
        vector<int> dp(nums.size(), numeric_limits<int>::min());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            // either some subarray ends with i-th element -> dp[i] = dp[i-1] + nums[i]
            // or it does not and i-th element is its first -> dp[i] = nums[i]
            // select better option here!
            dp[i] = nums[i] + max(0, dp[i - 1]);
        }
        return *max_element(dp.begin(), dp.end());
    }

    int maxSubArray(vector<int> &nums) {
        int maxSum = nums[0];
        int localMaxSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            localMaxSum = nums[i] + max(0, localMaxSum);
            if (localMaxSum > maxSum)
                maxSum = localMaxSum;
        }
        return maxSum;
    }
};

int main() { return 0; }
