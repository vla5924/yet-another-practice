// https://leetcode.com/problems/single-number/

#include <vector>

using namespace std;

class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        int num = 0;
        size_t sz = nums.size();
        for (size_t i = 0; i < sz; i++) {
            num ^= nums[i];
        }
        return num;
    }
};

int main() {
    return 0;
}
