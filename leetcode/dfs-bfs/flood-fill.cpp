// https://leetcode.com/problems/flood-fill/

#include <vector>

using namespace std;

class Solution {
    void dfs(vector<vector<int>> &image, int row, int col, int rows, int cols, int oldColor, int newColor) {
        static vector<pair<int, int>> neighbors = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        if (row < 0 || col < 0 || row >= rows || col >= cols)
            return;
        if (image[row][col] != oldColor || image[row][col] == newColor)
            return;
        image[row][col] = newColor;
        for (const auto &[drow, dcol] : neighbors) {
            dfs(image, row + drow, col + dcol, rows, cols, oldColor, newColor);
        }
    }

  public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
        if (image[sr][sc] != color)
            dfs(image, sr, sc, image.size(), image.front().size(), image[sr][sc], color);
        return image;
    }
};

int main() { return 0; }
