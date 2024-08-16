// https://leetcode.com/problems/binary-search/

#include <vector>

using namespace std;

class Solution {
  public:
    int search(vector<int> &nums, int target) {
        size_t left = 0U;
        size_t right = nums.size();
        while (left < right) {
            auto mid = left + (right - left) / 2U;
            if (nums[mid] == target) {
                return static_cast<int>(mid);
            }
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return -1;
    }
};

int main() {
    return 0;
}
