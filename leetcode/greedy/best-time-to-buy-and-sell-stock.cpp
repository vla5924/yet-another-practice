// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// Some decent explanation on this problem:
// Based on the fact that we have to sell after we buy and we are trying to maximize profit, we can iterate through the
// prices and only need to consider two things:
// 1. Is this price cheaper than any other price I've seen before?
// 2. If I subtract current price by the cheapest price I've found, does this yield a greater profit than what I've seen
// so far?

#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2 || is_sorted(prices.begin(), prices.end(), greater<int>()))
            return 0;
        int profit = 0;
        int cheapest = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            int current = prices[i];
            if (current < cheapest)
                cheapest = current;
            else if (current - cheapest > profit)
                profit = current - cheapest;
        }
        return profit;
    }
};

int main() { return 0; }
