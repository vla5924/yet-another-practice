// https://leetcode.com/problems/container-with-most-water/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxArea(vector<int> &height) {
        int sz = static_cast<int>(height.size());
        int left = 0;
        int right = sz - 1;
        int max = 0;
        while (left < right) {
            int current = (right - left) * min(height[left], height[right]);
            if (current > max)
                max = current;
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return max;
    }
};

int main() {
    return 0;
}
