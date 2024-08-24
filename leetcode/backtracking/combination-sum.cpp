// https://leetcode.com/problems/combination-sum/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    void backtrack(vector<int> &cands, int size, int idx, int target, vector<int> &curr, vector<vector<int>> &combs) {
        if (target < 0)
            return;
        if (idx == size) {
            if (target == 0)
                combs.push_back(curr);
            return;
        }
        curr.push_back(cands[idx]);
        backtrack(cands, size, idx, target - cands[idx], curr, combs);
        curr.pop_back();
        backtrack(cands, size, idx + 1, target, curr, combs);
    }

  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        if (candidates.front() > target)
            return {};
        int last = 0;
        while (last < candidates.size() && candidates[last] <= target)
            last++;
        vector<int> curr;
        curr.reserve(last);
        vector<vector<int>> combs;
        backtrack(candidates, last, 0, target, curr, combs);
        return combs;
    }
};

int main() { return 0; }
