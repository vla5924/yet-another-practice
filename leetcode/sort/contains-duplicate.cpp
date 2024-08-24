// https://leetcode.com/problems/contains-duplicate/

#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  public:
    bool containsDuplicateLazy(vector<int> &nums) {
        return nums.size() != unordered_set<int>(nums.begin(), nums.end()).size();
    }

    bool containsDuplicate(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] == nums[i - 1])
                return true;
        return false;
    }
};

int main() { return 0; }
