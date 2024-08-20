// https://leetcode.com/problems/coin-change/

#include <limits>
#include <vector>

using namespace std;

class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        if (amount == 0)
            return 0;
        // dp[i] = fewest number of coins to make up i
        vector<int> dp(amount + 1, 0);
        dp.front() = 0;
        int minDenom = coins.front();
        for (int denom : coins) {
            minDenom = min(denom, minDenom);
            if (denom < dp.size())
                dp[denom] = 1;
        }
        if (minDenom > amount)
            return -1;
        if (minDenom == amount)
            return 1;
        for (int i = 1; i < minDenom; i++)
            dp[i] = -1;
        for (int i = minDenom; i < dp.size(); i++) {
            if (dp[i] != 0)
                continue;
            int n = numeric_limits<int>::max();
            bool ok = false;
            for (int denom : coins) {
                if (denom < i && dp[i - denom] != -1) {
                    n = min(dp[i - denom] + 1, n);
                    ok = true;
                }
            }
            dp[i] = ok ? n : -1;
        }
        return dp.back();
    }
};

int main() { return 0; }
