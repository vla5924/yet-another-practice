// https://leetcode.com/problems/sliding-window-median/

#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

template <typename T>
void print(const T &values) {
    std::cout << "{ ";
    for (const auto &x : values)
        std::cout << x << ' ';
    std::cout << "}\n";
}

class Solution {
  public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        vector<double> medians;
        medians.reserve(nums.size() - k);
        multiset<int> gt_median;               // sorted sequence of values GE median, least is on top
        multiset<int, greater<int>> lt_median; // sorted sequence of values LT median, greatest is on top
        for (int i = 0; i < nums.size(); i++) {
            int value = nums[i];
            if (!gt_median.empty() && value > *lt_median.begin())
                gt_median.insert(value);
            else
                lt_median.insert(value);
            if (i >= k) {
                int del = nums[i - k];
                auto it = gt_median.find(del);
                if (it == gt_median.end()) {
                    auto it = lt_median.find(del);
                    if (it != lt_median.end())
                        lt_median.erase(it);
                } else {
                    gt_median.erase(it);
                }
            }
            size_t gt_size = gt_median.size();
            size_t lt_size = lt_median.size();
            if (gt_size > lt_size && gt_size - lt_size > 1) {
                for (size_t i = lt_size; i < gt_size; i++) {
                    auto gt_least = gt_median.begin();
                    lt_median.insert(*gt_least);
                    gt_median.erase(gt_least);
                    gt_size -= 1;
                    lt_size += 1;
                }
            } else if (lt_size > gt_size && lt_size - gt_size > 1) {
                for (size_t i = gt_size; i < lt_size; i++) {
                    auto lt_greatest = lt_median.begin();
                    gt_median.insert(*lt_greatest);
                    lt_median.erase(lt_greatest);
                    gt_size += 1;
                    lt_size -= 1;
                }
            }
            if (i >= k - 1) {
                double median = 0.0;
                long gt_least = *gt_median.begin();
                long lt_greatest = *lt_median.begin();
                if (gt_size == lt_size) {
                    median = static_cast<double>(lt_greatest) + (gt_least - lt_greatest) / 2.0;
                } else if (gt_size > lt_size) {
                    median = static_cast<double>(gt_least);
                } else {
                    median = static_cast<double>(lt_greatest);
                }
                medians.push_back(median);
            }
        }
        return medians;
    }
};
int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    Solution().medianSlidingWindow(nums, k);
    return 0;
}
