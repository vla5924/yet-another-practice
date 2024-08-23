// https://leetcode.com/problems/move-zeroes

#include <vector>

using namespace std;

class Solution {
  public:
    void moveZeroes(vector<int> &nums) {
        size_t writeTo = 0;
        for (size_t readFrom = 0; readFrom < nums.size(); readFrom++, writeTo++) {
            while (readFrom < nums.size() && nums[readFrom] == 0)
                readFrom++;
            if (readFrom >= nums.size())
                break;
            nums[writeTo] = nums[readFrom];
        }
        for (size_t i = writeTo; i < nums.size(); i++)
            nums[i] = 0;
    }
};

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    Solution().moveZeroes(nums);
    return 0;
}
