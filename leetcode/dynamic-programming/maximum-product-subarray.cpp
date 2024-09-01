// https://leetcode.com/problems/maximum-product-subarray

#include <vector>

using namespace std;

class Solution {
  public:
    int maxProduct(vector<int> &nums) {
        int sz = nums.size();
        if (sz == 1)
            return nums[0];
        int maxProd = nums[0];
        int localMax = maxProd;
        int localMin = maxProd;
        for (int i = 1; i < sz; i++) {
            // multiplied by a negative makes big number smaller, small number bigger
            if (nums[i] < 0)
                swap(localMax, localMin);
            // either add ith to existing subarray or start over
            localMax = max(nums[i], nums[i] * localMax);
            localMin = min(nums[i], nums[i] * localMin);
            maxProd = max(maxProd, localMax);
        }
        return maxProd;
    }
};

int main() { return 0; }
