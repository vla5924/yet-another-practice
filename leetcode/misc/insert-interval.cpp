// https://leetcode.com/problems/insert-interval

#include <iterator>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        if (intervals.empty())
            return {newInterval};
        auto firstNotLess = lower_bound(intervals.begin(), intervals.end(), newInterval);
        vector<vector<int>> res;
        res.reserve(intervals.size() + 1);
        copy(intervals.begin(), firstNotLess, back_inserter(res));
        if (res.empty()) {
            res.push_back(newInterval);
        } else {
            auto &prev = res.back();
            if (newInterval[0] <= prev[1])
                prev[1] = max(newInterval[1], prev[1]);
            else
                res.push_back(newInterval);
        }
        for (auto it = firstNotLess; it != intervals.end(); ++it) {
            auto &toInsert = *it;
            auto &prev = res.back();
            if (toInsert[0] <= prev[1])
                prev[1] = max(toInsert[1], prev[1]);
            else
                res.push_back(toInsert);
        }
        return res;
    }
};

int main() { return 0; }
