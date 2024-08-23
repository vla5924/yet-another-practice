// https://leetcode.com/problems/01-matrix

#include <queue>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        int rows = mat.size();
        int cols = mat.front().size();
        queue<pair<int, int>> bfs;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (mat[i][j] == 0) {
                    bfs.emplace(i, j);
                    visited[i][j] = true;
                }
        vector<vector<int>> dist(rows, vector<int>(cols, 0));
        static vector<pair<int, int>> neighbors = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!bfs.empty()) {
            auto [cRow, cCol] = bfs.front();
            int cDist = dist[cRow][cCol];
            bfs.pop();
            for (const auto &[dRow, dCol] : neighbors) {
                int nRow = cRow + dRow;
                int nCol = cCol + dCol;
                if (nRow < 0 || nCol < 0 || nRow >= rows || nCol >= cols || visited[nRow][nCol])
                    continue;
                dist[nRow][nCol] = cDist + 1;
                visited[nRow][nCol] = true;
                bfs.emplace(nRow, nCol);
            }
        }
        return dist;
    }
};

int main() { return 0; }
