// https://leetcode.com/problems/number-of-islands/

#include <utility>
#include <vector>

using namespace std;

class Solution {
    void dfs(vector<vector<char>> &grid, int row, int col, int rows, int cols, int &visited) {
        static vector<pair<int, int>> neighbors = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        if (row < 0 || col < 0 || row >= rows || col >= cols)
            return;
        if (grid[row][col] != '1')
            return;
        grid[row][col] = '2';
        visited += 1;
        for (const auto &[drow, dcol] : neighbors) {
            dfs(grid, row + drow, col + dcol, rows, cols, visited);
        }
    }

  public:
    int numIslands(vector<vector<char>> &grid) {
        int rows = grid.size();
        int cols = grid.front().size();
        int n = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                int visited = 0;
                dfs(grid, row, col, rows, cols, visited);
                if (visited != 0)
                    n++;
            }
        }
        return n;
    }
};

int main() {
    return 0;
}
