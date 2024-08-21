#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

int dfs(const vector<vector<int>> &matrix, int row, int col, int rows, int cols, vector<vector<int>> &memo) {
    if (memo[row][col] != -1)
        return memo[row][col];
    int longest = 0;
    static vector<pair<int, int>> neighbor = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (auto [drow, dcol] : neighbor) {
        int trow = row + drow;
        int tcol = col + dcol;
        if (trow < 0 || tcol < 0 || trow >= rows || tcol >= cols || matrix[trow][tcol] <= matrix[row][col])
            continue;
        int len = dfs(matrix, trow, tcol, rows, cols, memo);
        if (len > longest)
            longest = len;
    }
    return memo[row][col] = 1 + longest;
}

int getLongestIncreasingPath(int n, int m, const vector<vector<int>> &matrix) {
    int longest = 0;
    vector<vector<int>> memo(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int len = dfs(matrix, i, j, n, m, memo);
            if (len > longest)
                longest = len;
        }
    }
    return longest;
}

int readInt() {
    int x;
    cin >> x;
    return x;
}

vector<int> readList(int n) {
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }
    return res;
}

vector<vector<int>> readMatrix(int n, int m) {
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        matrix[i] = readList(m);
    }
    return matrix;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix = readMatrix(n, m);
    cout << getLongestIncreasingPath(n, m, matrix);
}
