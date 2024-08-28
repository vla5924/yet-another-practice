// https://leetcode.com/problems/next-permutation

#include <algorithm>
#include <vector>

using namespace std;

// https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order

class Solution {
  public:
    void nextPermutation(vector<int> &nums) {
        int sz = nums.size();
        // Find the largest index k such that a[k] < a[k + 1].
        int k = -1;
        for (int i = 0; i < sz - 1; i++) {
            if (nums[i] < nums[i + 1])
                k = i;
        }
        // If no such index exists, the permutation is the last permutation.
        if (k == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        // Find the largest index l greater than k such that a[k] < a[l].
        int l = -1;
        for (int i = k + 1; i < sz; i++) {
            if (nums[k] < nums[i])
                l = i;
        }
        // Swap the value of a[k] with that of a[l].
        swap(nums[k], nums[l]);
        // Reverse the sequence from a[k + 1] up to and including the final element a[n].
        reverse(nums.begin() + (k + 1), nums.end());
    }
};

int main() { return 0; }
