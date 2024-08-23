// https://leetcode.com/problems/3sum/

#include <algorithm>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
    struct Triplet {
        int a, b, c;

        Triplet(int pa, int pb, int pc) : a(pa), b(pb), c(pc) {
            if (a > b)
                swap(a, b);
            if (a > c)
                swap(a, c);
            if (b > c)
                swap(b, c);
        }

        bool operator<(const Triplet &other) const {
            return a < other.a || (a == other.a && b < other.b) || (a == other.a && b == other.b && c < other.c);
        }

        operator vector<int>() const { return {a, b, c}; }
    };

  public:
    vector<vector<int>> threeSome(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        if (nums.back() == 0 && nums.front() == 0)
            return {{0, 0, 0}};
        if (nums.back() < 0 && nums.front() < 0)
            return {};
        if (nums.back() > 0 && nums.front() > 0)
            return {};
        set<Triplet> triplets;
        for (int i = 0; i < nums.size() - 2; i++) {
            unordered_map<int, int> diffs;
            for (int j = i + 1; j < nums.size(); j++) {
                int diff = -(nums[i] + nums[j]);
                if (diffs.contains(diff)) {
                    triplets.emplace(nums[i], nums[j], diff);
                }
                diffs[nums[j]] = j;
            }
        }
        return {triplets.begin(), triplets.end()};
    }

    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        if (nums.back() == 0 && nums.front() == 0)
            return {{0, 0, 0}};
        if (nums.back() < 0 && nums.front() < 0)
            return {};
        if (nums.back() > 0 && nums.front() > 0)
            return {};
        set<Triplet> triplets;
        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    triplets.emplace(nums[i], nums[left], nums[right]);
                    right--;
                    left++;
                } else if (sum > 0)
                    right--;
                else if (sum < 0)
                    left++;
            }
        }
        return {triplets.begin(), triplets.end()};
    }
};

int main() { return 0; }
