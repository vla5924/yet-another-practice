// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <vector>

using namespace std;

class Solution {
  public:
    int search(vector<int> &nums, int target) {
        int left = 0U;
        int sz = nums.size();
        int right = sz;
        int k = 0; // rotation pivot index
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid == 0 && nums[0] < nums[right - 1]) {
                k = 0;
                break;
            }
            if (mid != 0 && nums[mid] < nums[mid - 1]) {
                k = mid;
                break;
            }
            if (nums[mid] > nums[right - 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        left = 0;
        right = sz;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int value = nums[(mid + k) % sz];
            if (value == target) {
                return (mid + k) % sz;
            }
            if (value < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return -1;
    }
};

int main() { return 0; }
