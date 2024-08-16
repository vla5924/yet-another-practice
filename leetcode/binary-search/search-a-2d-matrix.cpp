// https://leetcode.com/problems/search-a-2d-matrix/

#include <vector>

using namespace std;

class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        size_t rows = matrix.size();
        size_t cols = matrix.front().size();
        size_t left = 0U;
        size_t right = rows * cols;
        while (left < right) {
            auto mid = left + (right - left) / 2U;
            int elem = matrix[mid / cols][mid % cols];
            if (elem == target) {
                return true;
            }
            if (elem < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return false;
    }
};

int main() {
    return 0;
}
