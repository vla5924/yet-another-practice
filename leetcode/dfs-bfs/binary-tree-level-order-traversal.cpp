// https://leetcode.com/problems/binary-tree-level-order-traversal/

#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr)
            return {};
        vector<vector<int>> levels;
        levels.emplace_back();
        int i = 0;
        vector<int> sizes = {1, 0};
        queue<TreeNode *> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            auto *node = bfs.front();
            levels[i].push_back(node->val);
            bfs.pop();
            if (node->left) {
                bfs.push(node->left);
                sizes[i + 1]++;
            }
            if (node->right) {
                bfs.push(node->right);
                sizes[i + 1]++;
            }
            if (levels[i].size() == sizes[i]) {
                levels.emplace_back();
                sizes.push_back(0);
                i++;
            }
        }
        if (levels.back().empty())
            levels.pop_back();
        return levels;
    }
};

int main() { return 0; }
