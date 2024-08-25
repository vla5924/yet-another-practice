// https://leetcode.com/problems/majority-element/

// For this solution, map is faster than unordered_map!

#include <map>
#include <vector>

using namespace std;

class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        map<int, int> occurs;
        int sz = nums.size();
        for (int i = 0; i < sz; i++)
            occurs[nums[i]]++;
        for (auto &it : occurs)
            if (it.second > sz / 2)
                return it.first;
        return 0;
    }
};

int main() { return 0; }
