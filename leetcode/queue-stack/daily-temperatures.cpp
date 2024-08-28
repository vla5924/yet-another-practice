// https://leetcode.com/problems/daily-temperatures/

#include <stack>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        // monotonically decreasing stack, pair<temp, idx>
        stack<pair<int, int>> monostack;
        vector<int> res(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            while (!monostack.empty() && temperatures[i] > monostack.top().first) {
                res[monostack.top().second] = i - monostack.top().second;
                monostack.pop();
            }
            monostack.emplace(temperatures[i], i);
        }
        return res;
    }
};

int main() { return 0; }
