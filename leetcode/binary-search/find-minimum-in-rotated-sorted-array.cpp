// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <vector>

using namespace std;

class Solution {
  public:
    int findMin(vector<int> &nums) {
        int left = 0U;
        int sz = nums.size();
        int right = sz;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid == 0 && nums[0] <= nums[right - 1]) {
                return nums[0];
            }
            if (mid != 0 && nums[mid] < nums[mid - 1]) {
                return nums[mid];
            }
            if (nums[mid] > nums[right - 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return 0; // unreachable
    }
};

int main() { return 0; }
