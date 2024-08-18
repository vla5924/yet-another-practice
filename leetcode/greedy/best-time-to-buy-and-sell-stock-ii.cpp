// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <utility>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2)
            return 0;
        pair<int, int> lastTrade(prices[0], 0);
        int profit = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            int current = prices[i];
            // never tried to sell
            if (lastTrade.second == 0) {
                // buy today instead of that day -> more profitable?
                // sell otherwise
                if (current < lastTrade.first) {
                    profit += lastTrade.first - current;
                    lastTrade.first = current;
                } else {
                    lastTrade.second = current;
                    profit += current;
                }
                continue;
            }
            // sell today instead of that day -> more profitable?
            int expectedProfit = profit - lastTrade.second + current;
            if (expectedProfit > profit) {
                lastTrade.second = current;
                profit = expectedProfit;
                continue;
            }
            // alr js buy today then
            lastTrade.first = current;
            lastTrade.second = 0;
            profit -= current;
        }
        if (lastTrade.second == 0)
            profit += lastTrade.first;
        return profit;
    }
};

int main() { return 0; }
