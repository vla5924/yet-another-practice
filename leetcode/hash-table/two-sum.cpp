// https://leetcode.com/problems/two-sum

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> diffs;
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (diffs.contains(diff))
                return vector<int>{i, diffs[diff]};
            diffs[nums[i]] = i;
        }
        return {0, 0};
    }
};

int main() {
    return 0;
}
