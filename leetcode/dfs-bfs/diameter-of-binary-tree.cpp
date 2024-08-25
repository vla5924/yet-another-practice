// https://leetcode.com/problems/diameter-of-binary-tree/

#include <numeric>

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
    int dfs(TreeNode *node, int &diameter) {
        if (node == nullptr)
            return 0;
        int left = dfs(node->left, diameter);
        int right = dfs(node->right, diameter);
        diameter = max(diameter, left + right);
        return 1 + max(left, right);
    }

  public:
    int diameterOfBinaryTree(TreeNode *root) {
        int diameter = 0;
        dfs(root, diameter);
        return diameter;
    }
};

int main() { return 0; }
