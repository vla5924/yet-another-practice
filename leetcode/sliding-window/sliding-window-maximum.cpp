// https://leetcode.com/problems/sliding-window-maximum/

#include <deque>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> maximums;
        maximums.reserve(nums.size() - k);
        deque<pair<size_t, int>> slidingMax;
        for (size_t i = 0; i < nums.size(); i++) {
            while (!slidingMax.empty() && nums[i] > slidingMax.back().second) {
                slidingMax.pop_back();
            }
            if (i >= k && !slidingMax.empty() && slidingMax.front().first == i - k)
                slidingMax.pop_front();
            slidingMax.emplace_back(i, nums[i]);
            if (i >= k - 1)
                maximums.push_back(slidingMax.front().second);
        }
        return maximums;
    }
};

int main() {
    return 0;
}
