// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

// I couldn't make a straightforward greedy solution like the ones for previous "best time to buy and sell stock"
// problems work here, so I found this article with some explanations on how to approach this dynamic programming
// solution "intuitively":
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solutions/3668244/detailed-explanation-fastest-cakewalk-solution-for-everyone/

#include <vector>

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices, int fee) {
        int sz = prices.size();
        if (sz < 2)
            return 0;
        // we start from the last i, which means that we have nothing to buy/sell on the last day,
        // no more profit can be earned, that is why profitWhenSold and profitWhenOwned initialized with 0s
        int profitWhenSold = 0;
        int profitWhenOwned = 0;
        for (int i = sz - 1; i >= 0; i--) {
            // If stock is sold (== not bought) then it can be bought with a price == prices[i]
            profitWhenSold = max(profitWhenSold, profitWhenOwned - prices[i]);
            // If stock is owned (== bought) then is can be sold for a price == prices[i] (and fee)
            profitWhenOwned = max(profitWhenOwned, profitWhenSold + prices[i] - fee);
        }
        // stock cannot be owned in the beginning of process
        return profitWhenSold;
    }
};

int main() { return 0; }
