// https://leetcode.com/problems/sort-colors/

#include <vector>

using namespace std;

class Solution {
  public:
    void sortColors(vector<int> &nums) {
        int occurs[] = {0, 0, 0};
        for (int i = 0; i < nums.size(); i++)
            occurs[nums[i]]++;
        int insert = 0;
        for (int color = 0; color <= 2; color++)
            for (int i = 0; i < occurs[color]; i++)
                nums[insert++] = color;
    }
};

int main() { return 0; }
