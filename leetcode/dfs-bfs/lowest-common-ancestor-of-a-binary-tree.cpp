// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    bool dfs(TreeNode *node, TreeNode *needle, stack<TreeNode *> &path) {
        if (node == nullptr)
            return false;
        if (node == needle) {
            path.push(node);
            return true;
        }
        if (dfs(node->left, needle, path) || dfs(node->right, needle, path)) {
            path.push(node);
            return true;
        }
        return false;
    }

  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        stack<TreeNode *> pPath, qPath;
        dfs(root, p, pPath);
        dfs(root, q, qPath);
        TreeNode *anc = root;
        while (!pPath.empty() && !qPath.empty() && pPath.top() == qPath.top()) {
            anc = pPath.top();
            pPath.pop();
            qPath.pop();
        }
        return anc;
    }
};

int main() { return 0; }
