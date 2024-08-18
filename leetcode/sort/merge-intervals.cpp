// https://leetcode.com/problems/merge-intervals/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals.front());
        for (int i = 1; i < intervals.size(); i++) {
            const auto &curr = intervals[i];
            auto &last = result.back();
            if (curr[0] <= last[1])
                last[1] = max(last[1], curr[1]);
            else
                result.push_back(curr);
        }
        return result;
    }
};

int main() { return 0; }
