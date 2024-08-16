// https://leetcode.com/problems/4sum/

#include <algorithm>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> fourSumSlow(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end(), greater<int>());
        int64_t targetL = target;
        set<vector<int>> quadruplets;
        for (int a = 0; a < nums.size(); a++) {
            for (int b = a + 1; b < nums.size(); b++) {
                int64_t target2Sum = targetL - nums[a] - nums[b];
                unordered_map<int64_t, int> diffs;
                for (int c = b + 1; c < nums.size(); c++) {
                    int64_t remaining = target2Sum - nums[c];
                    if (diffs.contains(remaining)) {
                        int d = diffs[remaining];
                        quadruplets.emplace(vector<int>{nums[a], nums[b], nums[c], nums[d]});
                    }
                    diffs[nums[c]] = c;
                }
            }
        }
        return {quadruplets.begin(), quadruplets.end()};
    }

    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int64_t targetL = target;
        vector<vector<int>> quadruplets;
        size_t sz = nums.size();
        for (int a = 0; a < sz; a++) {
            if (a != 0 && nums[a] == nums[a - 1])
                continue;
            for (int b = a + 1; b < sz; b++) {
                if (b != a + 1 && nums[b] == nums[b - 1])
                    continue;
                int c = b + 1;
                int d = sz - 1;
                while (c < d) {
                    int64_t current = static_cast<int64_t>(nums[a]) + nums[b] + nums[c] + nums[d];
                    if (current == targetL) {
                        quadruplets.emplace_back(vector<int>{nums[a], nums[b], nums[c], nums[d]});
                        c++;
                        d--;
                        while (c < d && nums[c] == nums[c - 1])
                            c++;
                        while (c < d && nums[d] == nums[d + 1])
                            d--;
                        continue;
                    }
                    if (current > targetL)
                        d--;
                    else
                        c++;
                }
            }
        }
        return quadruplets;
    }
};

int main() {
    return 0;
}
