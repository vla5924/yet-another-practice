// https://leetcode.com/problems/rotting-oranges/

#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
  public:
    int orangesRotting(vector<vector<int>> &grid) {
        int rows = grid.size();
        int cols = grid.front().size();
        queue<pair<int, int>> bfs;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (grid[i][j] == 1) {
                    bfs.emplace(i, j);
                    visited[i][j] = true;
                }
        if (bfs.empty())
            return 0;
        bfs.emplace(-1, -1);
        int minute = 0;
        set<pair<int, int>> toRot;
        static vector<pair<int, int>> neighbors = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!bfs.empty()) {
            auto [cRow, cCol] = bfs.front();
            bfs.pop();
            if (cRow == -1) {
                if (toRot.empty())
                    return -1;
                for (auto [row, col] : toRot) {
                    grid[row][col] = 2;
                    visited[row][col] = false;
                }
                toRot.clear();
                minute++;
                if (bfs.empty())
                    break;
                bfs.emplace(-1, -1);
                continue;
            }
            bool willRot = false;
            for (const auto &[dRow, dCol] : neighbors) {
                int nRow = cRow + dRow;
                int nCol = cCol + dCol;
                if (nRow < 0 || nCol < 0 || nRow >= rows || nCol >= cols || visited[nRow][nCol])
                    continue;
                int stat = grid[nRow][nCol];
                if (stat == 1) {
                    bfs.emplace(nRow, nCol);
                    visited[nRow][nCol] = true;
                } else if (stat == 2) {
                    willRot = true;
                }
            }
            if (willRot) {
                toRot.emplace(cRow, cCol);
            } else {
                bfs.emplace(cRow, cCol);
            }
        }
        return minute;
    }
};

int main() {
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    // vector<vector<int>> grid = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
    // vector<vector<int>> grid = {{0, 2}};
    cout << Solution().orangesRotting(grid);
    return 0;
}
