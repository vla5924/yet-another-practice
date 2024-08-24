// https://leetcode.com/problems/validate-binary-search-tree/

#include <cstdint>
#include <limits>

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
    // Idea: inorder DFS must be strictly increasing array
    // Initial values should be:
    // prev = numeric_limits<int64_t>::min()
    // ascending = true
    void dfsNaive(TreeNode *node, int64_t &prev, bool &ascending) {
        if (node == nullptr)
            return;
        dfs(node->left, prev, ascending);
        ascending &= prev < node->val;
        prev = node->val;
        dfs(node->right, prev, ascending);
    }

    bool dfs(TreeNode *root, int64_t min, int64_t max) {
        if (root == nullptr)
            return true;
        if (root->val <= min || root->val >= max)
            return false;
        return dfs(root->left, min, root->val) && dfs(root->right, root->val, max);
    }

  public:
    bool isValidBST(TreeNode *root) {
        return dfs(root, numeric_limits<int64_t>::min(), numeric_limits<int64_t>::max());
    }
};

int main() { return 0; }
