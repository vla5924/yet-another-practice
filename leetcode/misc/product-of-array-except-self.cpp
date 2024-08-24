// https://leetcode.com/problems/product-of-array-except-self

#include <numeric>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> prefProd(nums.size(), 1);
        vector<int> suffProd(nums.size(), 1);
        exclusive_scan(nums.begin(), nums.end(), prefProd.begin(), 1, multiplies<int>());
        exclusive_scan(nums.rbegin(), nums.rend(), suffProd.rbegin(), 1, multiplies<int>());
        for (int i = 0; i < nums.size(); i++)
            nums[i] = prefProd[i] * suffProd[i];
        return nums;
    }
};

int main() { return 0; }
